/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreHighLevelGpuProgram.h"
#include "MogreGpuProgramParams.h"
#include "MogreGpuProgram.h"

namespace Mogre
{
	//################################################################
	//HighLevelGpuProgram
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Mogre::GpuNamedConstants^ HighLevelGpuProgram::ConstantDefinitions::get()
	{
		return static_cast<const Ogre::HighLevelGpuProgram*>(_native)->getConstantDefinitions( );
	}
	
	Mogre::GpuNamedConstants^ HighLevelGpuProgram::NamedConstants::get()
	{
		return static_cast<const Ogre::HighLevelGpuProgram*>(_native)->getNamedConstants( );
	}
	
	void HighLevelGpuProgram::_Init_CLRObject( )
	{
		static_cast<Ogre::HighLevelGpuProgram*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::GpuProgramParametersSharedPtr^ HighLevelGpuProgram::CreateParameters( )
	{
		return static_cast<Ogre::HighLevelGpuProgram*>(_native)->createParameters( );
	}
	
	Mogre::GpuProgram^ HighLevelGpuProgram::_getBindingDelegate( )
	{
		return static_cast<Ogre::HighLevelGpuProgram*>(_native)->_getBindingDelegate( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_HighLevelGpuProgram(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::HighLevelGpuProgram(pClrObj);
	}
	

}
