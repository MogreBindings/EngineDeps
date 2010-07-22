
set DEST=bin\libs\
set TOOLS=bin\tools\
set OGRESRC=Mogre\Main\OgreSrc\ogre\lib\bin\
set MOGRESRC=Mogre\Main\lib\
set MYGUISRC=mygui\build\bin\

REM OGRE3D AND MOGRE

Tools\robocopy /njh /njs /lev:0 %MOGRESRC%Debug\ %DEST%mogre\Debug\ Mogre.dll
Tools\robocopy /njh /njs /lev:0 %MOGRESRC%Debug\ %DEST%mogre\Debug\ Mogre.pdb

Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ OgreMain_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ ogremain_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ OgrePaging_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ ogrepaging_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ OgreRTShaderSystem_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ ogrertshadersystem_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ OgreTerrain_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ ogreterrain_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_BSPSceneManager_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_bspscenemanager_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_CgProgramManager_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_cgprogrammanager_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_OctreeSceneManager_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_octreescenemanager_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_OctreeZone_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_octreezone_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_ParticleFX_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_particlefx_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ Plugin_PCZSceneManager_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ plugin_pczscenemanager_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ RenderSystem_Direct3D9_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ rendersystem_direct3d9_d.pdb
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ RenderSystem_GL_d.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%debug\ %DEST%mogre\Debug\ rendersystem_gl_d.pdb

Tools\robocopy /njh /njs /lev:0 %MOGRESRC%Release\ %DEST%mogre\Release\ Mogre.dll

Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ OgreMain.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ OgrePaging.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ OgreRTShaderSystem.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ OgreTerrain.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_BSPSceneManager.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_CgProgramManager.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_OctreeSceneManager.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_OctreeZone.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_ParticleFX.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ Plugin_PCZSceneManager.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ RenderSystem_Direct3D9.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %DEST%mogre\Release\ RenderSystem_GL.dll

REM MYGUI

Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Debug\ %DEST%mygui\Debug\ MyGUI.dll
Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Debug\ %DEST%mygui\Debug\ MyGUI.pdb
Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Debug\ %DEST%mygui\Debug\ MyGUIEngine_d.dll
Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Debug\ %DEST%mygui\Debug\ MyGUIEngine_d.pdb

Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Release\ %DEST%mygui\Release\ MyGUI.dll
Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Release\ %DEST%mygui\Release\ MyGUIEngine.dll

REM LAYOUTEDITOR

Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Release\ %TOOLS%LayoutEditor\ LayoutEditor.exe
Tools\robocopy /njh /njs /lev:0 %MYGUISRC%Release\ %TOOLS%LayoutEditor\ MyGUIEngine.dll

Tools\robocopy /njh /njs /lev:0 %MOGRESRC%release\ %TOOLS%LayoutEditor\ Mogre.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %TOOLS%LayoutEditor\ OgreMain.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %TOOLS%LayoutEditor\ Plugin_OctreeSceneManager.dll
Tools\robocopy /njh /njs /lev:0 %OGRESRC%release\ %TOOLS%LayoutEditor\ RenderSystem_Direct3D9.dll

Tools\robocopy /njh /njs /e mygui\Media\MyGUI_Media\ %TOOLS%LayoutEditor\Media\MyGUI_Media\ *
Tools\robocopy /njh /njs /e mygui\Media\Common\Wallpapers\ %TOOLS%LayoutEditor\Media\Common\Wallpapers\ *
Tools\robocopy /njh /njs /e mygui\Media\Tools\LayoutEditor\ %TOOLS%LayoutEditor\Media\Tools\LayoutEditor\ *

REM SLIMDX

Tools\robocopy /njh /njs /lev:0 SlimDX\bin\Debug\ %DEST%slimdx\Debug\ SlimDX.dll
Tools\robocopy /njh /njs /lev:0 SlimDX\bin\Debug\ %DEST%slimdx\Debug\ SlimDX.pdb

Tools\robocopy /njh /njs /lev:0 SlimDX\bin\Release\ %DEST%slimdx\Release\ SlimDX.dll

REM PHYSX

Tools\robocopy /njh /njs /lev:0 PhysX\bin\ %DEST%physx\Debug\ *.dll

Tools\robocopy /njh /njs /lev:0 PhysX\bin\ %DEST%physx\Release\ *.dll

REM PHYSX WRAPPER

Tools\robocopy /njh /njs /lev:0 eyecm-physx\bin\Debug\eyecm.PhysX\ %DEST%physx\Debug\ eyecm.PhysX.dll
Tools\robocopy /njh /njs /lev:0 eyecm-physx\bin\Debug\eyecm.PhysX\ %DEST%physx\Debug\ eyecm.PhysX.pdb

Tools\robocopy /njh /njs /lev:0 eyecm-physx\bin\Release\eyecm.PhysX\ %DEST%physx\Release\ eyecm.PhysX.dll
