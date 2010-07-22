/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreHardwareBufferManager.h"
#include "MogreHardwareVertexBuffer.h"
#include "MogreHardwareIndexBuffer.h"
#include "MogreRenderToVertexBuffer.h"

namespace Mogre
{
	//################################################################
	//HardwareBufferManagerBase
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void HardwareBufferManagerBase::_Init_CLRObject( )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::HardwareVertexBufferSharedPtr^ HardwareBufferManagerBase::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareVertexBufferSharedPtr^ HardwareBufferManagerBase::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::HardwareIndexBufferSharedPtr^ HardwareBufferManagerBase::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareIndexBufferSharedPtr^ HardwareBufferManagerBase::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::RenderToVertexBufferSharedPtr^ HardwareBufferManagerBase::CreateRenderToVertexBuffer( )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createRenderToVertexBuffer( );
	}
	
	Mogre::VertexDeclaration^ HardwareBufferManagerBase::CreateVertexDeclaration( )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createVertexDeclaration( );
	}
	
	void HardwareBufferManagerBase::DestroyVertexDeclaration( Mogre::VertexDeclaration^ decl )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->destroyVertexDeclaration( decl );
	}
	
	Mogre::VertexBufferBinding^ HardwareBufferManagerBase::CreateVertexBufferBinding( )
	{
		return static_cast<Ogre::HardwareBufferManagerBase*>(_native)->createVertexBufferBinding( );
	}
	
	void HardwareBufferManagerBase::DestroyVertexBufferBinding( Mogre::VertexBufferBinding^ binding )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->destroyVertexBufferBinding( binding );
	}
	
	void HardwareBufferManagerBase::RegisterVertexBufferSourceAndCopy( Mogre::HardwareVertexBufferSharedPtr^ sourceBuffer, Mogre::HardwareVertexBufferSharedPtr^ copy )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->registerVertexBufferSourceAndCopy( (const Ogre::HardwareVertexBufferSharedPtr&)sourceBuffer, (const Ogre::HardwareVertexBufferSharedPtr&)copy );
	}
	
	void HardwareBufferManagerBase::ReleaseVertexBufferCopy( Mogre::HardwareVertexBufferSharedPtr^ bufferCopy )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->releaseVertexBufferCopy( (const Ogre::HardwareVertexBufferSharedPtr&)bufferCopy );
	}
	
	void HardwareBufferManagerBase::TouchVertexBufferCopy( Mogre::HardwareVertexBufferSharedPtr^ bufferCopy )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->touchVertexBufferCopy( (const Ogre::HardwareVertexBufferSharedPtr&)bufferCopy );
	}
	
	void HardwareBufferManagerBase::_freeUnusedBufferCopies( )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_freeUnusedBufferCopies( );
	}
	
	void HardwareBufferManagerBase::_releaseBufferCopies( bool forceFreeUnused )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_releaseBufferCopies( forceFreeUnused );
	}
	void HardwareBufferManagerBase::_releaseBufferCopies( )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_releaseBufferCopies( );
	}
	
	void HardwareBufferManagerBase::_forceReleaseBufferCopies( Mogre::HardwareVertexBufferSharedPtr^ sourceBuffer )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_forceReleaseBufferCopies( (const Ogre::HardwareVertexBufferSharedPtr&)sourceBuffer );
	}
	
	void HardwareBufferManagerBase::_forceReleaseBufferCopies( Mogre::HardwareVertexBuffer^ sourceBuffer )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_forceReleaseBufferCopies( sourceBuffer );
	}
	
	void HardwareBufferManagerBase::_notifyVertexBufferDestroyed( Mogre::HardwareVertexBuffer^ buf )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_notifyVertexBufferDestroyed( buf );
	}
	
	void HardwareBufferManagerBase::_notifyIndexBufferDestroyed( Mogre::HardwareIndexBuffer^ buf )
	{
		static_cast<Ogre::HardwareBufferManagerBase*>(_native)->_notifyIndexBufferDestroyed( buf );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_HardwareBufferManagerBase(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::HardwareBufferManagerBase(pClrObj);
	}
	
	//################################################################
	//HardwareBufferManager
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	void HardwareBufferManager::_Init_CLRObject( )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::HardwareVertexBufferSharedPtr^ HardwareBufferManager::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareVertexBufferSharedPtr^ HardwareBufferManager::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::HardwareIndexBufferSharedPtr^ HardwareBufferManager::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareIndexBufferSharedPtr^ HardwareBufferManager::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::RenderToVertexBufferSharedPtr^ HardwareBufferManager::CreateRenderToVertexBuffer( )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createRenderToVertexBuffer( );
	}
	
	Mogre::VertexDeclaration^ HardwareBufferManager::CreateVertexDeclaration( )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createVertexDeclaration( );
	}
	
	void HardwareBufferManager::DestroyVertexDeclaration( Mogre::VertexDeclaration^ decl )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->destroyVertexDeclaration( decl );
	}
	
	Mogre::VertexBufferBinding^ HardwareBufferManager::CreateVertexBufferBinding( )
	{
		return static_cast<Ogre::HardwareBufferManager*>(_native)->createVertexBufferBinding( );
	}
	
	void HardwareBufferManager::DestroyVertexBufferBinding( Mogre::VertexBufferBinding^ binding )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->destroyVertexBufferBinding( binding );
	}
	
	void HardwareBufferManager::RegisterVertexBufferSourceAndCopy( Mogre::HardwareVertexBufferSharedPtr^ sourceBuffer, Mogre::HardwareVertexBufferSharedPtr^ copy )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->registerVertexBufferSourceAndCopy( (const Ogre::HardwareVertexBufferSharedPtr&)sourceBuffer, (const Ogre::HardwareVertexBufferSharedPtr&)copy );
	}
	
	void HardwareBufferManager::ReleaseVertexBufferCopy( Mogre::HardwareVertexBufferSharedPtr^ bufferCopy )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->releaseVertexBufferCopy( (const Ogre::HardwareVertexBufferSharedPtr&)bufferCopy );
	}
	
	void HardwareBufferManager::TouchVertexBufferCopy( Mogre::HardwareVertexBufferSharedPtr^ bufferCopy )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->touchVertexBufferCopy( (const Ogre::HardwareVertexBufferSharedPtr&)bufferCopy );
	}
	
	void HardwareBufferManager::_freeUnusedBufferCopies( )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_freeUnusedBufferCopies( );
	}
	
	void HardwareBufferManager::_releaseBufferCopies( bool forceFreeUnused )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_releaseBufferCopies( forceFreeUnused );
	}
	void HardwareBufferManager::_releaseBufferCopies( )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_releaseBufferCopies( );
	}
	
	void HardwareBufferManager::_notifyVertexBufferDestroyed( Mogre::HardwareVertexBuffer^ buf )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_notifyVertexBufferDestroyed( buf );
	}
	
	void HardwareBufferManager::_notifyIndexBufferDestroyed( Mogre::HardwareIndexBuffer^ buf )
	{
		static_cast<Ogre::HardwareBufferManager*>(_native)->_notifyIndexBufferDestroyed( buf );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_HardwareBufferManager(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::HardwareBufferManager(pClrObj);
	}
	

}
