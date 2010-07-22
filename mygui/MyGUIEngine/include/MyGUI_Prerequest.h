/*!
	@file
	@author		Denis Koronchik
	@author		Georgiy Evmenov
	@author		Ну и я чуть чуть =)
	@date		09/2007
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

#ifndef __MYGUI_PREREQUEST_H__
#define __MYGUI_PREREQUEST_H__

#include "MyGUI_Platform.h"

#if MYGUI_COMPILER == MYGUI_COMPILER_MSVC
#	ifndef _CRT_SECURE_NO_WARNINGS
#		define _CRT_SECURE_NO_WARNINGS
#	endif
#endif

#define MYGUI_DEFINE_VERSION(major, minor, patch) ((major << 16) | (minor << 8) | patch)

#ifndef MYGUI_DONT_REPLACE_NULLPTR
	#if MYGUI_COMPILER == MYGUI_COMPILER_MSVC
		#ifndef _MANAGED
			#define nullptr 0
		#endif
	#else
		#define nullptr 0
	#endif
#endif

namespace MyGUI
{

	class Gui;
	class IWidgetCreator;

	// managers
	class LogManager;
	class InputManager;
	class SubWidgetManager;
	class LayerManager;
	class SkinManager;
	class WidgetManager;
	class FontManager;
	class ControllerManager;
	class PointerManager;
	class ClipboardManager;
	class LayoutManager;
	class PluginManager;
	class DynLibManager;
	class LanguageManager;
	class ResourceManager;
	class RenderManager;
	class FactoryManager;
	class ToolTipManager;

	class IWidgetFactory;

	class DynLib;

	namespace factory
	{
		template <typename T>
		class BaseWidgetFactory;
	}

	class IEventCaller;
	class UIElement;

	class Widget;
	class Button;
	class Window;
	class List;
	class HScroll;
	class VScroll;
	class Edit;
	class ComboBox;
	class StaticText;
	class Tab;
	class TabItem;
	class Progress;
	class ItemBox;
	class MultiList;
	class StaticImage;
	class Message;
	class MenuCtrl;
	class MenuItem;
	class PopupMenu;
	class MenuBar;
	class ScrollView;
	class DDContainer;
	class Canvas;
	class ListCtrl;
	class ListBox;
	class Panel;
	class StackPanel;
	class WrapPanel;

	typedef Widget* WidgetPtr;
	typedef Button* ButtonPtr;
	typedef Window* WindowPtr;
	typedef List* ListPtr;
	typedef HScroll* HScrollPtr;
	typedef VScroll* VScrollPtr;
	typedef Edit* EditPtr;
	typedef ComboBox* ComboBoxPtr;
	typedef StaticText* StaticTextPtr;
	typedef Tab* TabPtr;
	typedef TabItem* TabItemPtr;
	typedef Progress* ProgressPtr;
	typedef ItemBox* ItemBoxPtr;
	typedef MultiList* MultiListPtr;
	typedef StaticImage* StaticImagePtr;
	typedef Message* MessagePtr;
	typedef MenuCtrl* MenuCtrlPtr;
	typedef MenuItem* MenuItemPtr;
	typedef PopupMenu* PopupMenuPtr;
	typedef MenuBar* MenuBarPtr;
	typedef ScrollView* ScrollViewPtr;
	typedef DDContainer* DDContainerPtr;
	typedef Canvas* CanvasPtr;
	typedef ListCtrl* ListCtrlPtr;
	typedef ListBox* ListBoxPtr;

#ifndef MYGUI_DONT_USE_OBSOLETE

	typedef TabItem Sheet;
	typedef TabItem* SheetPtr;
	typedef Canvas RenderBox;
	typedef Canvas* RenderBoxPtr;

#endif // MYGUI_DONT_USE_OBSOLETE

	// Define version
	#define MYGUI_VERSION_MAJOR 3
	#define MYGUI_VERSION_MINOR 1
	#define MYGUI_VERSION_PATCH 0

	#define MYGUI_VERSION    MYGUI_DEFINE_VERSION(MYGUI_VERSION_MAJOR, MYGUI_VERSION_MINOR, MYGUI_VERSION_PATCH)

	// Disable warnings for MSVC compiler
#if MYGUI_COMPILER == MYGUI_COMPILER_MSVC

// disable: warning C4512: '***' : assignment operator could not be generated
#	pragma warning (disable : 4512)

// disable: warning C4127: conditional expression is constant
#	pragma warning (disable : 4127)

// disable: warning C4100: '***' : unreferenced formal parameter
#	pragma warning (disable : 4100)

// disable: warning C4275: non dll-interface class '***' used as base for dll-interface clas '***'
#	pragma warning (disable : 4275)

// disable: "<type> needs to have dll-interface to be used by clients'
// Happens on STL member variables which are not public therefore is ok
#	pragma warning (disable : 4251)

// disable: "no suitable definition provided for explicit template
// instantiation request" Occurs for no justifiable reason on all
// #includes of Singleton
#	pragma warning( disable: 4661)

#endif

} // namespace MyGUI

#endif // __MYGUI_PREREQUEST_H__
