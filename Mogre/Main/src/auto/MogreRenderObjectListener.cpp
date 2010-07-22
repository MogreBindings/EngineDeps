/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderObjectListener.h"

namespace Mogre
{
	//################################################################
	//RenderObjectListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void RenderObjectListener::_Init_CLRObject( )
	{
		static_cast<Ogre::RenderObjectListener*>(_native)->_Init_CLRObject( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_RenderObjectListener(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::RenderObjectListener(pClrObj);
	}
	

}
