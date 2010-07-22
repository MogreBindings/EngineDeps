/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreMaterialSerializer.h"
#include "MogreMaterial.h"
#include "MogreDataStream.h"

namespace Mogre
{
	//################################################################
	//MaterialSerializer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	MaterialSerializer::MaterialSerializer( )
	{
		_createdByCLR = true;
		_native = new Ogre::MaterialSerializer();
	}
	
	String^ MaterialSerializer::QueuedAsString::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::MaterialSerializer*>(_native)->getQueuedAsString( ) );
	}
	
	void MaterialSerializer::QueueForExport( Mogre::MaterialPtr^ pMat, bool clearQueued, bool exportDefaults, String^ materialName )
	{
		DECLARE_NATIVE_STRING( o_materialName, materialName )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->queueForExport( (const Ogre::MaterialPtr&)pMat, clearQueued, exportDefaults, o_materialName );
	}
	void MaterialSerializer::QueueForExport( Mogre::MaterialPtr^ pMat, bool clearQueued, bool exportDefaults )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->queueForExport( (const Ogre::MaterialPtr&)pMat, clearQueued, exportDefaults );
	}
	void MaterialSerializer::QueueForExport( Mogre::MaterialPtr^ pMat, bool clearQueued )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->queueForExport( (const Ogre::MaterialPtr&)pMat, clearQueued );
	}
	void MaterialSerializer::QueueForExport( Mogre::MaterialPtr^ pMat )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->queueForExport( (const Ogre::MaterialPtr&)pMat );
	}
	
	void MaterialSerializer::ExportQueued( String^ filename, bool includeProgDef, String^ programFilename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
		DECLARE_NATIVE_STRING( o_programFilename, programFilename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportQueued( o_filename, includeProgDef, o_programFilename );
	}
	void MaterialSerializer::ExportQueued( String^ filename, bool includeProgDef )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportQueued( o_filename, includeProgDef );
	}
	void MaterialSerializer::ExportQueued( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportQueued( o_filename );
	}
	
	void MaterialSerializer::ExportMaterial( Mogre::MaterialPtr^ pMat, String^ filename, bool exportDefaults, bool includeProgDef, String^ programFilename, String^ materialName )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
		DECLARE_NATIVE_STRING( o_programFilename, programFilename )
		DECLARE_NATIVE_STRING( o_materialName, materialName )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportMaterial( (const Ogre::MaterialPtr&)pMat, o_filename, exportDefaults, includeProgDef, o_programFilename, o_materialName );
	}
	void MaterialSerializer::ExportMaterial( Mogre::MaterialPtr^ pMat, String^ filename, bool exportDefaults, bool includeProgDef, String^ programFilename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
		DECLARE_NATIVE_STRING( o_programFilename, programFilename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportMaterial( (const Ogre::MaterialPtr&)pMat, o_filename, exportDefaults, includeProgDef, o_programFilename );
	}
	void MaterialSerializer::ExportMaterial( Mogre::MaterialPtr^ pMat, String^ filename, bool exportDefaults, bool includeProgDef )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportMaterial( (const Ogre::MaterialPtr&)pMat, o_filename, exportDefaults, includeProgDef );
	}
	void MaterialSerializer::ExportMaterial( Mogre::MaterialPtr^ pMat, String^ filename, bool exportDefaults )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportMaterial( (const Ogre::MaterialPtr&)pMat, o_filename, exportDefaults );
	}
	void MaterialSerializer::ExportMaterial( Mogre::MaterialPtr^ pMat, String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->exportMaterial( (const Ogre::MaterialPtr&)pMat, o_filename );
	}
	
	void MaterialSerializer::ClearQueue( )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->clearQueue( );
	}
	
	void MaterialSerializer::ParseScript( Mogre::DataStreamPtr^ stream, String^ groupName )
	{
		DECLARE_NATIVE_STRING( o_groupName, groupName )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->parseScript( (Ogre::DataStreamPtr&)stream, o_groupName );
	}
	
	void MaterialSerializer::BeginSection( unsigned short level, bool useMainBuffer )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->beginSection( level, useMainBuffer );
	}
	void MaterialSerializer::BeginSection( unsigned short level )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->beginSection( level );
	}
	
	void MaterialSerializer::EndSection( unsigned short level, bool useMainBuffer )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->endSection( level, useMainBuffer );
	}
	void MaterialSerializer::EndSection( unsigned short level )
	{
		static_cast<Ogre::MaterialSerializer*>(_native)->endSection( level );
	}
	
	void MaterialSerializer::WriteAttribute( unsigned short level, String^ att, bool useMainBuffer )
	{
		DECLARE_NATIVE_STRING( o_att, att )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeAttribute( level, o_att, useMainBuffer );
	}
	void MaterialSerializer::WriteAttribute( unsigned short level, String^ att )
	{
		DECLARE_NATIVE_STRING( o_att, att )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeAttribute( level, o_att );
	}
	
	void MaterialSerializer::WriteValue( String^ val, bool useMainBuffer )
	{
		DECLARE_NATIVE_STRING( o_val, val )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeValue( o_val, useMainBuffer );
	}
	void MaterialSerializer::WriteValue( String^ val )
	{
		DECLARE_NATIVE_STRING( o_val, val )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeValue( o_val );
	}
	
	void MaterialSerializer::WriteComment( unsigned short level, String^ comment, bool useMainBuffer )
	{
		DECLARE_NATIVE_STRING( o_comment, comment )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeComment( level, o_comment, useMainBuffer );
	}
	void MaterialSerializer::WriteComment( unsigned short level, String^ comment )
	{
		DECLARE_NATIVE_STRING( o_comment, comment )
	
		static_cast<Ogre::MaterialSerializer*>(_native)->writeComment( level, o_comment );
	}
	
	
	//Protected Declarations
	
	
	

}
