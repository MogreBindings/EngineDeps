/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreResourceBackgroundQueue.h"

namespace Mogre
{
	//################################################################
	//BackgroundProcessResult
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	BackgroundProcessResult::BackgroundProcessResult( )
	{
		_createdByCLR = true;
		_native = new Ogre::BackgroundProcessResult();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle BackgroundProcessResult::_CLRHandle::get()
	{
		return static_cast<Ogre::BackgroundProcessResult*>(_native)->_CLRHandle;
	}
	void BackgroundProcessResult::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::BackgroundProcessResult*>(_native)->_CLRHandle = value;
	}
	
	bool BackgroundProcessResult::Error::get()
	{
		return static_cast<Ogre::BackgroundProcessResult*>(_native)->error;
	}
	void BackgroundProcessResult::Error::set( bool value )
	{
		static_cast<Ogre::BackgroundProcessResult*>(_native)->error = value;
	}
	
	String^ BackgroundProcessResult::Message::get()
	{
		return TO_CLR_STRING( static_cast<Ogre::BackgroundProcessResult*>(_native)->message );
	}
	void BackgroundProcessResult::Message::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		static_cast<Ogre::BackgroundProcessResult*>(_native)->message = o_value;
	}
	
	
	//Protected Declarations
	
	
	

}
