/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreLodStrategy.h"
#include "MogreMovableObject.h"
#include "MogreCamera.h"

namespace Mogre
{
	//################################################################
	//LodStrategy
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Mogre::Real LodStrategy::BaseValue::get()
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->getBaseValue( );
	}
	
	String^ LodStrategy::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::LodStrategy*>(_native)->getName( ) );
	}
	
	void LodStrategy::_Init_CLRObject( )
	{
		static_cast<Ogre::LodStrategy*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::Real LodStrategy::TransformBias( Mogre::Real factor )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->transformBias( factor );
	}
	
	Mogre::Real LodStrategy::TransformUserValue( Mogre::Real userValue )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->transformUserValue( userValue );
	}
	
	Mogre::Real LodStrategy::GetValue( Mogre::MovableObject^ movableObject, Mogre::Camera^ camera )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->getValue( movableObject, camera );
	}
	
	Mogre::ushort LodStrategy::GetIndex( Mogre::Real value, Mogre::Mesh::Const_MeshLodUsageList^ meshLodUsageList )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->getIndex( value, meshLodUsageList );
	}
	
	Mogre::ushort LodStrategy::GetIndex( Mogre::Real value, Mogre::Material::Const_LodValueList^ materialLodValueList )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->getIndex( value, materialLodValueList );
	}
	
	void LodStrategy::Sort( Mogre::Mesh::MeshLodUsageList^ meshLodUsageList )
	{
		static_cast<const Ogre::LodStrategy*>(_native)->sort( meshLodUsageList );
	}
	
	bool LodStrategy::IsSorted( Mogre::Mesh::Const_LodValueList^ values )
	{
		return static_cast<const Ogre::LodStrategy*>(_native)->isSorted( values );
	}
	
	void LodStrategy::AssertSorted( Mogre::Mesh::Const_LodValueList^ values )
	{
		static_cast<const Ogre::LodStrategy*>(_native)->assertSorted( values );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_LodStrategy(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::LodStrategy(pClrObj);
	}
	

}
