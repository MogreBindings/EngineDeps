/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderable.h"
#include "MogreTechnique.h"
#include "MogreUserObjectBindings.h"
#include "MogreSceneManager.h"
#include "MogreRenderSystem.h"
#include "MogreGpuProgramParams.h"
#include "MogreMaterial.h"
#include "MogreRenderOperation.h"
#include "MogreCamera.h"
#include "MogreCommon.h"

namespace Mogre
{
	//################################################################
	//IRenderable
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDKEY size_t
	#define STLDECL_MANAGEDVALUE Mogre::Vector4
	#define STLDECL_NATIVEKEY size_t
	#define STLDECL_NATIVEVALUE Ogre::Vector4
	CPP_DECLARE_STLMAP( Renderable::, CustomParameterMap, STLDECL_MANAGEDKEY, STLDECL_MANAGEDVALUE, STLDECL_NATIVEKEY, STLDECL_NATIVEVALUE )
	#undef STLDECL_MANAGEDKEY
	#undef STLDECL_MANAGEDVALUE
	#undef STLDECL_NATIVEKEY
	#undef STLDECL_NATIVEVALUE
	
	//Private Declarations
	
	//Internal Declarations
	Ogre::Renderable* Renderable::_IRenderable_GetNativePtr()
	{
		return static_cast<Ogre::Renderable*>( static_cast<Renderable_Proxy*>(_native) );
	}
	
	
	//Public Declarations
	Renderable::Renderable( ) : Wrapper( (CLRObject*)0 )
	{
		_createdByCLR = true;
		Type^ thisType = this->GetType();
		_isOverriden = true;  //it's abstract or interface so it must be overriden
		Renderable_Proxy* proxy = new Renderable_Proxy(this);
		proxy->_overriden = Implementation::SubclassingManager::Instance->GetOverridenMethodsArrayPointer(thisType, Renderable::typeid, 8);
		_native = proxy;
	
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	bool Renderable::CastsShadows::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getCastsShadows( );
	}
	
