/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreResource.h"
#include "MogreStringInterface.h"
#include "MogreResourceManager.h"
#include "MogreCommon.h"

namespace Mogre
{
	//################################################################
	//Listener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	void Resource_Listener_Director::backgroundLoadingComplete( Ogre::Resource* param1 )
	{
		if (doCallForBackgroundLoadingComplete)
		{
			_receiver->BackgroundLoadingComplete( param1 );
		}
	}
	
	void Resource_Listener_Director::backgroundPreparingComplete( Ogre::Resource* param1 )
	{
		if (doCallForBackgroundPreparingComplete)
		{
			_receiver->BackgroundPreparingComplete( param1 );
		}
	}
	
	void Resource_Listener_Director::loadingComplete( Ogre::Resource* param1 )
	{
		if (doCallForLoadingComplete)
		{
			_receiver->LoadingComplete( param1 );
		}
	}
	
	void Resource_Listener_Director::preparingComplete( Ogre::Resource* param1 )
	{
		if (doCallForPreparingComplete)
		{
			_receiver->PreparingComplete( param1 );
		}
	}
	
	void Resource_Listener_Director::unloadingComplete( Ogre::Resource* param1 )
	{
		if (doCallForUnloadingComplete)
		{
			_receiver->UnloadingComplete( param1 );
		}
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//Resource
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::StringInterface* Resource::_IStringInterface_GetNativePtr()
	{
		return static_cast<Ogre::StringInterface*>( static_cast<Ogre::Resource*>(_native) );
	}
	
	
	//Public Declarations
	Mogre::ResourceManager^ Resource::Creator::get()
	{
		return static_cast<Ogre::Resource*>(_native)->getCreator( );
	}
	
	String^ Resource::Group::get()
	{
		return TO_CLR_STRING( static_cast<Ogre::Resource*>(_native)->getGroup( ) );
	}
	
	Mogre::ResourceHandle Resource::Handle::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->getHandle( );
	}
	
