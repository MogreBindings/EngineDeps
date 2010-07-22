/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreLog.h"

namespace Mogre
{
	//################################################################
	//LogListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void LogListener_Director::messageLogged( const Ogre::String& message, Ogre::LogMessageLevel lml, bool maskDebug, const Ogre::String& logName )
	{
		if (doCallForMessageLogged)
		{
			_receiver->MessageLogged( TO_CLR_STRING( message ), (Mogre::LogMessageLevel)lml, maskDebug, TO_CLR_STRING( logName ) );
		}
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//Log
	//################################################################
	
	//Nested Types
	//################################################################
	//Stream
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Log::Stream::Stream( Mogre::Log^ target, Mogre::LogMessageLevel lml, bool maskDebug )
	{
		_createdByCLR = true;
		_native = new Ogre::Log::Stream( target, (Ogre::LogMessageLevel)lml, maskDebug);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Log::Stream::Stream( Mogre::Log::Stream^ rhs )
	{
		_createdByCLR = true;
		_native = new Ogre::Log::Stream( rhs);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle Log::Stream::_CLRHandle::get()
	{
		return static_cast<Ogre::Log::Stream*>(_native)->_CLRHandle;
	}
	void Log::Stream::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::Log::Stream*>(_native)->_CLRHandle = value;
	}
	
	
	//Protected Declarations
	
	
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Log::Log( String^ name, bool debugOutput, bool suppressFileOutput )
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
	
		_native = new Ogre::Log( o_name, debugOutput, suppressFileOutput);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Log::Log( String^ name, bool debugOutput )
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
	
		_native = new Ogre::Log( o_name, debugOutput);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	Log::Log( String^ name )
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
	
		_native = new Ogre::Log( o_name);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle Log::_CLRHandle::get()
	{
		return static_cast<Ogre::Log*>(_native)->_CLRHandle;
	}
	void Log::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::Log*>(_native)->_CLRHandle = value;
	}
	
	bool Log::IsDebugOutputEnabled::get()
	{
		return static_cast<const Ogre::Log*>(_native)->isDebugOutputEnabled( );
	}
	
	bool Log::IsFileOutputSuppressed::get()
	{
		return static_cast<const Ogre::Log*>(_native)->isFileOutputSuppressed( );
	}
	
	bool Log::IsTimeStampEnabled::get()
	{
		return static_cast<const Ogre::Log*>(_native)->isTimeStampEnabled( );
	}
	
	Mogre::LoggingLevel Log::LogDetail::get()
	{
		return (Mogre::LoggingLevel)static_cast<const Ogre::Log*>(_native)->getLogDetail( );
	}
	void Log::LogDetail::set( Mogre::LoggingLevel ll )
	{
		static_cast<Ogre::Log*>(_native)->setLogDetail( (Ogre::LoggingLevel)ll );
	}
	
	String^ Log::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Log*>(_native)->getName( ) );
	}
	
	void Log::LogMessage( String^ message, Mogre::LogMessageLevel lml, bool maskDebug )
	{
		DECLARE_NATIVE_STRING( o_message, message )
	
		static_cast<Ogre::Log*>(_native)->logMessage( o_message, (Ogre::LogMessageLevel)lml, maskDebug );
	}
	void Log::LogMessage( String^ message, Mogre::LogMessageLevel lml )
	{
		DECLARE_NATIVE_STRING( o_message, message )
	
		static_cast<Ogre::Log*>(_native)->logMessage( o_message, (Ogre::LogMessageLevel)lml );
	}
	void Log::LogMessage( String^ message )
	{
		DECLARE_NATIVE_STRING( o_message, message )
	
		static_cast<Ogre::Log*>(_native)->logMessage( o_message );
	}
	
	Mogre::Log::Stream^ Log::GetStream( Mogre::LogMessageLevel lml, bool maskDebug )
	{
		return static_cast<Ogre::Log*>(_native)->stream( (Ogre::LogMessageLevel)lml, maskDebug );
	}
	Mogre::Log::Stream^ Log::GetStream( Mogre::LogMessageLevel lml )
	{
		return static_cast<Ogre::Log*>(_native)->stream( (Ogre::LogMessageLevel)lml );
	}
	Mogre::Log::Stream^ Log::GetStream( )
	{
		return static_cast<Ogre::Log*>(_native)->stream( );
	}
	
	void Log::SetDebugOutputEnabled( bool debugOutput )
	{
		static_cast<Ogre::Log*>(_native)->setDebugOutputEnabled( debugOutput );
	}
	
	void Log::SetTimeStampEnabled( bool timeStamp )
	{
		static_cast<Ogre::Log*>(_native)->setTimeStampEnabled( timeStamp );
	}
	
	
	//Protected Declarations
	
	
	

}
