/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderSystemCapabilities.h"
#include "MogreLog.h"

namespace Mogre
{
	//################################################################
	//RenderSystemCapabilities
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDTYPE String^
	#define STLDECL_NATIVETYPE Ogre::String
	CPP_DECLARE_STLSET( RenderSystemCapabilities::, ShaderProfiles, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	RenderSystemCapabilities::RenderSystemCapabilities( )
	{
		_createdByCLR = true;
		_native = new Ogre::RenderSystemCapabilities();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle RenderSystemCapabilities::_CLRHandle::get()
	{
		return static_cast<Ogre::RenderSystemCapabilities*>(_native)->_CLRHandle;
	}
	void RenderSystemCapabilities::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->_CLRHandle = value;
	}
	
	String^ RenderSystemCapabilities::DeviceName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getDeviceName( ) );
	}
	void RenderSystemCapabilities::DeviceName::set( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setDeviceName( o_name );
	}
	
	Mogre::DriverVersion RenderSystemCapabilities::DriverVersion::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getDriverVersion( );
	}
	void RenderSystemCapabilities::DriverVersion::set( Mogre::DriverVersion version )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setDriverVersion( version );
	}
	
	Mogre::ushort RenderSystemCapabilities::FragmentProgramConstantBoolCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getFragmentProgramConstantBoolCount( );
	}
	void RenderSystemCapabilities::FragmentProgramConstantBoolCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setFragmentProgramConstantBoolCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::FragmentProgramConstantFloatCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getFragmentProgramConstantFloatCount( );
	}
	void RenderSystemCapabilities::FragmentProgramConstantFloatCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setFragmentProgramConstantFloatCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::FragmentProgramConstantIntCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getFragmentProgramConstantIntCount( );
	}
	void RenderSystemCapabilities::FragmentProgramConstantIntCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setFragmentProgramConstantIntCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::GeometryProgramConstantBoolCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getGeometryProgramConstantBoolCount( );
	}
	void RenderSystemCapabilities::GeometryProgramConstantBoolCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setGeometryProgramConstantBoolCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::GeometryProgramConstantFloatCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getGeometryProgramConstantFloatCount( );
	}
	void RenderSystemCapabilities::GeometryProgramConstantFloatCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setGeometryProgramConstantFloatCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::GeometryProgramConstantIntCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getGeometryProgramConstantIntCount( );
	}
	void RenderSystemCapabilities::GeometryProgramConstantIntCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setGeometryProgramConstantIntCount( c );
	}
	
	int RenderSystemCapabilities::GeometryProgramNumOutputVertices::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getGeometryProgramNumOutputVertices( );
	}
	void RenderSystemCapabilities::GeometryProgramNumOutputVertices::set( int numOutputVertices )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setGeometryProgramNumOutputVertices( numOutputVertices );
	}
	
	Mogre::Real RenderSystemCapabilities::MaxPointSize::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getMaxPointSize( );
	}
	void RenderSystemCapabilities::MaxPointSize::set( Mogre::Real s )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setMaxPointSize( s );
	}
	
	bool RenderSystemCapabilities::NonPOW2TexturesLimited::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNonPOW2TexturesLimited( );
	}
	void RenderSystemCapabilities::NonPOW2TexturesLimited::set( bool l )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNonPOW2TexturesLimited( l );
	}
	
	Mogre::ushort RenderSystemCapabilities::NumMultiRenderTargets::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNumMultiRenderTargets( );
	}
	void RenderSystemCapabilities::NumMultiRenderTargets::set( Mogre::ushort num )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNumMultiRenderTargets( num );
	}
	
	Mogre::ushort RenderSystemCapabilities::NumTextureUnits::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNumTextureUnits( );
	}
	void RenderSystemCapabilities::NumTextureUnits::set( Mogre::ushort num )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNumTextureUnits( num );
	}
	
	Mogre::ushort RenderSystemCapabilities::NumVertexBlendMatrices::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNumVertexBlendMatrices( );
	}
	void RenderSystemCapabilities::NumVertexBlendMatrices::set( Mogre::ushort num )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNumVertexBlendMatrices( num );
	}
	
	Mogre::ushort RenderSystemCapabilities::NumVertexTextureUnits::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNumVertexTextureUnits( );
	}
	void RenderSystemCapabilities::NumVertexTextureUnits::set( Mogre::ushort n )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNumVertexTextureUnits( n );
	}
	
	Mogre::ushort RenderSystemCapabilities::NumWorldMatrices::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getNumWorldMatrices( );
	}
	void RenderSystemCapabilities::NumWorldMatrices::set( Mogre::ushort num )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setNumWorldMatrices( num );
	}
	
	String^ RenderSystemCapabilities::RenderSystemName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getRenderSystemName( ) );
	}
	void RenderSystemCapabilities::RenderSystemName::set( String^ rs )
	{
		DECLARE_NATIVE_STRING( o_rs, rs )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setRenderSystemName( o_rs );
	}
	
	Mogre::ushort RenderSystemCapabilities::StencilBufferBitDepth::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getStencilBufferBitDepth( );
	}
	void RenderSystemCapabilities::StencilBufferBitDepth::set( Mogre::ushort num )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setStencilBufferBitDepth( num );
	}
	
	Mogre::GPUVendor RenderSystemCapabilities::Vendor::get()
	{
		return (Mogre::GPUVendor)static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getVendor( );
	}
	void RenderSystemCapabilities::Vendor::set( Mogre::GPUVendor v )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setVendor( (Ogre::GPUVendor)v );
	}
	
	Mogre::ushort RenderSystemCapabilities::VertexProgramConstantBoolCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getVertexProgramConstantBoolCount( );
	}
	void RenderSystemCapabilities::VertexProgramConstantBoolCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setVertexProgramConstantBoolCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::VertexProgramConstantFloatCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getVertexProgramConstantFloatCount( );
	}
	void RenderSystemCapabilities::VertexProgramConstantFloatCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setVertexProgramConstantFloatCount( c );
	}
	
	Mogre::ushort RenderSystemCapabilities::VertexProgramConstantIntCount::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getVertexProgramConstantIntCount( );
	}
	void RenderSystemCapabilities::VertexProgramConstantIntCount::set( Mogre::ushort c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setVertexProgramConstantIntCount( c );
	}
	
	bool RenderSystemCapabilities::VertexTextureUnitsShared::get()
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getVertexTextureUnitsShared( );
	}
	void RenderSystemCapabilities::VertexTextureUnitsShared::set( bool shared )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setVertexTextureUnitsShared( shared );
	}
	
	size_t RenderSystemCapabilities::CalculateSize( )
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->calculateSize( );
	}
	
	void RenderSystemCapabilities::ParseDriverVersionFromString( String^ versionString )
	{
		DECLARE_NATIVE_STRING( o_versionString, versionString )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->parseDriverVersionFromString( o_versionString );
	}
	
	void RenderSystemCapabilities::ParseVendorFromString( String^ vendorString )
	{
		DECLARE_NATIVE_STRING( o_vendorString, vendorString )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->parseVendorFromString( o_vendorString );
	}
	
	bool RenderSystemCapabilities::IsDriverOlderThanVersion( Mogre::DriverVersion v )
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->isDriverOlderThanVersion( v );
	}
	
	bool RenderSystemCapabilities::IsCapabilityRenderSystemSpecific( Mogre::Capabilities c )
	{
		return static_cast<Ogre::RenderSystemCapabilities*>(_native)->isCapabilityRenderSystemSpecific( (Ogre::Capabilities)c );
	}
	
	void RenderSystemCapabilities::SetCapability( Mogre::Capabilities c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setCapability( (Ogre::Capabilities)c );
	}
	
	void RenderSystemCapabilities::UnsetCapability( Mogre::Capabilities c )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->unsetCapability( (Ogre::Capabilities)c );
	}
	
	bool RenderSystemCapabilities::HasCapability( Mogre::Capabilities c )
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->hasCapability( (Ogre::Capabilities)c );
	}
	
	void RenderSystemCapabilities::AddShaderProfile( String^ profile )
	{
		DECLARE_NATIVE_STRING( o_profile, profile )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->addShaderProfile( o_profile );
	}
	
	void RenderSystemCapabilities::RemoveShaderProfile( String^ profile )
	{
		DECLARE_NATIVE_STRING( o_profile, profile )
	
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->removeShaderProfile( o_profile );
	}
	
	bool RenderSystemCapabilities::IsShaderProfileSupported( String^ profile )
	{
		DECLARE_NATIVE_STRING( o_profile, profile )
	
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->isShaderProfileSupported( o_profile );
	}
	
	Mogre::RenderSystemCapabilities::Const_ShaderProfiles^ RenderSystemCapabilities::GetSupportedShaderProfiles( )
	{
		return static_cast<const Ogre::RenderSystemCapabilities*>(_native)->getSupportedShaderProfiles( );
	}
	
	void RenderSystemCapabilities::SetCategoryRelevant( Mogre::CapabilitiesCategory cat, bool relevant )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->setCategoryRelevant( (Ogre::CapabilitiesCategory)cat, relevant );
	}
	
	bool RenderSystemCapabilities::IsCategoryRelevant( Mogre::CapabilitiesCategory cat )
	{
		return static_cast<Ogre::RenderSystemCapabilities*>(_native)->isCategoryRelevant( (Ogre::CapabilitiesCategory)cat );
	}
	
	void RenderSystemCapabilities::Log( Mogre::Log^ pLog )
	{
		static_cast<Ogre::RenderSystemCapabilities*>(_native)->log( pLog );
	}
	
	Mogre::GPUVendor RenderSystemCapabilities::VendorFromString( String^ vendorString )
	{
		DECLARE_NATIVE_STRING( o_vendorString, vendorString )
	
		return (Mogre::GPUVendor)Ogre::RenderSystemCapabilities::vendorFromString( o_vendorString );
	}
	
	String^ RenderSystemCapabilities::VendorToString( Mogre::GPUVendor v )
	{
		return TO_CLR_STRING( Ogre::RenderSystemCapabilities::vendorToString( (Ogre::GPUVendor)v ) );
	}
	
	
	//Protected Declarations
	
	
	

}
