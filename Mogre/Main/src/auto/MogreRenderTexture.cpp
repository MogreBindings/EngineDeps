/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderTexture.h"

namespace Mogre
{
	//################################################################
	//RenderTexture
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void RenderTexture::_Init_CLRObject( )
	{
		static_cast<Ogre::RenderTexture*>(_native)->_Init_CLRObject( );
	}
	
	void RenderTexture::CopyContentsToMemory( Mogre::PixelBox dst, Mogre::RenderTarget::FrameBuffer buffer )
	{
		static_cast<Ogre::RenderTexture*>(_native)->copyContentsToMemory( dst, (Ogre::RenderTarget::FrameBuffer)buffer );
	}
	
	Mogre::PixelFormat RenderTexture::SuggestPixelFormat( )
	{
		return (Mogre::PixelFormat)static_cast<const Ogre::RenderTexture*>(_native)->suggestPixelFormat( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_RenderTexture(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::RenderTexture(pClrObj);
	}
	
	//################################################################
	//MultiRenderTarget
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDTYPE Mogre::RenderTexture^
	#define STLDECL_NATIVETYPE Ogre::RenderTexture*
	CPP_DECLARE_STLVECTOR( MultiRenderTarget::, BoundSufaceList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	void MultiRenderTarget::_Init_CLRObject( )
	{
		static_cast<Ogre::MultiRenderTarget*>(_native)->_Init_CLRObject( );
	}
	
	void MultiRenderTarget::BindSurface( size_t attachment, Mogre::RenderTexture^ target )
	{
		static_cast<Ogre::MultiRenderTarget*>(_native)->bindSurface( attachment, target );
	}
	
	void MultiRenderTarget::UnbindSurface( size_t attachment )
	{
		static_cast<Ogre::MultiRenderTarget*>(_native)->unbindSurface( attachment );
	}
	
	void MultiRenderTarget::CopyContentsToMemory( Mogre::PixelBox dst, Mogre::RenderTarget::FrameBuffer buffer )
	{
		static_cast<Ogre::MultiRenderTarget*>(_native)->copyContentsToMemory( dst, (Ogre::RenderTarget::FrameBuffer)buffer );
	}
	
	Mogre::PixelFormat MultiRenderTarget::SuggestPixelFormat( )
	{
		return (Mogre::PixelFormat)static_cast<const Ogre::MultiRenderTarget*>(_native)->suggestPixelFormat( );
	}
	
	Mogre::MultiRenderTarget::Const_BoundSufaceList^ MultiRenderTarget::GetBoundSurfaceList( )
	{
		return static_cast<const Ogre::MultiRenderTarget*>(_native)->getBoundSurfaceList( );
	}
	
	Mogre::RenderTexture^ MultiRenderTarget::GetBoundSurface( size_t index )
	{
		return static_cast<Ogre::MultiRenderTarget*>(_native)->getBoundSurface( index );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_MultiRenderTarget(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::MultiRenderTarget(pClrObj);
	}
	

}
