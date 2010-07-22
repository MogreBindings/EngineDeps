/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreUserObjectBindings.h"

namespace Mogre
{
	//################################################################
	//UserObjectBindings
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	UserObjectBindings::UserObjectBindings( ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::UserObjectBindings();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void UserObjectBindings::_Init_CLRObject( )
	{
		static_cast<Ogre::UserObjectBindings*>(_native)->_Init_CLRObject( );
	}
	
	void UserObjectBindings::EraseUserAny( String^ key )
	{
		DECLARE_NATIVE_STRING( o_key, key )
	
		static_cast<Ogre::UserObjectBindings*>(_native)->eraseUserAny( o_key );
	}
	
	void UserObjectBindings::Clear( )
	{
		static_cast<const Ogre::UserObjectBindings*>(_native)->clear( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_UserObjectBindings(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::UserObjectBindings(pClrObj);
	}
	

}
