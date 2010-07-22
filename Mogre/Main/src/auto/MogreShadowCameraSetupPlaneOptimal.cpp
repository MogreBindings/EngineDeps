/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreShadowCameraSetupPlaneOptimal.h"
#include "MogreMovablePlane.h"
#include "MogreSceneManager.h"
#include "MogreCamera.h"
#include "MogreViewport.h"
#include "MogreLight.h"

namespace Mogre
{
	//################################################################
	//PlaneOptimalShadowCameraSetup
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	PlaneOptimalShadowCameraSetup::PlaneOptimalShadowCameraSetup( Mogre::MovablePlane^ plane ) : ShadowCameraSetup((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::PlaneOptimalShadowCameraSetup( plane);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void PlaneOptimalShadowCameraSetup::_Init_CLRObject( )
	{
		static_cast<Ogre::PlaneOptimalShadowCameraSetup*>(_native)->_Init_CLRObject( );
	}
	
	void PlaneOptimalShadowCameraSetup::GetShadowCamera( Mogre::SceneManager^ sm, Mogre::Camera^ cam, Mogre::Viewport^ vp, Mogre::Light^ light, Mogre::Camera^ texCam, size_t iteration )
	{
		static_cast<const Ogre::PlaneOptimalShadowCameraSetup*>(_native)->getShadowCamera( sm, cam, vp, light, texCam, iteration );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_PlaneOptimalShadowCameraSetup(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::PlaneOptimalShadowCameraSetup(pClrObj);
	}
	

}
