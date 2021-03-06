/*!
	@file
	@author		Georgiy Evmenov
	@date		09/2008
*/

#include "precompiled.h"
#include "Common.h"
#include "PropertiesPanelView.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"
#include "UndoManager.h"
#include "Parse.h"
#include "GroupMessage.h"

#define ON_EXIT( CODE ) class _OnExit { public: void dummy() const { }; ~_OnExit() { CODE; } } _onExit; _onExit.dummy()

int grid_step;//FIXME_HOOK
int toGrid(int _x) { return _x / grid_step * grid_step; }

const std::string DEFAULT_STRING = "[DEFAULT]";
std::string DEFAULT_VALUE;
std::string ERROR_VALUE;

PropertiesPanelView::PropertiesPanelView() : BaseLayout("PropertiesPanelView.layout")
{
	DEFAULT_VALUE = localise("ColourDefault") + DEFAULT_STRING;
	ERROR_VALUE = localise("ColourError");

	assignBase(mPanelView, "scroll_View");

	MyGUI::Window* window = mMainWidget->castType<MyGUI::Window>(false);
	if (window != nullptr)
	{
		window->eventWindowChangeCoord = MyGUI::newDelegate(this, &PropertiesPanelView::notifyWindowChangeCoord);
		mOldSize = window->getSize();
	}

	mPanelMainProperties = new PanelMainProperties();
	mPanelView->addItem(mPanelMainProperties);
	mPanelMainProperties->eventCreatePair = MyGUI::newDelegate(this, &PropertiesPanelView::createPropertiesWidgetsPair);
	mPanelMainProperties->eventSetPositionText = MyGUI::newDelegate(this, &PropertiesPanelView::setPositionText);

	mPanelTypeProperties = new PanelProperties();
	mPanelView->addItem(mPanelTypeProperties);
	mPanelTypeProperties->eventCreatePair = MyGUI::newDelegate(this, &PropertiesPanelView::createPropertiesWidgetsPair);

	mPanelGeneralProperties = new PanelProperties();
	mPanelView->addItem(mPanelGeneralProperties);
	mPanelGeneralProperties->eventCreatePair = MyGUI::newDelegate(this, &PropertiesPanelView::createPropertiesWidgetsPair);

	mPanelItems = new PanelItems();
	mPanelView->addItem(mPanelItems);

	mPanelUserData = new PanelUserData();
	mPanelView->addItem(mPanelUserData);

	mPanelControllers = new PanelControllers();
	mPanelView->addItem(mPanelControllers);
	mPanelControllers->eventCreatePair = MyGUI::newDelegate(this, &PropertiesPanelView::createPropertiesWidgetsPair);
	mPanelControllers->eventHidePairs = MyGUI::newDelegate(this, &PropertiesPanelView::hideWidgetsPairs);

	mPanels.push_back(mPanelMainProperties);
	mPanels.push_back(mPanelTypeProperties);
	mPanels.push_back(mPanelGeneralProperties);
	mPanels.push_back(mPanelItems);
	mPanels.push_back(mPanelUserData);
	mPanels.push_back(mPanelControllers);

	current_widget = nullptr;

	// create widget rectangle
	current_widget_rectangle = MyGUI::Gui::getInstance().createWidget<MyGUI::Window>("StretchRectangle", MyGUI::IntCoord(), MyGUI::Align::Default, "LayoutEditor_Rectangle");
	current_widget_rectangle->eventWindowChangeCoord = newDelegate(this, &PropertiesPanelView::notifyRectangleResize);
	current_widget_rectangle->eventMouseButtonDoubleClick = newDelegate(mPanelItems, &PanelItems::notifyRectangleDoubleClick);
	current_widget_rectangle->eventKeyButtonPressed = newDelegate(this, &PropertiesPanelView::notifyRectangleKeyPressed);

	arrow_move = false;
}

PropertiesPanelView::~PropertiesPanelView()
{
	mPanelView->removeAllItems();
	delete mPanelMainProperties;
	delete mPanelTypeProperties;
	delete mPanelGeneralProperties;
	delete mPanelItems;
	delete mPanelUserData;
	delete mPanelControllers;
}

void PropertiesPanelView::notifyWindowChangeCoord(MyGUI::Window* _sender)
{
	const MyGUI::IntSize & size = _sender->getSize();
	if (size != mOldSize)
	{
		mOldSize = size;
		mPanelView->setNeedUpdate();
	}
}

