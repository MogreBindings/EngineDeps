/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreGpuProgramParams.h"
#include "MogreDataStream.h"

namespace Mogre
{
	//################################################################
	//GpuConstantDefinition_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::GpuConstantType GpuConstantDefinition_NativePtr::constType::get()
	{
		return (Mogre::GpuConstantType)_native->constType;
	}
	void GpuConstantDefinition_NativePtr::constType::set( Mogre::GpuConstantType value )
	{
		_native->constType = (Ogre::GpuConstantType)value;
	}
	
	size_t GpuConstantDefinition_NativePtr::physicalIndex::get()
	{
		return _native->physicalIndex;
	}
	void GpuConstantDefinition_NativePtr::physicalIndex::set( size_t value )
	{
		_native->physicalIndex = value;
	}
	
	size_t GpuConstantDefinition_NativePtr::logicalIndex::get()
	{
		return _native->logicalIndex;
	}
	void GpuConstantDefinition_NativePtr::logicalIndex::set( size_t value )
	{
		_native->logicalIndex = value;
	}
	
	size_t GpuConstantDefinition_NativePtr::elementSize::get()
	{
		return _native->elementSize;
	}
	void GpuConstantDefinition_NativePtr::elementSize::set( size_t value )
	{
		_native->elementSize = value;
	}
	
	size_t GpuConstantDefinition_NativePtr::arraySize::get()
	{
		return _native->arraySize;
	}
	void GpuConstantDefinition_NativePtr::arraySize::set( size_t value )
	{
		_native->arraySize = value;
	}
	
	Mogre::uint16 GpuConstantDefinition_NativePtr::variability::get()
	{
		return _native->variability;
	}
	void GpuConstantDefinition_NativePtr::variability::set( Mogre::uint16 value )
	{
		_native->variability = value;
	}
	
	bool GpuConstantDefinition_NativePtr::IsFloat::get()
	{
		return _native->isFloat( );
	}
	
