/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreTechnique.h"
#include "MogrePass.h"
#include "MogreMaterial.h"
#include "MogreUserObjectBindings.h"
#include "MogreCommon.h"

namespace Mogre
{
	//################################################################
	//Technique
	//################################################################
	
	//Nested Types
	//################################################################
	//GPUDeviceNameRule
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Technique::GPUDeviceNameRule::GPUDeviceNameRule( )
	{
		_createdByCLR = true;
		_native = new Ogre::Technique::GPUDeviceNameRule();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Technique::GPUDeviceNameRule::GPUDeviceNameRule( String^ pattern, Mogre::Technique::IncludeOrExclude ie, bool caseSen )
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		_native = new Ogre::Technique::GPUDeviceNameRule( o_pattern, (Ogre::Technique::IncludeOrExclude)ie, caseSen);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle Technique::GPUDeviceNameRule::_CLRHandle::get()
	{
		return static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->_CLRHandle;
	}
	void Technique::GPUDeviceNameRule::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->_CLRHandle = value;
	}
	
	Mogre::Technique::IncludeOrExclude Technique::GPUDeviceNameRule::IncludeOrExclude::get()
	{
		return (Mogre::Technique::IncludeOrExclude)static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->includeOrExclude;
	}
	void Technique::GPUDeviceNameRule::IncludeOrExclude::set( Mogre::Technique::IncludeOrExclude value )
	{
		static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->includeOrExclude = (Ogre::Technique::IncludeOrExclude)value;
	}
	
	bool Technique::GPUDeviceNameRule::CaseSensitive::get()
	{
		return static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->caseSensitive;
	}
	void Technique::GPUDeviceNameRule::CaseSensitive::set( bool value )
	{
		static_cast<Ogre::Technique::GPUDeviceNameRule*>(_native)->caseSensitive = value;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GPUVendorRule
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Technique::GPUVendorRule::GPUVendorRule( )
	{
		_createdByCLR = true;
		_native = new Ogre::Technique::GPUVendorRule();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Technique::GPUVendorRule::GPUVendorRule( Mogre::GPUVendor v, Mogre::Technique::IncludeOrExclude ie )
	{
		_createdByCLR = true;
		_native = new Ogre::Technique::GPUVendorRule( (Ogre::GPUVendor)v, (Ogre::Technique::IncludeOrExclude)ie);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle Technique::GPUVendorRule::_CLRHandle::get()
	{
		return static_cast<Ogre::Technique::GPUVendorRule*>(_native)->_CLRHandle;
	}
	void Technique::GPUVendorRule::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::Technique::GPUVendorRule*>(_native)->_CLRHandle = value;
	}
	
	Mogre::GPUVendor Technique::GPUVendorRule::Vendor::get()
	{
		return (Mogre::GPUVendor)static_cast<Ogre::Technique::GPUVendorRule*>(_native)->vendor;
	}
	void Technique::GPUVendorRule::Vendor::set( Mogre::GPUVendor value )
	{
		static_cast<Ogre::Technique::GPUVendorRule*>(_native)->vendor = (Ogre::GPUVendor)value;
	}
	
	Mogre::Technique::IncludeOrExclude Technique::GPUVendorRule::IncludeOrExclude::get()
	{
		return (Mogre::Technique::IncludeOrExclude)static_cast<Ogre::Technique::GPUVendorRule*>(_native)->includeOrExclude;
	}
	void Technique::GPUVendorRule::IncludeOrExclude::set( Mogre::Technique::IncludeOrExclude value )
	{
		static_cast<Ogre::Technique::GPUVendorRule*>(_native)->includeOrExclude = (Ogre::Technique::IncludeOrExclude)value;
	}
	
	
	//Protected Declarations
	
	
	
	#define STLDECL_MANAGEDTYPE Mogre::Technique::GPUVendorRule^
	#define STLDECL_NATIVETYPE Ogre::Technique::GPUVendorRule
	CPP_DECLARE_STLVECTOR( Technique::, GPUVendorRuleList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	#define STLDECL_MANAGEDTYPE Mogre::Technique::GPUDeviceNameRule^
	#define STLDECL_NATIVETYPE Ogre::Technique::GPUDeviceNameRule
	CPP_DECLARE_STLVECTOR( Technique::, GPUDeviceNameRuleList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	CPP_DECLARE_ITERATOR_NOCONSTRUCTOR( Technique::, PassIterator, Ogre::Technique::PassIterator, Mogre::Technique::Passes, Mogre::Pass^, Ogre::Pass* )
	
	CPP_DECLARE_ITERATOR( Technique::, IlluminationPassIterator, Ogre::Technique::IlluminationPassIterator, Mogre::IlluminationPassList, Mogre::IlluminationPass_NativePtr, Ogre::IlluminationPass*,  )
	
	CPP_DECLARE_ITERATOR( Technique::, GPUVendorRuleIterator, Ogre::Technique::GPUVendorRuleIterator, Mogre::Technique::GPUVendorRuleList, Mogre::Technique::GPUVendorRule^, Ogre::Technique::GPUVendorRule,  )
	
	CPP_DECLARE_ITERATOR( Technique::, GPUDeviceNameRuleIterator, Ogre::Technique::GPUDeviceNameRuleIterator, Mogre::Technique::GPUDeviceNameRuleList, Mogre::Technique::GPUDeviceNameRule^, Ogre::Technique::GPUDeviceNameRule,  )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Technique::Technique( Mogre::Material^ parent )
	{
		_createdByCLR = true;
		_native = new Ogre::Technique( parent);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Technique::Technique( Mogre::Material^ parent, Mogre::Technique^ oth )
	{
		_createdByCLR = true;
		_native = new Ogre::Technique( parent, oth);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle Technique::_CLRHandle::get()
	{
		return static_cast<Ogre::Technique*>(_native)->_CLRHandle;
	}
	void Technique::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::Technique*>(_native)->_CLRHandle = value;
	}
	
	bool Technique::HasColourWriteDisabled::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->hasColourWriteDisabled( );
	}
	
	bool Technique::IsDepthCheckEnabled::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isDepthCheckEnabled( );
	}
	
	bool Technique::IsDepthWriteEnabled::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isDepthWriteEnabled( );
	}
	
	bool Technique::IsLoaded::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isLoaded( );
	}
	
	bool Technique::IsSupported::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isSupported( );
	}
	