void PropertiesPanelView::load(MyGUI::xml::ElementEnumerator _field)
{
	MyGUI::xml::ElementEnumerator field = _field->getElementEnumerator();
	VectorPanel::iterator iter = mPanels.begin();
	while (field.next())
	{
		std::string key, value;

		if (field->getName() == "Property")
		{
			if (!field->findAttribute("key", key)) continue;
			if (!field->findAttribute("value", value)) continue;

			if ((key == MyGUI::utility::toString("PanelMinimized")) && (iter != mPanels.end()))
			{
				(*iter)->getPanelCell()->setMinimized(MyGUI::utility::parseBool(value));
				++iter;
			}
		}
	}
}

void PropertiesPanelView::save(MyGUI::xml::ElementPtr root)
{
	root = root->createChild("PropertiesPanelView");
	MyGUI::xml::ElementPtr nodeProp;

	for (VectorPanel::iterator iter = mPanels.begin(); iter != mPanels.end(); ++iter)
	{
		nodeProp = root->createChild("Property");
		nodeProp->addAttribute("key", MyGUI::utility::toString("Panel","Minimized"));
		nodeProp->addAttribute("value", (*iter)->getPanelCell()->isMinimized());
	}
}

void PropertiesPanelView::notifyRectangleResize(MyGUI::Window* _sender)
{
	if (!_sender->isVisible()) return;
	// ������ ��������������� ��������� ������� � ����������/��������
	WidgetContainer * widgetContainer = EditorWidgets::getInstance().find(current_widget);
	if (WidgetTypes::getInstance().find(current_widget->getTypeName())->resizeable)
	{
		MyGUI::IntCoord coord = convertCoordToParentCoord(_sender->getCoord(), current_widget);
		MyGUI::IntCoord old_coord = current_widget->getCoord();
		// align to grid
		if (!MyGUI::InputManager::getInstance().isShiftPressed() && !arrow_move)
		{
			if ((old_coord.width == coord.width) && (old_coord.height == coord.height)) // ���� ������ ����������
			{
				coord.left = toGrid(coord.left + grid_step-1 - old_coord.left) + old_coord.left;
				coord.top = toGrid(coord.top + grid_step-1 - old_coord.top) + old_coord.top;
			}
			else // ���� �����������
			{
				if (old_coord.left != coord.left)
				{
					coord.left = toGrid(coord.left + grid_step-1);
					coord.width = old_coord.right() - coord.left;
				}
				else if (old_coord.width != coord.width)
				{
					coord.width = toGrid(coord.width + old_coord.left) - old_coord.left;
				}

				if (old_coord.top != coord.top)
				{
					coord.top = toGrid(coord.top + grid_step-1);
					coord.height = old_coord.bottom() - coord.top;
				}
				else if (old_coord.height != coord.height)
				{
					coord.height = toGrid(coord.height + old_coord.top) - old_coord.top;
				}
			}
		}
		arrow_move = false;

		current_widget->setCoord(coord);
		// update coord because of current_widget can have MinMax size
		coord = current_widget->getCoord();
		setPositionText(widgetContainer->position());

		UndoManager::getInstance().addValue(PR_POSITION);
	}
	current_widget_rectangle->setCoord(current_widget->getAbsoluteCoord());
}

void PropertiesPanelView::notifyRectangleKeyPressed(MyGUI::Widget* _sender, MyGUI::KeyCode _key, MyGUI::Char _char)
{
	MyGUI::IntPoint delta;
	int k = MyGUI::InputManager::getInstance().isShiftPressed() ? 1 : grid_step;
	if (MyGUI::KeyCode::Tab == _key)
	{
		if ((nullptr != current_widget) && (nullptr != current_widget->getParent()) && (current_widget->getParent()->getTypeName() == "Tab")) update(current_widget->getParent());
		if (current_widget && current_widget->getTypeName() == "Tab")
		{
			MyGUI::Tab* tab = current_widget->castType<MyGUI::Tab>();
			size_t sheet = tab->getIndexSelected();
			sheet++;
			if (sheet >= tab->getItemCount()) sheet = 0;
			if (tab->getItemCount()) tab->setIndexSelected(sheet);
		}
	}
	else if (MyGUI::KeyCode::Delete == _key)
	{
		if (current_widget)
		{
			EditorWidgets::getInstance().remove(current_widget);
			eventRecreate();
			UndoManager::getInstance().addValue();
		}
	}
	else if (MyGUI::KeyCode::ArrowLeft == _key)
	{
		delta = MyGUI::IntPoint(-k, 0);
	}
	else if (MyGUI::KeyCode::ArrowRight == _key)
	{
		delta = MyGUI::IntPoint(k, 0);
	}
	else if (MyGUI::KeyCode::ArrowUp == _key)
	{
		delta = MyGUI::IntPoint(0, -k);
	}
	else if (MyGUI::KeyCode::ArrowDown == _key)
	{
		delta = MyGUI::IntPoint(0, k);
	}

	if (delta != MyGUI::IntPoint())
	{
		arrow_move = true;
		current_widget_rectangle->setPosition(current_widget_rectangle->getPosition() + delta);
		notifyRectangleResize(current_widget_rectangle);
		UndoManager::getInstance().addValue(PR_KEY_POSITION);
	}
}

