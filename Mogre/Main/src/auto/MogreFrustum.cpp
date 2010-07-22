/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreFrustum.h"
#include "MogreRenderable.h"
#include "MogrePlaneBoundedVolume.h"
#include "MogreRenderQueue.h"
#include "MogreCamera.h"
#include "MogreMaterial.h"
#include "MogreRenderOperation.h"
#include "MogreCommon.h"
#include "MogreMovablePlane.h"
#include "MogreTechnique.h"
#include "MogreSceneManager.h"
#include "MogreRenderSystem.h"
#include "MogreGpuProgramParams.h"

namespace Mogre
{
	//################################################################
	//Frustum
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	Ogre::Renderable* Frustum::_IRenderable_GetNativePtr()
	{
		return static_cast<Ogre::Renderable*>( static_cast<Ogre::Frustum*>(_native) );
	}
	
	
	//Public Declarations
	Frustum::Frustum( ) : MovableObject((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::Frustum();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	Mogre::Real Frustum::INFINITE_FAR_PLANE_ADJUST::get()
	{
		return Ogre::Frustum::INFINITE_FAR_PLANE_ADJUST;
	}
	
	Mogre::Real Frustum::AspectRatio::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getAspectRatio( );
	}
	void Frustum::AspectRatio::set( Mogre::Real ratio )
	{
		static_cast<Ogre::Frustum*>(_native)->setAspectRatio( ratio );
	}
	
	Mogre::AxisAlignedBox^ Frustum::BoundingBox::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getBoundingBox( );
	}
	
