/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreGpuProgram.h"
#include "MogreGpuProgramParams.h"

namespace Mogre
{
	//################################################################
	//GpuProgram
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Mogre::GpuNamedConstants^ GpuProgram::ConstantDefinitions::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getConstantDefinitions( );
	}
	
	bool GpuProgram::HasCompileError::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->hasCompileError( );
	}
	
	bool GpuProgram::HasDefaultParameters::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->hasDefaultParameters( );
	}
	
	bool GpuProgram::IsAdjacencyInfoRequired::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isAdjacencyInfoRequired( );
	}
	
	bool GpuProgram::IsMorphAnimationIncluded::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isMorphAnimationIncluded( );
	}
	
	bool GpuProgram::IsPoseAnimationIncluded::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isPoseAnimationIncluded( );
	}
	
	bool GpuProgram::IsSkeletalAnimationIncluded::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isSkeletalAnimationIncluded( );
	}
	
	bool GpuProgram::IsSupported::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isSupported( );
	}
	
	bool GpuProgram::IsVertexTextureFetchRequired::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->isVertexTextureFetchRequired( );
	}
	
	String^ GpuProgram::Language::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuProgram*>(_native)->getLanguage( ) );
	}
	
	String^ GpuProgram::ManualNamedConstantsFile::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuProgram*>(_native)->getManualNamedConstantsFile( ) );
	}
	void GpuProgram::ManualNamedConstantsFile::set( String^ paramDefFile )
	{
		DECLARE_NATIVE_STRING( o_paramDefFile, paramDefFile )
	
		static_cast<Ogre::GpuProgram*>(_native)->setManualNamedConstantsFile( o_paramDefFile );
	}
	
	Mogre::GpuNamedConstants^ GpuProgram::NamedConstants::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getNamedConstants( );
	}
	
	Mogre::ushort GpuProgram::NumberOfPosesIncluded::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getNumberOfPosesIncluded( );
	}
	
	bool GpuProgram::PassFogStates::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getPassFogStates( );
	}
	
	bool GpuProgram::PassSurfaceAndLightStates::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getPassSurfaceAndLightStates( );
	}
	
	bool GpuProgram::PassTransformStates::get()
	{
		return static_cast<const Ogre::GpuProgram*>(_native)->getPassTransformStates( );
	}
	
	String^ GpuProgram::Source::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuProgram*>(_native)->getSource( ) );
	}
	void GpuProgram::Source::set( String^ source )
	{
		DECLARE_NATIVE_STRING( o_source, source )
	
		static_cast<Ogre::GpuProgram*>(_native)->setSource( o_source );
	}
	
	String^ GpuProgram::SourceFile::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuProgram*>(_native)->getSourceFile( ) );
	}
	void GpuProgram::SourceFile::set( String^ filename )
	{
		DECLARE_NATIVE_STRING( o_filename, filename )
	
		static_cast<Ogre::GpuProgram*>(_native)->setSourceFile( o_filename );
	}
	
	String^ GpuProgram::SyntaxCode::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::GpuProgram*>(_native)->getSyntaxCode( ) );
	}
	void GpuProgram::SyntaxCode::set( String^ syntax )
	{
		DECLARE_NATIVE_STRING( o_syntax, syntax )
	
		static_cast<Ogre::GpuProgram*>(_native)->setSyntaxCode( o_syntax );
	}
	
	Mogre::GpuProgramType GpuProgram::Type::get()
	{
		return (Mogre::GpuProgramType)static_cast<const Ogre::GpuProgram*>(_native)->getType( );
	}
	void GpuProgram::Type::set( Mogre::GpuProgramType t )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setType( (Ogre::GpuProgramType)t );
	}
	
	void GpuProgram::_Init_CLRObject( )
	{
		static_cast<Ogre::GpuProgram*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::GpuProgram^ GpuProgram::_getBindingDelegate( )
	{
		return static_cast<Ogre::GpuProgram*>(_native)->_getBindingDelegate( );
	}
	
	Mogre::GpuProgramParametersSharedPtr^ GpuProgram::CreateParameters( )
	{
		return static_cast<Ogre::GpuProgram*>(_native)->createParameters( );
	}
	
	void GpuProgram::SetSkeletalAnimationIncluded( bool included )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setSkeletalAnimationIncluded( included );
	}
	
	void GpuProgram::SetMorphAnimationIncluded( bool included )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setMorphAnimationIncluded( included );
	}
	
	void GpuProgram::SetPoseAnimationIncluded( Mogre::ushort poseCount )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setPoseAnimationIncluded( poseCount );
	}
	
	void GpuProgram::SetVertexTextureFetchRequired( bool r )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setVertexTextureFetchRequired( r );
	}
	
	void GpuProgram::SetAdjacencyInfoRequired( bool r )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setAdjacencyInfoRequired( r );
	}
	
	Mogre::GpuProgramParametersSharedPtr^ GpuProgram::GetDefaultParameters( )
	{
		return static_cast<Ogre::GpuProgram*>(_native)->getDefaultParameters( );
	}
	
	void GpuProgram::ResetCompileError( )
	{
		static_cast<Ogre::GpuProgram*>(_native)->resetCompileError( );
	}
	
	void GpuProgram::SetManualNamedConstants( Mogre::GpuNamedConstants^ namedConstants )
	{
		static_cast<Ogre::GpuProgram*>(_native)->setManualNamedConstants( namedConstants );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_GpuProgram(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::GpuProgram(pClrObj);
	}
	

}
