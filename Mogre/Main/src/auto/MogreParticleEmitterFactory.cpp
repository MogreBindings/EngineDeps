/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreParticleEmitterFactory.h"
#include "MogreParticleEmitter.h"
#include "MogreParticleSystem.h"

namespace Mogre
{
	//################################################################
	//ParticleEmitterFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	String^ ParticleEmitterFactory::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::ParticleEmitterFactory*>(_native)->getName( ) );
	}
	
	void ParticleEmitterFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::ParticleEmitterFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::ParticleEmitter^ ParticleEmitterFactory::CreateEmitter( Mogre::ParticleSystem^ psys )
	{
		return static_cast<Ogre::ParticleEmitterFactory*>(_native)->createEmitter( psys );
	}
	
	void ParticleEmitterFactory::DestroyEmitter( Mogre::ParticleEmitter^ e )
	{
		static_cast<Ogre::ParticleEmitterFactory*>(_native)->destroyEmitter( e );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_ParticleEmitterFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::ParticleEmitterFactory(pClrObj);
	}
	

}
