/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreMeshSerializer.h"
#include "MogreMesh.h"
#include "MogreDataStream.h"

namespace Mogre
{
	//################################################################
	//MeshSerializer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	MeshSerializer::MeshSerializer( ) : Serializer((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::MeshSerializer();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::IMeshSerializerListener^ MeshSerializer::Listener::get()
	{
		return static_cast<Ogre::MeshSerializer*>(_native)->getListener( );
	}
	void MeshSerializer::Listener::set( Mogre::IMeshSerializerListener^ listener )
	{
		static_cast<Ogre::MeshSerializer*>(_native)->setListener( listener );
	}
	
	void MeshSerializer::_Init_CLRObject( )
	{
		static_cast<Ogre::MeshSerializer*>(_native)->_Init_CLRObject( );
	}
	
	void MeshSerializer::ExportMesh( Mogre::Mesh^ pMesh, String^ filename, Mogre::Serializer::Endian endianMode )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MeshSerializer*>(_native)->exportMesh( pMesh, o_filename, (Ogre::Serializer::Endian)endianMode );
	}
	void MeshSerializer::ExportMesh( Mogre::Mesh^ pMesh, String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::MeshSerializer*>(_native)->exportMesh( pMesh, o_filename );
	}
	
	void MeshSerializer::ImportMesh( Mogre::DataStreamPtr^ stream, Mogre::Mesh^ pDest )
	{
		static_cast<Ogre::MeshSerializer*>(_native)->importMesh( (Ogre::DataStreamPtr&)stream, pDest );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_MeshSerializer(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::MeshSerializer(pClrObj);
	}
	
	//################################################################
	//IMeshSerializerListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::MeshSerializerListener* MeshSerializerListener::_IMeshSerializerListener_GetNativePtr()
	{
		return static_cast<Ogre::MeshSerializerListener*>( static_cast<MeshSerializerListener_Proxy*>(_native) );
	}
	
	
	//Public Declarations
	MeshSerializerListener::MeshSerializerListener() : Wrapper( (CLRObject*)0 )
	{
		_createdByCLR = true;
		Type^ thisType = this->GetType();
		_isOverriden = true;  //it's abstract or interface so it must be overriden
		MeshSerializerListener_Proxy* proxy = new MeshSerializerListener_Proxy(this);
		proxy->_overriden = Implementation::SubclassingManager::Instance->GetOverridenMethodsArrayPointer(thisType, MeshSerializerListener::typeid, 0);
		_native = proxy;
	
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	
	
	
	//Protected Declarations
	
	
	
	
	//################################################################
	//MeshSerializerListener_Proxy
	//################################################################
	
	
	
	void MeshSerializerListener_Proxy::processMaterialName( Ogre::Mesh* mesh, Ogre::String* name )
	{
		_managed->ProcessMaterialName( mesh, gcnew array<String^> { (name ? TO_CLR_STRING( *name ) : String::Empty) } );
	}
	
	void MeshSerializerListener_Proxy::processSkeletonName( Ogre::Mesh* mesh, Ogre::String* name )
	{
		_managed->ProcessSkeletonName( mesh, gcnew array<String^> { (name ? TO_CLR_STRING( *name ) : String::Empty) } );
	}

}
