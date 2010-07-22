/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreAnimationState.h"

namespace Mogre
{
	//################################################################
	//AnimationState
	//################################################################
	
	//Nested Types
	#define STLDECL_MANAGEDTYPE float
	#define STLDECL_NATIVETYPE float
	CPP_DECLARE_STLVECTOR( AnimationState::, BoneBlendMask, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	AnimationState::AnimationState( String^ animName, Mogre::AnimationStateSet^ parent, Mogre::Real timePos, Mogre::Real length, Mogre::Real weight, bool enabled ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		_native = new Ogre::AnimationState( o_animName, parent, timePos, length, weight, enabled);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	AnimationState::AnimationState( String^ animName, Mogre::AnimationStateSet^ parent, Mogre::Real timePos, Mogre::Real length, Mogre::Real weight ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		_native = new Ogre::AnimationState( o_animName, parent, timePos, length, weight);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	AnimationState::AnimationState( String^ animName, Mogre::AnimationStateSet^ parent, Mogre::Real timePos, Mogre::Real length ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		_native = new Ogre::AnimationState( o_animName, parent, timePos, length);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	AnimationState::AnimationState( Mogre::AnimationStateSet^ parent, Mogre::AnimationState^ rhs ) : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::AnimationState( parent, rhs);
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	String^ AnimationState::AnimationName::get()
	{
		return ( CLR_NULL == _animationName ) ? (_animationName = TO_CLR_STRING( static_cast<const Ogre::AnimationState*>(_native)->getAnimationName( ) )) : _animationName;
	}
	
	bool AnimationState::Enabled::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getEnabled( );
	}
	void AnimationState::Enabled::set( bool enabled )
	{
		static_cast<Ogre::AnimationState*>(_native)->setEnabled( enabled );
	}
	
	bool AnimationState::HasBlendMask::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->hasBlendMask( );
	}
	
	bool AnimationState::HasEnded::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->hasEnded( );
	}
	
	Mogre::Real AnimationState::Length::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getLength( );
	}
	void AnimationState::Length::set( Mogre::Real len )
	{
		static_cast<Ogre::AnimationState*>(_native)->setLength( len );
	}
	
