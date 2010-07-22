/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreSerializer.h"

namespace Mogre
{
	//################################################################
	//Serializer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Serializer::Serializer( ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::Serializer();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void Serializer::_Init_CLRObject( )
	{
		static_cast<Ogre::Serializer*>(_native)->_Init_CLRObject( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Serializer(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Serializer(pClrObj);
	}
	

}
