/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreFileSystem.h"
#include "MogreDataStream.h"
#include "MogreStringVector.h"
#include "MogreArchive.h"

namespace Mogre
{
	//################################################################
	//FileSystemArchive
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	FileSystemArchive::FileSystemArchive( String^ name, String^ archType ) : Archive((CLRObject*) 0)
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_archType, archType )
	
		_native = new Ogre::FileSystemArchive( o_name, o_archType);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	bool FileSystemArchive::ms_IgnoreHidden::get()
	{
		return Ogre::FileSystemArchive::ms_IgnoreHidden;
	}
	void FileSystemArchive::ms_IgnoreHidden::set( bool value )
	{
		Ogre::FileSystemArchive::ms_IgnoreHidden = value;
	}
	
	bool FileSystemArchive::IgnoreHidden::get()
	{
		return Ogre::FileSystemArchive::getIgnoreHidden( );
	}
	void FileSystemArchive::IgnoreHidden::set( bool ignore )
	{
		Ogre::FileSystemArchive::setIgnoreHidden( ignore );
	}
	
	bool FileSystemArchive::IsCaseSensitive::get()
	{
		return static_cast<const Ogre::FileSystemArchive*>(_native)->isCaseSensitive( );
	}
	
	void FileSystemArchive::_Init_CLRObject( )
	{
		static_cast<Ogre::FileSystemArchive*>(_native)->_Init_CLRObject( );
	}
	
	void FileSystemArchive::Load( )
	{
		static_cast<Ogre::FileSystemArchive*>(_native)->load( );
	}
	
	void FileSystemArchive::Unload( )
	{
		static_cast<Ogre::FileSystemArchive*>(_native)->unload( );
	}
	
	Mogre::DataStreamPtr^ FileSystemArchive::Open( String^ filename, bool readOnly )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		return static_cast<const Ogre::FileSystemArchive*>(_native)->open( o_filename, readOnly );
	}
	Mogre::DataStreamPtr^ FileSystemArchive::Open( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		return static_cast<const Ogre::FileSystemArchive*>(_native)->open( o_filename );
	}
	
	Mogre::DataStreamPtr^ FileSystemArchive::Create( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		return static_cast<const Ogre::FileSystemArchive*>(_native)->create( o_filename );
	}
	
	void FileSystemArchive::Remove( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<const Ogre::FileSystemArchive*>(_native)->remove( o_filename );
	}
	
	Mogre::StringVectorPtr^ FileSystemArchive::List( bool recursive, bool dirs )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->list( recursive, dirs );
	}
	Mogre::StringVectorPtr^ FileSystemArchive::List( bool recursive )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->list( recursive );
	}
	Mogre::StringVectorPtr^ FileSystemArchive::List( )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->list( );
	}
	
	Mogre::FileInfoListPtr^ FileSystemArchive::ListFileInfo( bool recursive, bool dirs )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->listFileInfo( recursive, dirs );
	}
	Mogre::FileInfoListPtr^ FileSystemArchive::ListFileInfo( bool recursive )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->listFileInfo( recursive );
	}
	Mogre::FileInfoListPtr^ FileSystemArchive::ListFileInfo( )
	{
		return static_cast<Ogre::FileSystemArchive*>(_native)->listFileInfo( );
	}
	
	Mogre::StringVectorPtr^ FileSystemArchive::Find( String^ pattern, bool recursive, bool dirs )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->find( o_pattern, recursive, dirs );
	}
	Mogre::StringVectorPtr^ FileSystemArchive::Find( String^ pattern, bool recursive )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->find( o_pattern, recursive );
	}
	Mogre::StringVectorPtr^ FileSystemArchive::Find( String^ pattern )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->find( o_pattern );
	}
	
	Mogre::FileInfoListPtr^ FileSystemArchive::FindFileInfo( String^ pattern, bool recursive, bool dirs )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->findFileInfo( o_pattern, recursive, dirs );
	}
	Mogre::FileInfoListPtr^ FileSystemArchive::FindFileInfo( String^ pattern, bool recursive )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->findFileInfo( o_pattern, recursive );
	}
	Mogre::FileInfoListPtr^ FileSystemArchive::FindFileInfo( String^ pattern )
	{
		DECLARE_NATIVE_STRING( o_pattern, pattern )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->findFileInfo( o_pattern );
	}
	
	bool FileSystemArchive::Exists( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->exists( o_filename );
	}
	
	time_t FileSystemArchive::GetModifiedTime( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		return static_cast<Ogre::FileSystemArchive*>(_native)->getModifiedTime( o_filename );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_FileSystemArchive(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::FileSystemArchive(pClrObj);
	}
	

}
