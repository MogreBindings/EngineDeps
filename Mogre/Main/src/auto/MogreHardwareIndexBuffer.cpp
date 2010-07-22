/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreHardwareIndexBuffer.h"
#include "MogreHardwareBufferManager.h"

namespace Mogre
{
	//################################################################
	//HardwareIndexBuffer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	size_t HardwareIndexBuffer::IndexSize::get()
	{
		return static_cast<const Ogre::HardwareIndexBuffer*>(_native)->getIndexSize( );
	}
	
	Mogre::HardwareBufferManagerBase^ HardwareIndexBuffer::Manager::get()
	{
		return static_cast<const Ogre::HardwareIndexBuffer*>(_native)->getManager( );
	}
	
	size_t HardwareIndexBuffer::NumIndexes::get()
	{
		return static_cast<const Ogre::HardwareIndexBuffer*>(_native)->getNumIndexes( );
	}
	
	Mogre::HardwareIndexBuffer::IndexType HardwareIndexBuffer::Type::get()
	{
		return (Mogre::HardwareIndexBuffer::IndexType)static_cast<const Ogre::HardwareIndexBuffer*>(_native)->getType( );
	}
	
	void HardwareIndexBuffer::_Init_CLRObject( )
	{
		static_cast<Ogre::HardwareIndexBuffer*>(_native)->_Init_CLRObject( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_HardwareIndexBuffer(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::HardwareIndexBuffer(pClrObj);
	}
	

}
