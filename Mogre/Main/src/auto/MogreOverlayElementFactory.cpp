/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreOverlayElementFactory.h"
#include "MogreOverlayElement.h"

namespace Mogre
{
	//################################################################
	//OverlayElementFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	String^ OverlayElementFactory::TypeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::OverlayElementFactory*>(_native)->getTypeName( ) );
	}
	
	void OverlayElementFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::OverlayElementFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::OverlayElement^ OverlayElementFactory::CreateOverlayElement( String^ instanceName )
	{
		DECLARE_NATIVE_STRING( o_instanceName, instanceName )
	
		return static_cast<Ogre::OverlayElementFactory*>(_native)->createOverlayElement( o_instanceName );
	}
	
	void OverlayElementFactory::DestroyOverlayElement( Mogre::OverlayElement^ pElement )
	{
		static_cast<Ogre::OverlayElementFactory*>(_native)->destroyOverlayElement( pElement );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_OverlayElementFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::OverlayElementFactory(pClrObj);
	}
	
	//################################################################
	//PanelOverlayElementFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	PanelOverlayElementFactory::PanelOverlayElementFactory() : OverlayElementFactory((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::PanelOverlayElementFactory();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ PanelOverlayElementFactory::TypeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::PanelOverlayElementFactory*>(_native)->getTypeName( ) );
	}
	
	void PanelOverlayElementFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::PanelOverlayElementFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::OverlayElement^ PanelOverlayElementFactory::CreateOverlayElement( String^ instanceName )
	{
		DECLARE_NATIVE_STRING( o_instanceName, instanceName )
	
		return static_cast<Ogre::PanelOverlayElementFactory*>(_native)->createOverlayElement( o_instanceName );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_PanelOverlayElementFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::PanelOverlayElementFactory(pClrObj);
	}
	
	//################################################################
	//BorderPanelOverlayElementFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	BorderPanelOverlayElementFactory::BorderPanelOverlayElementFactory() : OverlayElementFactory((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::BorderPanelOverlayElementFactory();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ BorderPanelOverlayElementFactory::TypeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::BorderPanelOverlayElementFactory*>(_native)->getTypeName( ) );
	}
	
	void BorderPanelOverlayElementFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::BorderPanelOverlayElementFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::OverlayElement^ BorderPanelOverlayElementFactory::CreateOverlayElement( String^ instanceName )
	{
		DECLARE_NATIVE_STRING( o_instanceName, instanceName )
	
		return static_cast<Ogre::BorderPanelOverlayElementFactory*>(_native)->createOverlayElement( o_instanceName );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_BorderPanelOverlayElementFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::BorderPanelOverlayElementFactory(pClrObj);
	}
	
	//################################################################
	//TextAreaOverlayElementFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	TextAreaOverlayElementFactory::TextAreaOverlayElementFactory() : OverlayElementFactory((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::TextAreaOverlayElementFactory();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ TextAreaOverlayElementFactory::TypeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::TextAreaOverlayElementFactory*>(_native)->getTypeName( ) );
	}
	
	void TextAreaOverlayElementFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::TextAreaOverlayElementFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::OverlayElement^ TextAreaOverlayElementFactory::CreateOverlayElement( String^ instanceName )
	{
		DECLARE_NATIVE_STRING( o_instanceName, instanceName )
	
		return static_cast<Ogre::TextAreaOverlayElementFactory*>(_native)->createOverlayElement( o_instanceName );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_TextAreaOverlayElementFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::TextAreaOverlayElementFactory(pClrObj);
	}
	

}
