/*  This file is produced by the C++/CLI AutoWrapper utility.
        Copyright (c) 2006 by Argiris Kirtzidis  */

#include "MogreStableHeaders.h"

#include "MogreTextureManager.h"
#include "MogreResource.h"
#include "MogreCommon.h"
#include "MogreTexture.h"
#include "MogreImage.h"
#include "MogreDataStream.h"

namespace Mogre
{
	//################################################################
	//TextureManager
	//################################################################
	
	//Nested Types
	//Private Declarations
	
	//Internal Declarations
	
	//Public Declarations
	size_t TextureManager::DefaultNumMipmaps::get()
	{
		return static_cast<Ogre::TextureManager*>(_native)->getDefaultNumMipmaps( );
	}
	void TextureManager::DefaultNumMipmaps::set( size_t num )
	{
		static_cast<Ogre::TextureManager*>(_native)->setDefaultNumMipmaps( num );
	}
	
	Mogre::ushort TextureManager::PreferredFloatBitDepth::get()
	{
		return static_cast<const Ogre::TextureManager*>(_native)->getPreferredFloatBitDepth( );
	}
	
	Mogre::ushort TextureManager::PreferredIntegerBitDepth::get()
	{
		return static_cast<const Ogre::TextureManager*>(_native)->getPreferredIntegerBitDepth( );
	}
	
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat, hwGammaCorrection ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType, numMipmaps, gamma ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType, int numMipmaps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType, numMipmaps ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams, Mogre::TextureType texType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams, (Ogre::TextureType)texType ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader, Mogre::Const_NameValuePairList^ createParams )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader, createParams ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual, Mogre::IManualResourceLoader^ loader )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual, loader ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group, bool isManual )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group, isManual ) );
	}
	Pair<Mogre::ResourcePtr^, bool> TextureManager::CreateOrRetrieve( String^ name, String^ group )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return ToManaged<Pair<Mogre::ResourcePtr^, bool>, Ogre::ResourceManager::ResourceCreateOrRetrieveResult>( static_cast<Ogre::TextureManager*>(_native)->createOrRetrieve( o_name, o_group ) );
	}
	
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType, numMipmaps );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group, Mogre::TextureType texType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group, (Ogre::TextureType)texType );
	}
	Mogre::TexturePtr^ TextureManager::Prepare( String^ name, String^ group )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->prepare( o_name, o_group );
	}
	
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma, bool isAlpha )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma, isAlpha );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps, Mogre::Real gamma )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType, numMipmaps, gamma );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType, int numMipmaps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType, numMipmaps );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group, Mogre::TextureType texType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group, (Ogre::TextureType)texType );
	}
	Mogre::TexturePtr^ TextureManager::Load( String^ name, String^ group )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->load( o_name, o_group );
	}
	
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType, iNumMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma, bool isAlpha, Mogre::PixelFormat desiredFormat )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType, iNumMipmaps, gamma, isAlpha, (Ogre::PixelFormat)desiredFormat );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma, bool isAlpha )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType, iNumMipmaps, gamma, isAlpha );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType, iNumMipmaps, gamma );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType, int iNumMipmaps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType, iNumMipmaps );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img, Mogre::TextureType texType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img, (Ogre::TextureType)texType );
	}
	Mogre::TexturePtr^ TextureManager::LoadImage( String^ name, String^ group, Mogre::Image^ img )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadImage( o_name, o_group, img );
	}
	
	Mogre::TexturePtr^ TextureManager::LoadRawData( String^ name, String^ group, Mogre::DataStreamPtr^ stream, Mogre::ushort uWidth, Mogre::ushort uHeight, Mogre::PixelFormat format, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadRawData( o_name, o_group, (Ogre::DataStreamPtr&)stream, uWidth, uHeight, (Ogre::PixelFormat)format, (Ogre::TextureType)texType, iNumMipmaps, gamma, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::LoadRawData( String^ name, String^ group, Mogre::DataStreamPtr^ stream, Mogre::ushort uWidth, Mogre::ushort uHeight, Mogre::PixelFormat format, Mogre::TextureType texType, int iNumMipmaps, Mogre::Real gamma )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadRawData( o_name, o_group, (Ogre::DataStreamPtr&)stream, uWidth, uHeight, (Ogre::PixelFormat)format, (Ogre::TextureType)texType, iNumMipmaps, gamma );
	}
	Mogre::TexturePtr^ TextureManager::LoadRawData( String^ name, String^ group, Mogre::DataStreamPtr^ stream, Mogre::ushort uWidth, Mogre::ushort uHeight, Mogre::PixelFormat format, Mogre::TextureType texType, int iNumMipmaps )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadRawData( o_name, o_group, (Ogre::DataStreamPtr&)stream, uWidth, uHeight, (Ogre::PixelFormat)format, (Ogre::TextureType)texType, iNumMipmaps );
	}
	Mogre::TexturePtr^ TextureManager::LoadRawData( String^ name, String^ group, Mogre::DataStreamPtr^ stream, Mogre::ushort uWidth, Mogre::ushort uHeight, Mogre::PixelFormat format, Mogre::TextureType texType )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadRawData( o_name, o_group, (Ogre::DataStreamPtr&)stream, uWidth, uHeight, (Ogre::PixelFormat)format, (Ogre::TextureType)texType );
	}
	Mogre::TexturePtr^ TextureManager::LoadRawData( String^ name, String^ group, Mogre::DataStreamPtr^ stream, Mogre::ushort uWidth, Mogre::ushort uHeight, Mogre::PixelFormat format )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->loadRawData( o_name, o_group, (Ogre::DataStreamPtr&)stream, uWidth, uHeight, (Ogre::PixelFormat)format );
	}
	
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection, Mogre::uint fsaa, String^ fsaaHint )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
		DECLARE_NATIVE_STRING( o_fsaaHint, fsaaHint )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection, fsaa, o_fsaaHint );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection, Mogre::uint fsaa )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection, fsaa );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format, usage, loader );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format, int usage )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format, usage );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, Mogre::uint depth, int num_mips, Mogre::PixelFormat format )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, depth, num_mips, (Ogre::PixelFormat)format );
	}
	
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection, Mogre::uint fsaa, String^ fsaaHint )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
		DECLARE_NATIVE_STRING( o_fsaaHint, fsaaHint )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection, fsaa, o_fsaaHint );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection, Mogre::uint fsaa )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection, fsaa );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader, bool hwGammaCorrection )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format, usage, loader, hwGammaCorrection );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format, int usage, Mogre::IManualResourceLoader^ loader )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format, usage, loader );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format, int usage )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format, usage );
	}
	Mogre::TexturePtr^ TextureManager::CreateManual( String^ name, String^ group, Mogre::TextureType texType, Mogre::uint width, Mogre::uint height, int num_mips, Mogre::PixelFormat format )
	{
		DECLARE_NATIVE_STRING( o_name, name )
		DECLARE_NATIVE_STRING( o_group, group )
	
		return static_cast<Ogre::TextureManager*>(_native)->createManual( o_name, o_group, (Ogre::TextureType)texType, width, height, num_mips, (Ogre::PixelFormat)format );
	}
	
	void TextureManager::SetPreferredIntegerBitDepth( Mogre::ushort bits, bool reloadTextures )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredIntegerBitDepth( bits, reloadTextures );
	}
	void TextureManager::SetPreferredIntegerBitDepth( Mogre::ushort bits )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredIntegerBitDepth( bits );
	}
	
	void TextureManager::SetPreferredFloatBitDepth( Mogre::ushort bits, bool reloadTextures )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredFloatBitDepth( bits, reloadTextures );
	}
	void TextureManager::SetPreferredFloatBitDepth( Mogre::ushort bits )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredFloatBitDepth( bits );
	}
	
	void TextureManager::SetPreferredBitDepths( Mogre::ushort integerBits, Mogre::ushort floatBits, bool reloadTextures )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredBitDepths( integerBits, floatBits, reloadTextures );
	}
	void TextureManager::SetPreferredBitDepths( Mogre::ushort integerBits, Mogre::ushort floatBits )
	{
		static_cast<Ogre::TextureManager*>(_native)->setPreferredBitDepths( integerBits, floatBits );
	}
	
	bool TextureManager::IsFormatSupported( Mogre::TextureType ttype, Mogre::PixelFormat format, int usage )
	{
		return static_cast<Ogre::TextureManager*>(_native)->isFormatSupported( (Ogre::TextureType)ttype, (Ogre::PixelFormat)format, usage );
	}
	
	bool TextureManager::IsEquivalentFormatSupported( Mogre::TextureType ttype, Mogre::PixelFormat format, int usage )
	{
		return static_cast<Ogre::TextureManager*>(_native)->isEquivalentFormatSupported( (Ogre::TextureType)ttype, (Ogre::PixelFormat)format, usage );
	}
	
	Mogre::PixelFormat TextureManager::GetNativeFormat( Mogre::TextureType ttype, Mogre::PixelFormat format, int usage )
	{
		return (Mogre::PixelFormat)static_cast<Ogre::TextureManager*>(_native)->getNativeFormat( (Ogre::TextureType)ttype, (Ogre::PixelFormat)format, usage );
	}
	
	bool TextureManager::IsHardwareFilteringSupported( Mogre::TextureType ttype, Mogre::PixelFormat format, int usage, bool preciseFormatOnly )
	{
		return static_cast<Ogre::TextureManager*>(_native)->isHardwareFilteringSupported( (Ogre::TextureType)ttype, (Ogre::PixelFormat)format, usage, preciseFormatOnly );
	}
	bool TextureManager::IsHardwareFilteringSupported( Mogre::TextureType ttype, Mogre::PixelFormat format, int usage )
	{
		return static_cast<Ogre::TextureManager*>(_native)->isHardwareFilteringSupported( (Ogre::TextureType)ttype, (Ogre::PixelFormat)format, usage );
	}
	
	
	//Protected Declarations
	
	
	

}
