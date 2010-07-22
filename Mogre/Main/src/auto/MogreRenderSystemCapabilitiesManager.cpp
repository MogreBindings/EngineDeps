/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderSystemCapabilitiesManager.h"
#include "MogreRenderSystemCapabilities.h"

namespace Mogre
{
	//################################################################
	//RenderSystemCapabilitiesManager
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	RenderSystemCapabilitiesManager::RenderSystemCapabilitiesManager( )
	{
		_createdByCLR = true;
		_native = new Ogre::RenderSystemCapabilitiesManager();
	}
	
	void RenderSystemCapabilitiesManager::ParseCapabilitiesFromArchive( String^ filename, String^ archiveType, bool recursive )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
		DECLARE_NATIVE_STRING( o_archiveType, archiveType )
	
		static_cast<Ogre::RenderSystemCapabilitiesManager*>(_native)->parseCapabilitiesFromArchive( o_filename, o_archiveType, recursive );
	}
	void RenderSystemCapabilitiesManager::ParseCapabilitiesFromArchive( String^ filename, String^ archiveType )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
		DECLARE_NATIVE_STRING( o_archiveType, archiveType )
	
		static_cast<Ogre::RenderSystemCapabilitiesManager*>(_native)->parseCapabilitiesFromArchive( o_filename, o_archiveType );
	}
	
	Mogre::RenderSystemCapabilities^ RenderSystemCapabilitiesManager::LoadParsedCapabilities( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::RenderSystemCapabilitiesManager*>(_native)->loadParsedCapabilities( o_name );
	}
	
	void RenderSystemCapabilitiesManager::_addRenderSystemCapabilities( String^ name, Mogre::RenderSystemCapabilities^ caps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::RenderSystemCapabilitiesManager*>(_native)->_addRenderSystemCapabilities( o_name, caps );
	}
	
	
	//Protected Declarations
	
	
	

}
