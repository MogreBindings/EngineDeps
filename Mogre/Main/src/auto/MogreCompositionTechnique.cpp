/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreCompositionTechnique.h"
#include "MogrePixelFormat.h"
#include "MogreCompositionTargetPass.h"
#include "MogreCompositor.h"

namespace Mogre
{
	//################################################################
	//CompositionTechnique
	//################################################################
	
	//Nested Types
	//################################################################
	//TextureDefinition_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	String^ CompositionTechnique::TextureDefinition_NativePtr::name::get()
	{
		return TO_CLR_STRING( _native->name );
	}
	void CompositionTechnique::TextureDefinition_NativePtr::name::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		_native->name = o_value;
	}
	
	String^ CompositionTechnique::TextureDefinition_NativePtr::refCompName::get()
	{
		return TO_CLR_STRING( _native->refCompName );
	}
	void CompositionTechnique::TextureDefinition_NativePtr::refCompName::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		_native->refCompName = o_value;
	}
	
	String^ CompositionTechnique::TextureDefinition_NativePtr::refTexName::get()
	{
		return TO_CLR_STRING( _native->refTexName );
	}
	void CompositionTechnique::TextureDefinition_NativePtr::refTexName::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		_native->refTexName = o_value;
	}
	
	size_t CompositionTechnique::TextureDefinition_NativePtr::width::get()
	{
		return _native->width;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::width::set( size_t value )
	{
		_native->width = value;
	}
	
	size_t CompositionTechnique::TextureDefinition_NativePtr::height::get()
	{
		return _native->height;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::height::set( size_t value )
	{
		_native->height = value;
	}
	
	float CompositionTechnique::TextureDefinition_NativePtr::widthFactor::get()
	{
		return _native->widthFactor;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::widthFactor::set( float value )
	{
		_native->widthFactor = value;
	}
	
	float CompositionTechnique::TextureDefinition_NativePtr::heightFactor::get()
	{
		return _native->heightFactor;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::heightFactor::set( float value )
	{
		_native->heightFactor = value;
	}
	
	Mogre::PixelFormatList^ CompositionTechnique::TextureDefinition_NativePtr::formatList::get()
	{
		return Mogre::PixelFormatList::ByValue( _native->formatList );
	}
	void CompositionTechnique::TextureDefinition_NativePtr::formatList::set( Mogre::PixelFormatList^ value )
	{
		_native->formatList = value;
	}
	
	bool CompositionTechnique::TextureDefinition_NativePtr::fsaa::get()
	{
		return _native->fsaa;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::fsaa::set( bool value )
	{
		_native->fsaa = value;
	}
	
	bool CompositionTechnique::TextureDefinition_NativePtr::hwGammaWrite::get()
	{
		return _native->hwGammaWrite;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::hwGammaWrite::set( bool value )
	{
		_native->hwGammaWrite = value;
	}
	
	bool CompositionTechnique::TextureDefinition_NativePtr::pooled::get()
	{
		return _native->pooled;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::pooled::set( bool value )
	{
		_native->pooled = value;
	}
	
	Mogre::CompositionTechnique::TextureScope CompositionTechnique::TextureDefinition_NativePtr::scope::get()
	{
		return (Mogre::CompositionTechnique::TextureScope)_native->scope;
	}
	void CompositionTechnique::TextureDefinition_NativePtr::scope::set( Mogre::CompositionTechnique::TextureScope value )
	{
		_native->scope = (Ogre::CompositionTechnique::TextureScope)value;
	}
	
	
	Mogre::CompositionTechnique::TextureDefinition_NativePtr CompositionTechnique::TextureDefinition_NativePtr::Create( )
	{
		TextureDefinition_NativePtr ptr;
		ptr._native = new Ogre::CompositionTechnique::TextureDefinition();
		return ptr;
	}
	
	
	//Protected Declarations
	
	
	
	#define STLDECL_MANAGEDTYPE Mogre::CompositionTargetPass^
	#define STLDECL_NATIVETYPE Ogre::CompositionTargetPass*
	CPP_DECLARE_STLVECTOR( CompositionTechnique::, TargetPasses, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	#define STLDECL_MANAGEDTYPE Mogre::CompositionTechnique::TextureDefinition_NativePtr
	#define STLDECL_NATIVETYPE Ogre::CompositionTechnique::TextureDefinition*
	CPP_DECLARE_STLVECTOR( CompositionTechnique::, TextureDefinitions, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	CPP_DECLARE_ITERATOR( CompositionTechnique::, TargetPassIterator, Ogre::CompositionTechnique::TargetPassIterator, Mogre::CompositionTechnique::TargetPasses, Mogre::CompositionTargetPass^, Ogre::CompositionTargetPass*,  )
	
	CPP_DECLARE_ITERATOR( CompositionTechnique::, TextureDefinitionIterator, Ogre::CompositionTechnique::TextureDefinitionIterator, Mogre::CompositionTechnique::TextureDefinitions, Mogre::CompositionTechnique::TextureDefinition_NativePtr, Ogre::CompositionTechnique::TextureDefinition*,  )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	CompositionTechnique::CompositionTechnique( Mogre::Compositor^ parent ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::CompositionTechnique( parent);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ CompositionTechnique::CompositorLogicName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::CompositionTechnique*>(_native)->getCompositorLogicName( ) );
	}
	void CompositionTechnique::CompositorLogicName::set( String^ compositorLogicName )
	{
		DECLARE_NATIVE_STRING( o_compositorLogicName, compositorLogicName )
	
		static_cast<Ogre::CompositionTechnique*>(_native)->setCompositorLogicName( o_compositorLogicName );
	}
	
	size_t CompositionTechnique::NumTargetPasses::get()
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getNumTargetPasses( );
	}
	
	size_t CompositionTechnique::NumTextureDefinitions::get()
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getNumTextureDefinitions( );
	}
	
	Mogre::CompositionTargetPass^ CompositionTechnique::OutputTargetPass::get()
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getOutputTargetPass( );
	}
	
	Mogre::Compositor^ CompositionTechnique::Parent::get()
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getParent( );
	}
	
	String^ CompositionTechnique::SchemeName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::CompositionTechnique*>(_native)->getSchemeName( ) );
	}
	void CompositionTechnique::SchemeName::set( String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::CompositionTechnique*>(_native)->setSchemeName( o_schemeName );
	}
	
	void CompositionTechnique::_Init_CLRObject( )
	{
		static_cast<Ogre::CompositionTechnique*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::CompositionTechnique::TextureDefinition_NativePtr CompositionTechnique::CreateTextureDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::CompositionTechnique*>(_native)->createTextureDefinition( o_name );
	}
	
	void CompositionTechnique::RemoveTextureDefinition( size_t idx )
	{
		static_cast<Ogre::CompositionTechnique*>(_native)->removeTextureDefinition( idx );
	}
	
	Mogre::CompositionTechnique::TextureDefinition_NativePtr CompositionTechnique::GetTextureDefinition( size_t idx )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getTextureDefinition( idx );
	}
	
	Mogre::CompositionTechnique::TextureDefinition_NativePtr CompositionTechnique::GetTextureDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<Ogre::CompositionTechnique*>(_native)->getTextureDefinition( o_name );
	}
	
	void CompositionTechnique::RemoveAllTextureDefinitions( )
	{
		static_cast<Ogre::CompositionTechnique*>(_native)->removeAllTextureDefinitions( );
	}
	
	Mogre::CompositionTechnique::TextureDefinitionIterator^ CompositionTechnique::GetTextureDefinitionIterator( )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getTextureDefinitionIterator( );
	}
	
	Mogre::CompositionTargetPass^ CompositionTechnique::CreateTargetPass( )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->createTargetPass( );
	}
	
	void CompositionTechnique::RemoveTargetPass( size_t idx )
	{
		static_cast<Ogre::CompositionTechnique*>(_native)->removeTargetPass( idx );
	}
	
	Mogre::CompositionTargetPass^ CompositionTechnique::GetTargetPass( size_t idx )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getTargetPass( idx );
	}
	
	void CompositionTechnique::RemoveAllTargetPasses( )
	{
		static_cast<Ogre::CompositionTechnique*>(_native)->removeAllTargetPasses( );
	}
	
	Mogre::CompositionTechnique::TargetPassIterator^ CompositionTechnique::GetTargetPassIterator( )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->getTargetPassIterator( );
	}
	
	bool CompositionTechnique::IsSupported( bool allowTextureDegradation )
	{
		return static_cast<Ogre::CompositionTechnique*>(_native)->isSupported( allowTextureDegradation );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_CompositionTechnique(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::CompositionTechnique(pClrObj);
	}
	

}