	bool Resource::IsBackgroundLoaded::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isBackgroundLoaded( );
	}
	
	bool Resource::IsLoaded::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isLoaded( );
	}
	
	bool Resource::IsLoading::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isLoading( );
	}
	
	bool Resource::IsManuallyLoaded::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isManuallyLoaded( );
	}
	
	bool Resource::IsPrepared::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isPrepared( );
	}
	
	bool Resource::IsReloadable::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->isReloadable( );
	}
	
	String^ Resource::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Resource*>(_native)->getName( ) );
	}
	
	String^ Resource::Origin::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Resource*>(_native)->getOrigin( ) );
	}
	
	size_t Resource::Size::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->getSize( );
	}
	
	size_t Resource::StateCount::get()
	{
		return static_cast<const Ogre::Resource*>(_native)->getStateCount( );
	}
	
	void Resource::_Init_CLRObject( )
	{
		static_cast<Ogre::Resource*>(_native)->_Init_CLRObject( );
	}
	
	void Resource::Prepare( bool backgroundThread )
	{
		static_cast<Ogre::Resource*>(_native)->prepare( backgroundThread );
	}
	void Resource::Prepare( )
	{
		static_cast<Ogre::Resource*>(_native)->prepare( );
	}
	
	void Resource::Load( bool backgroundThread )
	{
		static_cast<Ogre::Resource*>(_native)->load( backgroundThread );
	}
	void Resource::Load( )
	{
		static_cast<Ogre::Resource*>(_native)->load( );
	}
	
	void Resource::Reload( )
	{
		static_cast<Ogre::Resource*>(_native)->reload( );
	}
	
	void Resource::Unload( )
	{
		static_cast<Ogre::Resource*>(_native)->unload( );
	}
	
	void Resource::Touch( )
	{
		static_cast<Ogre::Resource*>(_native)->touch( );
	}
	
	Mogre::Resource::LoadingState Resource::GetLoadingState( )
	{
		return (Mogre::Resource::LoadingState)static_cast<const Ogre::Resource*>(_native)->getLoadingState( );
	}
	
	void Resource::SetBackgroundLoaded( bool bl )
	{
		static_cast<Ogre::Resource*>(_native)->setBackgroundLoaded( bl );
	}
	
	void Resource::EscalateLoading( )
	{
		static_cast<Ogre::Resource*>(_native)->escalateLoading( );
	}
	
	void Resource::ChangeGroupOwnership( String^ newGroup )
	{
		DECLARE_NATIVE_STRING( o_newGroup, newGroup )
	
		static_cast<Ogre::Resource*>(_native)->changeGroupOwnership( o_newGroup );
	}
	
	void Resource::_notifyOrigin( String^ origin )
	{
		DECLARE_NATIVE_STRING( o_origin, origin )
	
		static_cast<Ogre::Resource*>(_native)->_notifyOrigin( o_origin );
	}
	
	void Resource::_dirtyState( )
	{
		static_cast<Ogre::Resource*>(_native)->_dirtyState( );
	}
	
	void Resource::_fireLoadingComplete( bool wasBackgroundLoaded )
	{
		static_cast<Ogre::Resource*>(_native)->_fireLoadingComplete( wasBackgroundLoaded );
	}
	
	void Resource::_firePreparingComplete( bool wasBackgroundLoaded )
	{
		static_cast<Ogre::Resource*>(_native)->_firePreparingComplete( wasBackgroundLoaded );
	}
	
	void Resource::_fireUnloadingComplete( )
	{
		static_cast<Ogre::Resource*>(_native)->_fireUnloadingComplete( );
	}
	
	//------------------------------------------------------------
	// Implementation for IStringInterface
	//------------------------------------------------------------
	
	Mogre::ParamDictionary_NativePtr Resource::ParamDictionary::get()
	{
		return static_cast<Ogre::Resource*>(_native)->getParamDictionary( );
	}
	
	Mogre::Const_ParameterList^ Resource::GetParameters( )
	{
		return static_cast<const Ogre::Resource*>(_native)->getParameters( );
	}
	
	bool Resource::SetParameter( String^ name, String^ value )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_value, value )
	
		return static_cast<Ogre::Resource*>(_native)->setParameter( o_name, o_value );
	}
	
	void Resource::SetParameterList( Mogre::Const_NameValuePairList^ paramList )
	{
		static_cast<Ogre::Resource*>(_native)->setParameterList( paramList );
	}
	
	String^ Resource::GetParameter( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return TO_CLR_STRING( static_cast<const Ogre::Resource*>(_native)->getParameter( o_name ) );
	}
	
	void Resource::CopyParametersTo( Mogre::IStringInterface^ dest )
	{
		static_cast<const Ogre::Resource*>(_native)->copyParametersTo( dest );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Resource(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Resource(pClrObj);
	}
	
	//################################################################
	//IManualResourceLoader
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::ManualResourceLoader* ManualResourceLoader::_IManualResourceLoader_GetNativePtr()
	{
		return static_cast<Ogre::ManualResourceLoader*>( static_cast<ManualResourceLoader_Proxy*>(_native) );
	}
	
	
	//Public Declarations
	ManualResourceLoader::ManualResourceLoader( ) : Wrapper( (CLRObject*)0 )
	{
		_createdByCLR = true;
		Type^ thisType = this->GetType();
		_isOverriden = true;  //it's abstract or interface so it must be overriden
		ManualResourceLoader_Proxy* proxy = new ManualResourceLoader_Proxy(this);
		proxy->_overriden = Implementation::SubclassingManager::Instance->GetOverridenMethodsArrayPointer(thisType, ManualResourceLoader::typeid, 1);
		_native = proxy;
	
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void ManualResourceLoader::PrepareResource( Mogre::Resource^ resource )
	{
		static_cast<ManualResourceLoader_Proxy*>(_native)->ManualResourceLoader::prepareResource( resource );
	}
	
	
	
	//Protected Declarations
	
	
	
	
	//################################################################
	//ManualResourceLoader_Proxy
	//################################################################
	
	
	
	void ManualResourceLoader_Proxy::prepareResource( Ogre::Resource* resource )
	{
		if (_overriden[ 0 ])
		{
			_managed->PrepareResource( resource );
		}
		else
			ManualResourceLoader::prepareResource( resource );
	}
	
	void ManualResourceLoader_Proxy::loadResource( Ogre::Resource* resource )
	{
		_managed->LoadResource( resource );
	}

}
