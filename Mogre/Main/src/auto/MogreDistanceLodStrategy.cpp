/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreDistanceLodStrategy.h"

namespace Mogre
{
	//################################################################
	//DistanceLodStrategy
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	DistanceLodStrategy::DistanceLodStrategy( ) : LodStrategy((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::DistanceLodStrategy();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::Real DistanceLodStrategy::BaseValue::get()
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->getBaseValue( );
	}
	
	bool DistanceLodStrategy::ReferenceViewEnabled::get()
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->getReferenceViewEnabled( );
	}
	void DistanceLodStrategy::ReferenceViewEnabled::set( bool value )
	{
		static_cast<Ogre::DistanceLodStrategy*>(_native)->setReferenceViewEnabled( value );
	}
	
	void DistanceLodStrategy::_Init_CLRObject( )
	{
		static_cast<Ogre::DistanceLodStrategy*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::Real DistanceLodStrategy::TransformBias( Mogre::Real factor )
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->transformBias( factor );
	}
	
	Mogre::Real DistanceLodStrategy::TransformUserValue( Mogre::Real userValue )
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->transformUserValue( userValue );
	}
	
	Mogre::ushort DistanceLodStrategy::GetIndex( Mogre::Real value, Mogre::Mesh::Const_MeshLodUsageList^ meshLodUsageList )
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->getIndex( value, meshLodUsageList );
	}
	
	Mogre::ushort DistanceLodStrategy::GetIndex( Mogre::Real value, Mogre::Material::Const_LodValueList^ materialLodValueList )
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->getIndex( value, materialLodValueList );
	}
	
	void DistanceLodStrategy::Sort( Mogre::Mesh::MeshLodUsageList^ meshLodUsageList )
	{
		static_cast<const Ogre::DistanceLodStrategy*>(_native)->sort( meshLodUsageList );
	}
	
	bool DistanceLodStrategy::IsSorted( Mogre::Mesh::Const_LodValueList^ values )
	{
		return static_cast<const Ogre::DistanceLodStrategy*>(_native)->isSorted( values );
	}
	
	void DistanceLodStrategy::SetReferenceView( Mogre::Real viewportWidth, Mogre::Real viewportHeight, Mogre::Radian fovY )
	{
		static_cast<Ogre::DistanceLodStrategy*>(_native)->setReferenceView( viewportWidth, viewportHeight, fovY );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_DistanceLodStrategy(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::DistanceLodStrategy(pClrObj);
	}
	

}