	Mogre::Real Frustum::BoundingRadius::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getBoundingRadius( );
	}
	
	Mogre::Real Frustum::FarClipDistance::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getFarClipDistance( );
	}
	void Frustum::FarClipDistance::set( Mogre::Real farDist )
	{
		static_cast<Ogre::Frustum*>(_native)->setFarClipDistance( farDist );
	}
	
	Mogre::Real Frustum::FocalLength::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getFocalLength( );
	}
	void Frustum::FocalLength::set( Mogre::Real focalLength )
	{
		static_cast<Ogre::Frustum*>(_native)->setFocalLength( focalLength );
	}
	
	Mogre::Radian Frustum::FOVy::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getFOVy( );
	}
	void Frustum::FOVy::set( Mogre::Radian fovy )
	{
		static_cast<Ogre::Frustum*>(_native)->setFOVy( fovy );
	}
	
	Mogre::Vector2 Frustum::FrustumOffset::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getFrustumOffset( );
	}
	void Frustum::FrustumOffset::set( Mogre::Vector2 offset )
	{
		static_cast<Ogre::Frustum*>(_native)->setFrustumOffset( offset );
	}
	
	const Mogre::Plane* Frustum::FrustumPlanes::get()
	{
		return reinterpret_cast<const Mogre::Plane*>(static_cast<const Ogre::Frustum*>(_native)->getFrustumPlanes( ));
	}
	
	bool Frustum::IsCustomNearClipPlaneEnabled::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->isCustomNearClipPlaneEnabled( );
	}
	
	bool Frustum::IsCustomProjectionMatrixEnabled::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->isCustomProjectionMatrixEnabled( );
	}
	
	bool Frustum::IsCustomViewMatrixEnabled::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->isCustomViewMatrixEnabled( );
	}
	
	bool Frustum::IsReflected::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->isReflected( );
	}
	
	String^ Frustum::MovableType::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Frustum*>(_native)->getMovableType( ) );
	}
	
	Mogre::Real Frustum::NearClipDistance::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getNearClipDistance( );
	}
	void Frustum::NearClipDistance::set( Mogre::Real nearDist )
	{
		static_cast<Ogre::Frustum*>(_native)->setNearClipDistance( nearDist );
	}
	
	Mogre::Quaternion Frustum::OrientationForViewUpdate::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getOrientationForViewUpdate( );
	}
	
	Mogre::OrientationMode Frustum::OrientationMode::get()
	{
		return (Mogre::OrientationMode)static_cast<const Ogre::Frustum*>(_native)->getOrientationMode( );
	}
	void Frustum::OrientationMode::set( Mogre::OrientationMode orientationMode )
	{
		static_cast<Ogre::Frustum*>(_native)->setOrientationMode( (Ogre::OrientationMode)orientationMode );
	}
	
	Mogre::Real Frustum::OrthoWindowHeight::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getOrthoWindowHeight( );
	}
	void Frustum::OrthoWindowHeight::set( Mogre::Real h )
	{
		static_cast<Ogre::Frustum*>(_native)->setOrthoWindowHeight( h );
	}
	
	Mogre::Real Frustum::OrthoWindowWidth::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getOrthoWindowWidth( );
	}
	void Frustum::OrthoWindowWidth::set( Mogre::Real w )
	{
		static_cast<Ogre::Frustum*>(_native)->setOrthoWindowWidth( w );
	}
	
	Mogre::PlaneBoundedVolume^ Frustum::PlaneBoundedVolume::get()
	{
		return static_cast<Ogre::Frustum*>(_native)->getPlaneBoundedVolume( );
	}
	
	Mogre::Vector3 Frustum::PositionForViewUpdate::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getPositionForViewUpdate( );
	}
	
	Mogre::Matrix4^ Frustum::ProjectionMatrix::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getProjectionMatrix( );
	}
	
	Mogre::Matrix4^ Frustum::ProjectionMatrixRS::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getProjectionMatrixRS( );
	}
	
	Mogre::Matrix4^ Frustum::ProjectionMatrixWithRSDepth::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getProjectionMatrixWithRSDepth( );
	}
	
	Mogre::ProjectionType Frustum::ProjectionType::get()
	{
		return (Mogre::ProjectionType)static_cast<const Ogre::Frustum*>(_native)->getProjectionType( );
	}
	void Frustum::ProjectionType::set( Mogre::ProjectionType pt )
	{
		static_cast<Ogre::Frustum*>(_native)->setProjectionType( (Ogre::ProjectionType)pt );
	}
	
	Mogre::Matrix4^ Frustum::ReflectionMatrix::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getReflectionMatrix( );
	}
	
	Mogre::Plane Frustum::ReflectionPlane::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getReflectionPlane( );
	}
	
	Mogre::uint32 Frustum::TypeFlags::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getTypeFlags( );
	}
	
	Mogre::Matrix4^ Frustum::ViewMatrix::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getViewMatrix( );
	}
	
	const Mogre::Vector3* Frustum::WorldSpaceCorners::get()
	{
		return reinterpret_cast<const Mogre::Vector3*>(static_cast<const Ogre::Frustum*>(_native)->getWorldSpaceCorners( ));
	}
	
	void Frustum::_Init_CLRObject( )
	{
		static_cast<Ogre::Frustum*>(_native)->_Init_CLRObject( );
	}
	
	void Frustum::SetFrustumOffset( Mogre::Real horizontal, Mogre::Real vertical )
	{
		static_cast<Ogre::Frustum*>(_native)->setFrustumOffset( horizontal, vertical );
	}
	void Frustum::SetFrustumOffset( Mogre::Real horizontal )
	{
		static_cast<Ogre::Frustum*>(_native)->setFrustumOffset( horizontal );
	}
	void Frustum::SetFrustumOffset( )
	{
		static_cast<Ogre::Frustum*>(_native)->setFrustumOffset( );
	}
	
	void Frustum::SetFrustumExtents( Mogre::Real left, Mogre::Real right, Mogre::Real top, Mogre::Real bottom )
	{
		static_cast<Ogre::Frustum*>(_native)->setFrustumExtents( left, right, top, bottom );
	}
	
	void Frustum::ResetFrustumExtents( )
	{
		static_cast<Ogre::Frustum*>(_native)->resetFrustumExtents( );
	}
	
	void Frustum::GetFrustumExtents( [Out] Mogre::Real% outleft, [Out] Mogre::Real% outright, [Out] Mogre::Real% outtop, [Out] Mogre::Real% outbottom )
	{
		pin_ptr<Mogre::Real> p_outleft = &outleft;
		pin_ptr<Mogre::Real> p_outright = &outright;
		pin_ptr<Mogre::Real> p_outtop = &outtop;
		pin_ptr<Mogre::Real> p_outbottom = &outbottom;
	
		static_cast<const Ogre::Frustum*>(_native)->getFrustumExtents( *p_outleft, *p_outright, *p_outtop, *p_outbottom );
	}
	
	void Frustum::CalcViewMatrixRelative( Mogre::Vector3 relPos, Mogre::Matrix4^ matToUpdate )
	{
		pin_ptr<Ogre::Matrix4> p_matToUpdate = interior_ptr<Ogre::Matrix4>(&matToUpdate->m00);
	
		static_cast<const Ogre::Frustum*>(_native)->calcViewMatrixRelative( relPos, *p_matToUpdate );
	}
	
	void Frustum::SetCustomViewMatrix( bool enable, Mogre::Matrix4^ viewMatrix )
	{
		pin_ptr<Ogre::Matrix4> p_viewMatrix = interior_ptr<Ogre::Matrix4>(&viewMatrix->m00);
	
		static_cast<Ogre::Frustum*>(_native)->setCustomViewMatrix( enable, *p_viewMatrix );
	}
	void Frustum::SetCustomViewMatrix( bool enable )
	{
		static_cast<Ogre::Frustum*>(_native)->setCustomViewMatrix( enable );
	}
	
	void Frustum::SetCustomProjectionMatrix( bool enable, Mogre::Matrix4^ projectionMatrix )
	{
		pin_ptr<Ogre::Matrix4> p_projectionMatrix = interior_ptr<Ogre::Matrix4>(&projectionMatrix->m00);
	
		static_cast<Ogre::Frustum*>(_native)->setCustomProjectionMatrix( enable, *p_projectionMatrix );
	}
	void Frustum::SetCustomProjectionMatrix( bool enable )
	{
		static_cast<Ogre::Frustum*>(_native)->setCustomProjectionMatrix( enable );
	}
	
	Mogre::Plane Frustum::GetFrustumPlane( unsigned short plane )
	{
		return static_cast<const Ogre::Frustum*>(_native)->getFrustumPlane( plane );
	}
	
	bool Frustum::IsVisible( Mogre::AxisAlignedBox^ bound, [Out] Mogre::FrustumPlane% culledBy )
	{
		pin_ptr<Mogre::FrustumPlane> p_culledBy = &culledBy;
	
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( (Ogre::AxisAlignedBox)bound, (Ogre::FrustumPlane*)p_culledBy );
	}
	bool Frustum::IsVisible( Mogre::AxisAlignedBox^ bound )
	{
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( (Ogre::AxisAlignedBox)bound );
	}
	
	bool Frustum::IsVisible( Mogre::Sphere bound, [Out] Mogre::FrustumPlane% culledBy )
	{
		pin_ptr<Mogre::FrustumPlane> p_culledBy = &culledBy;
	
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( bound, (Ogre::FrustumPlane*)p_culledBy );
	}
	bool Frustum::IsVisible( Mogre::Sphere bound )
	{
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( bound );
	}
	
	bool Frustum::IsVisible( Mogre::Vector3 vert, [Out] Mogre::FrustumPlane% culledBy )
	{
		pin_ptr<Mogre::FrustumPlane> p_culledBy = &culledBy;
	
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( vert, (Ogre::FrustumPlane*)p_culledBy );
	}
	bool Frustum::IsVisible( Mogre::Vector3 vert )
	{
		return static_cast<const Ogre::Frustum*>(_native)->isVisible( vert );
	}
	
	void Frustum::_updateRenderQueue( Mogre::RenderQueue^ queue )
	{
		static_cast<Ogre::Frustum*>(_native)->_updateRenderQueue( queue );
	}
	
	void Frustum::_notifyCurrentCamera( Mogre::Camera^ cam )
	{
		static_cast<Ogre::Frustum*>(_native)->_notifyCurrentCamera( cam );
	}
	
	Mogre::MaterialPtr^ Frustum::GetMaterial( )
	{
		return static_cast<const Ogre::Frustum*>(_native)->getMaterial( );
	}
	
	void Frustum::GetRenderOperation( Mogre::RenderOperation^ op )
	{
		static_cast<Ogre::Frustum*>(_native)->getRenderOperation( op );
	}
	
	void Frustum::GetWorldTransforms( Mogre::Matrix4::NativeValue* xform )
	{
		Ogre::Matrix4* o_xform = reinterpret_cast<Ogre::Matrix4*>(xform);
	
		static_cast<const Ogre::Frustum*>(_native)->getWorldTransforms( o_xform );
	}
	
	Mogre::Real Frustum::GetSquaredViewDepth( Mogre::Camera^ cam )
	{
		return static_cast<const Ogre::Frustum*>(_native)->getSquaredViewDepth( cam );
	}
	
	Mogre::Const_LightList^ Frustum::GetLights( )
	{
		return static_cast<const Ogre::Frustum*>(_native)->getLights( );
	}
	
	void Frustum::SetOrthoWindow( Mogre::Real w, Mogre::Real h )
	{
		static_cast<Ogre::Frustum*>(_native)->setOrthoWindow( w, h );
	}
	
	void Frustum::EnableReflection( Mogre::Plane p )
	{
		static_cast<Ogre::Frustum*>(_native)->enableReflection( p );
	}
	
	void Frustum::EnableReflection( Mogre::MovablePlane^ p )
	{
		static_cast<Ogre::Frustum*>(_native)->enableReflection( p );
	}
	
	void Frustum::DisableReflection( )
	{
		static_cast<Ogre::Frustum*>(_native)->disableReflection( );
	}
	
	bool Frustum::ProjectSphere( Mogre::Sphere sphere, [Out] Mogre::Real% left, [Out] Mogre::Real% top, [Out] Mogre::Real% right, [Out] Mogre::Real% bottom )
	{
		pin_ptr<Mogre::Real> p_left = &left;
		pin_ptr<Mogre::Real> p_top = &top;
		pin_ptr<Mogre::Real> p_right = &right;
		pin_ptr<Mogre::Real> p_bottom = &bottom;
	
		return static_cast<const Ogre::Frustum*>(_native)->projectSphere( sphere, p_left, p_top, p_right, p_bottom );
	}
	
	void Frustum::EnableCustomNearClipPlane( Mogre::MovablePlane^ plane )
	{
		static_cast<Ogre::Frustum*>(_native)->enableCustomNearClipPlane( plane );
	}
	
	void Frustum::EnableCustomNearClipPlane( Mogre::Plane plane )
	{
		static_cast<Ogre::Frustum*>(_native)->enableCustomNearClipPlane( plane );
	}
	
	void Frustum::DisableCustomNearClipPlane( )
	{
		static_cast<Ogre::Frustum*>(_native)->disableCustomNearClipPlane( );
	}
	
	//------------------------------------------------------------
	// Implementation for IRenderable
	//------------------------------------------------------------
	
	bool Frustum::CastsShadows::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getCastsShadows( );
	}
	
	unsigned short Frustum::NumWorldTransforms::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getNumWorldTransforms( );
	}
	
	bool Frustum::PolygonModeOverrideable::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getPolygonModeOverrideable( );
	}
	void Frustum::PolygonModeOverrideable::set( bool override )
	{
		static_cast<Ogre::Frustum*>(_native)->setPolygonModeOverrideable( override );
	}
	
	Mogre::Technique^ Frustum::Technique::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getTechnique( );
	}
	
	bool Frustum::UseIdentityProjection::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getUseIdentityProjection( );
	}
	void Frustum::UseIdentityProjection::set( bool useIdentityProjection )
	{
		static_cast<Ogre::Frustum*>(_native)->setUseIdentityProjection( useIdentityProjection );
	}
	
	bool Frustum::UseIdentityView::get()
	{
		return static_cast<const Ogre::Frustum*>(_native)->getUseIdentityView( );
	}
	void Frustum::UseIdentityView::set( bool useIdentityView )
	{
		static_cast<Ogre::Frustum*>(_native)->setUseIdentityView( useIdentityView );
	}
	
	bool Frustum::PreRender( Mogre::SceneManager^ sm, Mogre::RenderSystem^ rsys )
	{
		return static_cast<Ogre::Frustum*>(_native)->preRender( sm, rsys );
	}
	
	void Frustum::PostRender( Mogre::SceneManager^ sm, Mogre::RenderSystem^ rsys )
	{
		static_cast<Ogre::Frustum*>(_native)->postRender( sm, rsys );
	}
	
	void Frustum::SetCustomParameter( size_t index, Mogre::Vector4 value )
	{
		static_cast<Ogre::Frustum*>(_native)->setCustomParameter( index, value );
	}
	
	Mogre::Vector4 Frustum::GetCustomParameter( size_t index )
	{
		return static_cast<const Ogre::Frustum*>(_native)->getCustomParameter( index );
	}
	
	void Frustum::_updateCustomGpuParameter( Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr constantEntry, Mogre::GpuProgramParameters^ params )
	{
		static_cast<const Ogre::Frustum*>(_native)->_updateCustomGpuParameter( constantEntry, params );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Frustum(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Frustum(pClrObj);
	}
	

}
