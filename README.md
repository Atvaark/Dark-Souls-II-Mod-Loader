# Dark Souls II Mod Loader
A tool that replaces the file loading mechanism with a custom implementation.
This allows shenanigans like dumping files to disk and replacing requested files with customized ones at runtime.

Project source and latest releases are available at:
https://github.com/Atvaark/Dark-Souls-II-Mod-Loader

## Installation
1. Download the latest release from https://github.com/Atvaark/Dark-Souls-II-Mod-Loader/releases
2. Unpack the zip file somewhere

## Configuration
General settings are stored in *DarkSoulsIIModLoader.ini*. The available options are:
>`dump_files`
>When enabled the mod loader also saves all requested files to disk.
>Which files were dumped is logged to *DarkSoulsIIModLoader.dump.log*.
>
>`dump_directory`
>When uncommented specifies in which directory files will be dumped.
>When not specified the default dump directory is in the folder that contains the mod loader.
>
>`replace_files`
>When enabled the files specified in DarkSoulsIIModLoader.mods.ini are replaced.
>
>`mods_directory`
>When uncommented specifies in which directory the mods will be found.
>When not specified the default mods directory is in the folder that contains the mod loader.
>
>`log_hashes`
>For debugging and research purposes.
>When enabled logs every attempt of the game trying to hash a file name to *DarkSoulsIIModLoader.hash.log*.

Mod settings are stored in *DarkSoulsIIModLoader.mods.ini*.

Each file that should be replaced is specified using the following format:
`archive_file_name;replacement_file_path`
Valid archive_file_names can be read from the dump log. The replacement_file_path is relative to the mods_directory.

Example:
`text:/Text/English/TitleMenu.fmg;text\Text\English\TitleMenu.fmg`

Replacements can be disabled by commenting them out with a # character.
  
## Running
1. Run *DarkSoulsIIModLoader.Injector.exe* (administrative rights might be required)
2. Start Dark Souls II

## Remarks
* Replacing a file with a bigger one is not supported yet 

---

## Development

### Build Requirements
* Visual Studio 2013
