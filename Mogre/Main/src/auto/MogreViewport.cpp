/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreViewport.h"
#include "MogreCamera.h"
#include "MogreRenderTarget.h"
#include "MogreRenderQueueInvocation.h"

namespace Mogre
{
	//################################################################
	//Viewport
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Viewport::Viewport( Mogre::Camera^ camera, Mogre::RenderTarget^ target, Mogre::Real left, Mogre::Real top, Mogre::Real width, Mogre::Real height, int ZOrder ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::Viewport( camera, target, left, top, width, height, ZOrder);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	int Viewport::ActualHeight::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getActualHeight( );
	}
	
	int Viewport::ActualLeft::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getActualLeft( );
	}
	
	int Viewport::ActualTop::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getActualTop( );
	}
	
	int Viewport::ActualWidth::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getActualWidth( );
	}
	
	Mogre::ColourValue Viewport::BackgroundColour::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getBackgroundColour( );
	}
	void Viewport::BackgroundColour::set( Mogre::ColourValue colour )
	{
		static_cast<Ogre::Viewport*>(_native)->setBackgroundColour( colour );
	}
	
	Mogre::Camera^ Viewport::Camera::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getCamera( );
	}
	void Viewport::Camera::set( Mogre::Camera^ cam )
	{
		static_cast<Ogre::Viewport*>(_native)->setCamera( cam );
	}
	
	unsigned int Viewport::ClearBuffers::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getClearBuffers( );
	}
	
	bool Viewport::ClearEveryFrame::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getClearEveryFrame( );
	}
	
	Mogre::OrientationMode Viewport::DefaultOrientationMode::get()
	{
		return (Mogre::OrientationMode)Ogre::Viewport::getDefaultOrientationMode( );
	}
	void Viewport::DefaultOrientationMode::set( Mogre::OrientationMode orientationMode )
	{
		Ogre::Viewport::setDefaultOrientationMode( (Ogre::OrientationMode)orientationMode );
	}
	
	Mogre::Real Viewport::Height::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getHeight( );
	}
	
	bool Viewport::IsAutoUpdated::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->isAutoUpdated( );
	}
	
	Mogre::Real Viewport::Left::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getLeft( );
	}
	
	String^ Viewport::MaterialScheme::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Viewport*>(_native)->getMaterialScheme( ) );
	}
	void Viewport::MaterialScheme::set( String^ schemeName )
	{
		DECLARE_NATIVE_STRING( o_schemeName, schemeName )
	
		static_cast<Ogre::Viewport*>(_native)->setMaterialScheme( o_schemeName );
	}
	
	Mogre::OrientationMode Viewport::OrientationMode::get()
	{
		return (Mogre::OrientationMode)static_cast<const Ogre::Viewport*>(_native)->getOrientationMode( );
	}
	
	bool Viewport::OverlaysEnabled::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getOverlaysEnabled( );
	}
	void Viewport::OverlaysEnabled::set( bool enabled )
	{
		static_cast<Ogre::Viewport*>(_native)->setOverlaysEnabled( enabled );
	}
	
	String^ Viewport::RenderQueueInvocationSequenceName::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Viewport*>(_native)->getRenderQueueInvocationSequenceName( ) );
	}
	void Viewport::RenderQueueInvocationSequenceName::set( String^ sequenceName )
	{
		DECLARE_NATIVE_STRING( o_sequenceName, sequenceName )
	
		static_cast<Ogre::Viewport*>(_native)->setRenderQueueInvocationSequenceName( o_sequenceName );
	}
	
	bool Viewport::ShadowsEnabled::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getShadowsEnabled( );
	}
	void Viewport::ShadowsEnabled::set( bool enabled )
	{
		static_cast<Ogre::Viewport*>(_native)->setShadowsEnabled( enabled );
	}
	
	bool Viewport::SkiesEnabled::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getSkiesEnabled( );
	}
	void Viewport::SkiesEnabled::set( bool enabled )
	{
		static_cast<Ogre::Viewport*>(_native)->setSkiesEnabled( enabled );
	}
	
	Mogre::RenderTarget^ Viewport::Target::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getTarget( );
	}
	
	Mogre::Real Viewport::Top::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getTop( );
	}
	
	Mogre::uint Viewport::VisibilityMask::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getVisibilityMask( );
	}
	
	Mogre::Real Viewport::Width::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getWidth( );
	}
	
	int Viewport::ZOrder::get()
	{
		return static_cast<const Ogre::Viewport*>(_native)->getZOrder( );
	}
	
	void Viewport::_Init_CLRObject( )
	{
		static_cast<Ogre::Viewport*>(_native)->_Init_CLRObject( );
	}
	
	void Viewport::_updateDimensions( )
	{
		static_cast<Ogre::Viewport*>(_native)->_updateDimensions( );
	}
	
	void Viewport::Update( )
	{
		static_cast<Ogre::Viewport*>(_native)->update( );
	}
	
	void Viewport::Clear( unsigned int buffers, Mogre::ColourValue colour, Mogre::Real depth, unsigned short stencil )
	{
		static_cast<Ogre::Viewport*>(_native)->clear( buffers, colour, depth, stencil );
	}
	void Viewport::Clear( unsigned int buffers, Mogre::ColourValue colour, Mogre::Real depth )
	{
		static_cast<Ogre::Viewport*>(_native)->clear( buffers, colour, depth );
	}
	void Viewport::Clear( unsigned int buffers, Mogre::ColourValue colour )
	{
		static_cast<Ogre::Viewport*>(_native)->clear( buffers, colour );
	}
	void Viewport::Clear( unsigned int buffers )
	{
		static_cast<Ogre::Viewport*>(_native)->clear( buffers );
	}
	void Viewport::Clear( )
	{
		static_cast<Ogre::Viewport*>(_native)->clear( );
	}
	
	void Viewport::SetDimensions( Mogre::Real left, Mogre::Real top, Mogre::Real width, Mogre::Real height )
	{
		static_cast<Ogre::Viewport*>(_native)->setDimensions( left, top, width, height );
	}
	
	void Viewport::SetOrientationMode( Mogre::OrientationMode orientationMode, bool setDefault )
	{
		static_cast<Ogre::Viewport*>(_native)->setOrientationMode( (Ogre::OrientationMode)orientationMode, setDefault );
	}
	void Viewport::SetOrientationMode( Mogre::OrientationMode orientationMode )
	{
		static_cast<Ogre::Viewport*>(_native)->setOrientationMode( (Ogre::OrientationMode)orientationMode );
	}
	
	void Viewport::SetClearEveryFrame( bool clear, unsigned int buffers )
	{
		static_cast<Ogre::Viewport*>(_native)->setClearEveryFrame( clear, buffers );
	}
	void Viewport::SetClearEveryFrame( bool clear )
	{
		static_cast<Ogre::Viewport*>(_native)->setClearEveryFrame( clear );
	}
	
	void Viewport::SetAutoUpdated( bool autoupdate )
	{
		static_cast<Ogre::Viewport*>(_native)->setAutoUpdated( autoupdate );
	}
	
	void Viewport::GetActualDimensions( [Out] int% left, [Out] int% top, [Out] int% width, [Out] int% height )
	{
		pin_ptr<int> p_left = &left;
		pin_ptr<int> p_top = &top;
		pin_ptr<int> p_width = &width;
		pin_ptr<int> p_height = &height;
	
		static_cast<const Ogre::Viewport*>(_native)->getActualDimensions( *p_left, *p_top, *p_width, *p_height );
	}
	
	bool Viewport::_isUpdated( )
	{
		return static_cast<const Ogre::Viewport*>(_native)->_isUpdated( );
	}
	
	void Viewport::_clearUpdatedFlag( )
	{
		static_cast<Ogre::Viewport*>(_native)->_clearUpdatedFlag( );
	}
	
	unsigned int Viewport::_getNumRenderedFaces( )
	{
		return static_cast<const Ogre::Viewport*>(_native)->_getNumRenderedFaces( );
	}
	
	unsigned int Viewport::_getNumRenderedBatches( )
	{
		return static_cast<const Ogre::Viewport*>(_native)->_getNumRenderedBatches( );
	}
	
	void Viewport::SetVisibilityMask( Mogre::uint32 mask )
	{
		static_cast<Ogre::Viewport*>(_native)->setVisibilityMask( mask );
	}
	
	Mogre::RenderQueueInvocationSequence^ Viewport::_getRenderQueueInvocationSequence( )
	{
		return static_cast<Ogre::Viewport*>(_native)->_getRenderQueueInvocationSequence( );
	}
	
	void Viewport::PointOrientedToScreen( Mogre::Vector2 v, int orientationMode, Mogre::Vector2 outv )
	{
		static_cast<Ogre::Viewport*>(_native)->pointOrientedToScreen( v, orientationMode, outv );
	}
	
	void Viewport::PointOrientedToScreen( Mogre::Real orientedX, Mogre::Real orientedY, int orientationMode, [Out] Mogre::Real% screenX, [Out] Mogre::Real% screenY )
	{
		pin_ptr<Mogre::Real> p_screenX = &screenX;
		pin_ptr<Mogre::Real> p_screenY = &screenY;
	
		static_cast<Ogre::Viewport*>(_native)->pointOrientedToScreen( orientedX, orientedY, orientationMode, *p_screenX, *p_screenY );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Viewport(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Viewport(pClrObj);
	}
	

}
