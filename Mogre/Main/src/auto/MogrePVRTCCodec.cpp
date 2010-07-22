/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogrePVRTCCodec.h"
#include "MogreDataStream.h"

namespace Mogre
{
	//################################################################
	//PVRTCCodec
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	String^ PVRTCCodec::Type::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::PVRTCCodec*>(_native)->getType( ) );
	}
	
	Mogre::DataStreamPtr^ PVRTCCodec::Code( Mogre::MemoryDataStreamPtr^ input, Mogre::Codec::CodecDataPtr^ pData )
	{
		return static_cast<const Ogre::PVRTCCodec*>(_native)->code( (Ogre::MemoryDataStreamPtr&)input, (Ogre::Codec::CodecDataPtr&)pData );
	}
	
	void PVRTCCodec::CodeToFile( Mogre::MemoryDataStreamPtr^ input, String^ outFileName, Mogre::Codec::CodecDataPtr^ pData )
	{
		DECLARE_NATIVE_STRING( o_outFileName, outFileName )
	
		static_cast<const Ogre::PVRTCCodec*>(_native)->codeToFile( (Ogre::MemoryDataStreamPtr&)input, o_outFileName, (Ogre::Codec::CodecDataPtr&)pData );
	}
	
	Pair<Mogre::MemoryDataStreamPtr^, Mogre::Codec::CodecDataPtr^> PVRTCCodec::Decode( Mogre::DataStreamPtr^ input )
	{
		return ToManaged<Pair<Mogre::MemoryDataStreamPtr^, Mogre::Codec::CodecDataPtr^>, Ogre::Codec::DecodeResult>( static_cast<const Ogre::PVRTCCodec*>(_native)->decode( (Ogre::DataStreamPtr&)input ) );
	}
	
	String^ PVRTCCodec::MagicNumberToFileExt( const char* magicNumberPtr, size_t maxbytes )
	{
		return TO_CLR_STRING( static_cast<const Ogre::PVRTCCodec*>(_native)->magicNumberToFileExt( magicNumberPtr, maxbytes ) );
	}
	
	void PVRTCCodec::Startup( )
	{
		Ogre::PVRTCCodec::startup( );
	}
	
	void PVRTCCodec::Shutdown( )
	{
		Ogre::PVRTCCodec::shutdown( );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_PVRTCCodec(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::PVRTCCodec(pClrObj);
	}
	

}
