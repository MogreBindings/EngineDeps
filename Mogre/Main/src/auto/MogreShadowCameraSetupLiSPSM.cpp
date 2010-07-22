/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreShadowCameraSetupLiSPSM.h"
#include "MogreSceneManager.h"
#include "MogreCamera.h"
#include "MogreViewport.h"
#include "MogreLight.h"

namespace Mogre
{
	//################################################################
	//LiSPSMShadowCameraSetup
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	LiSPSMShadowCameraSetup::LiSPSMShadowCameraSetup( ) : FocusedShadowCameraSetup((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::LiSPSMShadowCameraSetup();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::Degree LiSPSMShadowCameraSetup::CameraLightDirectionThreshold::get()
	{
		return static_cast<const Ogre::LiSPSMShadowCameraSetup*>(_native)->getCameraLightDirectionThreshold( );
	}
	void LiSPSMShadowCameraSetup::CameraLightDirectionThreshold::set( Mogre::Degree angle )
	{
		static_cast<Ogre::LiSPSMShadowCameraSetup*>(_native)->setCameraLightDirectionThreshold( angle );
	}
	
	Mogre::Real LiSPSMShadowCameraSetup::OptimalAdjustFactor::get()
	{
		return static_cast<const Ogre::LiSPSMShadowCameraSetup*>(_native)->getOptimalAdjustFactor( );
	}
	void LiSPSMShadowCameraSetup::OptimalAdjustFactor::set( Mogre::Real n )
	{
		static_cast<Ogre::LiSPSMShadowCameraSetup*>(_native)->setOptimalAdjustFactor( n );
	}
	
	bool LiSPSMShadowCameraSetup::UseSimpleOptimalAdjust::get()
	{
		return static_cast<const Ogre::LiSPSMShadowCameraSetup*>(_native)->getUseSimpleOptimalAdjust( );
	}
	void LiSPSMShadowCameraSetup::UseSimpleOptimalAdjust::set( bool s )
	{
		static_cast<Ogre::LiSPSMShadowCameraSetup*>(_native)->setUseSimpleOptimalAdjust( s );
	}
	
	void LiSPSMShadowCameraSetup::_Init_CLRObject( )
	{
		static_cast<Ogre::LiSPSMShadowCameraSetup*>(_native)->_Init_CLRObject( );
	}
	
	void LiSPSMShadowCameraSetup::GetShadowCamera( Mogre::SceneManager^ sm, Mogre::Camera^ cam, Mogre::Viewport^ vp, Mogre::Light^ light, Mogre::Camera^ texCam, size_t iteration )
	{
		static_cast<const Ogre::LiSPSMShadowCameraSetup*>(_native)->getShadowCamera( sm, cam, vp, light, texCam, iteration );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_LiSPSMShadowCameraSetup(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::LiSPSMShadowCameraSetup(pClrObj);
	}
	

}
