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
#ifndef __MYGUI_INPUT_MANAGER_H__
#define __MYGUI_INPUT_MANAGER_H__

#include "MyGUI_Prerequest.h"
#include "MyGUI_Macros.h"
#include "MyGUI_Singleton.h"
#include "MyGUI_WidgetDefines.h"
#include "MyGUI_IUnlinkWidget.h"
#include "MyGUI_WidgetDefines.h"
#include "MyGUI_XmlDocument.h"
#include "MyGUI_MouseButton.h"
#include "MyGUI_KeyCode.h"
#include "MyGUI_Timer.h"
#include "MyGUI_ILayer.h"
#include "MyGUI_Delegate.h"

namespace MyGUI
{

	class MYGUI_EXPORT InputManager :
		public IUnlinkWidget,
		public MyGUI::Singleton<InputManager>
	{
	public:
		InputManager();

		void initialise();
		void shutdown();

		/** Inject MouseMove event
			@return true if event has been processed by GUI
		*/
		bool injectMouseMove(int _absx, int _absy, int _absz);
		/** Inject MousePress event
			@return true if event has been processed by GUI
		*/
		bool injectMousePress(int _absx, int _absy, MouseButton _id);
		/** Inject MouseRelease event
			@return true if event has been processed by GUI
		*/
		bool injectMouseRelease(int _absx, int _absy, MouseButton _id);

		/** Inject KeyPress event
			@return true if event has been processed by GUI
		*/
		bool injectKeyPress(KeyCode _key, Char _text = 0);
		/** Inject KeyRelease event
			@return true if event has been processed by GUI
		*/
		bool injectKeyRelease(KeyCode _key);

		/** Is any widget have mouse focus */
		bool isFocusMouse() { return mWidgetMouseFocus != nullptr; }
		/** Is any widget have key focus */
		bool isFocusKey() { return mWidgetKeyFocus != nullptr; }
		/** Is any widget captured mouse */
		bool isCaptureMouse() { return mIsWidgetMouseCapture; }

		/** Set key focus for _widget */
		void setKeyFocusWidget(Widget* _widget);
		/** Drop key focus for _widget */
		void resetKeyFocusWidget(Widget* _widget);
		/** Drop any key focus */
		void resetKeyFocusWidget() { setKeyFocusWidget(nullptr); }

		/** Get mouse focused widget */
		Widget* getMouseFocusWidget() { return mWidgetMouseFocus; }
		/** Get key focused widget */
		Widget* getKeyFocusWidget() { return mWidgetKeyFocus; }
		/** Get position of last left mouse button press.
			Position calculated on specific layer where mouse was pressed.
		*/
		const IntPoint& getLastLeftPressed() { return mLastLeftPressed; }
		/** Get current mouse position on screen */
		const IntPoint& getMousePosition() { return mMousePosition; }

		/** Get mouse position on current layer.
			This position might different from getMousePosition() if mouse is over non-2d layer.
		*/
		IntPoint getMousePositionByLayer();

		// работа с модальными окнами
		/** Add modal widget - all other widgets inaccessible while modal widget exist */
		void addWidgetModal(Widget* _widget);
		/** Remove modal widget */
		void removeWidgetModal(Widget* _widget);

		/** Return true if any modal widget exist */
		bool isModalAny() { return !mVectorModalRootWidget.empty(); }

		/** Is control button pressed */
		bool isControlPressed() { return mIsControlPressed; }
		/** Is shift button pressed */
		bool isShiftPressed() { return mIsShiftPressed; }

		/** Reset mouse capture.
			For example when we dragging and application
			lost focus you should call this)
		*/
		void resetMouseCaptureWidget() { mIsWidgetMouseCapture = false; }

		/** Unlink widget from input manager. */
		void unlinkWidget(Widget* _widget) { _unlinkWidget(_widget); }

		/** Event : MultiDelegate. Mouse focus was changed.\n
			signature : void method(MyGUI::Widget* _widget)\n
			@param _widget
		*/
		delegates::CMultiDelegate1<Widget*>
			eventChangeMouseFocus;

		/** Event : MultiDelegate. Key focus was changed.\n
			signature : void method(MyGUI::Widget* _widget)\n
			@param _widget
		*/
		delegates::CMultiDelegate1<Widget*>
			eventChangeKeyFocus;

	private:
		// тестовый вариант, очистка фокуса мыши
		/** Drop any mouse focus */
		void resetMouseFocusWidget();

		void updateMouseFocus();

		// удаляем данный виджет из всех возможных мест
		void _unlinkWidget(Widget* _widget);

		void frameEntered(float _frame);

		void firstEncoding(KeyCode _key, bool bIsKeyPressed);

		// запоминает клавишу для поддержки повторения
		void storeKey(KeyCode _key, Char _text);

		// сбрасывает клавишу повторения
		void resetKey();

		void onEventMouseEntry(Widget* _widget, Widget* _old);
		void onEventMouseLeave(Widget* _widget, Widget* _new);
		void onEventMouseMove(Widget* _widget, int _x, int _y);
		void onEventMouseDrag(Widget* _widget, int _x, int _y);
		void onEventMouseWheel(Widget* _widget, int _delta);
		void onEventMouseButtonDown(Widget* _widget, int _x, int _y, MouseButton _button);
		void onEventMouseButtonUp(Widget* _widget, int _x, int _y, MouseButton _button);
		void onEventMouseButtonClick(Widget* _widget, int _x, int _y, MouseButton _button);
		void onEventMouseButtonDoubleClick(Widget* _widget, int _x, int _y, MouseButton _button);
		void onEventGotKeyboardFocus(Widget* _widget, Widget* _old);
		void onEventLostKeyboardFocus(Widget* _widget, Widget* _new);
		void onEventKeyButtonDown(Widget* _widget, KeyCode _key, Char _text);
		void onEventKeyButtonUp(Widget* _widget, KeyCode _key);
		void onEventRootMouseFocusChanged(Widget* _widget, bool _focus);
		void onEventRootKeyboardFocusChanged(Widget* _widget, bool _focus);

	private:
		// виджеты которым принадлежит фокус
		Widget* mWidgetMouseFocus;
		Widget* mWidgetKeyFocus;
		ILayer* mLayerMouseFocus;
		// захватил ли мышь активный виджет
		bool mIsWidgetMouseCapture;
		// таймер для двойного клика
	    Timer mTimer; //used for double click timing

		// нажат ли шифт
		bool mIsShiftPressed;
		// нажат ли контрол
		bool mIsControlPressed;
		// там где была последний раз нажата левая кнопка
		IntPoint mLastLeftPressed;
		IntPoint mMousePosition;
		// клавиша для повтора
		KeyCode mHoldKey;
		Char mHoldChar;
		bool mFirstPressKey;
		float mTimerKey;
		int mOldAbsZ;

		// список виджетов с модальным режимом
		VectorWidgetPtr mVectorModalRootWidget;
	};

} // namespace MyGUI

#endif // __MYGUI_INPUT_MANAGER_H__