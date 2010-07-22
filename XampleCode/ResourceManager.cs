using System;
using System.Collections.Generic;
using System.IO;

using Mogre;

using MyGame.Shared.Configuration;

namespace MyGame.Engine.Resources
{
  /************************************************************************/
  /* resource manager uses ogre resource group manager                    */
  /************************************************************************/
  public class ResourceManager
  {
    //////////////////////////////////////////////////////////////////////////
    private EngineLibrary mLib;

    /************************************************************************/
    /* constructor                                                          */
    /************************************************************************/
    internal ResourceManager( EngineLibrary _lib )
    {
      mLib = _lib;
    }

    /************************************************************************/
    /* start up resource manager                                            */
    /************************************************************************/
    internal bool Startup()
    {
      // init resource locations
      if( !InitResourcePacks() )
        return false;

      // initialize bootstrap resource group
      InitGroup( mLib.EngineCfg.BootstrapResourceGroup );

      // preload bootstrap resource group
      LoadGroup( mLib.EngineCfg.BootstrapResourceGroup );

      // OK
      return true;
    }

    /************************************************************************/
    /* shut down resource manager                                           */
    /************************************************************************/
    internal void Shutdown()
    {
      if( ResourceGroupManager.Singleton != null )
      {
        // unload bootstrap resource group
        ResourceGroupManager.Singleton.UnloadResourceGroup( mLib.EngineCfg.BootstrapResourceGroup );

        // iterate resource groups
        StringVector groups = ResourceGroupManager.Singleton.GetResourceGroups();
        foreach( string group in groups )
        {
          // unload group if it is still loaded
          if( ResourceGroupManager.Singleton.IsResourceGroupLoaded( group ) )
            ResourceGroupManager.Singleton.UnloadResourceGroup( group );

          // clear the resource group
          ResourceGroupManager.Singleton.ClearResourceGroup( group );
        }

        // shutdown resource manager completely
        ResourceGroupManager.Singleton.ShutdownAll();
      }
    }

    /************************************************************************/
    /* update resource manager                                              */
    /************************************************************************/
    internal void Update( long _frameTime )
    {
    }

    //////////////////////////////////////////////////////////////////////////
    // internal functions ////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* init resource groups and locations defined in engine config          */
    /************************************************************************/
    private bool InitResourcePacks()
    {
      // some variables for paths
      string enginePath = mLib.SharedLib.Paths.EnginePath;
      string resPath;

      // get list of resource packs
      List<ResourcePaths.Resource> resPackList = mLib.EngineCfg.ResourcePacks;

      // iterate list to register packs with engine
      foreach( ResourcePaths.Resource res in resPackList )
      {
        // check directory first
        resPath = Path.Combine( enginePath, res.Directory );
        if( Directory.Exists( resPath ) )
        {
          // add directory as resource path
          ResourceGroupManager.Singleton.AddResourceLocation( resPath, "FileSystem", res.Group, true );
          continue;
        }

        // check zip pack file next
        resPath = Path.Combine( enginePath, res.PackFile );
        if( File.Exists( resPath ) )
        {
          // add zip file as resource pack
          ResourceGroupManager.Singleton.AddResourceLocation( resPath, "Zip", res.Group, true );
          continue;
        }

        // failed to register resource location
        return false;
      }

      // OK
      return true;
    }

    //////////////////////////////////////////////////////////////////////////
    // public functions //////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////

    /************************************************************************/
    /* init resource group and parse all ogre scripts inside                */
    /************************************************************************/
    public void InitGroup( string _groupName )
    {
      // init resource group if it is not yet initialized
      if( !ResourceGroupManager.Singleton.IsResourceGroupInitialised( _groupName ) )
        ResourceGroupManager.Singleton.InitialiseResourceGroup( _groupName );
    }

    /************************************************************************/
    /* load all resources for a resource group (preloading)                 */
    /************************************************************************/
    public void LoadGroup( string _groupName )
    {
      // load resource group if it is not yet loaded
      if( !ResourceGroupManager.Singleton.IsResourceGroupLoaded( _groupName ) )
        ResourceGroupManager.Singleton.LoadResourceGroup( _groupName );
    }

    /************************************************************************/
    /* unload all resource for a resource group                             */
    /************************************************************************/
    public void UnloadGroup( string _groupName )
    {
      // do not allow to unload the bootstrap resource group in this function
      if( _groupName == mLib.EngineCfg.BootstrapResourceGroup )
        return;

      // unload resource group if it is loaded
      if( ResourceGroupManager.Singleton.IsResourceGroupLoaded( _groupName ) )
        ResourceGroupManager.Singleton.UnloadResourceGroup( _groupName );
    }

    /************************************************************************/
    /* check if a resource exists in a resource group                       */
    /************************************************************************/
    public bool CheckResourceExists( string _groupName, string _fileName )
    {
      // check if file exists in requested resource group
      return ResourceGroupManager.Singleton.ResourceExists( _groupName, _fileName );
    }

    /************************************************************************/
    /* read a resource completely as a byte array                           */
    /************************************************************************/
    public byte[] ReadResource( string _groupName, string _fileName )
    {
      // if the file does not exist there is no way to load it
      if( !CheckResourceExists( _groupName, _fileName ) )
        return null;

      // open resource for reading
      DataStreamPtr streamPtr = ResourceGroupManager.Singleton.OpenResource( _fileName, _groupName );
      uint length = streamPtr.Size();
      uint readLength = 0;

      // create buffer to load resource into
      byte[] buffer = new byte[ (int) length ];
      if( length != 0 )
      {
        unsafe
        {
          fixed( byte* bufferPtr = &buffer[ 0 ] )
          {
            // read resource into buffer
            readLength = streamPtr.Read( bufferPtr, length );
          }
        }
      }

      // if reading the resource failed, just get rid of the buffer
      if( readLength != length )
        buffer = null;

      // close the resource stream
      streamPtr.Close();

      // return buffer of loaded resource or null if failed
      return buffer;
    }

    /************************************************************************/
    /* get a list of all known resource groups                              */
    /************************************************************************/
    public string[] GetResourceGroups()
    {
      // get list of resource groups from resource group manager
      StringVector groups = ResourceGroupManager.Singleton.GetResourceGroups();

      // create array to hold result list
      string[] res = new string[ groups.Count ];

      // copy resource group names into array
      for( int i = 0; i < groups.Count; ++i )
        res[ i ] = groups[ i ];

      // return list of resource groups
      return res;
    }

    /************************************************************************/
    /* get a list of all resources in a group                               */
    /************************************************************************/
    public string[] GetResourcesInGroup( string _group )
    {
      // get list of all resource in the requested resource group
      FileInfoList resources = ResourceGroupManager.Singleton.ListResourceFileInfo( _group );

      // create array to hold the result list
      string[] res = new string[ resources.Count ];

      // iterate list of resource infos
      for( int i = 0; i < resources.Count; ++i )
      {
        // get resource info
        FileInfo_NativePtr resource = resources[ i ];

        // store base file name in result list
        res[ i ] = resource.filename;
      }

      // return list of resources in the requested group
      return res;
    }

  } // class

} // namespace
