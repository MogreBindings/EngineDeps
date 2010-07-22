/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreMaterialManager.h"
#include "MogreDataStream.h"
#include "MogreMaterial.h"
#include "MogreTechnique.h"
#include "MogreRenderable.h"

namespace Mogre
{
	//################################################################
	//MaterialManager
	//################################################################
	
	//Nested Types
	//################################################################
	//IListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::MaterialManager::Listener* MaterialManager::Listener::_IListener_GetNativePtr()
	{
		return static_cast<Ogre::MaterialManager::Listener*>( static_cast<MaterialManager_Listener_Proxy*>(_native) );
	}
	
	
	//Public Declarations
	MaterialManager::Listener::Listener() : Wrapper( (CLRObject*)0 )
	{
		_createdByCLR = true;
		Type^ thisType = this->GetType();
		_isOverriden = true;  //it's abstract or interface so it must be overriden
		MaterialManager_Listener_Proxy* proxy = new MaterialManager_Listener_Proxy(this);
		proxy->_overriden = Implementation::SubclassingManager::Instance->GetOverridenMethodsArrayPointer(thisType, Listener::typeid, 0);
		_native = proxy;
	
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	
	
	//Protected Declarations
	
	
	
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	MaterialManager::MaterialManager( ) : ResourceManager((Ogre::ResourceManager*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::MaterialManager();
	}
	
	String^ MaterialManager::DEFAULT_SCHEME_NAME::get()
	{
		return TO_CLR_STRING( Ogre::MaterialManager::DEFAULT_SCHEME_NAME );
	}
	void MaterialManager::DEFAULT_SCHEME_NAME::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		Ogre::MaterialManager::DEFAULT_SCHEME_NAME = o_value;
	}
	
	String^ MaterialManager::ActiveScheme::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::MaterialManager*>(_native)->getActiveScheme( ) );
	}
	void MaterialManager::ActiveScheme::set( String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::MaterialManager*>(_native)->setActiveScheme( o_schemeName );
	}
	
	unsigned int MaterialManager::DefaultAnisotropy::get()
	{
		return static_cast<const Ogre::MaterialManager*>(_native)->getDefaultAnisotropy( );
	}
	void MaterialManager::DefaultAnisotropy::set( unsigned int maxAniso )
	{
		static_cast<Ogre::MaterialManager*>(_native)->setDefaultAnisotropy( maxAniso );
	}
	
	void MaterialManager::Initialise( )
	{
		static_cast<Ogre::MaterialManager*>(_native)->initialise( );
	}
	
	void MaterialManager::ParseScript( Mogre::DataStreamPtr^ stream, String^ groupName )
	{
		DECLARE_NATIVE_STRING( o_groupName, groupName )
	
		static_cast<Ogre::MaterialManager*>(_native)->parseScript( (Ogre::DataStreamPtr&)stream, o_groupName );
	}
	
	void MaterialManager::SetDefaultTextureFiltering( Mogre::TextureFilterOptions fo )
	{
		static_cast<Ogre::MaterialManager*>(_native)->setDefaultTextureFiltering( (Ogre::TextureFilterOptions)fo );
	}
	
	void MaterialManager::SetDefaultTextureFiltering( Mogre::FilterType ftype, Mogre::FilterOptions opts )
	{
		static_cast<Ogre::MaterialManager*>(_native)->setDefaultTextureFiltering( (Ogre::FilterType)ftype, (Ogre::FilterOptions)opts );
	}
	
	void MaterialManager::SetDefaultTextureFiltering( Mogre::FilterOptions minFilter, Mogre::FilterOptions magFilter, Mogre::FilterOptions mipFilter )
	{
		static_cast<Ogre::MaterialManager*>(_native)->setDefaultTextureFiltering( (Ogre::FilterOptions)minFilter, (Ogre::FilterOptions)magFilter, (Ogre::FilterOptions)mipFilter );
	}
	
	Mogre::FilterOptions MaterialManager::GetDefaultTextureFiltering( Mogre::FilterType ftype )
	{
		return (Mogre::FilterOptions)static_cast<const Ogre::MaterialManager*>(_native)->getDefaultTextureFiltering( (Ogre::FilterType)ftype );
	}
	
	Mogre::MaterialPtr^ MaterialManager::GetDefaultSettings( )
	{
		return static_cast<const Ogre::MaterialManager*>(_native)->getDefaultSettings( );
	}
	
	unsigned short MaterialManager::_getSchemeIndex( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::MaterialManager*>(_native)->_getSchemeIndex( o_name );
	}
	
	String^ MaterialManager::_getSchemeName( unsigned short index )
	{
		return TO_CLR_STRING( static_cast<Ogre::MaterialManager*>(_native)->_getSchemeName( index ) );
	}
	
	unsigned short MaterialManager::_getActiveSchemeIndex( )
	{
		return static_cast<const Ogre::MaterialManager*>(_native)->_getActiveSchemeIndex( );
	}
	
	void MaterialManager::AddListener( Mogre::MaterialManager::IListener^ l, String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::MaterialManager*>(_native)->addListener( l, o_schemeName );
	}
	void MaterialManager::AddListener( Mogre::MaterialManager::IListener^ l )
	{
		static_cast<Ogre::MaterialManager*>(_native)->addListener( l );
	}
	
	void MaterialManager::RemoveListener( Mogre::MaterialManager::IListener^ l, String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::MaterialManager*>(_native)->removeListener( l, o_schemeName );
	}
	void MaterialManager::RemoveListener( Mogre::MaterialManager::IListener^ l )
	{
		static_cast<Ogre::MaterialManager*>(_native)->removeListener( l );
	}
	
	Mogre::Technique^ MaterialManager::_arbitrateMissingTechniqueForActiveScheme( Mogre::Material^ mat, unsigned short lodIndex, Mogre::IRenderable^ rend )
	{
		return static_cast<Ogre::MaterialManager*>(_native)->_arbitrateMissingTechniqueForActiveScheme( mat, lodIndex, rend );
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//MaterialManager_Listener_Proxy
	//################################################################
	
	
	
	Ogre::Technique* MaterialManager_Listener_Proxy::handleSchemeNotFound( unsigned short schemeIndex, const Ogre::String& schemeName, Ogre::Material* originalMaterial, unsigned short lodIndex, const Ogre::Renderable* rend )
	{
		Mogre::Technique^ mp_return = _managed->HandleSchemeNotFound( schemeIndex, TO_CLR_STRING( schemeName ), originalMaterial, lodIndex, rend );
		return mp_return;
	}

}