	bool Technique::IsTransparent::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isTransparent( );
	}
	
	bool Technique::IsTransparentSortingEnabled::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isTransparentSortingEnabled( );
	}
	
	bool Technique::IsTransparentSortingForced::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->isTransparentSortingForced( );
	}
	
	unsigned short Technique::LodIndex::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->getLodIndex( );
	}
	void Technique::LodIndex::set( unsigned short index )
	{
		static_cast<Ogre::Technique*>(_native)->setLodIndex( index );
	}
	
	String^ Technique::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Technique*>(_native)->getName( ) );
	}
	void Technique::Name::set( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::Technique*>(_native)->setName( o_name );
	}
	
	unsigned short Technique::NumPasses::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->getNumPasses( );
	}
	
	Mogre::Material^ Technique::Parent::get()
	{
		return static_cast<const Ogre::Technique*>(_native)->getParent( );
	}
	
	String^ Technique::ResourceGroup::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Technique*>(_native)->getResourceGroup( ) );
	}
	
	String^ Technique::SchemeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Technique*>(_native)->getSchemeName( ) );
	}
	void Technique::SchemeName::set( String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::Technique*>(_native)->setSchemeName( o_schemeName );
	}
	
	Mogre::UserObjectBindings^ Technique::UserObjectBindings::get()
	{
		return static_cast<Ogre::Technique*>(_native)->getUserObjectBindings( );
	}
	
	String^ Technique::_compile( bool autoManageTextureUnits )
	{
		return TO_CLR_STRING( static_cast<Ogre::Technique*>(_native)->_compile( autoManageTextureUnits ) );
	}
	
	void Technique::_compileIlluminationPasses( )
	{
		static_cast<Ogre::Technique*>(_native)->_compileIlluminationPasses( );
	}
	
	Mogre::Pass^ Technique::CreatePass( )
	{
		return static_cast<Ogre::Technique*>(_native)->createPass( );
	}
	
	Mogre::Pass^ Technique::GetPass( unsigned short index )
	{
		return static_cast<Ogre::Technique*>(_native)->getPass( index );
	}
	
	Mogre::Pass^ Technique::GetPass( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::Technique*>(_native)->getPass( o_name );
	}
	
	void Technique::RemovePass( unsigned short index )
	{
		static_cast<Ogre::Technique*>(_native)->removePass( index );
	}
	
	void Technique::RemoveAllPasses( )
	{
		static_cast<Ogre::Technique*>(_native)->removeAllPasses( );
	}
	
	bool Technique::MovePass( unsigned short sourceIndex, unsigned short destinationIndex )
	{
		return static_cast<Ogre::Technique*>(_native)->movePass( sourceIndex, destinationIndex );
	}
	
	Mogre::Technique::PassIterator^ Technique::GetPassIterator( )
	{
		return static_cast<Ogre::Technique*>(_native)->getPassIterator( );
	}
	
	Mogre::Technique::IlluminationPassIterator^ Technique::GetIlluminationPassIterator( )
	{
		return static_cast<Ogre::Technique*>(_native)->getIlluminationPassIterator( );
	}
	
	
	void Technique::_prepare( )
	{
		static_cast<Ogre::Technique*>(_native)->_prepare( );
	}
	
	void Technique::_unprepare( )
	{
		static_cast<Ogre::Technique*>(_native)->_unprepare( );
	}
	
	void Technique::_load( )
	{
		static_cast<Ogre::Technique*>(_native)->_load( );
	}
	
	void Technique::_unload( )
	{
		static_cast<Ogre::Technique*>(_native)->_unload( );
	}
	
	void Technique::_notifyNeedsRecompile( )
	{
		static_cast<Ogre::Technique*>(_native)->_notifyNeedsRecompile( );
	}
	
	Mogre::MaterialPtr^ Technique::GetShadowCasterMaterial( )
	{
		return static_cast<const Ogre::Technique*>(_native)->getShadowCasterMaterial( );
	}
	
	void Technique::SetShadowCasterMaterial( Mogre::MaterialPtr^ val )
	{
		static_cast<Ogre::Technique*>(_native)->setShadowCasterMaterial( (Ogre::MaterialPtr)val );
	}
	
	void Technique::SetShadowCasterMaterial( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::Technique*>(_native)->setShadowCasterMaterial( o_name );
	}
	
	Mogre::MaterialPtr^ Technique::GetShadowReceiverMaterial( )
	{
		return static_cast<const Ogre::Technique*>(_native)->getShadowReceiverMaterial( );
	}
	
	void Technique::SetShadowReceiverMaterial( Mogre::MaterialPtr^ val )
	{
		static_cast<Ogre::Technique*>(_native)->setShadowReceiverMaterial( (Ogre::MaterialPtr)val );
	}
	
	void Technique::SetShadowReceiverMaterial( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::Technique*>(_native)->setShadowReceiverMaterial( o_name );
	}
	
	void Technique::SetPointSize( Mogre::Real ps )
	{
		static_cast<Ogre::Technique*>(_native)->setPointSize( ps );
	}
	
	void Technique::SetAmbient( Mogre::Real red, Mogre::Real green, Mogre::Real blue )
	{
		static_cast<Ogre::Technique*>(_native)->setAmbient( red, green, blue );
	}
	
	void Technique::SetAmbient( Mogre::ColourValue ambient )
	{
		static_cast<Ogre::Technique*>(_native)->setAmbient( ambient );
	}
	
	void Technique::SetDiffuse( Mogre::Real red, Mogre::Real green, Mogre::Real blue, Mogre::Real alpha )
	{
		static_cast<Ogre::Technique*>(_native)->setDiffuse( red, green, blue, alpha );
	}
	
	void Technique::SetDiffuse( Mogre::ColourValue diffuse )
	{
		static_cast<Ogre::Technique*>(_native)->setDiffuse( diffuse );
	}
	
	void Technique::SetSpecular( Mogre::Real red, Mogre::Real green, Mogre::Real blue, Mogre::Real alpha )
	{
		static_cast<Ogre::Technique*>(_native)->setSpecular( red, green, blue, alpha );
	}
	
	void Technique::SetSpecular( Mogre::ColourValue specular )
	{
		static_cast<Ogre::Technique*>(_native)->setSpecular( specular );
	}
	
	void Technique::SetShininess( Mogre::Real val )
	{
		static_cast<Ogre::Technique*>(_native)->setShininess( val );
	}
	
	void Technique::SetSelfIllumination( Mogre::Real red, Mogre::Real green, Mogre::Real blue )
	{
		static_cast<Ogre::Technique*>(_native)->setSelfIllumination( red, green, blue );
	}
	
	void Technique::SetSelfIllumination( Mogre::ColourValue selfIllum )
	{
		static_cast<Ogre::Technique*>(_native)->setSelfIllumination( selfIllum );
	}
	
	void Technique::SetDepthCheckEnabled( bool enabled )
	{
		static_cast<Ogre::Technique*>(_native)->setDepthCheckEnabled( enabled );
	}
	
	void Technique::SetDepthWriteEnabled( bool enabled )
	{
		static_cast<Ogre::Technique*>(_native)->setDepthWriteEnabled( enabled );
	}
	
	void Technique::SetDepthFunction( Mogre::CompareFunction func )
	{
		static_cast<Ogre::Technique*>(_native)->setDepthFunction( (Ogre::CompareFunction)func );
	}
	
	void Technique::SetColourWriteEnabled( bool enabled )
	{
		static_cast<Ogre::Technique*>(_native)->setColourWriteEnabled( enabled );
	}
	
	void Technique::SetCullingMode( Mogre::CullingMode mode )
	{
		static_cast<Ogre::Technique*>(_native)->setCullingMode( (Ogre::CullingMode)mode );
	}
	
	void Technique::SetManualCullingMode( Mogre::ManualCullingMode mode )
	{
		static_cast<Ogre::Technique*>(_native)->setManualCullingMode( (Ogre::ManualCullingMode)mode );
	}
	
	void Technique::SetLightingEnabled( bool enabled )
	{
		static_cast<Ogre::Technique*>(_native)->setLightingEnabled( enabled );
	}
	
	void Technique::SetShadingMode( Mogre::ShadeOptions mode )
	{
		static_cast<Ogre::Technique*>(_native)->setShadingMode( (Ogre::ShadeOptions)mode );
	}
	
	void Technique::SetFog( bool overrideScene, Mogre::FogMode mode, Mogre::ColourValue colour, Mogre::Real expDensity, Mogre::Real linearStart, Mogre::Real linearEnd )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene, (Ogre::FogMode)mode, colour, expDensity, linearStart, linearEnd );
	}
	void Technique::SetFog( bool overrideScene, Mogre::FogMode mode, Mogre::ColourValue colour, Mogre::Real expDensity, Mogre::Real linearStart )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene, (Ogre::FogMode)mode, colour, expDensity, linearStart );
	}
	void Technique::SetFog( bool overrideScene, Mogre::FogMode mode, Mogre::ColourValue colour, Mogre::Real expDensity )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene, (Ogre::FogMode)mode, colour, expDensity );
	}
	void Technique::SetFog( bool overrideScene, Mogre::FogMode mode, Mogre::ColourValue colour )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene, (Ogre::FogMode)mode, colour );
	}
	void Technique::SetFog( bool overrideScene, Mogre::FogMode mode )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene, (Ogre::FogMode)mode );
	}
	void Technique::SetFog( bool overrideScene )
	{
		static_cast<Ogre::Technique*>(_native)->setFog( overrideScene );
	}
	
	void Technique::SetDepthBias( float constantBias, float slopeScaleBias )
	{
		static_cast<Ogre::Technique*>(_native)->setDepthBias( constantBias, slopeScaleBias );
	}
	
	void Technique::SetTextureFiltering( Mogre::TextureFilterOptions filterType )
	{
		static_cast<Ogre::Technique*>(_native)->setTextureFiltering( (Ogre::TextureFilterOptions)filterType );
	}
	
	void Technique::SetTextureAnisotropy( unsigned int maxAniso )
	{
		static_cast<Ogre::Technique*>(_native)->setTextureAnisotropy( maxAniso );
	}
	
	void Technique::SetSceneBlending( Mogre::SceneBlendType sbt )
	{
		static_cast<Ogre::Technique*>(_native)->setSceneBlending( (Ogre::SceneBlendType)sbt );
	}
	
	void Technique::SetSeparateSceneBlending( Mogre::SceneBlendType sbt, Mogre::SceneBlendType sbta )
	{
		static_cast<Ogre::Technique*>(_native)->setSeparateSceneBlending( (Ogre::SceneBlendType)sbt, (Ogre::SceneBlendType)sbta );
	}
	
	void Technique::SetSceneBlending( Mogre::SceneBlendFactor sourceFactor, Mogre::SceneBlendFactor destFactor )
	{
		static_cast<Ogre::Technique*>(_native)->setSceneBlending( (Ogre::SceneBlendFactor)sourceFactor, (Ogre::SceneBlendFactor)destFactor );
	}
	
	void Technique::SetSeparateSceneBlending( Mogre::SceneBlendFactor sourceFactor, Mogre::SceneBlendFactor destFactor, Mogre::SceneBlendFactor sourceFactorAlpha, Mogre::SceneBlendFactor destFactorAlpha )
	{
		static_cast<Ogre::Technique*>(_native)->setSeparateSceneBlending( (Ogre::SceneBlendFactor)sourceFactor, (Ogre::SceneBlendFactor)destFactor, (Ogre::SceneBlendFactor)sourceFactorAlpha, (Ogre::SceneBlendFactor)destFactorAlpha );
	}
	
	unsigned short Technique::_getSchemeIndex( )
	{
		return static_cast<const Ogre::Technique*>(_native)->_getSchemeIndex( );
	}
	
	bool Technique::ApplyTextureAliases( Mogre::Const_AliasTextureNamePairList^ aliasList, bool apply )
	{
		return static_cast<const Ogre::Technique*>(_native)->applyTextureAliases( aliasList, apply );
	}
	bool Technique::ApplyTextureAliases( Mogre::Const_AliasTextureNamePairList^ aliasList )
	{
		return static_cast<const Ogre::Technique*>(_native)->applyTextureAliases( aliasList );
	}
	
	void Technique::AddGPUVendorRule( Mogre::GPUVendor vendor, Mogre::Technique::IncludeOrExclude includeOrExclude )
	{
		static_cast<Ogre::Technique*>(_native)->addGPUVendorRule( (Ogre::GPUVendor)vendor, (Ogre::Technique::IncludeOrExclude)includeOrExclude );
	}
	
	void Technique::AddGPUVendorRule( Mogre::Technique::GPUVendorRule^ rule )
	{
		static_cast<Ogre::Technique*>(_native)->addGPUVendorRule( rule );
	}
	
	void Technique::RemoveGPUVendorRule( Mogre::GPUVendor vendor )
	{
		static_cast<Ogre::Technique*>(_native)->removeGPUVendorRule( (Ogre::GPUVendor)vendor );
	}
	
	Mogre::Technique::GPUVendorRuleIterator^ Technique::GetGPUVendorRuleIterator( )
	{
		return static_cast<const Ogre::Technique*>(_native)->getGPUVendorRuleIterator( );
	}
	
	void Technique::AddGPUDeviceNameRule( String^ devicePattern, Mogre::Technique::IncludeOrExclude includeOrExclude, bool caseSensitive )
	{
		DECLARE_NATIVE_STRING( o_devicePattern, devicePattern )
	
		static_cast<Ogre::Technique*>(_native)->addGPUDeviceNameRule( o_devicePattern, (Ogre::Technique::IncludeOrExclude)includeOrExclude, caseSensitive );
	}
	void Technique::AddGPUDeviceNameRule( String^ devicePattern, Mogre::Technique::IncludeOrExclude includeOrExclude )
	{
		DECLARE_NATIVE_STRING( o_devicePattern, devicePattern )
	
		static_cast<Ogre::Technique*>(_native)->addGPUDeviceNameRule( o_devicePattern, (Ogre::Technique::IncludeOrExclude)includeOrExclude );
	}
	
	void Technique::AddGPUDeviceNameRule( Mogre::Technique::GPUDeviceNameRule^ rule )
	{
		static_cast<Ogre::Technique*>(_native)->addGPUDeviceNameRule( rule );
	}
	
	void Technique::RemoveGPUDeviceNameRule( String^ devicePattern )
	{
		DECLARE_NATIVE_STRING( o_devicePattern, devicePattern )
	
		static_cast<Ogre::Technique*>(_native)->removeGPUDeviceNameRule( o_devicePattern );
	}
	
	Mogre::Technique::GPUDeviceNameRuleIterator^ Technique::GetGPUDeviceNameRuleIterator( )
	{
		return static_cast<const Ogre::Technique*>(_native)->getGPUDeviceNameRuleIterator( );
	}
	
	
	//Protected Declarations
	
	
	

}
