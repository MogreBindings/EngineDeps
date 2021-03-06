/*!
	@file
	@author		Georgiy Evmenov
	@date		09/2008
*/

#include "precompiled.h"
#include "Common.h"
#include "PanelProperties.h"
#include "EditorWidgets.h"

PanelProperties::PanelProperties() : BasePanelViewItem("PanelProperties.layout")
{
}

void PanelProperties::initialise()
{
	mPanelCell->setCaption(localise("Widget_type_propertes"));
}

void PanelProperties::shutdown()
{
}

size_t PanelProperties::AddParametrs(WidgetStyle * widgetType, WidgetContainer * widgetContainer, int& y)
{
	size_t count = widgetType->parameter.size();

	for (VectorStringPairs::iterator iter = widgetType->parameter.begin(); iter != widgetType->parameter.end(); ++iter)
	{
		std::string value = "";
		for (VectorStringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
		{
			if (iterProperty->first == iter->first)
			{
				value = iterProperty->second;
				break;
			}
		}
		eventCreatePair(mWidgetClient, iter->first, value, iter->second, y);
		y += PropertyItemHeight;
	}

	if (widgetType->base != "Widget")
	{
		widgetType = WidgetTypes::getInstance().find(widgetType->base);
		count += AddParametrs(widgetType, widgetContainer, y);
	}

	return count;
}

void PanelProperties::update(MyGUI::Widget* _current_widget, PropertiesGroup _group)
{
	int y = 0;

	WidgetStyle * widgetType = WidgetTypes::getInstance().find(_current_widget->getTypeName());
	WidgetContainer * widgetContainer = EditorWidgets::getInstance().find(_current_widget);

	if (_group == TYPE_PROPERTIES)
	{
		MyGUI::LanguageManager::getInstance().addUserTag("widget_type", _current_widget->getTypeName());
		if (widgetType->name == "Widget")
		{
			if (_current_widget->getTypeName() != "Widget")
			{
				mPanelCell->setCaption(MyGUI::LanguageManager::getInstance().replaceTags(localise("Properties_not_available")));
				y += PropertyItemHeight;
			}
			else
			{
				setVisible(false);
			}
		}
		else
		{
			mPanelCell->setCaption(MyGUI::LanguageManager::getInstance().replaceTags(localise("Widget_type_propertes")));

			size_t count = AddParametrs(widgetType, widgetContainer, y);

			setVisible( count > 0 );
		}
	}
	else if (_group == WIDGET_PROPERTIES)
	{
		mPanelCell->setCaption(localise("Other_properties"));

		if (_current_widget->getTypeName() != "TabItem" &&
			_current_widget->getTypeName() != MyGUI::TabItem::getClassTypeName())
		{
			setVisible(true);
			//base properties (from Widget)
			WidgetStyle * baseType = WidgetTypes::getInstance().find("Widget");
			for (VectorStringPairs::iterator iter = baseType->parameter.begin(); iter != baseType->parameter.end(); ++iter)
			{
				std::string value = "";
				for (VectorStringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
				{
					if (iterProperty->first == iter->first)
					{
						value = iterProperty->second;
						break;
					}
				}

				eventCreatePair(mWidgetClient, iter->first, value, iter->second, y);
				y += PropertyItemHeight;
			}
		}
		else
		{
			setVisible(false);
		}
	}

	mPanelCell->setClientHeight(y);
}