	bool AnimationState::Loop::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getLoop( );
	}
	void AnimationState::Loop::set( bool loop )
	{
		static_cast<Ogre::AnimationState*>(_native)->setLoop( loop );
	}
	
	Mogre::AnimationStateSet^ AnimationState::Parent::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getParent( );
	}
	
	Mogre::Real AnimationState::TimePosition::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getTimePosition( );
	}
	void AnimationState::TimePosition::set( Mogre::Real timePos )
	{
		static_cast<Ogre::AnimationState*>(_native)->setTimePosition( timePos );
	}
	
	Mogre::Real AnimationState::Weight::get()
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getWeight( );
	}
	void AnimationState::Weight::set( Mogre::Real weight )
	{
		static_cast<Ogre::AnimationState*>(_native)->setWeight( weight );
	}
	
	void AnimationState::_Init_CLRObject( )
	{
		static_cast<Ogre::AnimationState*>(_native)->_Init_CLRObject( );
	}
	
	void AnimationState::AddTime( Mogre::Real offset )
	{
		static_cast<Ogre::AnimationState*>(_native)->addTime( offset );
	}
	
	bool AnimationState::Equals(Object^ obj)
	{
	    AnimationState^ clr = dynamic_cast<AnimationState^>(obj);
	    if (clr == CLR_NULL)
	    {
	        return false;
	    }
	
	    if (_native == NULL) throw gcnew Exception("The underlying native object for the caller is null.");
	    if (clr->_native == NULL) throw gcnew ArgumentException("The underlying native object for parameter 'obj' is null.");
	
	    return *(static_cast<Ogre::AnimationState*>(_native)) == *(static_cast<Ogre::AnimationState*>(clr->_native));
	}
	
	bool AnimationState::Equals(AnimationState^ obj)
	{
	    if (obj == CLR_NULL)
	    {
	        return false;
	    }
	
	    if (_native == NULL) throw gcnew Exception("The underlying native object for the caller is null.");
	    if (obj->_native == NULL) throw gcnew ArgumentException("The underlying native object for parameter 'obj' is null.");
	
	    return *(static_cast<Ogre::AnimationState*>(_native)) == *(static_cast<Ogre::AnimationState*>(obj->_native));
	}
	
	bool AnimationState::operator ==(AnimationState^ obj1, AnimationState^ obj2)
	{
		if ((Object^)obj1 == (Object^)obj2) return true;
		if ((Object^)obj1 == nullptr || (Object^)obj2 == nullptr) return false;
	
		return obj1->Equals(obj2);
	}
	
	bool AnimationState::operator !=(AnimationState^ obj1, AnimationState^ obj2)
	{
		return !(obj1 == obj2);
	}
	
	
	void AnimationState::CopyStateFrom( Mogre::AnimationState^ animState )
	{
		static_cast<Ogre::AnimationState*>(_native)->copyStateFrom( animState );
	}
	
	void AnimationState::CreateBlendMask( size_t blendMaskSizeHint, float initialWeight )
	{
		static_cast<Ogre::AnimationState*>(_native)->createBlendMask( blendMaskSizeHint, initialWeight );
	}
	void AnimationState::CreateBlendMask( size_t blendMaskSizeHint )
	{
		static_cast<Ogre::AnimationState*>(_native)->createBlendMask( blendMaskSizeHint );
	}
	
	void AnimationState::DestroyBlendMask( )
	{
		static_cast<Ogre::AnimationState*>(_native)->destroyBlendMask( );
	}
	
	void AnimationState::_setBlendMaskData( const float* blendMaskData )
	{
		static_cast<Ogre::AnimationState*>(_native)->_setBlendMaskData( blendMaskData );
	}
	
	void AnimationState::_setBlendMask( Mogre::AnimationState::Const_BoneBlendMask^ blendMask )
	{
		static_cast<Ogre::AnimationState*>(_native)->_setBlendMask( blendMask );
	}
	
	Mogre::AnimationState::Const_BoneBlendMask^ AnimationState::GetBlendMask( )
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getBlendMask( );
	}
	
	void AnimationState::SetBlendMaskEntry( size_t boneHandle, float weight )
	{
		static_cast<Ogre::AnimationState*>(_native)->setBlendMaskEntry( boneHandle, weight );
	}
	
	float AnimationState::GetBlendMaskEntry( size_t boneHandle )
	{
		return static_cast<const Ogre::AnimationState*>(_native)->getBlendMaskEntry( boneHandle );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_AnimationState(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::AnimationState(pClrObj);
	}
	
	//################################################################
	//AnimationStateSet
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	AnimationStateSet::AnimationStateSet( )
	{
		_createdByCLR = true;
		_native = new Ogre::AnimationStateSet();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	AnimationStateSet::AnimationStateSet( Mogre::AnimationStateSet^ rhs )
	{
		_createdByCLR = true;
		_native = new Ogre::AnimationStateSet( rhs);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle AnimationStateSet::_CLRHandle::get()
	{
		return static_cast<Ogre::AnimationStateSet*>(_native)->_CLRHandle;
	}
	void AnimationStateSet::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::AnimationStateSet*>(_native)->_CLRHandle = value;
	}
	
	unsigned long AnimationStateSet::DirtyFrameNumber::get()
	{
		return static_cast<const Ogre::AnimationStateSet*>(_native)->getDirtyFrameNumber( );
	}
	
	bool AnimationStateSet::HasEnabledAnimationState::get()
	{
		return static_cast<const Ogre::AnimationStateSet*>(_native)->hasEnabledAnimationState( );
	}
	
	Mogre::AnimationState^ AnimationStateSet::CreateAnimationState( String^ animName, Mogre::Real timePos, Mogre::Real length, Mogre::Real weight, bool enabled )
	{
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		return static_cast<Ogre::AnimationStateSet*>(_native)->createAnimationState( o_animName, timePos, length, weight, enabled );
	}
	Mogre::AnimationState^ AnimationStateSet::CreateAnimationState( String^ animName, Mogre::Real timePos, Mogre::Real length, Mogre::Real weight )
	{
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		return static_cast<Ogre::AnimationStateSet*>(_native)->createAnimationState( o_animName, timePos, length, weight );
	}
	Mogre::AnimationState^ AnimationStateSet::CreateAnimationState( String^ animName, Mogre::Real timePos, Mogre::Real length )
	{
		DECLARE_NATIVE_STRING( o_animName, animName )
	
		return static_cast<Ogre::AnimationStateSet*>(_native)->createAnimationState( o_animName, timePos, length );
	}
	
	Mogre::AnimationState^ AnimationStateSet::GetAnimationState( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::AnimationStateSet*>(_native)->getAnimationState( o_name );
	}
	
	bool AnimationStateSet::HasAnimationState( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::AnimationStateSet*>(_native)->hasAnimationState( o_name );
	}
	
	void AnimationStateSet::RemoveAnimationState( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::AnimationStateSet*>(_native)->removeAnimationState( o_name );
	}
	
	void AnimationStateSet::RemoveAllAnimationStates( )
	{
		static_cast<Ogre::AnimationStateSet*>(_native)->removeAllAnimationStates( );
	}
	
	Mogre::AnimationStateIterator^ AnimationStateSet::GetAnimationStateIterator( )
	{
		return static_cast<Ogre::AnimationStateSet*>(_native)->getAnimationStateIterator( );
	}
	
	void AnimationStateSet::CopyMatchingState( Mogre::AnimationStateSet^ target )
	{
		static_cast<const Ogre::AnimationStateSet*>(_native)->copyMatchingState( target );
	}
	
	void AnimationStateSet::_notifyDirty( )
	{
		static_cast<Ogre::AnimationStateSet*>(_native)->_notifyDirty( );
	}
	
	void AnimationStateSet::_notifyAnimationStateEnabled( Mogre::AnimationState^ target, bool enabled )
	{
		static_cast<Ogre::AnimationStateSet*>(_native)->_notifyAnimationStateEnabled( target, enabled );
	}
	
	Mogre::ConstEnabledAnimationStateIterator^ AnimationStateSet::GetEnabledAnimationStateIterator( )
	{
		return static_cast<const Ogre::AnimationStateSet*>(_native)->getEnabledAnimationStateIterator( );
	}
	
	
	//Protected Declarations
	
	
	
	#define STLDECL_MANAGEDKEY String^
	#define STLDECL_MANAGEDVALUE Mogre::AnimationState^
	#define STLDECL_NATIVEKEY Ogre::String
	#define STLDECL_NATIVEVALUE Ogre::AnimationState*
	CPP_DECLARE_STLMAP( , AnimationStateMap, STLDECL_MANAGEDKEY, STLDECL_MANAGEDVALUE, STLDECL_NATIVEKEY, STLDECL_NATIVEVALUE )
	#undef STLDECL_MANAGEDKEY
	#undef STLDECL_MANAGEDVALUE
	#undef STLDECL_NATIVEKEY
	#undef STLDECL_NATIVEVALUE
	
	CPP_DECLARE_MAP_ITERATOR( , AnimationStateIterator, Ogre::AnimationStateIterator, Mogre::AnimationStateMap, Mogre::AnimationState^, Ogre::AnimationState*, String^, Ogre::String,  )
	
	#define STLDECL_MANAGEDTYPE Mogre::AnimationState^
	#define STLDECL_NATIVETYPE Ogre::AnimationState*
	CPP_DECLARE_STLLIST( , EnabledAnimationStateList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	CPP_DECLARE_ITERATOR( , ConstEnabledAnimationStateIterator, Ogre::ConstEnabledAnimationStateIterator, Mogre::EnabledAnimationStateList, Mogre::AnimationState^, Ogre::AnimationState*, const )
	

}