void PropertiesPanelView::update(MyGUI::Widget* _current_widget)
{
	current_widget = _current_widget;

	if (nullptr == current_widget)
		current_widget_rectangle->setVisible(false);
	else
	{
		MyGUI::LayerManager::getInstance().upLayerItem(current_widget);
		MyGUI::IntCoord coord = current_widget->getCoord();
		MyGUI::Widget* parent = current_widget->getParent();
		if (nullptr != parent)
		{
			// ���� ������� ������ �� ����, �� ������� ���� ����
			if (parent->getTypeName() == "TabItem" || parent->getTypeName() == MyGUI::TabItem::getClassTypeName())
			{
				MyGUI::Tab* tab = parent->getParent()->castType<MyGUI::Tab>();
				MyGUI::TabItem* sheet = parent->castType<MyGUI::TabItem>();
				tab->setItemSelected(sheet);
			}
			// ���� ������� ���� ����, �� ������� ���� ����
			if (current_widget->getTypeName() == "TabItem" || current_widget->getTypeName() == MyGUI::TabItem::getClassTypeName())
			{
				MyGUI::Tab* tab = parent->castType<MyGUI::Tab>();
				MyGUI::TabItem* sheet = current_widget->castType<MyGUI::TabItem>();
				tab->setItemSelected(sheet);
			}
			coord = current_widget->getAbsoluteCoord();
		}
		current_widget_rectangle->setVisible(true);
		current_widget_rectangle->setCoord(coord);
		MyGUI::InputManager::getInstance().setKeyFocusWidget(current_widget_rectangle);
	}

	// delete(hide) all previous properties
	for (std::map<MyGUI::Widget*, std::vector<MyGUI::StaticText*> >::iterator iterVector = mPropertiesText.begin(); iterVector != mPropertiesText.end(); ++iterVector)
	{
		hideWidgetsPairs(iterVector->first);
	}

	if (nullptr == _current_widget)
	{
		mMainWidget->setVisible(false);
	}
	else
	{
		mMainWidget->setVisible(true);

		mPairsCounter = 0;
		mPanelMainProperties->update(_current_widget);
		mPairsCounter = 0;
		mPanelTypeProperties->update(_current_widget, PanelProperties::TYPE_PROPERTIES);
		mPairsCounter = 0;
		mPanelGeneralProperties->update(_current_widget, PanelProperties::WIDGET_PROPERTIES);
		mPanelItems->update(_current_widget);
		mPanelUserData->update(_current_widget);
		mPairsCounter = 0;
		mPanelControllers->update(_current_widget);
	}
}

