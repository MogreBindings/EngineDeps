==========================
PhysX Candy Wrapper README
==========================


Software versions
-----------------

At the time of the writing, the latest version of the NVIDIA PhysX SDK is 2.8.1.
This is the version supported in this release.
The library was successfully compiled with Microsoft's Visual C++ 2008 Express Edition.



Important stuff
---------------

This library source package is not a part of and does not contain any part of the NVIDIA PhysX SDK.
In order to compile the source package, you need to obtain the SDK through NVIDIA's webpage at http://www.nvidia.com/object/nvidia_physx.html
The author of this library is in no way affiliated with NVIDIA Corporation.
In no manner does NVIDIA Corporation endorse or otherwise approve of this library.
Read the license.txt file.



Build checklist
---------------

[x] Read the readme.txt file!

[ ] Make sure you have a library of managed math classes pre-made.
	- What your math classes are named or what namespace and assembly they reside in is your own choice.
	- You will need:
		[ ] Vector3, 
		[ ] Matrix3x3, Matrix4x4 (or Matrix3x4 if you prefer), 
		[ ] Quaternion, 
		[ ] AxisAlignedBox, OrientedBox, 
		[ ] Line, Plane, Sphere, Capsule, Triangle

	- You will customize the library to use these types directly. More on this below.
	  
[ ] Install the NVIDIA PhysX SDK.
[ ] Install Microsoft Visual C++. (The '2008 Express Edition' seems to work well.)
[ ] Set-up the include paths within Visual C++ (Tool|Options|Projects and Solutions|VC++ Directories) 
    to point to the include folders of the NVIDIA PhysX SDK.

[ ] Check out (via svn) a copy of eyecm-physx to a folder of your choice.
[ ] Copy files from your NVIDIA PhysX SDK 'Tools\NxuStream2' folder to the 'Source\eyecm.PhysX\Physics\NxuStream' folder.
[ ] Copy files from your NVIDIA PhysX SDK 'SDKs\NxCharacter' folder to the 'Source\eyecm.PhysX\Character\NxCharacter' folder ('include' and 'src' folders).

[ ] Open the eyecm.PhysX.sln solution file.
	[ ] Open the configuration manager (Build|Configuration Manager) and activate either the 'Debug' or 'Release' configuration.
	    (The 'Debug eyecm' and 'Release eyecm' configurations are only included as an example.)
		
	[ ] Open project properties (Project|eyecm.PhysX Properties)
		[ ] Select ConfigurationProperties|C/C++|Preprocessor|Preprocessor Definitions
		    Add a symbol definition of the form: UserCustomization=\"custom.[mycompany].h\";
		    (replace [mycompany] with a string of your choice.)

[ ] Open the 'Source\eyecm.PhysX\Customization' folder with a file manager (Explorer).
	[ ] Copy the 'custom.example.h'  to 'custom.[mycompany].h'  (again replace [mycompany] with the same string you've chosen above)
	[ ] Copy the 'convert.example.h' to 'convert.[mycompany].h' (again replace [mycompany] with the same string you've chosen above)	

	[ ] Open the 'custom.[mycompany].h' file for editing and follow the instructions contained within.
		[ ] You will need to define the fully qualified names of your managed math classes and some other macros and #using-s.
			Example definitions are already provided.
		
	[ ] Open the 'convert.[mycompany].h' file for editing and follow the instructions contained within.
		[ ] You will need to implement all the functions that convert from your managed classes to the unmanaged PhysX SDK classes and vice versa.
		    An example implementation of conversions is already provided, it should be fairly easy to adapt it to your needs.

[ ] Compile.
	