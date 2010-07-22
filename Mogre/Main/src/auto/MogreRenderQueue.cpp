/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreRenderQueue.h"
#include "MogreRenderQueueSortingGrouping.h"
#include "MogreRenderable.h"
#include "MogreMovableObject.h"
#include "MogreCamera.h"
#include "MogreTechnique.h"

namespace Mogre
{
	//################################################################
	//RenderQueue
	//################################################################
	
	//Nested Types
	//################################################################
	//IRenderableListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::RenderQueue::RenderableListener* RenderQueue::RenderableListener::_IRenderableListener_GetNativePtr()
	{
		return static_cast<Ogre::RenderQueue::RenderableListener*>( static_cast<RenderQueue_RenderableListener_Proxy*>(_native) );
	}
	
	
	//Public Declarations
	RenderQueue::RenderableListener::RenderableListener( ) : Wrapper( (CLRObject*)0 )
	{
		_createdByCLR = true;
		Type^ thisType = this->GetType();
		_isOverriden = true;  //it's abstract or interface so it must be overriden
		RenderQueue_RenderableListener_Proxy* proxy = new RenderQueue_RenderableListener_Proxy(this);
		proxy->_overriden = Implementation::SubclassingManager::Instance->GetOverridenMethodsArrayPointer(thisType, RenderableListener::typeid, 0);
		_native = proxy;
	
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	
	
	//Protected Declarations
	
	
	
	
	#define STLDECL_MANAGEDKEY Mogre::uint8
	#define STLDECL_MANAGEDVALUE Mogre::RenderQueueGroup^
	#define STLDECL_NATIVEKEY Ogre::uint8
	#define STLDECL_NATIVEVALUE Ogre::RenderQueueGroup*
	CPP_DECLARE_STLMAP( RenderQueue::, RenderQueueGroupMap, STLDECL_MANAGEDKEY, STLDECL_MANAGEDVALUE, STLDECL_NATIVEKEY, STLDECL_NATIVEVALUE )
	#undef STLDECL_MANAGEDKEY
	#undef STLDECL_MANAGEDVALUE
	#undef STLDECL_NATIVEKEY
	#undef STLDECL_NATIVEVALUE
	
	CPP_DECLARE_MAP_ITERATOR( RenderQueue::, QueueGroupIterator, Ogre::RenderQueue::QueueGroupIterator, Mogre::RenderQueue::RenderQueueGroupMap, Mogre::RenderQueueGroup^, Ogre::RenderQueueGroup*, Mogre::uint8, Ogre::uint8,  )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	RenderQueue::RenderQueue( ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::RenderQueue();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::uint8 RenderQueue::DefaultQueueGroup::get()
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getDefaultQueueGroup( );
	}
	void RenderQueue::DefaultQueueGroup::set( Mogre::uint8 grp )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setDefaultQueueGroup( grp );
	}
	
	Mogre::ushort RenderQueue::DefaultRenderablePriority::get()
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getDefaultRenderablePriority( );
	}
	void RenderQueue::DefaultRenderablePriority::set( Mogre::ushort priority )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setDefaultRenderablePriority( priority );
	}
	
	bool RenderQueue::ShadowCastersCannotBeReceivers::get()
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getShadowCastersCannotBeReceivers( );
	}
	void RenderQueue::ShadowCastersCannotBeReceivers::set( bool ind )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setShadowCastersCannotBeReceivers( ind );
	}
	
	bool RenderQueue::SplitNoShadowPasses::get()
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getSplitNoShadowPasses( );
	}
	void RenderQueue::SplitNoShadowPasses::set( bool split )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setSplitNoShadowPasses( split );
	}
	
	bool RenderQueue::SplitPassesByLightingType::get()
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getSplitPassesByLightingType( );
	}
	void RenderQueue::SplitPassesByLightingType::set( bool split )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setSplitPassesByLightingType( split );
	}
	
	void RenderQueue::_Init_CLRObject( )
	{
		static_cast<Ogre::RenderQueue*>(_native)->_Init_CLRObject( );
	}
	
	void RenderQueue::Clear( bool destroyPassMaps )
	{
		static_cast<Ogre::RenderQueue*>(_native)->clear( destroyPassMaps );
	}
	void RenderQueue::Clear( )
	{
		static_cast<Ogre::RenderQueue*>(_native)->clear( );
	}
	
	Mogre::RenderQueueGroup^ RenderQueue::GetQueueGroup( Mogre::uint8 qid )
	{
		return static_cast<Ogre::RenderQueue*>(_native)->getQueueGroup( qid );
	}
	
	void RenderQueue::AddRenderable( Mogre::IRenderable^ pRend, Mogre::uint8 groupID, Mogre::ushort priority )
	{
		static_cast<Ogre::RenderQueue*>(_native)->addRenderable( pRend, groupID, priority );
	}
	
	void RenderQueue::AddRenderable( Mogre::IRenderable^ pRend, Mogre::uint8 groupId )
	{
		static_cast<Ogre::RenderQueue*>(_native)->addRenderable( pRend, groupId );
	}
	
	void RenderQueue::AddRenderable( Mogre::IRenderable^ pRend )
	{
		static_cast<Ogre::RenderQueue*>(_native)->addRenderable( pRend );
	}
	
	Mogre::RenderQueue::QueueGroupIterator^ RenderQueue::_getQueueGroupIterator( )
	{
		return static_cast<Ogre::RenderQueue*>(_native)->_getQueueGroupIterator( );
	}
	
	void RenderQueue::SetRenderableListener( Mogre::RenderQueue::IRenderableListener^ listener )
	{
		static_cast<Ogre::RenderQueue*>(_native)->setRenderableListener( listener );
	}
	
	Mogre::RenderQueue::IRenderableListener^ RenderQueue::GetRenderableListener( )
	{
		return static_cast<const Ogre::RenderQueue*>(_native)->getRenderableListener( );
	}
	
	void RenderQueue::Merge( Mogre::RenderQueue^ rhs )
	{
		static_cast<Ogre::RenderQueue*>(_native)->merge( rhs );
	}
	
	void RenderQueue::ProcessVisibleObject( Mogre::MovableObject^ mo, Mogre::Camera^ cam, bool onlyShadowCasters, Mogre::VisibleObjectsBoundsInfo_NativePtr visibleBounds )
	{
		static_cast<Ogre::RenderQueue*>(_native)->processVisibleObject( mo, cam, onlyShadowCasters, visibleBounds );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_RenderQueue(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::RenderQueue(pClrObj);
	}
	
	//################################################################
	//RenderQueue_RenderableListener_Proxy
	//################################################################
	
	
	
	bool RenderQueue_RenderableListener_Proxy::renderableQueued( Ogre::Renderable* rend, Ogre::uint8 groupID, Ogre::ushort priority, Ogre::Technique** ppTech, Ogre::RenderQueue* pQueue )
	{
		Mogre::Technique^ out_ppTech;
		bool mp_return = _managed->RenderableQueued( rend, groupID, priority, out_ppTech, pQueue );
		if (ppTech) *ppTech = out_ppTech;
	
		return mp_return;
	}

}
