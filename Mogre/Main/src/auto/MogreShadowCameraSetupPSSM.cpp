/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreShadowCameraSetupPSSM.h"
#include "MogreSceneManager.h"
#include "MogreCamera.h"
#include "MogreViewport.h"
#include "MogreLight.h"

namespace Mogre
{
	//################################################################
	//PSSMShadowCameraSetup
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDTYPE Mogre::Real
	#define STLDECL_NATIVETYPE Ogre::Real
	CPP_DECLARE_STLVECTOR( PSSMShadowCameraSetup::, SplitPointList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	#define STLDECL_MANAGEDTYPE Mogre::Real
	#define STLDECL_NATIVETYPE Ogre::Real
	CPP_DECLARE_STLVECTOR( PSSMShadowCameraSetup::, OptimalAdjustFactorList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	PSSMShadowCameraSetup::PSSMShadowCameraSetup( ) : LiSPSMShadowCameraSetup((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::PSSMShadowCameraSetup();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	size_t PSSMShadowCameraSetup::SplitCount::get()
	{
		return static_cast<const Ogre::PSSMShadowCameraSetup*>(_native)->getSplitCount( );
	}
	
	Mogre::Real PSSMShadowCameraSetup::SplitPadding::get()
	{
		return static_cast<const Ogre::PSSMShadowCameraSetup*>(_native)->getSplitPadding( );
	}
	void PSSMShadowCameraSetup::SplitPadding::set( Mogre::Real pad )
	{
		static_cast<Ogre::PSSMShadowCameraSetup*>(_native)->setSplitPadding( pad );
	}
	
	void PSSMShadowCameraSetup::CalculateSplitPoints( size_t splitCount, Mogre::Real nearDist, Mogre::Real farDist, Mogre::Real lambda )
	{
		static_cast<Ogre::PSSMShadowCameraSetup*>(_native)->calculateSplitPoints( splitCount, nearDist, farDist, lambda );
	}
	void PSSMShadowCameraSetup::CalculateSplitPoints( size_t splitCount, Mogre::Real nearDist, Mogre::Real farDist )
	{
		static_cast<Ogre::PSSMShadowCameraSetup*>(_native)->calculateSplitPoints( splitCount, nearDist, farDist );
	}
	
	void PSSMShadowCameraSetup::SetSplitPoints( Mogre::PSSMShadowCameraSetup::Const_SplitPointList^ newSplitPoints )
	{
		static_cast<Ogre::PSSMShadowCameraSetup*>(_native)->setSplitPoints( newSplitPoints );
	}
	
	void PSSMShadowCameraSetup::GetShadowCamera( Mogre::SceneManager^ sm, Mogre::Camera^ cam, Mogre::Viewport^ vp, Mogre::Light^ light, Mogre::Camera^ texCam, size_t iteration )
	{
		static_cast<const Ogre::PSSMShadowCameraSetup*>(_native)->getShadowCamera( sm, cam, vp, light, texCam, iteration );
	}
	
	Mogre::PSSMShadowCameraSetup::Const_SplitPointList^ PSSMShadowCameraSetup::GetSplitPoints( )
	{
		return static_cast<const Ogre::PSSMShadowCameraSetup*>(_native)->getSplitPoints( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_PSSMShadowCameraSetup(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::PSSMShadowCameraSetup(pClrObj);
	}
	

}
