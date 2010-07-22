/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreDefaultHardwareBufferManager.h"
#include "MogreHardwareVertexBuffer.h"
#include "MogreHardwareIndexBuffer.h"
#include "MogreRenderToVertexBuffer.h"

namespace Mogre
{
	//################################################################
	//DefaultHardwareBufferManagerBase
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	DefaultHardwareBufferManagerBase::DefaultHardwareBufferManagerBase( ) : HardwareBufferManagerBase((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::DefaultHardwareBufferManagerBase();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void DefaultHardwareBufferManagerBase::_Init_CLRObject( )
	{
		static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::HardwareVertexBufferSharedPtr^ DefaultHardwareBufferManagerBase::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareVertexBufferSharedPtr^ DefaultHardwareBufferManagerBase::CreateVertexBuffer( size_t vertexSize, size_t numVerts, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->createVertexBuffer( vertexSize, numVerts, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::HardwareIndexBufferSharedPtr^ DefaultHardwareBufferManagerBase::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage, bool useShadowBuffer )
	{
		return static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage, useShadowBuffer );
	}
	Mogre::HardwareIndexBufferSharedPtr^ DefaultHardwareBufferManagerBase::CreateIndexBuffer( Mogre::HardwareIndexBuffer::IndexType itype, size_t numIndexes, Mogre::HardwareBuffer::Usage usage )
	{
		return static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->createIndexBuffer( (Ogre::HardwareIndexBuffer::IndexType)itype, numIndexes, (Ogre::HardwareBuffer::Usage)usage );
	}
	
	Mogre::RenderToVertexBufferSharedPtr^ DefaultHardwareBufferManagerBase::CreateRenderToVertexBuffer( )
	{
		return static_cast<Ogre::DefaultHardwareBufferManagerBase*>(_native)->createRenderToVertexBuffer( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_DefaultHardwareBufferManagerBase(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::DefaultHardwareBufferManagerBase(pClrObj);
	}
	
	//################################################################
	//DefaultHardwareBufferManager
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	DefaultHardwareBufferManager::DefaultHardwareBufferManager( ) : HardwareBufferManager((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::DefaultHardwareBufferManager();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_DefaultHardwareBufferManager(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::DefaultHardwareBufferManager(pClrObj);
	}
	

}