	unsigned short Renderable::NumWorldTransforms::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getNumWorldTransforms( );
	}
	
	bool Renderable::PolygonModeOverrideable::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getPolygonModeOverrideable( );
	}
	void Renderable::PolygonModeOverrideable::set( bool override )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::setPolygonModeOverrideable( override );
	}
	
	Mogre::Technique^ Renderable::Technique::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getTechnique( );
	}
	
	bool Renderable::UseIdentityProjection::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getUseIdentityProjection( );
	}
	void Renderable::UseIdentityProjection::set( bool useIdentityProjection )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::setUseIdentityProjection( useIdentityProjection );
	}
	
	bool Renderable::UseIdentityView::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getUseIdentityView( );
	}
	void Renderable::UseIdentityView::set( bool useIdentityView )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::setUseIdentityView( useIdentityView );
	}
	
	Mogre::UserObjectBindings^ Renderable::UserObjectBindings::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getUserObjectBindings( );
	}
	
	
	
	bool Renderable::PreRender( Mogre::SceneManager^ sm, Mogre::RenderSystem^ rsys )
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::preRender( sm, rsys );
	}
	
	void Renderable::PostRender( Mogre::SceneManager^ sm, Mogre::RenderSystem^ rsys )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::postRender( sm, rsys );
	}
	
	
	
	
	void Renderable::SetCustomParameter( size_t index, Mogre::Vector4 value )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::setCustomParameter( index, value );
	}
	
	Mogre::Vector4 Renderable::GetCustomParameter( size_t index )
	{
		return static_cast<Renderable_Proxy*>(_native)->Renderable::getCustomParameter( index );
	}
	
	void Renderable::_updateCustomGpuParameter( Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr constantEntry, Mogre::GpuProgramParameters^ params )
	{
		static_cast<Renderable_Proxy*>(_native)->Renderable::_updateCustomGpuParameter( constantEntry, params );
	}
	
	
	//Protected Declarations
	Mogre::Renderable::CustomParameterMap^ Renderable::mCustomParameters::get()
	{
		return ( CLR_NULL == _mCustomParameters ) ? (_mCustomParameters = static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mCustomParameters) : _mCustomParameters;
	}
	
	bool Renderable::mPolygonModeOverrideable::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mPolygonModeOverrideable;
	}
	void Renderable::mPolygonModeOverrideable::set( bool value )
	{
		static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mPolygonModeOverrideable = value;
	}
	
	bool Renderable::mUseIdentityProjection::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUseIdentityProjection;
	}
	void Renderable::mUseIdentityProjection::set( bool value )
	{
		static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUseIdentityProjection = value;
	}
	
	bool Renderable::mUseIdentityView::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUseIdentityView;
	}
	void Renderable::mUseIdentityView::set( bool value )
	{
		static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUseIdentityView = value;
	}
	
	Mogre::UserObjectBindings^ Renderable::mUserObjectBindings::get()
	{
		return static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUserObjectBindings;
	}
	void Renderable::mUserObjectBindings::set( Mogre::UserObjectBindings^ value )
	{
		static_cast<Renderable_Proxy*>(_native)->Ogre::Renderable::mUserObjectBindings = value;
	}
	
	
	
	
	
	//################################################################
	//Renderable_Proxy
	//################################################################
	
	
	
	const Ogre::MaterialPtr& Renderable_Proxy::getMaterial( ) const
	{
		Mogre::MaterialPtr^ mp_return = _managed->GetMaterial( );
		return (const Ogre::MaterialPtr&)mp_return;
	}
	
	Ogre::Technique* Renderable_Proxy::getTechnique( ) const
	{
		if (_overriden[ 0 ])
		{
			Mogre::Technique^ mp_return = _managed->Technique;
			return mp_return;
		}
		else
			return Renderable::getTechnique( );
	}
	
	void Renderable_Proxy::getRenderOperation( Ogre::RenderOperation& op )
	{
		_managed->GetRenderOperation( op );
	}
	
	bool Renderable_Proxy::preRender( Ogre::SceneManager* sm, Ogre::RenderSystem* rsys )
	{
		if (_overriden[ 1 ])
		{
			bool mp_return = _managed->PreRender( sm, rsys );
			return mp_return;
		}
		else
			return Renderable::preRender( sm, rsys );
	}
	
	void Renderable_Proxy::postRender( Ogre::SceneManager* sm, Ogre::RenderSystem* rsys )
	{
		if (_overriden[ 2 ])
		{
			_managed->PostRender( sm, rsys );
		}
		else
			Renderable::postRender( sm, rsys );
	}
	
	void Renderable_Proxy::getWorldTransforms( Ogre::Matrix4* xform ) const
	{
		_managed->GetWorldTransforms( reinterpret_cast<Mogre::Matrix4::NativeValue*>(xform) );
	}
	
	unsigned short Renderable_Proxy::getNumWorldTransforms( ) const
	{
		if (_overriden[ 3 ])
		{
			unsigned short mp_return = _managed->NumWorldTransforms;
			return mp_return;
		}
		else
			return Renderable::getNumWorldTransforms( );
	}
	
	Ogre::Real Renderable_Proxy::getSquaredViewDepth( const Ogre::Camera* cam ) const
	{
		Mogre::Real mp_return = _managed->GetSquaredViewDepth( cam );
		return mp_return;
	}
	
	const Ogre::LightList& Renderable_Proxy::getLights( ) const
	{
		Mogre::Const_LightList^ mp_return = _managed->GetLights( );
		return mp_return;
	}
	
	bool Renderable_Proxy::getCastsShadows( ) const
	{
		if (_overriden[ 4 ])
		{
			bool mp_return = _managed->CastsShadows;
			return mp_return;
		}
		else
			return Renderable::getCastsShadows( );
	}
	
	void Renderable_Proxy::_updateCustomGpuParameter( const Ogre::GpuProgramParameters::AutoConstantEntry& constantEntry, Ogre::GpuProgramParameters* params ) const
	{
		if (_overriden[ 5 ])
		{
			_managed->_updateCustomGpuParameter( constantEntry, params );
		}
		else
			Renderable::_updateCustomGpuParameter( constantEntry, params );
	}
	
	void Renderable_Proxy::setPolygonModeOverrideable( bool override )
	{
		if (_overriden[ 6 ])
		{
			_managed->PolygonModeOverrideable = override;
		}
		else
			Renderable::setPolygonModeOverrideable( override );
	}
	
	bool Renderable_Proxy::getPolygonModeOverrideable( ) const
	{
		if (_overriden[ 7 ])
		{
			bool mp_return = _managed->PolygonModeOverrideable;
			return mp_return;
		}
		else
			return Renderable::getPolygonModeOverrideable( );
	}

}
