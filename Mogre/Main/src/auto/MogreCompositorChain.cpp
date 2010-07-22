/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreCompositorChain.h"
#include "MogreCompositorInstance.h"
#include "MogreViewport.h"
#include "MogreCompositor.h"

namespace Mogre
{
	//################################################################
	//CompositorChain
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDTYPE Mogre::CompositorInstance^
	#define STLDECL_NATIVETYPE Ogre::CompositorInstance*
	CPP_DECLARE_STLVECTOR( CompositorChain::, Instances, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	CPP_DECLARE_ITERATOR( CompositorChain::, InstanceIterator, Ogre::CompositorChain::InstanceIterator, Mogre::CompositorChain::Instances, Mogre::CompositorInstance^, Ogre::CompositorInstance*,  )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	CompositorChain::CompositorChain( Mogre::Viewport^ vp ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::CompositorChain( vp);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	size_t CompositorChain::LAST::get()
	{
		return Ogre::CompositorChain::LAST;
	}
	
	size_t CompositorChain::BEST::get()
	{
		return Ogre::CompositorChain::BEST;
	}
	
	size_t CompositorChain::NumCompositors::get()
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getNumCompositors( );
	}
	
	Mogre::Viewport^ CompositorChain::Viewport::get()
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getViewport( );
	}
	
	void CompositorChain::_Init_CLRObject( )
	{
		static_cast<Ogre::CompositorChain*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::CompositorInstance^ CompositorChain::AddCompositor( Mogre::CompositorPtr^ filter, size_t addPosition, String^ scheme )
	{
		DECLARE_NATIVE_STRING( o_scheme, scheme )
	
		return static_cast<Ogre::CompositorChain*>(_native)->addCompositor( (Ogre::CompositorPtr)filter, addPosition, o_scheme );
	}
	Mogre::CompositorInstance^ CompositorChain::AddCompositor( Mogre::CompositorPtr^ filter, size_t addPosition )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->addCompositor( (Ogre::CompositorPtr)filter, addPosition );
	}
	Mogre::CompositorInstance^ CompositorChain::AddCompositor( Mogre::CompositorPtr^ filter )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->addCompositor( (Ogre::CompositorPtr)filter );
	}
	
	void CompositorChain::RemoveCompositor( size_t position )
	{
		static_cast<Ogre::CompositorChain*>(_native)->removeCompositor( position );
	}
	void CompositorChain::RemoveCompositor( )
	{
		static_cast<Ogre::CompositorChain*>(_native)->removeCompositor( );
	}
	
	void CompositorChain::RemoveAllCompositors( )
	{
		static_cast<Ogre::CompositorChain*>(_native)->removeAllCompositors( );
	}
	
	Mogre::CompositorInstance^ CompositorChain::GetCompositor( size_t index )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getCompositor( index );
	}
	
	Mogre::CompositorInstance^ CompositorChain::GetCompositor( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::CompositorChain*>(_native)->getCompositor( o_name );
	}
	
	Mogre::CompositorInstance^ CompositorChain::_getOriginalSceneCompositor( )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->_getOriginalSceneCompositor( );
	}
	
	Mogre::CompositorChain::InstanceIterator^ CompositorChain::GetCompositors( )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getCompositors( );
	}
	
	void CompositorChain::SetCompositorEnabled( size_t position, bool state )
	{
		static_cast<Ogre::CompositorChain*>(_native)->setCompositorEnabled( position, state );
	}
	
	void CompositorChain::PreRenderTargetUpdate( Mogre::RenderTargetEvent_NativePtr evt )
	{
		static_cast<Ogre::CompositorChain*>(_native)->preRenderTargetUpdate( evt );
	}
	
	void CompositorChain::PostRenderTargetUpdate( Mogre::RenderTargetEvent_NativePtr evt )
	{
		static_cast<Ogre::CompositorChain*>(_native)->postRenderTargetUpdate( evt );
	}
	
	void CompositorChain::PreViewportUpdate( Mogre::RenderTargetViewportEvent_NativePtr evt )
	{
		static_cast<Ogre::CompositorChain*>(_native)->preViewportUpdate( evt );
	}
	
	void CompositorChain::PostViewportUpdate( Mogre::RenderTargetViewportEvent_NativePtr evt )
	{
		static_cast<Ogre::CompositorChain*>(_native)->postViewportUpdate( evt );
	}
	
	void CompositorChain::ViewportRemoved( Mogre::RenderTargetViewportEvent_NativePtr evt )
	{
		static_cast<Ogre::CompositorChain*>(_native)->viewportRemoved( evt );
	}
	
	void CompositorChain::_markDirty( )
	{
		static_cast<Ogre::CompositorChain*>(_native)->_markDirty( );
	}
	
	void CompositorChain::_notifyViewport( Mogre::Viewport^ vp )
	{
		static_cast<Ogre::CompositorChain*>(_native)->_notifyViewport( vp );
	}
	
	void CompositorChain::_removeInstance( Mogre::CompositorInstance^ i )
	{
		static_cast<Ogre::CompositorChain*>(_native)->_removeInstance( i );
	}
	
	void CompositorChain::_compile( )
	{
		static_cast<Ogre::CompositorChain*>(_native)->_compile( );
	}
	
	Mogre::CompositorInstance^ CompositorChain::GetPreviousInstance( Mogre::CompositorInstance^ curr, bool activeOnly )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getPreviousInstance( curr, activeOnly );
	}
	Mogre::CompositorInstance^ CompositorChain::GetPreviousInstance( Mogre::CompositorInstance^ curr )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getPreviousInstance( curr );
	}
	
	Mogre::CompositorInstance^ CompositorChain::GetNextInstance( Mogre::CompositorInstance^ curr, bool activeOnly )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getNextInstance( curr, activeOnly );
	}
	Mogre::CompositorInstance^ CompositorChain::GetNextInstance( Mogre::CompositorInstance^ curr )
	{
		return static_cast<Ogre::CompositorChain*>(_native)->getNextInstance( curr );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_CompositorChain(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::CompositorChain(pClrObj);
	}
	

}
