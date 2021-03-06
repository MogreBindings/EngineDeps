/*!
	@file
	@author		Albert Semenov
	@date		11/2007
*/
/*
	This file is part of MyGUI.

	MyGUI is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	MyGUI is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with MyGUI.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "MyGUI_Precompiled.h"
#include "MyGUI_Gui.h"
#include "MyGUI_Widget.h"
#include "MyGUI_InputManager.h"
#include "MyGUI_SkinManager.h"
#include "MyGUI_WidgetManager.h"
#include "MyGUI_ResourceSkin.h"
#include "MyGUI_WidgetDefines.h"
#include "MyGUI_LayerItem.h"
#include "MyGUI_LayerManager.h"
#include "MyGUI_RenderItem.h"
#include "MyGUI_ISubWidget.h"
#include "MyGUI_ISubWidgetText.h"
#include "MyGUI_StaticText.h"
#include "MyGUI_FactoryManager.h"
#include "MyGUI_LanguageManager.h"
#include "MyGUI_CoordConverter.h"
#include "MyGUI_RenderManager.h"
#include "MyGUI_ToolTipManager.h"

namespace MyGUI
{

	void Widget::staticConstructor()
	{
		InputElement::registerInputElement();
	}

	void Widget::staticDestructor()
	{
		InputElement::unregisterInputElement();
	}

	Widget::Widget() :
		mMaskPickInfo(nullptr),
		mText(nullptr),
		mMainSkin(nullptr),
		mSubSkinsVisible(true),
		mAlpha(ALPHA_MIN),
		mRealAlpha(ALPHA_MIN),
		mInheritsAlpha(true),
		mTexture(nullptr),
		mParent(nullptr),
		mIWidgetCreator(nullptr),
		mInheritsPick(false),
		mWidgetClient(nullptr),
		mNeedToolTip(false),
		mWidgetStyle(WidgetStyle::Child),
		mMaxSize(MAX_COORD, MAX_COORD),
		mContainer(nullptr)
	{
	}

	Widget::~Widget()
	{
	}

	void Widget::_initialise(WidgetStyle _style, const IntCoord& _coord, Align _align, ResourceSkin* _info, Widget* _parent, ICroppedRectangle * _croppedParent, IWidgetCreator * _creator, const std::string& _name)
	{
		mCoord = IntCoord(_coord.point(), _info->getSize());
		mStateInfo = _info->getStateInfo();
		mMaskPickInfo = _info->getMask();

		mTextureName = _info->getTextureName();
		mTexture = RenderManager::getInstance().getTexture(mTextureName);

		mAlign = _align;
		mCroppedParent = _croppedParent;

		mName = _name;
		mParent = _parent;
		mIWidgetCreator = _creator;

		mWidgetStyle = _style;

		// имя отсылателя сообщений
		mWidgetEventSender = this;

#if MYGUI_DEBUG_MODE == 1
		// проверяем соответсвие входных данных
		if (mWidgetStyle == WidgetStyle::Child)
		{
			MYGUI_ASSERT(mCroppedParent, "must be cropped");
			MYGUI_ASSERT(mParent, "must be parent");
		}
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			MYGUI_ASSERT((mParent == nullptr) == (mCroppedParent == nullptr), "error cropped");
		}
		else if (mWidgetStyle == WidgetStyle::Popup)
		{
			MYGUI_ASSERT(!mCroppedParent, "cropped must be nullptr");
			MYGUI_ASSERT(mParent, "must be parent");
		}
#endif

		// корректируем абсолютные координаты
		mAbsolutePosition = _coord.point();

		if (nullptr != mCroppedParent)
		{
			mAbsolutePosition += mCroppedParent->getAbsolutePosition();
		}

		initialiseWidgetSkin(_info, _coord.size());

		// дочернее окно обыкновенное
		if (mWidgetStyle == WidgetStyle::Child)
		{
			if (mParent) mParent->addChildItem(this);
		}
		// дочернее нуно перекрывающееся
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			// дочернее перекрывающееся
			if (mParent) mParent->addChildNode(this);
		}
	}

	void Widget::_shutdown()
	{
		shutdownWidgetSkin(true);

		_destroyAllChildWidget();

		// дочернее окно обыкновенное
		if (mWidgetStyle == WidgetStyle::Child)
		{
			if (mParent) mParent->removeChildItem(this);
		}
		// дочернее нуно перекрывающееся
		else if (mWidgetStyle == WidgetStyle::Overlapped)
		{
			// дочернее перекрывающееся
			if (mParent) mParent->removeChildNode(this);
		}

		mParent = nullptr;
		mIWidgetCreator = nullptr;
		mTexture = nullptr;
		mCroppedParent = nullptr;
	}

	void Widget::changeWidgetSkin(const std::string& _skinname)
	{
		ResourceSkin* skin_info = SkinManager::getInstance().getByName(_skinname);
		baseChangeWidgetSkin(skin_info);
	}

	void Widget::baseChangeWidgetSkin(ResourceSkin* _info)
	{
		IntSize size = mCoord.size();

		saveLayerItem();

		shutdownWidgetSkin();
		initialiseWidgetSkin(_info, size);

		restoreLayerItem();
	}

	void Widget::initialiseWidgetSkin(ResourceSkin* _info, const IntSize& _size)
	{
		FactoryManager& factory = FactoryManager::getInstance();

		mTextureName = _info->getTextureName();
		mTexture = RenderManager::getInstance().getTexture(mTextureName);

		setRenderItemTexture(mTexture);
		mStateInfo = _info->getStateInfo();
		Widget::setSize(_info->getSize());

		// загружаем кирпичики виджета
		for (VectorSubWidgetInfo::const_iterator iter=_info->getBasisInfo().begin(); iter!=_info->getBasisInfo().end(); ++iter)
		{
			IObject* object = factory.createObject("BasisSkin", (*iter).type);
			if (object == nullptr) continue;

			ISubWidget* sub = object->castType<ISubWidget>();
			sub->_setCroppedParent(this);
			sub->setCoord((*iter).coord);
			sub->setAlign((*iter).align);

			mSubSkinChild.push_back(sub);
			addRenderItem(sub);

			// ищем дефолтные сабвиджеты
			if (mMainSkin == nullptr) mMainSkin = sub->castType<ISubWidgetRect>(false);
			if (mText == nullptr) mText = sub->castType<ISubWidgetText>(false);
		}

		if (!isRootWidget())
		{
			// проверяем наследуемую скрытость
			if ((!mParent->isVisible()) || (!mParent->_isInheritsVisible()))
			{
				_updateInheritsVisible();
			}
			// проверяем наследуемый дизейбл
			if ((!mParent->isEnabled()) || (!mParent->_isInheritsEnable()))
			{
				_updateInheritsEnable();
			}
		}

		Widget::setState("normal");//FIXME - явный вызов

		// парсим свойства
		const MapString& properties = _info->getProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			if ((iter = properties.find("NeedKey")) != properties.end()) setNeedKeyFocus(utility::parseBool(iter->second));
			if ((iter = properties.find("NeedMouse")) != properties.end()) setNeedMouseFocus(utility::parseBool(iter->second));
			if ((iter = properties.find("Pointer")) != properties.end()) mPointer = iter->second;
			if ((iter = properties.find("Visible")) != properties.end()) { setVisible(utility::parseBool(iter->second)); }

			// OBSOLETE
			if ((iter = properties.find("AlignText")) != properties.end()) _setTextAlign(Align::parse(iter->second));
			if ((iter = properties.find("Colour")) != properties.end()) _setTextColour(Colour::parse(iter->second));
			if ((iter = properties.find("Show")) != properties.end()) { setVisible(utility::parseBool(iter->second)); }
			if ((iter = properties.find("TextAlign")) != properties.end()) _setTextAlign(Align::parse(iter->second));
			if ((iter = properties.find("TextColour")) != properties.end()) _setTextColour(Colour::parse(iter->second));
			if ((iter = properties.find("FontName")) != properties.end()) _setFontName(iter->second);
			if ((iter = properties.find("FontHeight")) != properties.end()) _setFontHeight(utility::parseInt(iter->second));
		}

		// выставляем альфу, корректировка по отцу автоматически
		Widget::setAlpha(ALPHA_MAX);//FIXME - явный вызов

		// создаем детей скина
		const VectorChildSkinInfo& child = _info->getChild();
		for (VectorChildSkinInfo::const_iterator iter=child.begin(); iter!=child.end(); ++iter)
		{
			//FIXME - явный вызов
			Widget* widget = Widget::baseCreateWidget(iter->style, iter->type, iter->skin, iter->coord, iter->align, iter->layer, "");
			widget->_setInternalData(iter->name);
			// заполняем UserString пропертями
			for (MapString::const_iterator prop=iter->params.begin(); prop!=iter->params.end(); ++prop)
			{
				widget->setUserString(prop->first, prop->second);
			}
			// для детей скина свой список
			mWidgetChildSkin.push_back(widget);
			mWidgetChild.pop_back();
		}

		Widget::setSize(_size);//FIXME - явный вызов
	}

	void Widget::shutdownWidgetSkin(bool _deep)
	{
		// удаляем все сабскины
		mMainSkin = nullptr;
		mText = nullptr;

		removeAllRenderItems();

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			delete (*skin);
		}
		mSubSkinChild.clear();

		mStateInfo.clear();

		// удаляем виджеты чтобы ли в скине
		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			// Добавляем себя чтобы удалилось
			mWidgetChild.push_back(*iter);
			_destroyChildWidget(*iter);
		}
		mWidgetChildSkin.clear();
	}

	Widget* Widget::baseCreateWidget(WidgetStyle _style, const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _layer, const std::string& _name)
	{
		Widget* widget = WidgetManager::getInstance().createWidget(_style, _type, _skin, _coord, _align, this,
			_style == WidgetStyle::Popup ? nullptr : this, this, _name);

		mWidgetChild.push_back(widget);

		// присоединяем виджет с уровню
		if (!_layer.empty() && widget->isRootWidget()) LayerManager::getInstance().attachToLayerNode(_layer, widget);

		//invalidateMeasure();

		return widget;
	}

	Widget* Widget::createWidgetRealT(const std::string& _type, const std::string& _skin, const FloatCoord& _coord, Align _align, const std::string& _name)
	{
		return createWidgetT(_type, _skin, CoordConverter::convertFromRelative(_coord, getSize()), _align, _name);
	}

	void Widget::_updateView()
	{

		bool margin = mCroppedParent ? _checkMargin() : false;

		// вьюпорт стал битым
		if (margin)
		{
			// проверка на полный выход за границу
			if (_checkOutside())
			{
				// запоминаем текущее состояние
				mIsMargin = margin;

				// скрываем
				_setSubSkinVisible(false);

				// для тех кому нужно подправить себя при движении
				//for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
				//	(*skin)->_updateView();

				// вся иерархия должна быть проверенна
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
					(*widget)->_updateView();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
					(*widget)->_updateView();

				return;
			}

		}
		// мы не обрезаны и были нормальные
		else if (!mIsMargin)
		{
			// запоминаем текущее состояние
			//mIsMargin = margin;

			//_setSubSkinVisible(true);
			// для тех кому нужно подправить себя при движении
			for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
				(*skin)->_updateView();

			return;
		}

		// запоминаем текущее состояние
		mIsMargin = margin;

		// если скин был скрыт, то покажем
		_setSubSkinVisible(true);

		// обновляем наших детей, а они уже решат обновлять ли своих детей
		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
			(*widget)->_updateView();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
			(*widget)->_updateView();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_updateView();

	}

	void Widget::setCaption(const UString& _caption)
	{
		if (nullptr != mText) mText->setCaption(_caption);
	}

	const UString& Widget::getCaption()
	{
		if (nullptr == mText)
		{
			static UString empty;
			return empty;
		}
		return mText->getCaption();
	}

	bool Widget::setState(const std::string& _state)
	{
		MapWidgetStateInfo::const_iterator iter = mStateInfo.find(_state);
		if (iter == mStateInfo.end()) return false;
		size_t index=0;
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin, ++index)
		{
			IStateInfo* data = (*iter).second[index];
			if (data != nullptr)
			{
				(*skin)->setStateData(data);
			}
		}
		return true;
	}

	void Widget::_destroyChildWidget(Widget* _widget)
	{
		MYGUI_ASSERT(nullptr != _widget, "invalid widget pointer");

		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), _widget);
		if (iter != mWidgetChild.end())
		{
			// сохраняем указатель
			MyGUI::Widget* widget = *iter;

			// удаляем из списка
			*iter = mWidgetChild.back();
			mWidgetChild.pop_back();

			// отписываем от всех
			WidgetManager::getInstance().unlinkFromUnlinkers(_widget);

			// непосредственное удаление
			_deleteWidget(widget);
		}
		else
		{
			MYGUI_EXCEPT("Widget '" << _widget->getName() << "' not found");
		}
	}

	// удаляет всех детей
	void Widget::_destroyAllChildWidget()
	{
		WidgetManager& manager = WidgetManager::getInstance();
		while (!mWidgetChild.empty())
		{
			// сразу себя отписывем, иначе вложенной удаление убивает все
			Widget* widget = mWidgetChild.back();
			mWidgetChild.pop_back();

			//if (widget->isRootWidget()) widget->detachWidget();

			// отписываем от всех
			manager.unlinkFromUnlinkers(widget);

			// и сами удалим, так как его больше в списке нет
			widget->_shutdown();
			WidgetManager::getInstance()._addWidgetToDestroy(widget);
		}
	}

	IntCoord Widget::getClientCoord()
	{
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->getCoord();
		return IntCoord(0, 0, mCoord.width, mCoord.height);
	}

	void Widget::setAlpha(float _alpha)
	{
		if (mAlpha == _alpha) return;
		mAlpha = _alpha;
		if (nullptr != mParent) mRealAlpha = mAlpha * (mInheritsAlpha ? mParent->_getRealAlpha() : ALPHA_MAX);
		else mRealAlpha = mAlpha;

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
			(*widget)->_updateAlpha();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
			(*widget)->_updateAlpha();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->setAlpha(mRealAlpha);
	}

	void Widget::_updateAlpha()
	{
		MYGUI_DEBUG_ASSERT(nullptr != mParent, "Widget must have parent");
		mRealAlpha = mAlpha * (mInheritsAlpha ? mParent->_getRealAlpha() : ALPHA_MAX);

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
			(*widget)->_updateAlpha();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
			(*widget)->_updateAlpha();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->setAlpha(mRealAlpha);
	}

	void Widget::setInheritsAlpha(bool _inherits)
	{
		mInheritsAlpha = _inherits;
		// принудительно обновляем
		float alpha = mAlpha;
		mAlpha += std::numeric_limits<float>::max();
		setAlpha(alpha);
	}

	ILayerItem * Widget::getLayerItemByPoint(int _left, int _top)
	{
		// проверяем попадание
		if (!mSubSkinsVisible
			|| !isEnabled()
			|| !isVisible()
			|| (!isNeedMouseFocus() && !mInheritsPick)
			|| !_checkPoint(_left, _top)
			// если есть маска, проверяем еще и по маске
			|| ((!mMaskPickInfo->empty()) && (!mMaskPickInfo->pick(IntPoint(_left - mCoord.left, _top - mCoord.top), mCoord))))
				return nullptr;
		// спрашиваем у детишек
		for (VectorWidgetPtr::reverse_iterator widget= mWidgetChild.rbegin(); widget != mWidgetChild.rend(); ++widget)
		{
			// общаемся только с послушными детьми
			if ((*widget)->mWidgetStyle == WidgetStyle::Popup) continue;

			ILayerItem * item = (*widget)->getLayerItemByPoint(_left - mCoord.left, _top - mCoord.top);
			if (item != nullptr) return item;
		}
		// спрашиваем у детишек скна
		for (VectorWidgetPtr::reverse_iterator widget= mWidgetChildSkin.rbegin(); widget != mWidgetChildSkin.rend(); ++widget)
		{
			ILayerItem * item = (*widget)->getLayerItemByPoint(_left - mCoord.left, _top - mCoord.top);
			if (item != nullptr) return item;
		}
		// непослушные дети
		return mInheritsPick ? nullptr : this;
	}

	void Widget::_updateAbsolutePoint()
	{
		// мы рут, нам не надо
		if (!mCroppedParent) return;

		mAbsolutePosition = mCroppedParent->getAbsolutePosition() + mCoord.point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
			(*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
			(*widget)->_updateAbsolutePoint();
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_correctView();
	}

	void Widget::_setUVSet(const FloatRect& _rect)
	{
		if (nullptr != mMainSkin) mMainSkin->_setUVSet(_rect);
	}

	void Widget::_setTextureName(const std::string& _texture)
	{
		mTextureName = _texture;
		mTexture = RenderManager::getInstance().getTexture(mTextureName);

		setRenderItemTexture(mTexture);
	}

	const std::string& Widget::_getTextureName()
	{
		return mTextureName;
	}

	void Widget::_setSubSkinVisible(bool _visible)
	{
		if (mSubSkinsVisible == _visible) return;
		mSubSkinsVisible = _visible;

		// просто обновляем
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			(*skin)->_updateView();
		}
	}

	void Widget::_forcePeek(Widget* _widget)
	{
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) mWidgetClient->_forcePeek(_widget);

		size_t size = mWidgetChild.size();
		if ( (size < 2) || (mWidgetChild[size-1] == _widget) ) return;
		for (size_t pos=0; pos<size; pos++)
		{
			if (mWidgetChild[pos] == _widget)
			{
				mWidgetChild[pos] = mWidgetChild[size-1];
				mWidgetChild[size-1] = _widget;
				return;
			}
		}
	}

	const std::string& Widget::getLayerName()
	{
		ILayer* layer = getLayer();
		if (nullptr == layer)
		{
			static std::string empty;
			return empty;
		}
		return layer->getName();
	}

	Widget* Widget::findWidget(const std::string& _name)
	{
		if (_name == mName) return this;
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->findWidget(_name);
		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
		{
			Widget* find = (*widget)->findWidget(_name);
			if (nullptr != find) return find;
		}
		return nullptr;
	}

	void Widget::setMaskPick(const std::string& _filename)
	{
		if (mOwnMaskPickInfo.load(_filename))
		{
			mMaskPickInfo = &mOwnMaskPickInfo;
		}
		else
		{
			MYGUI_LOG(Error, "mask not load '" << _filename << "'");
		}
	}

	void Widget::setRealPosition(const FloatPoint& _point)
	{
		setPosition(CoordConverter::convertFromRelative(_point, getParentSize()));
	}

	void Widget::setRealSize(const FloatSize& _size)
	{
		setSize(CoordConverter::convertFromRelative(_size, getParentSize()));
	}

	void Widget::setRealCoord(const FloatCoord& _coord)
	{
		setCoord(CoordConverter::convertFromRelative(_coord, getParentSize()));
	}

	void Widget::_linkChildWidget(Widget* _widget)
	{
		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), _widget);
		MYGUI_ASSERT(iter == mWidgetChild.end(), "widget already exist");
		mWidgetChild.push_back(_widget);
	}

	void Widget::_unlinkChildWidget(Widget* _widget)
	{
		VectorWidgetPtr::iterator iter = std::remove(mWidgetChild.begin(), mWidgetChild.end(), _widget);
		MYGUI_ASSERT(iter != mWidgetChild.end(), "widget not found");
		mWidgetChild.erase(iter);
	}

	void Widget::_setTextAlign(Align _align)
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) text->setTextAlign(_align);

		if (mText != nullptr) mText->setTextAlign(_align);
	}

	Align Widget::_getTextAlign()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getTextAlign();

		if (mText != nullptr) return mText->getTextAlign();
		return Align::Default;
	}

	void Widget::_setTextColour(const Colour& _colour)
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->setTextColour(_colour);

		if (nullptr != mText) mText->setTextColour(_colour);
	}

	const Colour& Widget::_getTextColour()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getTextColour();

		return (nullptr == mText) ? Colour::Zero : mText->getTextColour();
	}

	void Widget::_setFontName(const std::string& _font)
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) text->setFontName(_font);

		if (nullptr != mText) mText->setFontName(_font);
	}

	const std::string& Widget::_getFontName()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getFontName();

		if (nullptr == mText)
		{
			static std::string empty;
			return empty;
		}
		return mText->getFontName();
	}

	void Widget::_setFontHeight(int _height)
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) text->setFontHeight(_height);

		if (nullptr != mText) mText->setFontHeight(_height);
	}

	int Widget::_getFontHeight()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getFontHeight();

		return (nullptr == mText) ? 0 : mText->getFontHeight();
	}

	IntSize Widget::_getTextSize()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getTextSize();

		return (nullptr == mText) ? IntSize() : mText->getTextSize();
	}

	IntCoord Widget::_getTextRegion()
	{
		StaticText* text = this->castType<StaticText>(false);
		if (text) return text->getTextRegion();

		return (nullptr == mText) ? IntCoord() : mText->getCoord();
	}

	void Widget::setPosition(const IntPoint& _point)
	{
		setCoord(_point.left, _point.top, mCoord.width, mCoord.height);
		/*IntPoint point = _point;
		if (mAlign == Align::Center)
		{
			IntSize size = getParentSize();
			point.left = (size.width - mCoord.width) / 2;
			point.top = (size.height - mCoord.height) / 2;
		}

		// обновляем абсолютные координаты
		mAbsolutePosition += point - mCoord.point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		mCoord = point;

		_updateView();*/
	}

	void Widget::setSize(const IntSize& _size)
	{
		setCoord(mCoord.left, mCoord.top, _size.width, _size.height);
		// устанавливаем новую координату а старую пускаем в расчеты
		/*IntSize old = mCoord.size();
		mCoord = _size;

		bool visible = true;

		// обновляем выравнивание
		bool margin = mCroppedParent ? _checkMargin() : false;

		if (margin)
		{
			// проверка на полный выход за границу
			if (_checkOutside())
			{
				// скрываем
				visible = false;
			}
		}

		_setSubSkinVisible(visible);

		// передаем старую координату , до вызова, текущая координата отца должна быть новой
		overrideArrange(old);

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_setAlign(old, mIsMargin || margin);

		// запоминаем текущее состояние
		mIsMargin = margin;*/
	}

	void Widget::setCoord(const IntCoord& _coord)
	{
		IntCoord coord = _coord;
		IntSize size = getParentSize();
		if (mAlign.isHCenter())
			coord.left = (size.width - coord.width) / 2;
		if (mAlign.isVCenter())
			coord.top = (size.height - coord.height) / 2;

		// обновляем абсолютные координаты
		mAbsolutePosition += coord.point() - mCoord.point();

		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		// устанавливаем новую координату а старую пускаем в расчеты
		IntCoord old = mCoord;
		mCoord = coord;

		bool visible = true;

		// обновляем выравнивание
		bool margin = mCroppedParent ? _checkMargin() : false;

		if (margin)
		{
			// проверка на полный выход за границу
			if (_checkOutside())
			{
				// скрываем
				visible = false;
			}
		}

		_setSubSkinVisible(visible);

		// передаем старую координату , до вызова, текущая координата отца должна быть новой
		overrideArrange(old.size());

		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
			(*skin)->_setAlign(old.size(), mIsMargin || margin);

		// запоминаем текущее состояние
		mIsMargin = margin;
	}

	void Widget::setAlign(Align _align)
	{
		ICroppedRectangle::setAlign(_align);

		if (mAlign.isHCenter() || mAlign.isVCenter())
			setCoord(mCoord);

		if (mSizePolicy != SizePolicy::Manual)
			invalidateMeasure();
	}

	void Widget::detachFromWidget(const std::string& _layer)
	{
		std::string oldlayer = getLayerName();

		Widget* parent = getParent();
		if (parent)
		{
			// отдетачиваемся от лееров
			if ( ! isRootWidget() )
			{
				detachFromLayerItemNode(true);

				if (mWidgetStyle == WidgetStyle::Child)
				{
					mParent->removeChildItem(this);
				}
				else if (mWidgetStyle == WidgetStyle::Overlapped)
				{
					mParent->removeChildNode(this);
				}

				mWidgetStyle = WidgetStyle::Overlapped;

				mCroppedParent = nullptr;

				// обновляем координаты
				mAbsolutePosition = mCoord.point();

				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

				// сбрасываем обрезку
				mMargin.clear();

				_updateView();
			}

			// нам нужен самый рутовый парент
			while (parent->getParent()) { parent = parent->getParent(); }

			mIWidgetCreator = parent->mIWidgetCreator;
			mIWidgetCreator->_linkChildWidget(this);
			mParent->_unlinkChildWidget(this);
			mParent = nullptr;
		}

		if (!_layer.empty())
		{
			LayerManager::getInstance().attachToLayerNode(_layer, this);
		}
		else if (!oldlayer.empty())
		{
			LayerManager::getInstance().attachToLayerNode(oldlayer, this);
		}

		// корректируем параметры
		float alpha = mAlpha;
		mAlpha += 101;
		setAlpha(alpha);
	}

	void Widget::attachToWidget(Widget* _parent, WidgetStyle _style, const std::string& _layer)
	{
		MYGUI_ASSERT(_parent, "parent must be valid");
		MYGUI_ASSERT(_parent != this, "cyclic attach (attaching to self)");

		// attach to client if widget have it
		if (_parent->getClientWidget())
			_parent = _parent->getClientWidget();

		// проверяем на цикличность атача
		Widget* parent = _parent;
		while (parent->getParent())
		{
			MYGUI_ASSERT(parent != this, "cyclic attach");
			parent = parent->getParent();
		}

		// отдетачиваемся от всего
		detachFromWidget();

		mWidgetStyle = _style;

		if (_style == WidgetStyle::Popup)
		{
			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = _parent;
			mParent = _parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = nullptr;

			if (!_layer.empty())
			{
				LayerManager::getInstance().attachToLayerNode(_layer, this);
			}
		}
		else if (_style == WidgetStyle::Child)
		{
			LayerManager::getInstance().detachFromLayer(this);

			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = _parent;
			mParent = _parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = _parent;
			mAbsolutePosition = _parent->getAbsolutePosition() + mCoord.point();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

			mParent->addChildItem(this);

			_updateView();
		}
		else if (_style == WidgetStyle::Overlapped)
		{
			LayerManager::getInstance().detachFromLayer(this);

			mIWidgetCreator->_unlinkChildWidget(this);
			mIWidgetCreator = _parent;
			mParent = _parent;
			mParent->_linkChildWidget(this);

			mCroppedParent = _parent;
			mAbsolutePosition = _parent->getAbsolutePosition() + mCoord.point();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

			mParent->addChildNode(this);

			_updateView();
		}

		// корректируем параметры
		float alpha = mAlpha;
		mAlpha = -1;
		setAlpha(alpha);

	}

	void Widget::setWidgetStyle(WidgetStyle _style, const std::string& _layer)
	{
		if (_style == mWidgetStyle) return;
		if (nullptr == getParent()) return;

		Widget* parent = mParent;

		detachFromWidget();
		attachToWidget(parent, _style, _layer);
		// ищем леер к которому мы присоедененны
		/*Widget* root = this;
		while (!root->isRootWidget())
		{
			root = root->getParent();
		}

		// отсоединяем рут
		std::string layername;
		ILayer* layer = root->getLayer();
		if (layer)
		{
			layername = layer->getName();
			LayerManager::getInstance().detachFromLayer(root);

			// если мы рут, то придется отцеплят более высокого рута
			if (root == this)
			{
				layername.clear();

				if (getParent())
				{
					// ищем леер к которому мы присоедененны
					root = getParent();
					while (!root->isRootWidget())
					{
						root = root->getParent();
					}

					layer = root->getLayer();
					if (layer)
					{
						layername = layer->getName();
						LayerManager::getInstance().detachFromLayer(root);
					}

				}
			}
		}

		// корректируем
		mWidgetStyle = _style;
		if (_style == WidgetStyle::Child)
		{

			Widget* parent = getParent();
			if (parent)
			{
				mAbsolutePosition = parent->getAbsolutePosition() + mCoord.point();
				mCroppedParent = parent;
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();
			}

		}
		else if (_style == WidgetStyle::Popup)
		{

			mCroppedParent = nullptr;
			// обновляем координаты
			mAbsolutePosition = mCoord.point();
			// сбрасываем обрезку
			mMargin.clear();

			for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
			for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();

		}
		else if (_style == WidgetStyle::Overlapped)
		{

			Widget* parent = getParent();
			if (parent)
			{
				mAbsolutePosition = parent->getAbsolutePosition() + mCoord.point();
				mCroppedParent = parent;
				for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget) (*widget)->_updateAbsolutePoint();
				for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget) (*widget)->_updateAbsolutePoint();
			}

		}

		// присоединяем обратно
		if (!layername.empty())
		{
			LayerManager::getInstance().attachToLayerNode(layername, root);
		}*/

	}

	void Widget::setCaptionWithNewLine(const std::string& _value)
	{
		// change '\n' on char 10
		size_t pos = _value.find("\\n");
		if (pos == std::string::npos)
		{
			setCaption(LanguageManager::getInstance().replaceTags(_value));
		}
		else
		{
			std::string value(_value);
			while (pos != std::string::npos)
			{
				value[pos++] = '\n';
				value.erase(pos, 1);
				pos = value.find("\\n");
			}
			setCaption(LanguageManager::getInstance().replaceTags(value));
		}
	}

	Widget* Widget::createWidgetT(const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _name)
	{
		return baseCreateWidget(WidgetStyle::Child, _type, _skin, _coord, _align, "", _name);
	}

	Widget* Widget::createWidgetT(const std::string& _type, const std::string& _skin, int _left, int _top, int _width, int _height, Align _align, const std::string& _name)
	{
		return createWidgetT(_type, _skin, IntCoord(_left, _top, _width, _height), _align, _name);
	}

	Widget* Widget::createWidgetRealT(const std::string& _type, const std::string& _skin, float _left, float _top, float _width, float _height, Align _align, const std::string& _name)
	{
		return createWidgetRealT(_type, _skin, FloatCoord(_left, _top, _width, _height), _align, _name);
	}

	Widget* Widget::createWidgetT(WidgetStyle _style, const std::string& _type, const std::string& _skin, const IntCoord& _coord, Align _align, const std::string& _layer, const std::string& _name)
	{
		return baseCreateWidget(_style, _type, _skin, _coord, _align, _layer, _name);
	}

	EnumeratorWidgetPtr Widget::getEnumerator()
	{
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->getEnumerator();
		return Enumerator<VectorWidgetPtr>(mWidgetChild.begin(), mWidgetChild.end());
	}

	size_t Widget::getChildCount()
	{
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->getChildCount();
		return mWidgetChild.size();
	}

	Widget* Widget::getChildAt(size_t _index)
	{
		MYGUI_ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->getChildAt(_index);
		MYGUI_ASSERT_RANGE(_index, mWidgetChild.size(), "Widget::getChildAt");
		return mWidgetChild[_index];
	}

	const std::string& Widget::getPointer()
	{
		if (!isEnabled())
		{
			static std::string empty;
			return empty;
		}
		return mPointer;
	}

	void Widget::setProperty(const std::string& _key, const std::string& _value)
	{
		/// @wproperty{Widget, Widget_Caption, string} Sets caption
		if (_key == "Widget_Caption") setCaptionWithNewLine(_value);
		/// @wproperty{Widget, Widget_Position, IntPoint} Sets position
		else if (_key == "Widget_Position") setPosition(utility::parseValue<IntPoint>(_value));
		else if (_key == "Widget_Size") setSize(utility::parseValue<IntSize>(_value));
		else if (_key == "Widget_Coord") setCoord(utility::parseValue<IntCoord>(_value));
		else if (_key == "Widget_Visible") setVisible(utility::parseValue<bool>(_value));
		else if (_key == "Widget_Alpha") setAlpha(utility::parseValue<float>(_value));
		else if (_key == "Widget_Colour") setColour(utility::parseValue<Colour>(_value));
		else if (_key == "Widget_InheritsAlpha") setInheritsAlpha(utility::parseValue<bool>(_value));
		else if (_key == "Widget_InheritsPick") setInheritsPick(utility::parseValue<bool>(_value));
		else if (_key == "Widget_MaskPick") setMaskPick(_value);
		else if (_key == "Widget_State") setState(_value);
		else if (_key == "Widget_NeedKey") setNeedKeyFocus(utility::parseValue<bool>(_value));
		else if (_key == "Widget_NeedMouse") setNeedMouseFocus(utility::parseValue<bool>(_value));
		else if (_key == "Widget_Enabled") setEnabled(utility::parseValue<bool>(_value));
		else if (_key == "Widget_NeedToolTip") setNeedToolTip(utility::parseValue<bool>(_value));
		else if (_key == "Widget_Pointer") setPointer(_value);

		else if (_key == "Widget_SizePolicy") setSizePolicy(utility::parseValue<SizePolicy>(_value));
		else if (_key == "Widget_Margin") setMargin(utility::parseValue<IntRect>(_value));
		else if (_key == "Widget_Padding") setPadding(utility::parseValue<IntRect>(_value));
		else if (_key == "Widget_MinSize") setMinSize(utility::parseValue<IntSize>(_value));
		else if (_key == "Widget_MaxSize") setMaxSize(utility::parseValue<IntSize>(_value));

#ifndef MYGUI_DONT_USE_OBSOLETE
		else if (_key == "Widget_TextColour")
		{
			MYGUI_LOG(Warning, "Widget_TextColour is obsolete, use Text_TextColour");
			_setTextColour(Colour::parse(_value));
		}
		else if (_key == "Widget_FontName")
		{
			MYGUI_LOG(Warning, "Widget_FontName is obsolete, use Text_FontName");
			_setFontName(_value);
		}
		else if (_key == "Widget_FontHeight")
		{
			MYGUI_LOG(Warning, "Widget_FontHeight is obsolete, use Text_FontHeight");
			this->_setFontHeight(utility::parseValue<int>(_value));
		}
		else if (_key == "Widget_TextAlign")
		{
			MYGUI_LOG(Warning, "Widget_TextAlign is obsolete, use Text_TextAlign");
			_setTextAlign(Align::parse(_value));
		}
		else if (_key == "Widget_AlignText")
		{
			MYGUI_LOG(Warning, "Widget_AlignText is obsolete, use Text_TextAlign");
			_setTextAlign(Align::parse(_value));
		}
		else if (_key == "Widget_Show")
		{
			MYGUI_LOG(Warning, "Widget_Show is obsolete, use Widget_Visible");
			setVisible(utility::parseValue<bool>(_value));
		}
		else if (_key == "Widget_InheritsPeek")
		{
			MYGUI_LOG(Warning, "Widget_InheritsPeek is obsolete, use Widget_InheritsPick");
			setInheritsPick(utility::parseValue<bool>(_value));
		}
		else if (_key == "Widget_MaskPeek")
		{
			MYGUI_LOG(Warning, "Widget_MaskPeek is obsolete, use Widget_MaskPick");
			setMaskPick(_value);
		}
#endif // MYGUI_DONT_USE_OBSOLETE

		else
		{
			MYGUI_LOG(Warning, "Property " << _key << " not found");
			return;
		}

		eventChangeProperty(this, _key, _value);
	}

	void Widget::baseUpdateEnable()
	{
		if (isEnabled())
		{
			setState("normal");
		}
		else
		{
			setState("disabled");
		}
	}

	void Widget::setColour(const Colour& _value)
	{
		for (VectorSubWidget::iterator skin = mSubSkinChild.begin(); skin != mSubSkinChild.end(); ++skin)
		{
			ISubWidgetRect* rect = (*skin)->castType<ISubWidgetRect>(false);
			if (rect)
				rect->_setColour(_value);
		}
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
		{
			(*widget)->setColour(_value);
		}
	}

	void Widget::invalidateMeasure()
	{
		if (getVisualParent() != nullptr)
		{
			getVisualParent()->invalidateMeasure();
			overrideArrange(getSize());
		}
		else
		{
			const IntSize& size = getParentSize();
			updateArrange(IntCoord(0, 0, size.width, size.height), size);
		}
	}

	void Widget::setMargin(const IntRect& _value)
	{
		mMargin = _value;
		invalidateMeasure();
	}

	void Widget::setMinSize(const IntSize& _value)
	{
		mMinSize = _value;
		invalidateMeasure();
	}

	void Widget::setMaxSize(const IntSize& _value)
	{
		mMaxSize = _value;
		invalidateMeasure();
	}

	void Widget::setSizePolicy(SizePolicy _value)
	{
		mSizePolicy = _value;
		invalidateMeasure();
	}

	IntSize Widget::getParentSize()
	{
		if (getVisualParent())
			return getVisualParent()->getSize();
		if (getLayer())
			return getLayer()->getSize();

		return RenderManager::getInstance().getViewSize();
	}

	/*
	Запрос размера.
	Метод overrideMeasure вызывается для обновления размера mDesiredSize.
	Метод является перекрываемым, для того чтобы виджеты могли учесть свою внутренюю структуру для размещения содержимого.
	В метод передается доступный размер _sizeAvailable. В этот размер не входят внешние отступы Margin, т.е. это размер для самого виджета.
	В этом методе виджет должен сам учесть свои внутренние отступы Padding, размеры свой рамки и размер содержимого.
	Если размер mDesiredSize будет больше _sizeAvailable то он усечется.
	*/
	IntSize Widget::overrideMeasure(const IntSize& _sizeAvailable)
	{
		IntSize result;
		IntSize size_place(_sizeAvailable.width - getPaddingWidth(), _sizeAvailable.height - getPaddingHeight());

		EnumeratorWidgetPtr child = /*mWidgetClient ? mWidgetClient->getEnumerator() : */getEnumerator();
		while (child.next())
		{
			if (!child->isVisible())
				continue;

			if (child->getSizePolicy() == SizePolicy::Manual)
			{
				result.width = std::max(result.width, child->getRight());
				result.height = std::max(result.height, child->getBottom());
			}
			else
			{
				/*
				передаем ребенку размер доступного места, без учета нашего внутреннего отступа Padding
				*/
				child->updateMeasure(size_place);
				if (child->getSizePolicy() == SizePolicy::Content)
				{
					result.width = std::max(result.width, child->getDesiredSize().width);
					result.height = std::max(result.height, child->getDesiredSize().height);
				}
				else if (child->getSizePolicy() == SizePolicy::ContentWidth)
				{
					result.width = std::max(result.width, child->getDesiredSize().width);
					result.height = std::max(result.height, child->getBottom());
				}
				else if (child->getSizePolicy() == SizePolicy::ContentHeight)
				{
					result.width = std::max(result.width, child->getRight());
					result.height = std::max(result.height, child->getDesiredSize().height);
				}
			}
		}

		// а может всетаки там прибавить
		result.width += getPaddingWidth();
		result.height += getPaddingHeight();

		return result;
	}

	/*
	вызывается отцом для того чтобы виджет себя физически разместил
	передается _coordPlace это координаты места где виджет будет находиться
	виджет не имеет права заходить за эти координаты,
	в эти координаты не входит внутрение отступы отца Padding, так как они принадлежат отцу
	эти отступы отец уже учел
	*/
	void Widget::updateArrange(const IntCoord& _coordPlace, const IntSize& _oldsize)
	{
		IntCoord coord = mCoord;

		if (mSizePolicy != SizePolicy::Content && mSizePolicy != SizePolicy::ContentWidth)
		{
			const IntSize& size = getParentSize();
			if (mAlign.isHStretch())
			{
				// растягиваем
				coord.width = mCoord.width + (size.width - _oldsize.width);
			}
			else if (mAlign.isRight())
			{
				// двигаем по правому краю
				coord.left = mCoord.left + (size.width - _oldsize.width);
			}
			else if (mAlign.isHCenter())
			{
				// выравнивание по горизонтали без растяжения
				coord.left = (size.width - mCoord.width) / 2;
			}
		}

		if (mSizePolicy != SizePolicy::Content && mSizePolicy != SizePolicy::ContentHeight)
		{
			const IntSize& size = getParentSize();
			if (mAlign.isVStretch())
			{
				// растягиваем
				coord.height = mCoord.height + (size.height - _oldsize.height);
			}
			else if (mAlign.isBottom())
			{
				// двигаем по нижнему краю
				coord.top = mCoord.top + (size.height - _oldsize.height);
			}
			else if (mAlign.isVCenter())
			{
				// выравнивание по вертикали без растяжения
				coord.top = (size.height - mCoord.height) / 2;
			}
		}

		if (mSizePolicy != SizePolicy::Manual)
		{
			/*
			обновляем наши размеры по содержимому
			и используем эти размеры для выравнивания внутри доступной зоны
			которую нам указал отец
			*/
			updateMeasure(_coordPlace.size());
			const IntSize& size_content = getDesiredSize();

			if (mSizePolicy == SizePolicy::Content || mSizePolicy == SizePolicy::ContentWidth)
			{
				if (mAlign.isHStretch())
				{
					coord.left = mMargin.left + _coordPlace.left;
					coord.width = _coordPlace.width - getMarginWidth();

					// дополнительно чекаем, потому что при стрейтч размер контента не учитывается
					coord.width = std::min(coord.width, mMaxSize.width);
					coord.width = std::max(coord.width, mMinSize.width);
				}
				else if (mAlign.isRight())
				{
					coord.width = size_content.width - getMarginWidth();
					coord.left = _coordPlace.width - size_content.width + mMargin.left + _coordPlace.left;
				}
				else if (mAlign.isLeft())
				{
					coord.width = size_content.width - getMarginWidth();
					coord.left = mMargin.left + _coordPlace.left;
				}
				else if (mAlign.isHCenter())
				{
					coord.width = size_content.width - getMarginWidth();
					coord.left = (_coordPlace.width - (size_content.width)) / 2 + mMargin.left + _coordPlace.left;
				}

				coord.left = std::max(coord.left, _coordPlace.left);
				coord.width = std::min(coord.width, _coordPlace.width);
			}

			if (mSizePolicy == SizePolicy::Content || mSizePolicy == SizePolicy::ContentHeight)
			{
				if (mAlign.isVStretch())
				{
					coord.top = mMargin.top + _coordPlace.top;
					coord.height = _coordPlace.height - getMarginHeight();

					// дополнительно чекаем, потому что при стрейтч размер контента не учитывается
					coord.height = std::min(coord.height, mMaxSize.height);
					coord.height = std::max(coord.height, mMinSize.height);
				}
				else if (mAlign.isBottom())
				{
					coord.top = _coordPlace.height - size_content.height  + mMargin.top + _coordPlace.top;
					coord.height = size_content.height - getMarginHeight();
				}
				else if (mAlign.isTop())
				{
					coord.top = mMargin.top + _coordPlace.top;
					coord.height = size_content.height - getMarginHeight();
				}
				else if (mAlign.isVCenter())
				{
					coord.top = (_coordPlace.height - (size_content.height)) / 2 + mMargin.top + _coordPlace.top;
					coord.height = size_content.height - getMarginHeight();
				}

				coord.top = std::max(coord.top, _coordPlace.top);
				coord.height = std::min(coord.height, _coordPlace.height);
			}
		}

		if (coord.point() != mCoord.point())
		{
			if (coord.size() != mCoord.size())
				setCoord(coord);
			else
				setPosition(coord.point());
		}
		else if (coord.size() != mCoord.size())
		{
			setSize(coord.size());
		}
		else
		{
			// только если не вызвано передвижение и сайз
			_updateView();
		}
	}

	/*
	Обновление размеров содержимого.
	Метод updateMeasure вызывается для обновления mDesiredSize по нашему содержимому.
	В этот размер входят наши внешние отступы Margin, внутрение отступы Padding, размер наших рамок и размер самого содержимого.
	При расчете mDesiredSize учитывается MinSize и MaxSize, но только для виджета, без учета внешних отступов Margin.
	В метод передается размер доступной зоны _sizeAvailable в который мы должны себя уместить.
	Размер mDesiredSize не может быть больше чем размер доступной зоны _sizeAvailable.
	*/
	void Widget::updateMeasure(const IntSize& _sizeAvailable)
	{
		/*
		в overrideMeasure передается размер без учета внешних отступов
		это то место где реально можно будет разместить виджет
		*/
		IntSize size_place(_sizeAvailable.width - getMarginWidth(), _sizeAvailable.height - getMarginHeight());
		mDesiredSize = overrideMeasure(size_place);

		// хз, может перенести в оверайд меасуре
		//mDesiredSize.width += getPaddingWidth();
		//mDesiredSize.height += getPaddingHeight();

		mDesiredSize.width = std::max(mDesiredSize.width, mMinSize.width);
		mDesiredSize.height = std::max(mDesiredSize.height, mMinSize.height);
		mDesiredSize.width = std::min(mDesiredSize.width, mMaxSize.width);
		mDesiredSize.height = std::min(mDesiredSize.height, mMaxSize.height);

		mDesiredSize.width += getMarginWidth();
		mDesiredSize.height += getMarginHeight();

		mDesiredSize.width = std::min(mDesiredSize.width, _sizeAvailable.width);
		mDesiredSize.height = std::min(mDesiredSize.height, _sizeAvailable.height);
	}

	/*
	Метод overrideArrange для раставления дочерних виджетов.
	Можно использовать размер mDesiredSize дочерних виджетов.
	*/
	void Widget::overrideArrange(const IntSize& _oldSize)
	{
		for (VectorWidgetPtr::iterator widget = mWidgetChild.begin(); widget != mWidgetChild.end(); ++widget)
		{
			// рутовые всплывающие дочки
			if ((*widget)->getVisualParent() == nullptr)
			{
				const IntSize& size = (*widget)->getParentSize();
				(*widget)->updateArrange(IntCoord(0, 0, size.width, size.height), size);
			}
			else
			{
				(*widget)->updateArrange(
					IntCoord(mPadding.left, mPadding.top, mCoord.width - getPaddingWidth(), mCoord.height - getPaddingHeight()),
					_oldSize);
			}
		}
		for (VectorWidgetPtr::iterator widget = mWidgetChildSkin.begin(); widget != mWidgetChildSkin.end(); ++widget)
		{
			(*widget)->updateArrange(
				IntCoord(mPadding.left, mPadding.top, mCoord.width - getPaddingWidth(), mCoord.height - getPaddingHeight()),
				_oldSize);
		}
	}

	int Widget::getPaddingWidth()
	{
		if (mWidgetClient != nullptr)
			return mWidgetClient->getPaddingWidth();

		return mPadding.left + mPadding.right;
	}

	int Widget::getPaddingHeight()
	{
		if (mWidgetClient != nullptr)
			return mWidgetClient->getPaddingHeight();

		return mPadding.top + mPadding.bottom;
	}

	const IntRect& Widget::getPadding()
	{
		if (mWidgetClient != nullptr)
			return mWidgetClient->getPadding();

		return mPadding;
	}

	void Widget::setPadding(const IntRect& _value)
	{
		if (mWidgetClient != nullptr)
			mWidgetClient->setPadding(_value);

		mPadding = _value;
		invalidateMeasure();
	}

	void Widget::setNeedToolTip(bool _value)
	{
		if (mNeedToolTip == _value)
			return;
		mNeedToolTip = _value;
	}

	void Widget::_resetContainer(bool _updateOnly)
	{
		if (mNeedToolTip)
			ToolTipManager::getInstance()._unlinkWidget(this);
	}

} // namespace MyGUI
