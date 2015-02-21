#Dark Souls II Mod Loader
A tool that replaces the file loading mechanism with a custom implementation. This allows shenanigans like dumping files to disk and replacing requested files with customized ones at runtime.

##Build Requirements
* Visual Studio 2013

##Requirements
* A dll injector

##Configuration
Settings are saved in DarkSoulsIIModLoader.ini.
Each file that should be replaced has be added using the following format:
```
archive_name:relative_file_path;absolute_file_path
```

e.g.
```
text:/Text/English/TitleMenu.fmg;E:\text\Text\English\TitleMenu.fmg
map:/param/GeneratorParam_m10_04_00_00.param;E:\map\param\GeneratorParam_m10_04_00_00.param
```

##Remarks
* The hard coded offsets are for Dark Souls II 1.0.7
* File dumping is enabled by default
