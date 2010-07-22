/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreProfiler.h"
#include "Mogre-WIN32_OgreTimerImp.h"

namespace Mogre
{
	//################################################################
	//Profiler
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Profiler::Profiler( )
	{
		_createdByCLR = true;
		_native = new Ogre::Profiler();
	}
	
	bool Profiler::Enabled::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getEnabled( );
	}
	void Profiler::Enabled::set( bool enabled )
	{
		static_cast<Ogre::Profiler*>(_native)->setEnabled( enabled );
	}
	
	Mogre::Real Profiler::OverlayHeight::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getOverlayHeight( );
	}
	
	Mogre::Real Profiler::OverlayLeft::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getOverlayLeft( );
	}
	
	Mogre::Real Profiler::OverlayTop::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getOverlayTop( );
	}
	
	Mogre::Real Profiler::OverlayWidth::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getOverlayWidth( );
	}
	
	Mogre::uint32 Profiler::ProfileGroupMask::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getProfileGroupMask( );
	}
	void Profiler::ProfileGroupMask::set( Mogre::uint32 mask )
	{
		static_cast<Ogre::Profiler*>(_native)->setProfileGroupMask( mask );
	}
	
	Mogre::Timer^ Profiler::Timer::get()
	{
		return static_cast<Ogre::Profiler*>(_native)->getTimer( );
	}
	void Profiler::Timer::set( Mogre::Timer^ t )
	{
		static_cast<Ogre::Profiler*>(_native)->setTimer( t );
	}
	
	Mogre::uint Profiler::UpdateDisplayFrequency::get()
	{
		return static_cast<const Ogre::Profiler*>(_native)->getUpdateDisplayFrequency( );
	}
	void Profiler::UpdateDisplayFrequency::set( Mogre::uint freq )
	{
		static_cast<Ogre::Profiler*>(_native)->setUpdateDisplayFrequency( freq );
	}
	
	void Profiler::BeginProfile( String^ profileName, Mogre::uint32 groupID )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->beginProfile( o_profileName, groupID );
	}
	void Profiler::BeginProfile( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->beginProfile( o_profileName );
	}
	
	void Profiler::EndProfile( String^ profileName, Mogre::uint32 groupID )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->endProfile( o_profileName, groupID );
	}
	void Profiler::EndProfile( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->endProfile( o_profileName );
	}
	
	void Profiler::EnableProfile( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->enableProfile( o_profileName );
	}
	
	void Profiler::DisableProfile( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		static_cast<Ogre::Profiler*>(_native)->disableProfile( o_profileName );
	}
	
	bool Profiler::WatchForMax( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		return static_cast<Ogre::Profiler*>(_native)->watchForMax( o_profileName );
	}
	
	bool Profiler::WatchForMin( String^ profileName )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		return static_cast<Ogre::Profiler*>(_native)->watchForMin( o_profileName );
	}
	
	bool Profiler::WatchForLimit( String^ profileName, Mogre::Real limit, bool greaterThan )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		return static_cast<Ogre::Profiler*>(_native)->watchForLimit( o_profileName, limit, greaterThan );
	}
	bool Profiler::WatchForLimit( String^ profileName, Mogre::Real limit )
	{
		DECLARE_NATIVE_STRING( o_profileName, profileName )
	
		return static_cast<Ogre::Profiler*>(_native)->watchForLimit( o_profileName, limit );
	}
	
	void Profiler::LogResults( )
	{
		static_cast<Ogre::Profiler*>(_native)->logResults( );
	}
	
	void Profiler::Reset( )
	{
		static_cast<Ogre::Profiler*>(_native)->reset( );
	}
	
	void Profiler::SetDisplayMode( Mogre::Profiler::DisplayMode d )
	{
		static_cast<Ogre::Profiler*>(_native)->setDisplayMode( (Ogre::Profiler::DisplayMode)d );
	}
	
	Mogre::Profiler::DisplayMode Profiler::GetDisplayMode( )
	{
		return (Mogre::Profiler::DisplayMode)static_cast<const Ogre::Profiler*>(_native)->getDisplayMode( );
	}
	
	void Profiler::SetOverlayDimensions( Mogre::Real width, Mogre::Real height )
	{
		static_cast<Ogre::Profiler*>(_native)->setOverlayDimensions( width, height );
	}
	
	void Profiler::SetOverlayPosition( Mogre::Real left, Mogre::Real top )
	{
		static_cast<Ogre::Profiler*>(_native)->setOverlayPosition( left, top );
	}
	
	
	//Protected Declarations
	
	
	

}
