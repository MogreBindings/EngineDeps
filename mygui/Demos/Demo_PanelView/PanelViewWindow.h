/*!
	@file
	@author		Albert Semenov
	@date		01/2009
*/
#ifndef __PANEL_VIEW_WINDOW_H__
#define __PANEL_VIEW_WINDOW_H__

#include "PanelView.h"
#include "BaseLayout/BaseLayout.h"

namespace demo
{

	class PanelViewWindow : public wraps::BaseLayout
	{
	public:
		PanelViewWindow() : BaseLayout("PanelView.layout")
		{
			assignBase(mPanelView, "scroll_View");

			MyGUI::Window* window = mMainWidget->castType<MyGUI::Window>(false);
			if (window != nullptr)
			{
				window->eventWindowChangeCoord = MyGUI::newDelegate(this, &PanelViewWindow::notifyWindowChangeCoord);
				mOldSize = window->getSize();
			}
		}

		PanelView* getPanelView() { return mPanelView; }

	private:
		void notifyWindowChangeCoord(MyGUI::Window* _sender)
		{
			const MyGUI::IntSize & size = _sender->getSize();
			if (size != mOldSize)
			{
				mOldSize = size;
				mPanelView->setNeedUpdate();
			}
		}

	private:
		MyGUI::IntSize mOldSize;
		PanelView* mPanelView;
	};

} // namespace demo

#endif // __PANEL_VIEW_WINDOW_H__