void PropertiesPanelView::hideWidgetsPairs(MyGUI::Widget* _window)
{
	mPairsCounter = 0;
	for (std::vector<MyGUI::StaticText*>::iterator iter = mPropertiesText[_window].begin(); iter != mPropertiesText[_window].end(); ++iter)
	{
		(*iter)->setVisible(false);
	}

	for (MyGUI::VectorWidgetPtr::iterator iter = mPropertiesElement[_window].begin(); iter != mPropertiesElement[_window].end(); ++iter)
	{
		(*iter)->setVisible(false);
	}
}
void PropertiesPanelView::createPropertiesWidgetsPair(MyGUI::Widget* _window, const std::string& _property, const std::string& _value, const std::string& _type, int y)
{
	mPairsCounter++;
	int x1 = 0, x2 = 125;
	int w1 = 120;
	int w2 = _window->getWidth() - x2;
	const int h = PropertyItemHeight;

	if (_property == "Position")
	{
		x1 = 66;
		w1 = w1 - x1;
	}

	MyGUI::StaticText* text;
	MyGUI::Widget* editOrCombo;
	//int string_int_float; // 0 - string, 1 - int, 2 - float

	enum PropertyType
	{
		PropertyType_Edit,
		PropertyType_ComboBox,
		PropertyType_EditAcceptOnly,
		PropertyType_Count
	};

	PropertyType widget_for_type;

	std::string type_names[PropertyType_Count] = { "Edit", "ComboBox", "Edit" };

	if ("Name" == _type) widget_for_type = PropertyType_Edit;
	else if ("Skin" == _type) widget_for_type = PropertyType_ComboBox;
	else if ("Position" == _type) widget_for_type = PropertyType_Edit;
	else if ("Layer" == _type) widget_for_type = PropertyType_ComboBox;
	else if ("String" == _type) widget_for_type = PropertyType_Edit;
	else if ("StringAccept" == _type) widget_for_type = PropertyType_EditAcceptOnly;
	else if ("Align" == _type) widget_for_type = PropertyType_ComboBox;
	else if ("FileName" == _type) widget_for_type = PropertyType_Edit;
	// �� ������ ��������� FIXME
	else if ("1 int" == _type) widget_for_type = PropertyType_Edit;
	else if ("2 int" == _type) widget_for_type = PropertyType_Edit;
	else if ("4 int" == _type) widget_for_type = PropertyType_Edit;
	else if ("alpha" == _type) widget_for_type = PropertyType_Edit;
	else if ("1 float" == _type) widget_for_type = PropertyType_Edit;
	else if ("2 float" == _type) widget_for_type = PropertyType_Edit;
	// ���� ������� ����� FIXME
	else if ("Colour" == _type) widget_for_type = PropertyType_Edit; //"Colour" ������ �� ������������
	else if ("MessageButton" == _type) widget_for_type = PropertyType_ComboBox;
	else widget_for_type = PropertyType_ComboBox;

	if (mPropertiesText[_window].size() < mPairsCounter)
	{
		text = _window->createWidget<MyGUI::StaticText>("Editor_StaticText", x1, y, w1, h, MyGUI::Align::Default);
		text->setTextAlign(MyGUI::Align::Right);

		mPropertiesText[_window].push_back(text);
	}
	else
	{
		text = mPropertiesText[_window][mPairsCounter-1];
		text->setVisible(true);
		text->setCoord(x1, y, w1, h);
	}
	std::string prop = _property;
	// trim widget name
	std::string::iterator iterS;
	iterS = std::find(prop.begin(), prop.end(), '_');
	if (iterS != prop.end()) prop.erase(prop.begin(), ++iterS);

	size_t idx = prop.find_last_of(' ');
	if (idx != std::string::npos) prop = prop.substr(idx);

	text->setCaption(prop);

	if ((mPropertiesElement[_window].size() < mPairsCounter) ||
		(type_names[widget_for_type] != mPropertiesElement[_window][mPairsCounter-1]->getTypeName()))
	{
		if (widget_for_type == PropertyType_Edit)
		{
			editOrCombo = _window->createWidget<MyGUI::Edit>("Edit", x2, y, w2, h, MyGUI::Align::Top | MyGUI::Align::HStretch);
			editOrCombo->castType<MyGUI::Edit>()->eventEditTextChange = newDelegate (this, &PropertiesPanelView::notifyTryApplyProperties);
			editOrCombo->castType<MyGUI::Edit>()->eventEditSelectAccept = newDelegate (this, &PropertiesPanelView::notifyForceApplyProperties);
		}
		else if (widget_for_type == PropertyType_ComboBox)
		{
			editOrCombo = _window->createWidget<MyGUI::ComboBox>("ComboBox", x2, y, w2, h, MyGUI::Align::Top | MyGUI::Align::HStretch);
			editOrCombo->castType<MyGUI::ComboBox>()->eventComboAccept = newDelegate (this, &PropertiesPanelView::notifyForceApplyProperties2);

			editOrCombo->castType<MyGUI::ComboBox>()->setComboModeDrop(true);
		}
		else if (widget_for_type == PropertyType_EditAcceptOnly)
		{
			editOrCombo = _window->createWidget<MyGUI::Edit>("Edit", x2, y, w2, h, MyGUI::Align::Top | MyGUI::Align::HStretch);
			editOrCombo->castType<MyGUI::Edit>()->eventEditSelectAccept = newDelegate (this, &PropertiesPanelView::notifyForceApplyProperties);
		}

		if (mPropertiesElement[_window].size() < mPairsCounter)
		{
			mPropertiesElement[_window].push_back(editOrCombo);
		}
		else
		{
			MyGUI::Gui::getInstance().destroyWidget(mPropertiesElement[_window][mPairsCounter-1]);
			mPropertiesElement[_window][mPairsCounter-1] = editOrCombo;
		}
	}
	else
	{
		editOrCombo = mPropertiesElement[_window][mPairsCounter-1];
		if (widget_for_type == 1) editOrCombo->castType<MyGUI::ComboBox>()->removeAllItems();
		editOrCombo->setVisible(true);
		editOrCombo->setCoord(x2, y, w2, h);
	}

	// fill possible values
	if (widget_for_type == PropertyType_ComboBox)
	{
		std::vector<std::string> values;
		if (_type == "Skin") values = WidgetTypes::getInstance().find(current_widget->getTypeName())->skin;
		else values = WidgetTypes::getInstance().findPossibleValues(_type);

		for (std::vector<std::string>::iterator iter = values.begin(); iter != values.end(); ++iter)
			editOrCombo->castType<MyGUI::ComboBox>()->addItem(*iter);
	}

	editOrCombo->setUserString("action", _property);
	editOrCombo->setUserString("type", _type);

	if (_value.empty())
	{
		editOrCombo->setCaption(DEFAULT_VALUE);
	}
	else
	{
		editOrCombo->castType<MyGUI::Edit>()->setOnlyText(_value);
		checkType(editOrCombo->castType<MyGUI::Edit>(), _type);
	}
}

