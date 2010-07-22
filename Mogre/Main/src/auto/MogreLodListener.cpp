/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreLodListener.h"
#include "MogreSubEntity.h"
#include "MogreCamera.h"
#include "MogreEntity.h"
#include "MogreMovableObject.h"

namespace Mogre
{
	//################################################################
	//EntityMaterialLodChangedEvent_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::SubEntity^ EntityMaterialLodChangedEvent_NativePtr::subEntity::get()
	{
		return _native->subEntity;
	}
	
	Mogre::Camera^ EntityMaterialLodChangedEvent_NativePtr::camera::get()
	{
		return _native->camera;
	}
	
	Mogre::Real EntityMaterialLodChangedEvent_NativePtr::lodValue::get()
	{
		return _native->lodValue;
	}
	
	Mogre::ushort EntityMaterialLodChangedEvent_NativePtr::previousLodIndex::get()
	{
		return _native->previousLodIndex;
	}
	
	Mogre::ushort EntityMaterialLodChangedEvent_NativePtr::newLodIndex::get()
	{
		return _native->newLodIndex;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//EntityMeshLodChangedEvent_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::Entity^ EntityMeshLodChangedEvent_NativePtr::entity::get()
	{
		return _native->entity;
	}
	
	Mogre::Camera^ EntityMeshLodChangedEvent_NativePtr::camera::get()
	{
		return _native->camera;
	}
	
	Mogre::Real EntityMeshLodChangedEvent_NativePtr::lodValue::get()
	{
		return _native->lodValue;
	}
	
	Mogre::ushort EntityMeshLodChangedEvent_NativePtr::previousLodIndex::get()
	{
		return _native->previousLodIndex;
	}
	
	Mogre::ushort EntityMeshLodChangedEvent_NativePtr::newLodIndex::get()
	{
		return _native->newLodIndex;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//MovableObjectLodChangedEvent_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::MovableObject^ MovableObjectLodChangedEvent_NativePtr::movableObject::get()
	{
		return _native->movableObject;
	}
	
	Mogre::Camera^ MovableObjectLodChangedEvent_NativePtr::camera::get()
	{
		return _native->camera;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//LodListener
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	LodListener::LodListener() : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::LodListener();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void LodListener::_Init_CLRObject( )
	{
		static_cast<Ogre::LodListener*>(_native)->_Init_CLRObject( );
	}
	
	bool LodListener::PrequeueMovableObjectLodChanged( Mogre::MovableObjectLodChangedEvent_NativePtr evt )
	{
		return static_cast<Ogre::LodListener*>(_native)->prequeueMovableObjectLodChanged( evt );
	}
	
	void LodListener::PostqueueMovableObjectLodChanged( Mogre::MovableObjectLodChangedEvent_NativePtr evt )
	{
		static_cast<Ogre::LodListener*>(_native)->postqueueMovableObjectLodChanged( evt );
	}
	
	bool LodListener::PrequeueEntityMeshLodChanged( Mogre::EntityMeshLodChangedEvent_NativePtr evt )
	{
		return static_cast<Ogre::LodListener*>(_native)->prequeueEntityMeshLodChanged( evt );
	}
	
	void LodListener::PostqueueEntityMeshLodChanged( Mogre::EntityMeshLodChangedEvent_NativePtr evt )
	{
		static_cast<Ogre::LodListener*>(_native)->postqueueEntityMeshLodChanged( evt );
	}
	
	bool LodListener::PrequeueEntityMaterialLodChanged( Mogre::EntityMaterialLodChangedEvent_NativePtr evt )
	{
		return static_cast<Ogre::LodListener*>(_native)->prequeueEntityMaterialLodChanged( evt );
	}
	
	void LodListener::PostqueueEntityMaterialLodChanged( Mogre::EntityMaterialLodChangedEvent_NativePtr evt )
	{
		static_cast<Ogre::LodListener*>(_native)->postqueueEntityMaterialLodChanged( evt );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_LodListener(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::LodListener(pClrObj);
	}
	

}
