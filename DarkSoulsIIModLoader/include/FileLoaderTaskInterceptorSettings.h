#pragma once
#include <map>
#include "FileInfo.h"
#include "InputFileInfo.h"

class FileLoaderTaskInterceptorSettings
{
	std::wstring mods_path;
	std::wstring settings_path;
	void read_settings();
	void parse_replacement_file(std::wstring &line);
public:
	std::map<FileInfo, InputFileInfo> file_replacements;

	FileLoaderTaskInterceptorSettings();
	FileLoaderTaskInterceptorSettings(std::wstring &mods_path, std::wstring &settings_path);
	~FileLoaderTaskInterceptorSettings();
	
};
