/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreLodStrategyManager.h"
#include "MogreLodStrategy.h"

namespace Mogre
{
	//################################################################
	//LodStrategyManager
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	LodStrategyManager::LodStrategyManager( )
	{
		_createdByCLR = true;
		_native = new Ogre::LodStrategyManager();
	}
	
	Mogre::LodStrategy^ LodStrategyManager::DefaultStrategy::get()
	{
		return static_cast<Ogre::LodStrategyManager*>(_native)->getDefaultStrategy( );
	}
	void LodStrategyManager::DefaultStrategy::set( Mogre::LodStrategy^ strategy )
	{
		static_cast<Ogre::LodStrategyManager*>(_native)->setDefaultStrategy( strategy );
	}
	
	void LodStrategyManager::AddStrategy( Mogre::LodStrategy^ strategy )
	{
		static_cast<Ogre::LodStrategyManager*>(_native)->addStrategy( strategy );
	}
	
	Mogre::LodStrategy^ LodStrategyManager::RemoveStrategy( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::LodStrategyManager*>(_native)->removeStrategy( o_name );
	}
	
	void LodStrategyManager::RemoveAllStrategies( )
	{
		static_cast<Ogre::LodStrategyManager*>(_native)->removeAllStrategies( );
	}
	
	Mogre::LodStrategy^ LodStrategyManager::GetStrategy( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::LodStrategyManager*>(_native)->getStrategy( o_name );
	}
	
	void LodStrategyManager::SetDefaultStrategy( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::LodStrategyManager*>(_native)->setDefaultStrategy( o_name );
	}
	
	
	//Protected Declarations
	
	
	

}
