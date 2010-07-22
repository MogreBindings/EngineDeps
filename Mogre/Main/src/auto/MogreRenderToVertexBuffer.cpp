/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderToVertexBuffer.h"
#include "MogreRenderable.h"
#include "MogreHardwareVertexBuffer.h"
#include "MogreRenderOperation.h"
#include "MogreSceneManager.h"
#include "MogreMaterial.h"

namespace Mogre
{
	//################################################################
	//RenderToVertexBuffer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	unsigned int RenderToVertexBuffer::MaxVertexCount::get()
	{
		return static_cast<const Ogre::RenderToVertexBuffer*>(_native)->getMaxVertexCount( );
	}
	void RenderToVertexBuffer::MaxVertexCount::set( unsigned int maxVertexCount )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->setMaxVertexCount( maxVertexCount );
	}
	
	Mogre::RenderOperation::OperationTypes RenderToVertexBuffer::OperationType::get()
	{
		return (Mogre::RenderOperation::OperationTypes)static_cast<const Ogre::RenderToVertexBuffer*>(_native)->getOperationType( );
	}
	void RenderToVertexBuffer::OperationType::set( Mogre::RenderOperation::OperationTypes operationType )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->setOperationType( (Ogre::RenderOperation::OperationType)operationType );
	}
	
	bool RenderToVertexBuffer::ResetsEveryUpdate::get()
	{
		return static_cast<const Ogre::RenderToVertexBuffer*>(_native)->getResetsEveryUpdate( );
	}
	void RenderToVertexBuffer::ResetsEveryUpdate::set( bool resetsEveryUpdate )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->setResetsEveryUpdate( resetsEveryUpdate );
	}
	
	Mogre::IRenderable^ RenderToVertexBuffer::SourceRenderable::get()
	{
		return static_cast<const Ogre::RenderToVertexBuffer*>(_native)->getSourceRenderable( );
	}
	void RenderToVertexBuffer::SourceRenderable::set( Mogre::IRenderable^ source )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->setSourceRenderable( source );
	}
	
	Mogre::VertexDeclaration^ RenderToVertexBuffer::VertexDeclaration::get()
	{
		return static_cast<Ogre::RenderToVertexBuffer*>(_native)->getVertexDeclaration( );
	}
	
	void RenderToVertexBuffer::_Init_CLRObject( )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->_Init_CLRObject( );
	}
	
	void RenderToVertexBuffer::GetRenderOperation( Mogre::RenderOperation^ op )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->getRenderOperation( op );
	}
	
	void RenderToVertexBuffer::Update( Mogre::SceneManager^ sceneMgr )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->update( sceneMgr );
	}
	
	void RenderToVertexBuffer::Reset( )
	{
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->reset( );
	}
	
	Mogre::MaterialPtr^ RenderToVertexBuffer::GetRenderToBufferMaterial( )
	{
		return static_cast<Ogre::RenderToVertexBuffer*>(_native)->getRenderToBufferMaterial( );
	}
	
	void RenderToVertexBuffer::SetRenderToBufferMaterialName( String^ materialName )
	{
		DECLARE_NATIVE_STRING( o_materialName, materialName )
	
		static_cast<Ogre::RenderToVertexBuffer*>(_native)->setRenderToBufferMaterialName( o_materialName );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_RenderToVertexBuffer(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::RenderToVertexBuffer(pClrObj);
	}
	

}