void PropertiesPanelView::setPositionText(const std::string& _caption)
{
	MyGUI::Widget* window = mPanelMainProperties->getMainWidget();
	if (window)
	{
		mPropertiesElement[window][1]->setCaption(_caption);
	}
}

bool PropertiesPanelView::checkType(MyGUI::Edit* _edit, const std::string& _type)
{
	bool success = true;
	if ("Name" == _type)
	{
		const MyGUI::UString & text = _edit->getOnlyText();
		size_t index = _edit->getTextCursor();
		WidgetContainer * textWC = EditorWidgets::getInstance().find(text);
		if ((!text.empty()) && (nullptr != textWC) &&
			(EditorWidgets::getInstance().find(current_widget) != textWC))
		{
			static const MyGUI::UString colour = ERROR_VALUE;
			_edit->setCaption(colour + text);
			success = false;
		}
		else
		{
			_edit->setCaption(text);
			success = true;
		}
		_edit->setTextCursor(index);
	}
	//else if ("Skin" == _type) widget_for_type = PropertyType_ComboBox;
	//else
	if ("Position" == _type)
	{
		if (EditorWidgets::getInstance().find(current_widget)->relative_mode)
			success = Parse::checkParse<float>(_edit, 4);
		else
			success = Parse::checkParse<int>(_edit, 4);
	}
	//else if ("Layer" == _type) // ��������� �� ����� ������ ���������, � ���� � ������� ����� ���� - ���� ��������
	//else if ("String" == _type) // ������������ ������? O_o
	//else if ("Align" == _type) // ��������� �� ����� ������ ���������, � ���� � ������� ����� ���� - ���� ��������
	else if ("1 int" == _type) success = Parse::checkParse<int>(_edit, 1);
	else if ("2 int" == _type) success = Parse::checkParse<int>(_edit, 2);
	else if ("4 int" == _type) success = Parse::checkParse<int>(_edit, 4);
	else if ("alpha" == _type) success = Parse::checkParseInterval<float>(_edit, 1, 0., 1.);
	else if ("1 float" == _type) success = Parse::checkParse<float>(_edit, 1);
	else if ("2 float" == _type) success = Parse::checkParse<float>(_edit, 2);
	// ���� ������� ������������ � ��� �������� FIXME
	//else if ("Colour" == _type) success = Parse::checkParse<float>(_edit, 4);
	else if ("FileName" == _type) success = Parse::checkParseFileName(_edit);
	return success;
}

