/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreShadowCameraSetup.h"
#include "MogreSceneManager.h"
#include "MogreCamera.h"
#include "MogreViewport.h"
#include "MogreLight.h"

namespace Mogre
{
	//################################################################
	//ShadowCameraSetup
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void ShadowCameraSetup::_Init_CLRObject( )
	{
		static_cast<Ogre::ShadowCameraSetup*>(_native)->_Init_CLRObject( );
	}
	
	void ShadowCameraSetup::GetShadowCamera( Mogre::SceneManager^ sm, Mogre::Camera^ cam, Mogre::Viewport^ vp, Mogre::Light^ light, Mogre::Camera^ texCam, size_t iteration )
	{
		static_cast<const Ogre::ShadowCameraSetup*>(_native)->getShadowCamera( sm, cam, vp, light, texCam, iteration );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_ShadowCameraSetup(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::ShadowCameraSetup(pClrObj);
	}
	
	//################################################################
	//DefaultShadowCameraSetup
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	DefaultShadowCameraSetup::DefaultShadowCameraSetup( ) : ShadowCameraSetup((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::DefaultShadowCameraSetup();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void DefaultShadowCameraSetup::_Init_CLRObject( )
	{
		static_cast<Ogre::DefaultShadowCameraSetup*>(_native)->_Init_CLRObject( );
	}
	
	void DefaultShadowCameraSetup::GetShadowCamera( Mogre::SceneManager^ sm, Mogre::Camera^ cam, Mogre::Viewport^ vp, Mogre::Light^ light, Mogre::Camera^ texCam, size_t iteration )
	{
		static_cast<const Ogre::DefaultShadowCameraSetup*>(_native)->getShadowCamera( sm, cam, vp, light, texCam, iteration );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_DefaultShadowCameraSetup(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::DefaultShadowCameraSetup(pClrObj);
	}
	

}