	bool GpuConstantDefinition_NativePtr::IsSampler::get()
	{
		return _native->isSampler( );
	}
	
	
	Mogre::GpuConstantDefinition_NativePtr GpuConstantDefinition_NativePtr::Create( )
	{
		GpuConstantDefinition_NativePtr ptr;
		ptr._native = new Ogre::GpuConstantDefinition();
		return ptr;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GpuNamedConstants
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuNamedConstants::GpuNamedConstants( )
	{
		_createdByCLR = true;
		_native = new Ogre::GpuNamedConstants();
	}
	
	size_t GpuNamedConstants::floatBufferSize::get()
	{
		return static_cast<Ogre::GpuNamedConstants*>(_native)->floatBufferSize;
	}
	void GpuNamedConstants::floatBufferSize::set( size_t value )
	{
		static_cast<Ogre::GpuNamedConstants*>(_native)->floatBufferSize = value;
	}
	
	size_t GpuNamedConstants::intBufferSize::get()
	{
		return static_cast<Ogre::GpuNamedConstants*>(_native)->intBufferSize;
	}
	void GpuNamedConstants::intBufferSize::set( size_t value )
	{
		static_cast<Ogre::GpuNamedConstants*>(_native)->intBufferSize = value;
	}
	
	Mogre::GpuConstantDefinitionMap^ GpuNamedConstants::map::get()
	{
		return ( CLR_NULL == _map ) ? (_map = static_cast<Ogre::GpuNamedConstants*>(_native)->map) : _map;
	}
	
	void GpuNamedConstants::GenerateConstantDefinitionArrayEntries( String^ paramName, Mogre::GpuConstantDefinition_NativePtr baseDef )
	{
		DECLARE_NATIVE_STRING( o_paramName, paramName )
	
		static_cast<Ogre::GpuNamedConstants*>(_native)->generateConstantDefinitionArrayEntries( o_paramName, baseDef );
	}
	
	void GpuNamedConstants::Save( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<const Ogre::GpuNamedConstants*>(_native)->save( o_filename );
	}
	
	void GpuNamedConstants::Load( Mogre::DataStreamPtr^ stream )
	{
		static_cast<Ogre::GpuNamedConstants*>(_native)->load( (Ogre::DataStreamPtr&)stream );
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GpuNamedConstantsSerializer
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuNamedConstantsSerializer::GpuNamedConstantsSerializer( ) : Serializer((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::GpuNamedConstantsSerializer();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void GpuNamedConstantsSerializer::ExportNamedConstants( Mogre::GpuNamedConstants^ pConsts, String^ filename, Mogre::Serializer::Endian endianMode )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::GpuNamedConstantsSerializer*>(_native)->exportNamedConstants( pConsts, o_filename, (Ogre::Serializer::Endian)endianMode );
	}
	void GpuNamedConstantsSerializer::ExportNamedConstants( Mogre::GpuNamedConstants^ pConsts, String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::GpuNamedConstantsSerializer*>(_native)->exportNamedConstants( pConsts, o_filename );
	}
	
	void GpuNamedConstantsSerializer::ImportNamedConstants( Mogre::DataStreamPtr^ stream, Mogre::GpuNamedConstants^ pDest )
	{
		static_cast<Ogre::GpuNamedConstantsSerializer*>(_native)->importNamedConstants( (Ogre::DataStreamPtr&)stream, pDest );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_GpuNamedConstantsSerializer(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::GpuNamedConstantsSerializer(pClrObj);
	}
	
	//################################################################
	//GpuLogicalBufferStruct
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuLogicalBufferStruct::GpuLogicalBufferStruct( )
	{
		_createdByCLR = true;
		_native = new Ogre::GpuLogicalBufferStruct();
	}
	
	size_t GpuLogicalBufferStruct::bufferSize::get()
	{
		return static_cast<Ogre::GpuLogicalBufferStruct*>(_native)->bufferSize;
	}
	void GpuLogicalBufferStruct::bufferSize::set( size_t value )
	{
		static_cast<Ogre::GpuLogicalBufferStruct*>(_native)->bufferSize = value;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GpuSharedParameters
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuSharedParameters::GpuSharedParameters( String^ name )
	{
		_createdByCLR = true;
		DECLARE_NATIVE_STRING( o_name, name )
	
		_native = new Ogre::GpuSharedParameters( o_name);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle GpuSharedParameters::_CLRHandle::get()
	{
		return static_cast<Ogre::GpuSharedParameters*>(_native)->_CLRHandle;
	}
	void GpuSharedParameters::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::GpuSharedParameters*>(_native)->_CLRHandle = value;
	}
	
	Mogre::GpuNamedConstants^ GpuSharedParameters::ConstantDefinitions::get()
	{
		return static_cast<const Ogre::GpuSharedParameters*>(_native)->getConstantDefinitions( );
	}
	
	size_t GpuSharedParameters::FrameLastUpdated::get()
	{
		return static_cast<const Ogre::GpuSharedParameters*>(_native)->getFrameLastUpdated( );
	}
	
	String^ GpuSharedParameters::Name::get()
	{
		return TO_CLR_STRING( static_cast<Ogre::GpuSharedParameters*>(_native)->getName( ) );
	}
	
	unsigned long GpuSharedParameters::Version::get()
	{
		return static_cast<const Ogre::GpuSharedParameters*>(_native)->getVersion( );
	}
	
	void GpuSharedParameters::AddConstantDefinition( String^ name, Mogre::GpuConstantType constType, size_t arraySize )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->addConstantDefinition( o_name, (Ogre::GpuConstantType)constType, arraySize );
	}
	void GpuSharedParameters::AddConstantDefinition( String^ name, Mogre::GpuConstantType constType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->addConstantDefinition( o_name, (Ogre::GpuConstantType)constType );
	}
	
	void GpuSharedParameters::RemoveConstantDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->removeConstantDefinition( o_name );
	}
	
	void GpuSharedParameters::RemoveAllConstantDefinitions( )
	{
		static_cast<Ogre::GpuSharedParameters*>(_native)->removeAllConstantDefinitions( );
	}
	
	void GpuSharedParameters::_markDirty( )
	{
		static_cast<Ogre::GpuSharedParameters*>(_native)->_markDirty( );
	}
	
	Mogre::GpuConstantDefinitionIterator^ GpuSharedParameters::GetConstantDefinitionIterator( )
	{
		return static_cast<const Ogre::GpuSharedParameters*>(_native)->getConstantDefinitionIterator( );
	}
	
	Mogre::GpuConstantDefinition_NativePtr GpuSharedParameters::GetConstantDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::GpuSharedParameters*>(_native)->getConstantDefinition( o_name );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, Mogre::Real val )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, val );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, int val )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, val );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, Mogre::Vector4 vec )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, vec );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, Mogre::Vector3 vec )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, vec );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, Mogre::Matrix4^ m )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		pin_ptr<Ogre::Matrix4> p_m = interior_ptr<Ogre::Matrix4>(&m->m00);
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, *p_m );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, const Mogre::Matrix4::NativeValue* m, size_t numEntries )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		const Ogre::Matrix4* o_m = reinterpret_cast<const Ogre::Matrix4*>(m);
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, o_m, numEntries );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, const float* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, const double* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, Mogre::ColourValue colour )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, colour );
	}
	
	void GpuSharedParameters::SetNamedConstant( String^ name, const int* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuSharedParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	float* GpuSharedParameters::GetFloatPointer( size_t pos )
	{
		return static_cast<Ogre::GpuSharedParameters*>(_native)->getFloatPointer( pos );
	}
	
	int* GpuSharedParameters::GetIntPointer( size_t pos )
	{
		return static_cast<Ogre::GpuSharedParameters*>(_native)->getIntPointer( pos );
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GpuSharedParametersUsage
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuSharedParametersUsage::GpuSharedParametersUsage( Mogre::GpuSharedParametersPtr^ sharedParams, Mogre::GpuProgramParameters^ params )
	{
		_createdByCLR = true;
		_native = new Ogre::GpuSharedParametersUsage( (Ogre::GpuSharedParametersPtr)sharedParams, params);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle GpuSharedParametersUsage::_CLRHandle::get()
	{
		return static_cast<Ogre::GpuSharedParametersUsage*>(_native)->_CLRHandle;
	}
	void GpuSharedParametersUsage::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::GpuSharedParametersUsage*>(_native)->_CLRHandle = value;
	}
	
	String^ GpuSharedParametersUsage::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuSharedParametersUsage*>(_native)->getName( ) );
	}
	
	Mogre::GpuProgramParameters^ GpuSharedParametersUsage::TargetParams::get()
	{
		return static_cast<const Ogre::GpuSharedParametersUsage*>(_native)->getTargetParams( );
	}
	
	void GpuSharedParametersUsage::_copySharedParamsToTargetParams( )
	{
		static_cast<Ogre::GpuSharedParametersUsage*>(_native)->_copySharedParamsToTargetParams( );
	}
	
	Mogre::GpuSharedParametersPtr^ GpuSharedParametersUsage::GetSharedParams( )
	{
		return static_cast<const Ogre::GpuSharedParametersUsage*>(_native)->getSharedParams( );
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//GpuProgramParameters
	//################################################################
	
	//Nested Types
	//################################################################
	//AutoConstantDefinition_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::GpuProgramParameters::AutoConstantType GpuProgramParameters::AutoConstantDefinition_NativePtr::acType::get()
	{
		return (Mogre::GpuProgramParameters::AutoConstantType)_native->acType;
	}
	void GpuProgramParameters::AutoConstantDefinition_NativePtr::acType::set( Mogre::GpuProgramParameters::AutoConstantType value )
	{
		_native->acType = (Ogre::GpuProgramParameters::AutoConstantType)value;
	}
	
	String^ GpuProgramParameters::AutoConstantDefinition_NativePtr::name::get()
	{
		return TO_CLR_STRING( _native->name );
	}
	void GpuProgramParameters::AutoConstantDefinition_NativePtr::name::set( String^ value )
	{
		DECLARE_NATIVE_STRING( o_value, value )
	
		_native->name = o_value;
	}
	
	size_t GpuProgramParameters::AutoConstantDefinition_NativePtr::elementCount::get()
	{
		return _native->elementCount;
	}
	void GpuProgramParameters::AutoConstantDefinition_NativePtr::elementCount::set( size_t value )
	{
		_native->elementCount = value;
	}
	
	Mogre::GpuProgramParameters::ElementType GpuProgramParameters::AutoConstantDefinition_NativePtr::elementType::get()
	{
		return (Mogre::GpuProgramParameters::ElementType)_native->elementType;
	}
	void GpuProgramParameters::AutoConstantDefinition_NativePtr::elementType::set( Mogre::GpuProgramParameters::ElementType value )
	{
		_native->elementType = (Ogre::GpuProgramParameters::ElementType)value;
	}
	
	Mogre::GpuProgramParameters::ACDataType GpuProgramParameters::AutoConstantDefinition_NativePtr::dataType::get()
	{
		return (Mogre::GpuProgramParameters::ACDataType)_native->dataType;
	}
	void GpuProgramParameters::AutoConstantDefinition_NativePtr::dataType::set( Mogre::GpuProgramParameters::ACDataType value )
	{
		_native->dataType = (Ogre::GpuProgramParameters::ACDataType)value;
	}
	
	
	Mogre::GpuProgramParameters::AutoConstantDefinition_NativePtr GpuProgramParameters::AutoConstantDefinition_NativePtr::Create( Mogre::GpuProgramParameters::AutoConstantType _acType, String^ _name, size_t _elementCount, Mogre::GpuProgramParameters::ElementType _elementType, Mogre::GpuProgramParameters::ACDataType _dataType )
	{
		DECLARE_NATIVE_STRING( o__name, _name )
	
		AutoConstantDefinition_NativePtr ptr;
		ptr._native = new Ogre::GpuProgramParameters::AutoConstantDefinition( (Ogre::GpuProgramParameters::AutoConstantType)_acType, o__name, _elementCount, (Ogre::GpuProgramParameters::ElementType)_elementType, (Ogre::GpuProgramParameters::ACDataType)_dataType);
		return ptr;
	}
	
	
	//Protected Declarations
	
	
	
	//################################################################
	//AutoConstantEntry_NativePtr
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	
	Mogre::GpuProgramParameters::AutoConstantType GpuProgramParameters::AutoConstantEntry_NativePtr::paramType::get()
	{
		return (Mogre::GpuProgramParameters::AutoConstantType)_native->paramType;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::paramType::set( Mogre::GpuProgramParameters::AutoConstantType value )
	{
		_native->paramType = (Ogre::GpuProgramParameters::AutoConstantType)value;
	}
	
	size_t GpuProgramParameters::AutoConstantEntry_NativePtr::physicalIndex::get()
	{
		return _native->physicalIndex;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::physicalIndex::set( size_t value )
	{
		_native->physicalIndex = value;
	}
	
	size_t GpuProgramParameters::AutoConstantEntry_NativePtr::elementCount::get()
	{
		return _native->elementCount;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::elementCount::set( size_t value )
	{
		_native->elementCount = value;
	}
	
	size_t GpuProgramParameters::AutoConstantEntry_NativePtr::data::get()
	{
		return _native->data;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::data::set( size_t value )
	{
		_native->data = value;
	}
	
	Mogre::Real GpuProgramParameters::AutoConstantEntry_NativePtr::fData::get()
	{
		return _native->fData;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::fData::set( Mogre::Real value )
	{
		_native->fData = value;
	}
	
	Mogre::uint16 GpuProgramParameters::AutoConstantEntry_NativePtr::variability::get()
	{
		return _native->variability;
	}
	void GpuProgramParameters::AutoConstantEntry_NativePtr::variability::set( Mogre::uint16 value )
	{
		_native->variability = value;
	}
	
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::AutoConstantEntry_NativePtr::Create( Mogre::GpuProgramParameters::AutoConstantType theType, size_t theIndex, size_t theData, Mogre::uint16 theVariability, size_t theElemCount )
	{
		AutoConstantEntry_NativePtr ptr;
		ptr._native = new Ogre::GpuProgramParameters::AutoConstantEntry( (Ogre::GpuProgramParameters::AutoConstantType)theType, theIndex, theData, theVariability, theElemCount);
		return ptr;
	}
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::AutoConstantEntry_NativePtr::Create( Mogre::GpuProgramParameters::AutoConstantType theType, size_t theIndex, size_t theData, Mogre::uint16 theVariability )
	{
		AutoConstantEntry_NativePtr ptr;
		ptr._native = new Ogre::GpuProgramParameters::AutoConstantEntry( (Ogre::GpuProgramParameters::AutoConstantType)theType, theIndex, theData, theVariability);
		return ptr;
	}
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::AutoConstantEntry_NativePtr::Create( Mogre::GpuProgramParameters::AutoConstantType theType, size_t theIndex, Mogre::Real theData, Mogre::uint16 theVariability, size_t theElemCount )
	{
		AutoConstantEntry_NativePtr ptr;
		ptr._native = new Ogre::GpuProgramParameters::AutoConstantEntry( (Ogre::GpuProgramParameters::AutoConstantType)theType, theIndex, theData, theVariability, theElemCount);
		return ptr;
	}
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::AutoConstantEntry_NativePtr::Create( Mogre::GpuProgramParameters::AutoConstantType theType, size_t theIndex, Mogre::Real theData, Mogre::uint16 theVariability )
	{
		AutoConstantEntry_NativePtr ptr;
		ptr._native = new Ogre::GpuProgramParameters::AutoConstantEntry( (Ogre::GpuProgramParameters::AutoConstantType)theType, theIndex, theData, theVariability);
		return ptr;
	}
	
	
	//Protected Declarations
	
	
	
	#define STLDECL_MANAGEDTYPE Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr
	#define STLDECL_NATIVETYPE Ogre::GpuProgramParameters::AutoConstantEntry
	CPP_DECLARE_STLVECTOR( GpuProgramParameters::, AutoConstantList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	#define STLDECL_MANAGEDTYPE Mogre::GpuSharedParametersUsage^
	#define STLDECL_NATIVETYPE Ogre::GpuSharedParametersUsage
	CPP_DECLARE_STLVECTOR( GpuProgramParameters::, GpuSharedParamUsageList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	CPP_DECLARE_ITERATOR( GpuProgramParameters::, AutoConstantIterator, Ogre::GpuProgramParameters::AutoConstantIterator, Mogre::GpuProgramParameters::AutoConstantList, Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr, Ogre::GpuProgramParameters::AutoConstantEntry,  )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	GpuProgramParameters::GpuProgramParameters( )
	{
		_createdByCLR = true;
		_native = new Ogre::GpuProgramParameters();
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	GpuProgramParameters::GpuProgramParameters( Mogre::GpuProgramParameters^ oth )
	{
		_createdByCLR = true;
		_native = new Ogre::GpuProgramParameters( oth);
	
		_native->_CLRHandle._MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	CLRHandle GpuProgramParameters::_CLRHandle::get()
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->_CLRHandle;
	}
	void GpuProgramParameters::_CLRHandle::set( CLRHandle value )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_CLRHandle = value;
	}
	
	size_t GpuProgramParameters::AutoConstantCount::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getAutoConstantCount( );
	}
	
	Mogre::GpuNamedConstants^ GpuProgramParameters::ConstantDefinitions::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getConstantDefinitions( );
	}
	
	bool GpuProgramParameters::HasAutoConstants::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->hasAutoConstants( );
	}
	
	bool GpuProgramParameters::HasLogicalIndexedParameters::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->hasLogicalIndexedParameters( );
	}
	
	bool GpuProgramParameters::HasNamedParameters::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->hasNamedParameters( );
	}
	
	bool GpuProgramParameters::HasPassIterationNumber::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->hasPassIterationNumber( );
	}
	
	size_t GpuProgramParameters::NumAutoConstantDefinitions::get()
	{
		return Ogre::GpuProgramParameters::getNumAutoConstantDefinitions( );
	}
	
	size_t GpuProgramParameters::PassIterationNumberIndex::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getPassIterationNumberIndex( );
	}
	
	bool GpuProgramParameters::TransposeMatrices::get()
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getTransposeMatrices( );
	}
	void GpuProgramParameters::TransposeMatrices::set( bool val )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setTransposeMatrices( val );
	}
	
	
	void GpuProgramParameters::_setNamedConstants( Mogre::GpuNamedConstantsPtr^ constantmap )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setNamedConstants( (const Ogre::GpuNamedConstantsPtr&)constantmap );
	}
	
	void GpuProgramParameters::_setLogicalIndexes( Mogre::GpuLogicalBufferStructPtr^ floatIndexMap, Mogre::GpuLogicalBufferStructPtr^ intIndexMap )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setLogicalIndexes( (const Ogre::GpuLogicalBufferStructPtr&)floatIndexMap, (const Ogre::GpuLogicalBufferStructPtr&)intIndexMap );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, Mogre::Vector4 vec )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, vec );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, Mogre::Real val )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, val );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, Mogre::Vector3 vec )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, vec );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, Mogre::Matrix4^ m )
	{
		pin_ptr<Ogre::Matrix4> p_m = interior_ptr<Ogre::Matrix4>(&m->m00);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, *p_m );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, const Mogre::Matrix4::NativeValue* m, size_t numEntries )
	{
		const Ogre::Matrix4* o_m = reinterpret_cast<const Ogre::Matrix4*>(m);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, o_m, numEntries );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, const float* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, val, count );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, const double* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, val, count );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, Mogre::ColourValue colour )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, colour );
	}
	
	void GpuProgramParameters::SetConstant( size_t index, const int* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstant( index, val, count );
	}
	
	void GpuProgramParameters::_writeRawConstants( size_t physicalIndex, const float* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstants( physicalIndex, val, count );
	}
	
	void GpuProgramParameters::_writeRawConstants( size_t physicalIndex, const double* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstants( physicalIndex, val, count );
	}
	
	void GpuProgramParameters::_writeRawConstants( size_t physicalIndex, const int* val, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstants( physicalIndex, val, count );
	}
	
	void GpuProgramParameters::_readRawConstants( size_t physicalIndex, size_t count, [Out] float% dest )
	{
		pin_ptr<float> p_dest = &dest;
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->_readRawConstants( physicalIndex, count, p_dest );
	}
	
	void GpuProgramParameters::_readRawConstants( size_t physicalIndex, size_t count, [Out] int% dest )
	{
		pin_ptr<int> p_dest = &dest;
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->_readRawConstants( physicalIndex, count, p_dest );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::Vector4 vec, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, vec, count );
	}
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::Vector4 vec )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, vec );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::Real val )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, val );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, int val )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, val );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::Vector3 vec )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, vec );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::Matrix4^ m, size_t elementCount )
	{
		pin_ptr<Ogre::Matrix4> p_m = interior_ptr<Ogre::Matrix4>(&m->m00);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, *p_m, elementCount );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, const Mogre::Matrix4::NativeValue* m, size_t numEntries )
	{
		const Ogre::Matrix4* o_m = reinterpret_cast<const Ogre::Matrix4*>(m);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, o_m, numEntries );
	}
	
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::ColourValue colour, size_t count )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, colour, count );
	}
	void GpuProgramParameters::_writeRawConstant( size_t physicalIndex, Mogre::ColourValue colour )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_writeRawConstant( physicalIndex, colour );
	}
	
	Mogre::GpuConstantDefinitionIterator^ GpuProgramParameters::GetConstantDefinitionIterator( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getConstantDefinitionIterator( );
	}
	
	Mogre::GpuConstantDefinition_NativePtr GpuProgramParameters::GetConstantDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getConstantDefinition( o_name );
	}
	
	Mogre::GpuLogicalBufferStructPtr^ GpuProgramParameters::GetFloatLogicalBufferStruct( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getFloatLogicalBufferStruct( );
	}
	
	size_t GpuProgramParameters::GetFloatLogicalIndexForPhysicalIndex( size_t physicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->getFloatLogicalIndexForPhysicalIndex( physicalIndex );
	}
	
	size_t GpuProgramParameters::GetIntLogicalIndexForPhysicalIndex( size_t physicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->getIntLogicalIndexForPhysicalIndex( physicalIndex );
	}
	
	Mogre::GpuLogicalBufferStructPtr^ GpuProgramParameters::GetIntLogicalBufferStruct( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getIntLogicalBufferStruct( );
	}
	
	Mogre::Const_FloatConstantList^ GpuProgramParameters::GetFloatConstantList( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getFloatConstantList( );
	}
	
	float* GpuProgramParameters::GetFloatPointer( size_t pos )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->getFloatPointer( pos );
	}
	
	Mogre::Const_IntConstantList^ GpuProgramParameters::GetIntConstantList( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getIntConstantList( );
	}
	
	int* GpuProgramParameters::GetIntPointer( size_t pos )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->getIntPointer( pos );
	}
	
	Mogre::GpuProgramParameters::Const_AutoConstantList^ GpuProgramParameters::GetAutoConstantList( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getAutoConstantList( );
	}
	
	void GpuProgramParameters::SetAutoConstant( size_t index, Mogre::GpuProgramParameters::AutoConstantType acType, size_t extraInfo )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setAutoConstant( index, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo );
	}
	void GpuProgramParameters::SetAutoConstant( size_t index, Mogre::GpuProgramParameters::AutoConstantType acType )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setAutoConstant( index, (Ogre::GpuProgramParameters::AutoConstantType)acType );
	}
	
	void GpuProgramParameters::SetAutoConstantReal( size_t index, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::Real rData )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setAutoConstantReal( index, (Ogre::GpuProgramParameters::AutoConstantType)acType, rData );
	}
	
	void GpuProgramParameters::SetAutoConstant( size_t index, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::uint16 extraInfo1, Mogre::uint16 extraInfo2 )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setAutoConstant( index, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo1, extraInfo2 );
	}
	
	void GpuProgramParameters::_setRawAutoConstant( size_t physicalIndex, Mogre::GpuProgramParameters::AutoConstantType acType, size_t extraInfo, Mogre::uint16 variability, size_t elementSize )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setRawAutoConstant( physicalIndex, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo, variability, elementSize );
	}
	void GpuProgramParameters::_setRawAutoConstant( size_t physicalIndex, Mogre::GpuProgramParameters::AutoConstantType acType, size_t extraInfo, Mogre::uint16 variability )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setRawAutoConstant( physicalIndex, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo, variability );
	}
	
	void GpuProgramParameters::_setRawAutoConstantReal( size_t physicalIndex, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::Real rData, Mogre::uint16 variability, size_t elementSize )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setRawAutoConstantReal( physicalIndex, (Ogre::GpuProgramParameters::AutoConstantType)acType, rData, variability, elementSize );
	}
	void GpuProgramParameters::_setRawAutoConstantReal( size_t physicalIndex, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::Real rData, Mogre::uint16 variability )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_setRawAutoConstantReal( physicalIndex, (Ogre::GpuProgramParameters::AutoConstantType)acType, rData, variability );
	}
	
	void GpuProgramParameters::ClearAutoConstant( size_t index )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->clearAutoConstant( index );
	}
	
	void GpuProgramParameters::SetConstantFromTime( size_t index, Mogre::Real factor )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setConstantFromTime( index, factor );
	}
	
	void GpuProgramParameters::ClearAutoConstants( )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->clearAutoConstants( );
	}
	
	Mogre::GpuProgramParameters::AutoConstantIterator^ GpuProgramParameters::GetAutoConstantIterator( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getAutoConstantIterator( );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::GetAutoConstantEntry( size_t index )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->getAutoConstantEntry( index );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::FindFloatAutoConstantEntry( size_t logicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->findFloatAutoConstantEntry( logicalIndex );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::FindIntAutoConstantEntry( size_t logicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->findIntAutoConstantEntry( logicalIndex );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::FindAutoConstantEntry( String^ paramName )
	{
		DECLARE_NATIVE_STRING( o_paramName, paramName )
	
		return static_cast<Ogre::GpuProgramParameters*>(_native)->findAutoConstantEntry( o_paramName );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::_findRawAutoConstantEntryFloat( size_t physicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->_findRawAutoConstantEntryFloat( physicalIndex );
	}
	
	Mogre::GpuProgramParameters::AutoConstantEntry_NativePtr GpuProgramParameters::_findRawAutoConstantEntryInt( size_t physicalIndex )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->_findRawAutoConstantEntryInt( physicalIndex );
	}
	
	void GpuProgramParameters::SetIgnoreMissingParams( bool state )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->setIgnoreMissingParams( state );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, Mogre::Real val )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, int val )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, Mogre::Vector4 vec )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, vec );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, Mogre::Vector3 vec )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, vec );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, Mogre::Matrix4^ m )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		pin_ptr<Ogre::Matrix4> p_m = interior_ptr<Ogre::Matrix4>(&m->m00);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, *p_m );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, const Mogre::Matrix4::NativeValue* m, size_t numEntries )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		const Ogre::Matrix4* o_m = reinterpret_cast<const Ogre::Matrix4*>(m);
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, o_m, numEntries );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, const float* val, size_t count, size_t multiple )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count, multiple );
	}
	void GpuProgramParameters::SetNamedConstant( String^ name, const float* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, const double* val, size_t count, size_t multiple )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count, multiple );
	}
	void GpuProgramParameters::SetNamedConstant( String^ name, const double* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, Mogre::ColourValue colour )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, colour );
	}
	
	void GpuProgramParameters::SetNamedConstant( String^ name, const int* val, size_t count, size_t multiple )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count, multiple );
	}
	void GpuProgramParameters::SetNamedConstant( String^ name, const int* val, size_t count )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstant( o_name, val, count );
	}
	
	void GpuProgramParameters::SetNamedAutoConstant( String^ name, Mogre::GpuProgramParameters::AutoConstantType acType, size_t extraInfo )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedAutoConstant( o_name, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo );
	}
	void GpuProgramParameters::SetNamedAutoConstant( String^ name, Mogre::GpuProgramParameters::AutoConstantType acType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedAutoConstant( o_name, (Ogre::GpuProgramParameters::AutoConstantType)acType );
	}
	
	void GpuProgramParameters::SetNamedAutoConstantReal( String^ name, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::Real rData )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedAutoConstantReal( o_name, (Ogre::GpuProgramParameters::AutoConstantType)acType, rData );
	}
	
	void GpuProgramParameters::SetNamedAutoConstant( String^ name, Mogre::GpuProgramParameters::AutoConstantType acType, Mogre::uint16 extraInfo1, Mogre::uint16 extraInfo2 )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedAutoConstant( o_name, (Ogre::GpuProgramParameters::AutoConstantType)acType, extraInfo1, extraInfo2 );
	}
	
	void GpuProgramParameters::SetNamedConstantFromTime( String^ name, Mogre::Real factor )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->setNamedConstantFromTime( o_name, factor );
	}
	
	void GpuProgramParameters::ClearNamedAutoConstant( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->clearNamedAutoConstant( o_name );
	}
	
	Mogre::GpuConstantDefinition_NativePtr GpuProgramParameters::_findNamedConstantDefinition( String^ name, bool throwExceptionIfMissing )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->_findNamedConstantDefinition( o_name, throwExceptionIfMissing );
	}
	Mogre::GpuConstantDefinition_NativePtr GpuProgramParameters::_findNamedConstantDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->_findNamedConstantDefinition( o_name );
	}
	
	size_t GpuProgramParameters::_getFloatConstantPhysicalIndex( size_t logicalIndex, size_t requestedSize, Mogre::uint16 variability )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->_getFloatConstantPhysicalIndex( logicalIndex, requestedSize, variability );
	}
	
	size_t GpuProgramParameters::_getIntConstantPhysicalIndex( size_t logicalIndex, size_t requestedSize, Mogre::uint16 variability )
	{
		return static_cast<Ogre::GpuProgramParameters*>(_native)->_getIntConstantPhysicalIndex( logicalIndex, requestedSize, variability );
	}
	
	void GpuProgramParameters::CopyConstantsFrom( Mogre::GpuProgramParameters^ source )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->copyConstantsFrom( source );
	}
	
	void GpuProgramParameters::CopyMatchingNamedConstantsFrom( Mogre::GpuProgramParameters^ source )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->copyMatchingNamedConstantsFrom( source );
	}
	
	void GpuProgramParameters::IncPassIterationNumber( )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->incPassIterationNumber( );
	}
	
	void GpuProgramParameters::AddSharedParameters( Mogre::GpuSharedParametersPtr^ sharedParams )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->addSharedParameters( (Ogre::GpuSharedParametersPtr)sharedParams );
	}
	
	void GpuProgramParameters::AddSharedParameters( String^ sharedParamsName )
	{
		DECLARE_NATIVE_STRING( o_sharedParamsName, sharedParamsName )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->addSharedParameters( o_sharedParamsName );
	}
	
	bool GpuProgramParameters::IsUsingSharedParameters( String^ sharedParamsName )
	{
		DECLARE_NATIVE_STRING( o_sharedParamsName, sharedParamsName )
	
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->isUsingSharedParameters( o_sharedParamsName );
	}
	
	void GpuProgramParameters::RemoveSharedParameters( String^ sharedParamsName )
	{
		DECLARE_NATIVE_STRING( o_sharedParamsName, sharedParamsName )
	
		static_cast<Ogre::GpuProgramParameters*>(_native)->removeSharedParameters( o_sharedParamsName );
	}
	
	void GpuProgramParameters::RemoveAllSharedParameters( )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->removeAllSharedParameters( );
	}
	
	Mogre::GpuProgramParameters::Const_GpuSharedParamUsageList^ GpuProgramParameters::GetSharedParameters( )
	{
		return static_cast<const Ogre::GpuProgramParameters*>(_native)->getSharedParameters( );
	}
	
	void GpuProgramParameters::_copySharedParams( )
	{
		static_cast<Ogre::GpuProgramParameters*>(_native)->_copySharedParams( );
	}
	
	Mogre::GpuProgramParameters::AutoConstantDefinition_NativePtr GpuProgramParameters::GetAutoConstantDefinition( String^ name )
	{
		DECLARE_NATIVE_STRING( o_name, name )
	
		return Ogre::GpuProgramParameters::getAutoConstantDefinition( o_name );
	}
	
	Mogre::GpuProgramParameters::AutoConstantDefinition_NativePtr GpuProgramParameters::GetAutoConstantDefinition( size_t idx )
	{
		return Ogre::GpuProgramParameters::getAutoConstantDefinition( idx );
	}
	
	
	//Protected Declarations
	
	
	
	#define STLDECL_MANAGEDKEY String^
	#define STLDECL_MANAGEDVALUE Mogre::GpuConstantDefinition_NativePtr
	#define STLDECL_NATIVEKEY Ogre::String
	#define STLDECL_NATIVEVALUE Ogre::GpuConstantDefinition
	CPP_DECLARE_STLMAP( , GpuConstantDefinitionMap, STLDECL_MANAGEDKEY, STLDECL_MANAGEDVALUE, STLDECL_NATIVEKEY, STLDECL_NATIVEVALUE )
	#undef STLDECL_MANAGEDKEY
	#undef STLDECL_MANAGEDVALUE
	#undef STLDECL_NATIVEKEY
	#undef STLDECL_NATIVEVALUE
	
	CPP_DECLARE_MAP_ITERATOR( , GpuConstantDefinitionIterator, Ogre::GpuConstantDefinitionIterator, Mogre::GpuConstantDefinitionMap, Mogre::GpuConstantDefinition_NativePtr, Ogre::GpuConstantDefinition, String^, Ogre::String,  )
	
	#define STLDECL_MANAGEDTYPE float
	#define STLDECL_NATIVETYPE float
	CPP_DECLARE_STLVECTOR( , FloatConstantList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	
	#define STLDECL_MANAGEDTYPE int
	#define STLDECL_NATIVETYPE int
	CPP_DECLARE_STLVECTOR( , IntConstantList, STLDECL_MANAGEDTYPE, STLDECL_NATIVETYPE )
	#undef STLDECL_MANAGEDTYPE
	#undef STLDECL_NATIVETYPE
	

}
