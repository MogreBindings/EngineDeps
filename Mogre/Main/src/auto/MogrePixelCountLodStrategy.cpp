/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogrePixelCountLodStrategy.h"

namespace Mogre
{
	//################################################################
	//PixelCountLodStrategy
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	PixelCountLodStrategy::PixelCountLodStrategy( ) : LodStrategy((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::PixelCountLodStrategy();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::Real PixelCountLodStrategy::BaseValue::get()
	{
		return static_cast<const Ogre::PixelCountLodStrategy*>(_native)->getBaseValue( );
	}
	
	void PixelCountLodStrategy::_Init_CLRObject( )
	{
		static_cast<Ogre::PixelCountLodStrategy*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::Real PixelCountLodStrategy::TransformBias( Mogre::Real factor )
	{
		return static_cast<const Ogre::PixelCountLodStrategy*>(_native)->transformBias( factor );
	}
	
	Mogre::ushort PixelCountLodStrategy::GetIndex( Mogre::Real value, Mogre::Mesh::Const_MeshLodUsageList^ meshLodUsageList )
	{
		return static_cast<const Ogre::PixelCountLodStrategy*>(_native)->getIndex( value, meshLodUsageList );
	}
	
	Mogre::ushort PixelCountLodStrategy::GetIndex( Mogre::Real value, Mogre::Material::Const_LodValueList^ materialLodValueList )
	{
		return static_cast<const Ogre::PixelCountLodStrategy*>(_native)->getIndex( value, materialLodValueList );
	}
	
	void PixelCountLodStrategy::Sort( Mogre::Mesh::MeshLodUsageList^ meshLodUsageList )
	{
		static_cast<const Ogre::PixelCountLodStrategy*>(_native)->sort( meshLodUsageList );
	}
	
	bool PixelCountLodStrategy::IsSorted( Mogre::Mesh::Const_LodValueList^ values )
	{
		return static_cast<const Ogre::PixelCountLodStrategy*>(_native)->isSorted( values );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_PixelCountLodStrategy(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::PixelCountLodStrategy(pClrObj);
	}
	

}
