/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreParticleAffectorFactory.h"
#include "MogreParticleAffector.h"
#include "MogreParticleSystem.h"

namespace Mogre
{
	//################################################################
	//ParticleAffectorFactory
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	String^ ParticleAffectorFactory::Name::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::ParticleAffectorFactory*>(_native)->getName( ) );
	}
	
	void ParticleAffectorFactory::_Init_CLRObject( )
	{
		static_cast<Ogre::ParticleAffectorFactory*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::ParticleAffector^ ParticleAffectorFactory::CreateAffector( Mogre::ParticleSystem^ psys )
	{
		return static_cast<Ogre::ParticleAffectorFactory*>(_native)->createAffector( psys );
	}
	
	void ParticleAffectorFactory::DestroyAffector( Mogre::ParticleAffector^ e )
	{
		static_cast<Ogre::ParticleAffectorFactory*>(_native)->destroyAffector( e );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_ParticleAffectorFactory(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::ParticleAffectorFactory(pClrObj);
	}
	

}
