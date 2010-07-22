//=============================+=====================================+=
#include                       "stdafx.h"
#include                       "Scene.h"
#include                       "Actor.h"
#include                       "Material.h"
#include                       "Joint.h"
#include                       "Cloth.h"
#include                       "Fluid.h"
#include                       "SoftBody.h"
#include                       "ForceField.h"
#include                       "ForceFieldKernel.h"
#include                       "nxlist.h"
#include                       "nxenumerable.h"

//=============================+=====================================+=
                                BeginNamespace

//=============================+=====================================+=
#pragma                         unmanaged                             // these are unmanaged on purpose, else compiler warns about unmanaged compilation of virtuals

//=============================+=====================================+=
NxMaterial*                     GetMaterial(NxScene* scene, int idx)  { return scene->getMaterialFromIndex( static_cast<NxMaterialIndex>( idx ) ); }
int                             GetMaterialCount(NxScene* scene)      { return static_cast<int>( scene->getNbMaterials() ); }

NxActor*                        GetActor(NxScene* scene, int idx)     { return scene->getActors()[idx]; }
int                             GetActorCount(NxScene* scene)         { return static_cast<int>( scene->getNbActors() ); }

NxCloth*                        GetCloth(NxScene* scene, int idx)     { return scene->getCloths()[idx]; }
int                             GetClothCount(NxScene* scene)         { return static_cast<int>( scene->getNbCloths() ); }

NxFluid*                        GetFluid(NxScene* scene, int idx)     { return scene->getFluids()[idx]; }
int                             GetFluidCount(NxScene* scene)         { return static_cast<int>( scene->getNbFluids() ); }

NxSoftBody*                     GetSoftBody(NxScene* scene, int idx)  { return scene->getSoftBodies()[idx]; }
int                             GetSoftBodyCount(NxScene* scene)      { return static_cast<int>( scene->getNbSoftBodies() ); }

NxForceField*                   GetForceField(NxScene* scene, int idx){ return scene->getForceFields()[idx]; }
int                             GetForceFieldCount(NxScene* scene)    { return static_cast<int>( scene->getNbForceFields() ); }

NxJoint*                        GetNextJoint(NxScene* scene)          { return scene->getNextJoint(); }
void                            ResetJoints(NxScene* scene)           { scene->resetJointIterator(); }
int                             GetJointCount(NxScene* scene)         { return static_cast<int>( scene->getNbJoints() ); }

NxForceFieldShapeGroup*         GetNextFFSG(NxScene* scene)           { return scene->getNextForceFieldShapeGroup(); }
void                            ResetFFSG(NxScene* scene)             { scene->resetForceFieldShapeGroupsIterator(); }
int                             GetFFSGCount(NxScene* scene)          { return static_cast<int>( scene->getNbForceFieldShapeGroups() ); }

NxForceFieldLinearKernel*       GetNextFFLK(NxScene* scene)           { return scene->getNextForceFieldLinearKernel(); }
void                            ResetFFLK(NxScene* scene)             { scene->resetForceFieldLinearKernelsIterator(); }
int                             GetFFLKCount(NxScene* scene)          { return static_cast<int>( scene->getNbForceFieldLinearKernels() ); }

//=============================+=====================================+=
#pragma                         managed

//=============================+=====================================+=
typedef                         giNxReadOnlyList<
                                  Scene, Material,
                                  GetMaterial, GetMaterialCount
                                >                                     MaterialCollection;

typedef                         giNxReadOnlyList<
                                  Scene, Actor,
                                  GetActor, GetActorCount
                                >                                     ActorCollection;

typedef                         giNxReadOnlyList<
                                  Scene, Cloth,
                                  GetCloth, GetClothCount
                                >                                     ClothCollection;

typedef                         giNxReadOnlyList<
                                  Scene, Fluid,
                                  GetFluid, GetFluidCount
                                >                                     FluidCollection;

typedef                         giNxReadOnlyList<
                                  Scene, SoftBody,
                                  GetSoftBody, GetSoftBodyCount
                                >                                     SoftBodyCollection;

typedef                         giNxReadOnlyList<
                                  Scene, ForceField,
                                  GetForceField, GetForceFieldCount
                                >                                     ForceFieldCollection;

//=============================+=====================================+=
void                            Scene::InitLists()
  {
    listMaterials   = gcnew MaterialCollection  ( this );
    listActors      = gcnew ActorCollection     ( this );
    listCloths      = gcnew ClothCollection     ( this );
    listFluids      = gcnew FluidCollection     ( this );
    listSoftBodys   = gcnew SoftBodyCollection  ( this );
    listForceFields = gcnew ForceFieldCollection( this );

    enumJoint                  = giNxEnumerable<Scene, Joint,                  GetNextJoint, ResetJoints, GetJointCount>::Create( this );
    enumForceFieldLinearKernel = giNxEnumerable<Scene, ForceFieldLinearKernel, GetNextFFLK,  ResetFFLK,   GetFFLKCount >::Create( this );
    enumForceFieldShapeGroup   = giNxEnumerable<Scene, ForceFieldShapeGroup,   GetNextFFSG,  ResetFFSG,   GetFFSGCount >::Create( this );
  }

//=============================+=====================================+=
void                            Scene::DeInitLists()
  {
    delete static_cast<MaterialCollection^>  ( listMaterials   ); listMaterials   = nullptr;
    delete static_cast<ActorCollection^>     ( listActors      ); listActors      = nullptr;
    delete static_cast<ClothCollection^>     ( listCloths      ); listCloths      = nullptr;
    delete static_cast<FluidCollection^>     ( listFluids      ); listFluids      = nullptr;
    delete static_cast<SoftBodyCollection^>  ( listSoftBodys   ); listSoftBodys   = nullptr;
    delete static_cast<ForceFieldCollection^>( listForceFields ); listForceFields = nullptr;

    delete enumJoint;                  enumJoint                  = nullptr;
    delete enumForceFieldLinearKernel; enumForceFieldLinearKernel = nullptr;
    delete enumForceFieldShapeGroup;   enumForceFieldShapeGroup   = nullptr;
  }

//=============================+=====================================+=
                                EndNamespace

