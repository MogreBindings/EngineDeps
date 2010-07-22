/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreLight.h"
#include "MogreNode.h"
#include "MogreRenderQueue.h"
#include "MogrePlaneBoundedVolume.h"
#include "MogreCamera.h"
#include "MogreAnimable.h"
#include "MogreShadowCameraSetup.h"
#include "MogreGpuProgramParams.h"
#include "MogreMovableObject.h"

namespace Mogre
{
	//################################################################
	//Light
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Light::Light( ) : MovableObject((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::Light();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Light::Light( String^ name ) : MovableObject((CLRObject*) 0)
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
	
		_native = new Ogre::Light( o_name);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::Real Light::tempSquareDist::get()
	{
		return static_cast<Ogre::Light*>(_native)->tempSquareDist;
	}
	void Light::tempSquareDist::set( Mogre::Real value )
	{
		static_cast<Ogre::Light*>(_native)->tempSquareDist = value;
	}
	
	Mogre::Real Light::AttenuationConstant::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getAttenuationConstant( );
	}
	
	Mogre::Real Light::AttenuationLinear::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getAttenuationLinear( );
	}
	
	Mogre::Real Light::AttenuationQuadric::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getAttenuationQuadric( );
	}
	
	Mogre::Real Light::AttenuationRange::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getAttenuationRange( );
	}
	
	Mogre::AxisAlignedBox^ Light::BoundingBox::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getBoundingBox( );
	}
	
	Mogre::Real Light::BoundingRadius::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getBoundingRadius( );
	}
	
	Mogre::Vector3 Light::DerivedDirection::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getDerivedDirection( );
	}
	
	Mogre::ColourValue Light::DiffuseColour::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getDiffuseColour( );
	}
	void Light::DiffuseColour::set( Mogre::ColourValue colour )
	{
		static_cast<Ogre::Light*>(_native)->setDiffuseColour( colour );
	}
	
	Mogre::Vector3 Light::Direction::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getDirection( );
	}
	void Light::Direction::set( Mogre::Vector3 vec )
	{
		static_cast<Ogre::Light*>(_native)->setDirection( vec );
	}
	
	String^ Light::MovableType::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Light*>(_native)->getMovableType( ) );
	}
	
	Mogre::Vector3 Light::Position::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getPosition( );
	}
	void Light::Position::set( Mogre::Vector3 vec )
	{
		static_cast<Ogre::Light*>(_native)->setPosition( vec );
	}
	
	Mogre::Real Light::PowerScale::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getPowerScale( );
	}
	void Light::PowerScale::set( Mogre::Real power )
	{
		static_cast<Ogre::Light*>(_native)->setPowerScale( power );
	}
	
	Mogre::Real Light::ShadowFarClipDistance::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getShadowFarClipDistance( );
	}
	void Light::ShadowFarClipDistance::set( Mogre::Real farClip )
	{
		static_cast<Ogre::Light*>(_native)->setShadowFarClipDistance( farClip );
	}
	
	Mogre::Real Light::ShadowFarDistance::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getShadowFarDistance( );
	}
	void Light::ShadowFarDistance::set( Mogre::Real distance )
	{
		static_cast<Ogre::Light*>(_native)->setShadowFarDistance( distance );
	}
	
	Mogre::Real Light::ShadowFarDistanceSquared::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getShadowFarDistanceSquared( );
	}
	
	Mogre::Real Light::ShadowNearClipDistance::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getShadowNearClipDistance( );
	}
	void Light::ShadowNearClipDistance::set( Mogre::Real nearClip )
	{
		static_cast<Ogre::Light*>(_native)->setShadowNearClipDistance( nearClip );
	}
	
	Mogre::ColourValue Light::SpecularColour::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getSpecularColour( );
	}
	void Light::SpecularColour::set( Mogre::ColourValue colour )
	{
		static_cast<Ogre::Light*>(_native)->setSpecularColour( colour );
	}
	
	Mogre::Real Light::SpotlightFalloff::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getSpotlightFalloff( );
	}
	void Light::SpotlightFalloff::set( Mogre::Real val )
	{
		static_cast<Ogre::Light*>(_native)->setSpotlightFalloff( val );
	}
	
	Mogre::Radian Light::SpotlightInnerAngle::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getSpotlightInnerAngle( );
	}
	void Light::SpotlightInnerAngle::set( Mogre::Radian val )
	{
		static_cast<Ogre::Light*>(_native)->setSpotlightInnerAngle( val );
	}
	
	Mogre::Radian Light::SpotlightOuterAngle::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getSpotlightOuterAngle( );
	}
	void Light::SpotlightOuterAngle::set( Mogre::Radian val )
	{
		static_cast<Ogre::Light*>(_native)->setSpotlightOuterAngle( val );
	}
	
	Mogre::Light::LightTypes Light::Type::get()
	{
		return (Mogre::Light::LightTypes)static_cast<const Ogre::Light*>(_native)->getType( );
	}
	void Light::Type::set( Mogre::Light::LightTypes type )
	{
		static_cast<Ogre::Light*>(_native)->setType( (Ogre::Light::LightTypes)type );
	}
	
	Mogre::uint32 Light::TypeFlags::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getTypeFlags( );
	}
	
	bool Light::Visible::get()
	{
		return static_cast<const Ogre::Light*>(_native)->getVisible( );
	}
	void Light::Visible::set( bool visible )
	{
		static_cast<Ogre::Light*>(_native)->setVisible( visible );
	}
	
	void Light::_Init_CLRObject( )
	{
		static_cast<Ogre::Light*>(_native)->_Init_CLRObject( );
	}
	
	void Light::_calcTempSquareDist( Mogre::Vector3 worldPos )
	{
		static_cast<Ogre::Light*>(_native)->_calcTempSquareDist( worldPos );
	}
	
	void Light::SetDiffuseColour( Mogre::Real red, Mogre::Real green, Mogre::Real blue )
	{
		static_cast<Ogre::Light*>(_native)->setDiffuseColour( red, green, blue );
	}
	
	void Light::SetSpecularColour( Mogre::Real red, Mogre::Real green, Mogre::Real blue )
	{
		static_cast<Ogre::Light*>(_native)->setSpecularColour( red, green, blue );
	}
	
	void Light::SetAttenuation( Mogre::Real range, Mogre::Real constant, Mogre::Real linear, Mogre::Real quadratic )
	{
		static_cast<Ogre::Light*>(_native)->setAttenuation( range, constant, linear, quadratic );
	}
	
	void Light::SetPosition( Mogre::Real x, Mogre::Real y, Mogre::Real z )
	{
		static_cast<Ogre::Light*>(_native)->setPosition( x, y, z );
	}
	
	void Light::SetDirection( Mogre::Real x, Mogre::Real y, Mogre::Real z )
	{
		static_cast<Ogre::Light*>(_native)->setDirection( x, y, z );
	}
	
	void Light::SetSpotlightRange( Mogre::Radian innerAngle, Mogre::Radian outerAngle, Mogre::Real falloff )
	{
		static_cast<Ogre::Light*>(_native)->setSpotlightRange( innerAngle, outerAngle, falloff );
	}
	void Light::SetSpotlightRange( Mogre::Radian innerAngle, Mogre::Radian outerAngle )
	{
		static_cast<Ogre::Light*>(_native)->setSpotlightRange( innerAngle, outerAngle );
	}
	
	void Light::_notifyAttached( Mogre::Node^ parent, bool isTagPoint )
	{
		static_cast<Ogre::Light*>(_native)->_notifyAttached( parent, isTagPoint );
	}
	void Light::_notifyAttached( Mogre::Node^ parent )
	{
		static_cast<Ogre::Light*>(_native)->_notifyAttached( parent );
	}
	
	void Light::_notifyMoved( )
	{
		static_cast<Ogre::Light*>(_native)->_notifyMoved( );
	}
	
	void Light::_updateRenderQueue( Mogre::RenderQueue^ queue )
	{
		static_cast<Ogre::Light*>(_native)->_updateRenderQueue( queue );
	}
	
	Mogre::Vector3 Light::GetDerivedPosition( bool cameraRelativeIfSet )
	{
		return static_cast<const Ogre::Light*>(_native)->getDerivedPosition( cameraRelativeIfSet );
	}
	Mogre::Vector3 Light::GetDerivedPosition( )
	{
		return static_cast<const Ogre::Light*>(_native)->getDerivedPosition( );
	}
	
	Mogre::Vector4 Light::GetAs4DVector( bool cameraRelativeIfSet )
	{
		return static_cast<const Ogre::Light*>(_native)->getAs4DVector( cameraRelativeIfSet );
	}
	Mogre::Vector4 Light::GetAs4DVector( )
	{
		return static_cast<const Ogre::Light*>(_native)->getAs4DVector( );
	}
	
	Mogre::PlaneBoundedVolume^ Light::_getNearClipVolume( Mogre::Camera^ cam )
	{
		return static_cast<const Ogre::Light*>(_native)->_getNearClipVolume( cam );
	}
	
	Mogre::Const_PlaneBoundedVolumeList^ Light::_getFrustumClipVolumes( Mogre::Camera^ cam )
	{
		return static_cast<const Ogre::Light*>(_native)->_getFrustumClipVolumes( cam );
	}
	
	Mogre::AnimableValuePtr^ Light::CreateAnimableValue( String^ valueName )
	{
		DECLARE_NATIVE_STRING( o_valueName, valueName )
	
		return static_cast<Ogre::Light*>(_native)->createAnimableValue( o_valueName );
	}
	
	void Light::SetCustomShadowCameraSetup( Mogre::ShadowCameraSetupPtr^ customShadowSetup )
	{
		static_cast<Ogre::Light*>(_native)->setCustomShadowCameraSetup( (const Ogre::ShadowCameraSetupPtr&)customShadowSetup );
	}
	
	void Light::ResetCustomShadowCameraSetup( )
	{
		static_cast<Ogre::Light*>(_native)->resetCustomShadowCameraSetup( );
	}
	
	Mogre::ShadowCameraSetupPtr^ Light::GetCustomShadowCameraSetup( )
	{
		return static_cast<const Ogre::Light*>(_native)->getCustomShadowCameraSetup( );
	}
	
	size_t Light::_getIndexInFrame( )
	{
		return static_cast<const Ogre::Light*>(_native)->_getIndexInFrame( );
	}
	
	void Light::_notifyIndexInFrame( size_t i )
	{
		static_cast<Ogre::Light*>(_native)->_notifyIndexInFrame( i );
	}
	
	void Light::ResetShadowFarDistance( )
	{
		static_cast<Ogre::Light*>(_native)->resetShadowFarDistance( );
	}
	
	Mogre::Real Light::_deriveShadowNearClipDistance( Mogre::Camera^ maincam )
	{
		return static_cast<const Ogre::Light*>(_native)->_deriveShadowNearClipDistance( maincam );
	}
	
	Mogre::Real Light::_deriveShadowFarClipDistance( Mogre::Camera^ maincam )
	{
		return static_cast<const Ogre::Light*>(_native)->_deriveShadowFarClipDistance( maincam );
	}
	
	void Light::_setCameraRelative( Mogre::Camera^ cam )
	{
		static_cast<Ogre::Light*>(_native)->_setCameraRelative( cam );
	}
	
	void Light::SetCustomParameter( Mogre::uint16 index, Mogre::Vector4 value )
	{
		static_cast<Ogre::Light*>(_native)->setCustomParameter( index, value );
	}
	
	Mogre::Vector4 Light::GetCustomParameter( Mogre::uint16 index )
	{
		return static_cast<const Ogre::Light*>(_native)->getCustomParameter( index );
	}
	
	void Light::_updateCustomGpuParameter( Mogre::uint16 paramIndex, Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr constantEntry, Mogre::GpuProgramParameters^ params )
	{
		static_cast<const Ogre::Light*>(_native)->_updateCustomGpuParameter( paramIndex, constantEntry, params );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Light(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Light(pClrObj);
	}
	
	//################################################################
	//LightFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	LightFactory::LightFactory( ) : MovableObjectFactory((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::LightFactory();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ LightFactory::FACTORY_TYPE_NAME::get()
	{
		return TO_CLR_STRING( Ogre::LightFactory::FACTORY_TYPE_NAME );
	}
	void LightFactory::FACTORY_TYPE_NAME::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		Ogre::LightFactory::FACTORY_TYPE_NAME = o_value;
	}
	
	String^ LightFactory::Type::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::LightFactory*>(_native)->getType( ) );
	}
	
	void LightFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::LightFactory*>(_native)->_Init_CLRObject( );
	}
	
	void LightFactory::DestroyInstance( Mogre::MovableObject^ obj )
	{
		static_cast<Ogre::LightFactory*>(_native)->destroyInstance( obj );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_LightFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::LightFactory(pClrObj);
	}
	

}
