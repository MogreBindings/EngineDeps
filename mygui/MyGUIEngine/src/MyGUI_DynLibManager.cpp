/*!
	@file
	@author		Denis Koronchik
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
#include "MyGUI_Precompiled.h"
#include "MyGUI_DynLibManager.h"
#include "MyGUI_WidgetManager.h"
#include "MyGUI_Gui.h"

namespace MyGUI
{

	template <> const char* Singleton<DynLibManager>::INSTANCE_TYPE_NAME("DynLibManager");

	void DynLibManager::initialise()
	{
		MYGUI_ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		MYGUI_LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		Gui::getInstance().eventFrameStart += newDelegate(this, &DynLibManager::notifyEventFrameStart);

		MYGUI_LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void DynLibManager::shutdown()
	{
		if (!mIsInitialise) return;
		MYGUI_LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		unloadAll();

		Gui::getInstance().eventFrameStart -= newDelegate(this, &DynLibManager::notifyEventFrameStart);
		_unloadDelayDynLibs();

		MYGUI_LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	DynLib* DynLibManager::load(const std::string &fileName)
	{
		StringDynLibMap::iterator it = mLibsMap.find(fileName);

		if (it != mLibsMap.end())
		{
			return it->second;
		}

		DynLib *pLib = new DynLib(fileName);
		if (!pLib->load())
		{
			delete pLib;
			return 0;
		}

		mLibsMap[fileName] = pLib;
		return pLib;
	}

	void DynLibManager::unload(DynLib *library)
	{
		StringDynLibMap::iterator it = mLibsMap.find(library->getName());

		if (it != mLibsMap.end())
			mLibsMap.erase(it);

		mDelayDynLib.push_back(library);
	}

	void DynLibManager::unloadAll()
	{
		// unload and delete resources
		for (StringDynLibMap::iterator it = mLibsMap.begin(); it != mLibsMap.end(); ++it)
		{
			mDelayDynLib.push_back(it->second);
		}
		// Empty the list
		mLibsMap.clear();
	}

	void DynLibManager::notifyEventFrameStart(float _time)
	{
		_unloadDelayDynLibs();
	}

	void DynLibManager::_unloadDelayDynLibs()
	{
		if (!mDelayDynLib.empty())
		{
			WidgetManager* manager = WidgetManager::getInstancePtr();
			if (manager != nullptr)
				manager->_deleteDelayWidgets();

			for (VectorDynLib::iterator entry=mDelayDynLib.begin(); entry!=mDelayDynLib.end(); ++entry)
			{
				(*entry)->unload();
				delete (*entry);
			}
			mDelayDynLib.clear();
		}
	}

}
