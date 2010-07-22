/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreCodec.h"
#include "MogreDataStream.h"
#include "MogreStringVector.h"

namespace Mogre
{
	//################################################################
	//Codec
	//################################################################
	
	//Nested Types
	//################################################################
	//CodecData
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	Codec::CodecData::CodecData() : Wrapper((CLRObject*) 0)
	{
		_createdByCLR = true;
		_native = new Ogre::Codec::CodecData();
	
		_native->_MapToCLRObject(this, System::Runtime::InteropServices::GCHandleType::Normal);
	}
	
	void Codec::CodecData::_Init_CLRObject( )
	{
		static_cast<Ogre::Codec::CodecData*>(_native)->_Init_CLRObject( );
	}
	
	String^ Codec::CodecData::DataType( )
	{
		return TO_CLR_STRING( static_cast<const Ogre::Codec::CodecData*>(_native)->dataType( ) );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Codec_CodecData(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Codec::CodecData(pClrObj);
	}
	
	CPP_DECLARE_MAP_ITERATOR_NOCONSTRUCTOR( Codec::, CodecIterator, Ogre::Codec::CodecIterator, Mogre::Codec::CodecList, Mogre::Codec^, Ogre::Codec*, String^, Ogre::String )
	
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	String^ Codec::DataType::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Codec*>(_native)->getDataType( ) );
	}
	
	String^ Codec::Type::get()
	{
		return TO_CLR_STRING( static_cast<const Ogre::Codec*>(_native)->getType( ) );
	}
	
	void Codec::_Init_CLRObject( )
	{
		static_cast<Ogre::Codec*>(_native)->_Init_CLRObject( );
	}
	
	Mogre::DataStreamPtr^ Codec::Code( Mogre::MemoryDataStreamPtr^ input, Mogre::Codec::CodecDataPtr^ pData )
	{
		return static_cast<const Ogre::Codec*>(_native)->code( (Ogre::MemoryDataStreamPtr&)input, (Ogre::Codec::CodecDataPtr&)pData );
	}
	
	void Codec::CodeToFile( Mogre::MemoryDataStreamPtr^ input, String^ outFileName, Mogre::Codec::CodecDataPtr^ pData )
	{
		DECLARE_NATIVE_STRING( o_outFileName, outFileName )
	
		static_cast<const Ogre::Codec*>(_native)->codeToFile( (Ogre::MemoryDataStreamPtr&)input, o_outFileName, (Ogre::Codec::CodecDataPtr&)pData );
	}
	
	Pair<Mogre::MemoryDataStreamPtr^, Mogre::Codec::CodecDataPtr^> Codec::Decode( Mogre::DataStreamPtr^ input )
	{
		return ToManaged<Pair<Mogre::MemoryDataStreamPtr^, Mogre::Codec::CodecDataPtr^>, Ogre::Codec::DecodeResult>( static_cast<const Ogre::Codec*>(_native)->decode( (Ogre::DataStreamPtr&)input ) );
	}
	
	bool Codec::MagicNumberMatch( const char* magicNumberPtr, size_t maxbytes )
	{
		return static_cast<const Ogre::Codec*>(_native)->magicNumberMatch( magicNumberPtr, maxbytes );
	}
	
	String^ Codec::MagicNumberToFileExt( const char* magicNumberPtr, size_t maxbytes )
	{
		return TO_CLR_STRING( static_cast<const Ogre::Codec*>(_native)->magicNumberToFileExt( magicNumberPtr, maxbytes ) );
	}
	
	void Codec::RegisterCodec( Mogre::Codec^ pCodec )
	{
		Ogre::Codec::registerCodec( pCodec );
	}
	
	bool Codec::IsCodecRegistered( String^ codecType )
	{
		DECLARE_NATIVE_STRING( o_codecType, codecType )
	
		return Ogre::Codec::isCodecRegistered( o_codecType );
	}
	
	void Codec::UnRegisterCodec( Mogre::Codec^ pCodec )
	{
		Ogre::Codec::unRegisterCodec( pCodec );
	}
	
	Mogre::Codec::CodecIterator^ Codec::GetCodecIterator( )
	{
		return Ogre::Codec::getCodecIterator( );
	}
	
	Mogre::StringVector^ Codec::GetExtensions( )
	{
		return Mogre::StringVector::ByValue( Ogre::Codec::getExtensions( ) );
	}
	
	Mogre::Codec^ Codec::GetCodec( String^ extension )
	{
		DECLARE_NATIVE_STRING( o_extension, extension )
	
		return Ogre::Codec::getCodec( o_extension );
	}
	
	Mogre::Codec^ Codec::GetCodec( [Out] char% magicNumberPtr, size_t maxbytes )
	{
		pin_ptr<char> p_magicNumberPtr = &magicNumberPtr;
	
		return Ogre::Codec::getCodec( p_magicNumberPtr, maxbytes );
	}
	
	
	//Protected Declarations
	
	
	__declspec(dllexport) void _Init_CLRObject_Codec(CLRObject* pClrObj)
	{
		*pClrObj = gcnew Mogre::Codec(pClrObj);
	}
	

}
