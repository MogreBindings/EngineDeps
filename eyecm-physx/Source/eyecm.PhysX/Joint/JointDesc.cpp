//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "JointDesc.h"
#include                       "Actor.h"

//=============================+=====================================+=
JointDesc::giActor^             JointDesc::ProxyActor::Actor::get()                       { return giActor::CastOrNull( data->actor[idx] ); }
void                            JointDesc::ProxyActor::Actor::set(JointDesc::giActor^ v)  { data->actor[idx] = v == nullptr ? 0 : v->ptr; }

//=============================+=====================================+=
void                            JointDesc::SetActors(Actor^ First, Actor^ Second)
  {
    data->actor[0] = First  == nullptr ? 0 : First->ptr;
    data->actor[1] = Second == nullptr ? 0 : Second->ptr;
  }

//=============================+=====================================+=
JointDesc^                      JointDesc::Wrap(NxJointDesc& desc)
  {
    switch( desc.getType() ) {

      case NX_JOINT_PRISMATIC:      return PrismaticJointDesc::Wrap   ( desc );
      case NX_JOINT_REVOLUTE:       return RevoluteJointDesc::Wrap    ( desc );
      case NX_JOINT_CYLINDRICAL:    return CylindricalJointDesc::Wrap ( desc );
      case NX_JOINT_SPHERICAL:      return SphericalJointDesc::Wrap   ( desc );
      case NX_JOINT_POINT_ON_LINE:  return PointOnLineJointDesc::Wrap ( desc );
      case NX_JOINT_POINT_IN_PLANE: return PointInPlaneJointDesc::Wrap( desc );
      case NX_JOINT_DISTANCE:       return DistanceJointDesc::Wrap    ( desc );
      case NX_JOINT_PULLEY:         return PulleyJointDesc::Wrap      ( desc );
      case NX_JOINT_FIXED:          return FixedJointDesc::Wrap       ( desc );
      case NX_JOINT_D6:             return D6JointDesc::Wrap          ( desc );
    }

    throw gcnew Exception();
  }

//=============================+=====================================+=
JointDesc^                      JointDesc::Clone()
  {
    switch( data->getType() ) {

      case NX_JOINT_PRISMATIC:      return static_cast<PrismaticJointDesc^>   ( this )->Clone();
      case NX_JOINT_REVOLUTE:       return static_cast<RevoluteJointDesc^>    ( this )->Clone();
      case NX_JOINT_CYLINDRICAL:    return static_cast<CylindricalJointDesc^> ( this )->Clone();
      case NX_JOINT_SPHERICAL:      return static_cast<SphericalJointDesc^>   ( this )->Clone();
      case NX_JOINT_POINT_ON_LINE:  return static_cast<PointOnLineJointDesc^> ( this )->Clone();
      case NX_JOINT_POINT_IN_PLANE: return static_cast<PointInPlaneJointDesc^>( this )->Clone();
      case NX_JOINT_DISTANCE:       return static_cast<DistanceJointDesc^>    ( this )->Clone();
      case NX_JOINT_PULLEY:         return static_cast<PulleyJointDesc^>      ( this )->Clone();
      case NX_JOINT_FIXED:          return static_cast<FixedJointDesc^>       ( this )->Clone();
      case NX_JOINT_D6:             return static_cast<D6JointDesc^>          ( this )->Clone();
    }

    throw gcnew Exception();
  }