void PropertiesPanelView::notifyApplyProperties(MyGUI::Widget* _sender, bool _force)
{
	EditorWidgets * ew = &EditorWidgets::getInstance();
	WidgetContainer * widgetContainer = ew->find(current_widget);
	MyGUI::Edit* senderEdit = _sender->castType<MyGUI::Edit>();
	std::string action = senderEdit->getUserString("action");
	std::string value = senderEdit->getOnlyText();
	std::string type = senderEdit->getUserString("type");

	ON_EXIT(UndoManager::getInstance().addValue(PR_PROPERTIES););

	bool goodData = checkType(senderEdit, type);

	if (value == DEFAULT_STRING && senderEdit->getCaption() == DEFAULT_VALUE) value = "";

	if (action == "Name")
	{
		if (goodData)
		{
			widgetContainer->name = value;
			ew->widgets_changed = true;
		}
		return;
	}
	else if (action == "Skin")
	{
		widgetContainer->skin = value;
		if ( MyGUI::SkinManager::getInstance().isExist(widgetContainer->skin) || widgetContainer->skin.empty())
		{
			MyGUI::xml::Document * savedDoc = ew->savexmlDocument();
			ew->clear();
			ew->loadxmlDocument(savedDoc);
			delete savedDoc;
			eventRecreate();
		}
		else
		{
			std::string mess = MyGUI::utility::toString("Skin '", widgetContainer->skin, "' not found. This value will be saved.");
			GroupMessage::getInstance().addMessage(mess, MyGUI::LogLevel::Error);
		}
		return;
	}
	else if (action == "Position")
	{
		if (!goodData) return;
		if (widgetContainer->relative_mode)
		{
			std::istringstream str(value);
			MyGUI::FloatCoord float_coord;
			str >> float_coord;
			float_coord.left = float_coord.left/100;
			float_coord.top = float_coord.top/100;
			float_coord.width = float_coord.width/100;
			float_coord.height = float_coord.height/100;
			MyGUI::IntCoord coord = MyGUI::CoordConverter::convertFromRelative(float_coord, current_widget->getParentSize());
			current_widget->setCoord(coord);
			current_widget_rectangle->setCoord(current_widget->getAbsoluteCoord());
			return;
		}
		widgetContainer->widget->setProperty("Widget_Coord", value);
		current_widget_rectangle->setCoord(current_widget->getAbsoluteCoord());
		return;
	}
	else if (action == "Align")
	{
		widgetContainer->align = value;
		widgetContainer->widget->setAlign(MyGUI::Align::parse(value));
		return;
	}
	else if (action == "Layer")
	{
		widgetContainer->layer = value;
		return;
	}
	else
	{
		std::string tmp = action;
		if (splitString(tmp, ' ') == "Controller")
		{
			int n = MyGUI::utility::parseValue<int>(splitString(tmp, ' '));
			std::string key = splitString(tmp, ' ');
			widgetContainer->mController[n]->mProperty[key] = value;
			return;
		}
	}

	bool success = false;
	if (goodData || _force)
		success = ew->tryToApplyProperty(widgetContainer->widget, action, value);
	else
		return;

	if (success)
	{
		current_widget_rectangle->setCoord(current_widget->getAbsoluteCoord());
	}
	else
	{
		senderEdit->setCaption(DEFAULT_VALUE);
		return;
	}

	// ���� ����� ��-�� ����, �� ������� (��� ������ ���� ������) ��������
	for (VectorStringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
	{
		if (iterProperty->first == action)
		{
			if (value.empty()) widgetContainer->mProperty.erase(iterProperty);
			else iterProperty->second = value;
			return;
		}
	}

	// ���� ������ �������� �� ���� ������, �� ���������
	if (!value.empty()) widgetContainer->mProperty.push_back(std::make_pair(action, value));
}

std::string PropertiesPanelView::splitString(std::string& str, char separator)
{
	size_t spaceIdx = str.find(separator);
	if (spaceIdx == std::string::npos)
	{
		std::string tmp = str;
		str.clear();
		return tmp;
	}
	else
	{
		std::string tmp = str.substr(0, spaceIdx);
		str.erase(0, spaceIdx + 1);
		return tmp;
	}
}

void PropertiesPanelView::notifyTryApplyProperties(MyGUI::Edit* _sender)
{
	notifyApplyProperties(_sender, false);
}

void PropertiesPanelView::notifyForceApplyProperties(MyGUI::Edit* _sender)
{
	notifyApplyProperties(_sender, true);
}

void PropertiesPanelView::notifyForceApplyProperties2(MyGUI::ComboBox* _sender, size_t _index)
{
	notifyApplyProperties(_sender, true);
}
