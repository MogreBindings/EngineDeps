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
#include "MyGUI_InputManager.h"
#include "MyGUI_Widget.h"
#include "MyGUI_WidgetManager.h"
#include "MyGUI_Gui.h"
#include "MyGUI_WidgetManager.h"

namespace MyGUI
{
	// FIXME - move to settings
	const unsigned long INPUT_TIME_DOUBLE_CLICK = 250; //measured in milliseconds
	const float INPUT_DELAY_FIRST_KEY = 0.4f;
	const float INPUT_INTERVAL_KEY = 0.05f;

	template <> const char* Singleton<InputManager>::INSTANCE_TYPE_NAME("InputManager");

	InputManager::InputManager() :
		mWidgetMouseFocus(nullptr),
		mWidgetKeyFocus(nullptr),
		mLayerMouseFocus(nullptr),
		mIsWidgetMouseCapture(false),
		mIsShiftPressed(false),
		mIsControlPressed(false),
		mHoldKey(KeyCode::None),
		mHoldChar(0),
		mFirstPressKey(false),
		mTimerKey(0.0f),
		mOldAbsZ(0)
	{
	}

	void InputManager::initialise()
	{
		MYGUI_ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		MYGUI_LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		mIsWidgetMouseCapture = false;
		mIsShiftPressed = false;
		mIsControlPressed = false;
		mHoldKey = KeyCode::None;
		mHoldChar = 0;
		mFirstPressKey = true;
		mTimerKey = 0.0f;
		mOldAbsZ = 0;

		WidgetManager::getInstance().registerUnlinker(this);
		Gui::getInstance().eventFrameStart += newDelegate(this, &InputManager::frameEntered);

		MYGUI_LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void InputManager::shutdown()
	{
		if (!mIsInitialise)
			return;
		MYGUI_LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		Gui::getInstance().eventFrameStart -= newDelegate(this, &InputManager::frameEntered);
		WidgetManager::getInstance().unregisterUnlinker(this);

		mWidgetMouseFocus = nullptr;
		mWidgetKeyFocus = nullptr;
		mLayerMouseFocus = nullptr;

		MYGUI_LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool InputManager::injectMouseMove(int _absx, int _absy, int _absz)
	{
		// запоминаем позицию
		mMousePosition.set(_absx, _absy);

		// вычисляем прирост по колеса
		int relz = _absz - mOldAbsZ;
		mOldAbsZ = _absz;

		// проверка на скролл
		if (relz != 0)
		{
			bool isFocus = isFocusMouse();
			if (mWidgetMouseFocus != nullptr)
				onEventMouseWheel(mWidgetMouseFocus, relz);
			return isFocus;
		}

		if (mIsWidgetMouseCapture)
		{
			if (mWidgetMouseFocus != nullptr)
			{
				if (mLayerMouseFocus != nullptr)
				{
					IntPoint point = mLayerMouseFocus->getPosition(_absx, _absy);
					onEventMouseDrag(mWidgetMouseFocus, point.left, point.top);
				}
			}
			else
				mIsWidgetMouseCapture = false;
			return true;
		}

		/*
		Widget* oldMouseFocus = mWidgetMouseFocus;

		// ищем активное окно
		Widget* newMouseFocus = LayerManager::getInstance().getWidgetFromPoint(_absx, _absy);

		// запоминаем текущее окно
		mWidgetMouseFocus = newMouseFocus;

		// ничего не изменилось
		if (oldMouseFocus == newMouseFocus)
		{
			bool isFocus = isFocusMouse();
			if (oldMouseFocus != nullptr)
			{
				if (mLayerMouseFocus != nullptr)
				{
					IntPoint point = mLayerMouseFocus->getPosition(_absx, _absy);
					onEventMouseMove(newMouseFocus, _absx, _absy);
				}
			}
			return isFocus;
		}

		if (newMouseFocus != nullptr)
		{
			// поднимаемся до рута
			Widget* root = newMouseFocus;
			while (root->getParent())
				root = root->getParent();

			// проверяем на модальность
			if (!mVectorModalRootWidget.empty())
			{
				if (root != mVectorModalRootWidget.back())
				{
					newMouseFocus = nullptr;
				}
			}

			if (newMouseFocus != nullptr)
			{
				mLayerMouseFocus = root->getLayer();
			}
		}

		//-------------------------------------------------------------------------------------//
		// новый вид рутового фокуса мыши
		Widget* save_widget = nullptr;

		// спускаемся по новому виджету и устанавливаем рутовый фокус
		Widget* root_focus = newMouseFocus;
		while (root_focus != nullptr)
		{
			if (root_focus->getMouseRootFocus())
			{
				save_widget = root_focus;
				break;
			}

			onEventRootMouseFocusChanged(root_focus, true);

			root_focus = root_focus->getParent();
		}

		// спускаемся по старому виджету и сбрасываем фокус
		root_focus = oldMouseFocus;
		while (root_focus != nullptr)
		{
			if (root_focus == save_widget)
				break;

			onEventRootMouseFocusChanged(root_focus, false);

			root_focus = root_focus->getParent();
		}
		//-------------------------------------------------------------------------------------//

		// смена фокуса, проверяем на доступность виджета
		if ((oldMouseFocus != nullptr) && (oldMouseFocus->isEnabled()))
			onEventMouseLeave(oldMouseFocus, newMouseFocus);

		if ((newMouseFocus != nullptr) && (newMouseFocus->isEnabled()))
			onEventMouseEntry(newMouseFocus, oldMouseFocus);

		if (oldMouseFocus != newMouseFocus)
			eventChangeMouseFocus(newMouseFocus);
*/
		updateMouseFocus();

		if ((mWidgetMouseFocus != nullptr) && (mWidgetMouseFocus->isEnabled()))
			onEventMouseMove(mWidgetMouseFocus, _absx, _absy);

		return isFocusMouse();
	}

	bool InputManager::injectMousePress(int _absx, int _absy, MouseButton _id)
	{
		Widget* old_key_focus = mWidgetKeyFocus;

		// если мы щелкнули не на гуй
		if (!isFocusMouse())
		{
			resetKeyFocusWidget();

			if (old_key_focus != mWidgetKeyFocus)
				eventChangeKeyFocus(mWidgetKeyFocus);

			return false;
		}

		// если активный элемент заблокирован
		//FIXME
		if (!mWidgetMouseFocus->isEnabled())
			return true;

		// захватываем только по левой клавише и только если виджету надо
		if (MouseButton::Left == _id)
		{
			// захват окна
			mIsWidgetMouseCapture = true;
			// запоминаем место нажатия
			if (mLayerMouseFocus != nullptr)
			{
				IntPoint point = mLayerMouseFocus->getPosition(_absx, _absy);
				mLastLeftPressed = point;
			}
		}

		// ищем вверх тот виджет который может принимать фокус
		Widget* item = mWidgetMouseFocus;
		while ((item != nullptr) && (!item->isNeedKeyFocus()))
			item = item->getParent();

		// устанавливаем перед вызовом т.к. возможно внутри ктонить поменяет фокус под себя
		setKeyFocusWidget(item);

		if (mWidgetMouseFocus != nullptr)
		{
			onEventMouseButtonDown(mWidgetMouseFocus, _absx, _absy, _id);

			// после пресса может сброситься
			if (mWidgetMouseFocus)
			{
				// поднимаем виджет, надо подумать что делать если поменялся фокус клавы
				LayerManager::getInstance().upLayerItem(mWidgetMouseFocus);

				// поднимаем пикинг Overlapped окон
				Widget* pick = mWidgetMouseFocus;
				do
				{
					// если оверлаппед, то поднимаем пикинг
					if (pick->getWidgetStyle() == WidgetStyle::Overlapped)
					{
						if (pick->getParent())
							pick->getParent()->_forcePeek(pick);
					}

					pick = pick->getParent();
				}
				while (pick);
			}
		}

		if (old_key_focus != mWidgetKeyFocus)
			eventChangeKeyFocus(mWidgetKeyFocus);

		return true;
	}

	bool InputManager::injectMouseRelease(int _absx, int _absy, MouseButton _id)
	{
		if (isFocusMouse())
		{
			// если активный элемент заблокирован
			if (!mWidgetMouseFocus->isEnabled())
				return true;

			onEventMouseButtonUp(mWidgetMouseFocus, _absx, _absy, _id);

			if (mIsWidgetMouseCapture)
			{
				// сбрасываем захват
				mIsWidgetMouseCapture = false;

				// после вызова, виджет может быть сброшен
				if (nullptr != mWidgetMouseFocus)
				{
					if ((MouseButton::Left == _id) && mTimer.getMilliseconds() < INPUT_TIME_DOUBLE_CLICK)
					{
						onEventMouseButtonClick(mWidgetMouseFocus, _absx, _absy, MouseButton::Left);
						// после вызова, виджет может быть сброшен
						if (nullptr != mWidgetMouseFocus)
							onEventMouseButtonDoubleClick(mWidgetMouseFocus, _absx, _absy, MouseButton::Left);
					}
					else
					{
						// проверяем над тем ли мы окном сейчас что и были при нажатии
						Widget* item = LayerManager::getInstance().getWidgetFromPoint(_absx, _absy);
						if ( item == mWidgetMouseFocus)
						{
							onEventMouseButtonClick(mWidgetMouseFocus, _absx, _absy, MouseButton::Left);
						}
						mTimer.reset();
					}
				}
			}

			// для корректного отображения
			injectMouseMove(_absx, _absy, mOldAbsZ);

			return true;
		}

		return false;
	}

	bool InputManager::injectKeyPress(KeyCode _key, Char _text)
	{
		// проверка на переключение языков
		firstEncoding(_key, true);

		// запоминаем клавишу
		storeKey(_key, _text);

		bool wasFocusKey = isFocusKey();

		//Pass keystrokes to the current active text widget
		if (isFocusKey())
			onEventKeyButtonDown(mWidgetKeyFocus, _key, _text);

		return wasFocusKey;
	}

	bool InputManager::injectKeyRelease(KeyCode _key)
	{
		// проверка на переключение языков
		firstEncoding(_key, false);

		// сбрасываем клавишу
		resetKey();

		bool wasFocusKey = isFocusKey();

		if (isFocusKey())
			onEventKeyButtonUp(mWidgetKeyFocus, _key);

		return wasFocusKey;
	}

	void InputManager::firstEncoding(KeyCode _key, bool bIsKeyPressed)
	{
		if ((_key == KeyCode::LeftShift) || (_key == KeyCode::RightShift))
			mIsShiftPressed = bIsKeyPressed;
		if ((_key == KeyCode::LeftControl) || (_key == KeyCode::RightControl))
			mIsControlPressed = bIsKeyPressed;
	}

	void InputManager::setKeyFocusWidget(Widget* _widget)
	{
		if (_widget == mWidgetKeyFocus)
			return;

		Widget* old_focus = mWidgetKeyFocus;
		mWidgetKeyFocus = _widget;

		//-------------------------------------------------------------------------------------//
		// новый вид рутового фокуса
		Widget* save_widget = nullptr;

		// спускаемся по новому виджету и устанавливаем рутовый фокус
		Widget* root_focus = _widget;
		while (root_focus != nullptr)
		{
			if (root_focus->getKeyboardRootFocus())
			{
				save_widget = root_focus;
				break;
			}

			onEventRootKeyboardFocusChanged(root_focus, true);

			root_focus = root_focus->getParent();
		}

		// спускаемся по старому виджету и сбрасываем фокус
		root_focus = old_focus;
		while (root_focus != nullptr)
		{
			if (root_focus == save_widget)
				break;

			onEventRootKeyboardFocusChanged(root_focus, false);

			root_focus = root_focus->getParent();
		}
		//-------------------------------------------------------------------------------------//
		// сбрасываем старый
		if (old_focus)
			onEventLostKeyboardFocus(old_focus, _widget);

		// устанавливаем новый
		if (_widget && _widget->isNeedKeyFocus())
			onEventGotKeyboardFocus(_widget, old_focus);
	}

	void InputManager::resetMouseFocusWidget()
	{
		// спускаемся по старому виджету и сбрасываем фокус
		Widget* root_focus = mWidgetMouseFocus;
		while (root_focus != nullptr)
		{
			onEventRootMouseFocusChanged(root_focus, false);

			root_focus = root_focus->getParent();
		}

		mIsWidgetMouseCapture = false;
		if (nullptr != mWidgetMouseFocus)
		{
			onEventMouseLeave(mWidgetMouseFocus, nullptr);
			mWidgetMouseFocus = nullptr;
		}
	}

	// удаляем данный виджет из всех возможных мест
	void InputManager::_unlinkWidget(Widget* _widget)
	{
		if (nullptr == _widget)
			return;

		bool updateMouse = false;

		if (_widget == mWidgetMouseFocus)
		{
			resetMouseFocusWidget();
			resetMouseCaptureWidget();
			updateMouse = true;
			//mIsWidgetMouseCapture = false;
			//mWidgetMouseFocus = nullptr;
		}

		if (_widget == mWidgetKeyFocus)
		{
			resetKeyFocusWidget();
			//mWidgetKeyFocus = nullptr;
		}

		// ручками сбрасываем, чтобы не менять фокусы
		for (VectorWidgetPtr::iterator iter=mVectorModalRootWidget.begin(); iter!=mVectorModalRootWidget.end(); ++iter)
		{
			if ((*iter == _widget))
			{
				mVectorModalRootWidget.erase(iter);
				break;
			}
		}

		if (updateMouse)
			updateMouseFocus();
	}

	void InputManager::addWidgetModal(Widget* _widget)
	{
		if (nullptr == _widget)
			return;

		MYGUI_ASSERT(nullptr == _widget->getParent(), "Modal widget must be root");

		resetMouseFocusWidget();
		removeWidgetModal(_widget);
		mVectorModalRootWidget.push_back(_widget);

		setKeyFocusWidget(_widget);
		LayerManager::getInstance().upLayerItem(_widget);
	}

	void InputManager::removeWidgetModal(Widget* _widget)
	{
		resetKeyFocusWidget(_widget);
		resetMouseFocusWidget();

		for (VectorWidgetPtr::iterator iter=mVectorModalRootWidget.begin(); iter!=mVectorModalRootWidget.end(); ++iter)
		{
			if ((*iter == _widget))
			{
				mVectorModalRootWidget.erase(iter);
				break;
			}
		}
		// если еще есть модальные то их фокусируем и поднимаем
		if (!mVectorModalRootWidget.empty())
		{
			setKeyFocusWidget(mVectorModalRootWidget.back());
			LayerManager::getInstance().upLayerItem(mVectorModalRootWidget.back());
		}
	}

	void InputManager::storeKey(KeyCode _key, Char _text)
	{
		mHoldKey = KeyCode::None;
		mHoldChar = 0;

		if ( !isFocusKey() )
			return;
		if ( (_key == KeyCode::LeftShift) || (_key == KeyCode::RightShift)
			|| (_key == KeyCode::LeftControl) || (_key == KeyCode::RightControl)
			|| (_key == KeyCode::LeftAlt) || (_key == KeyCode::RightAlt)
			) return;

		mFirstPressKey = true;
		mHoldKey = _key;
		mHoldChar = _text;
		mTimerKey = 0.0f;
	}

	void InputManager::resetKey()
	{
		mHoldKey = KeyCode::None;
		mHoldChar = 0;
	}

	void InputManager::frameEntered(float _frame)
	{
		if ( mHoldKey == KeyCode::None)
			return;

		if ( !isFocusKey() )
		{
			mHoldKey = KeyCode::None;
			mHoldChar = 0;
			return;
		}

		mTimerKey += _frame;

		if (mFirstPressKey)
		{
			if (mTimerKey > INPUT_DELAY_FIRST_KEY)
			{
				mFirstPressKey = false;
				mTimerKey = 0.0f;
			}
		}
		else
		{
			if (mTimerKey > INPUT_INTERVAL_KEY)
			{
				while (mTimerKey > INPUT_INTERVAL_KEY)
					mTimerKey -= INPUT_INTERVAL_KEY;
				onEventKeyButtonDown(mWidgetKeyFocus, mHoldKey, mHoldChar);
				// focus can be dropped in onKeyButtonPressed
				if (isFocusKey())
					onEventKeyButtonUp(mWidgetKeyFocus, mHoldKey);
			}
		}

	}

	void InputManager::resetKeyFocusWidget(Widget* _widget)
	{
		if (mWidgetKeyFocus == _widget)
			setKeyFocusWidget(nullptr);
	}

	IntPoint InputManager::getMousePositionByLayer()
	{
		if (mLayerMouseFocus != nullptr)
			return mLayerMouseFocus->getPosition(mMousePosition.left, mMousePosition.top);
		return mMousePosition;
	}

	void InputManager::updateMouseFocus()
	{
		Widget* oldMouseFocus = mWidgetMouseFocus;

		// ищем активное окно
		Widget* newMouseFocus = LayerManager::getInstance().getWidgetFromPoint(mMousePosition.left, mMousePosition.top);

		// запоминаем текущее окно
		mWidgetMouseFocus = newMouseFocus;

		// ничего не изменилось
		if (oldMouseFocus == newMouseFocus)
		{
			if (oldMouseFocus != nullptr)
			{
				if (mLayerMouseFocus != nullptr)
				{
					IntPoint point = mLayerMouseFocus->getPosition(mMousePosition.left, mMousePosition.top);
					onEventMouseMove(newMouseFocus, mMousePosition.left, mMousePosition.top);
				}
			}
			return;
		}

		if (newMouseFocus != nullptr)
		{
			// поднимаемся до рута
			Widget* root = newMouseFocus;
			while (root->getParent())
				root = root->getParent();

			// проверяем на модальность
			if (!mVectorModalRootWidget.empty())
			{
				if (root != mVectorModalRootWidget.back())
				{
					newMouseFocus = nullptr;
				}
			}

			if (newMouseFocus != nullptr)
			{
				mLayerMouseFocus = root->getLayer();
			}
		}

		// новый вид рутового фокуса мыши
		Widget* save_widget = nullptr;

		// спускаемся по новому виджету и устанавливаем рутовый фокус
		Widget* root_focus = newMouseFocus;
		while (root_focus != nullptr)
		{
			if (root_focus->getMouseRootFocus())
			{
				save_widget = root_focus;
				break;
			}

			onEventRootMouseFocusChanged(root_focus, true);

			root_focus = root_focus->getParent();
		}

		// спускаемся по старому виджету и сбрасываем фокус
		root_focus = oldMouseFocus;
		while (root_focus != nullptr)
		{
			if (root_focus == save_widget)
				break;

			onEventRootMouseFocusChanged(root_focus, false);

			root_focus = root_focus->getParent();
		}

		// смена фокуса, проверяем на доступность виджета
		if ((oldMouseFocus != nullptr) && (oldMouseFocus->isEnabled()))
			onEventMouseLeave(oldMouseFocus, newMouseFocus);

		if ((newMouseFocus != nullptr) && (newMouseFocus->isEnabled()))
			onEventMouseEntry(newMouseFocus, oldMouseFocus);

		if (oldMouseFocus != newMouseFocus)
			eventChangeMouseFocus(newMouseFocus);
	}

	void InputManager::onEventMouseLeave(Widget* _widget, Widget* _new)
	{
		_widget->onMouseLostFocus(_new);
		FocusChangedEventArgs args(false);
		_widget->raiseEventMouseFocusChanged(&args);
	}

	void InputManager::onEventMouseEntry(Widget* _widget, Widget* _old)
	{
		_widget->onMouseSetFocus(_old);
		FocusChangedEventArgs args(true);
		_widget->raiseEventMouseFocusChanged(&args);
	}

	void InputManager::onEventMouseMove(Widget* _widget, int _x, int _y)
	{
		_widget->onMouseMove(_x, _y);
		MouseMoveEventArgs args(_x, _y);
		_widget->raiseEventMouseMove(&args);
	}

	void InputManager::onEventMouseDrag(Widget* _widget, int _x, int _y)
	{
		_widget->onMouseDrag(_x, _y);
		MouseMoveEventArgs args(_x, _y);
		_widget->raiseEventMouseDrag(&args);
	}

	void InputManager::onEventMouseWheel(Widget* _widget, int _delta)
	{
		_widget->onMouseWheel(_delta);
		MouseWheelEventArgs args(_delta);
		_widget->raiseEventMouseWheel(&args);
	}

	void InputManager::onEventMouseButtonDown(Widget* _widget, int _x, int _y, MouseButton _button)
	{
		_widget->onMouseButtonPressed(_x, _y, _button);
		MouseButtonEventArgs args(_x, _y, _button);
		_widget->raiseEventMouseButtonDown(&args);
	}

	void InputManager::onEventMouseButtonUp(Widget* _widget, int _x, int _y, MouseButton _button)
	{
		_widget->onMouseButtonReleased(_x, _y, _button);
		MouseButtonEventArgs args(_x, _y, _button);
		_widget->raiseEventMouseButtonUp(&args);
	}

	void InputManager::onEventMouseButtonClick(Widget* _widget, int _x, int _y, MouseButton _button)
	{
		_widget->onMouseButtonClick();
		MouseButtonEventArgs args(_x, _y, _button);
		_widget->raiseEventMouseButtonClick(&args);
	}

	void InputManager::onEventMouseButtonDoubleClick(Widget* _widget, int _x, int _y, MouseButton _button)
	{
		_widget->onMouseButtonDoubleClick();
		MouseButtonEventArgs args(_x, _y, _button);
		_widget->raiseEventMouseButtonDoubleClick(&args);
	}

	void InputManager::onEventGotKeyboardFocus(Widget* _widget, Widget* _old)
	{
		_widget->onKeySetFocus(_old);
		KeyboardFocusChangedEventArgs args(_old, _widget, true);
		_widget->raiseEventKeyboardFocusChanged(&args);
	}

	void InputManager::onEventLostKeyboardFocus(Widget* _widget, Widget* _new)
	{
		_widget->onKeyLostFocus(_new);
		KeyboardFocusChangedEventArgs args(_widget, _new, false);
		_widget->raiseEventKeyboardFocusChanged(&args);
	}

	void InputManager::onEventKeyButtonDown(Widget* _widget, KeyCode _key, Char _text)
	{
		_widget->onKeyButtonPressed(_key, _text);
		KeyButtonEventArgs args(_key, _text);
		_widget->raiseEventKeyButtonDown(&args);
	}

	void InputManager::onEventKeyButtonUp(Widget* _widget, KeyCode _key)
	{
		_widget->onKeyButtonReleased(_key);
		KeyButtonEventArgs args(_key);
		_widget->raiseEventKeyButtonUp(&args);
	}

	void InputManager::onEventRootMouseFocusChanged(Widget* _widget, bool _focus)
	{
		FocusChangedEventArgs args(_focus);
		_widget->raiseEventMouseRootFocusChanged(&args);
		_widget->onMouseChangeRootFocus(_focus);
	}

	void InputManager::onEventRootKeyboardFocusChanged(Widget* _widget, bool _focus)
	{
		FocusChangedEventArgs args(_focus);
		_widget->raiseEventKeyboardRootFocusChanged(&args);
		_widget->onKeyChangeRootFocus(_focus);
	}

} // namespace MyGUI
