#pragma once
#include <map>
#include "FileInfo.h"
#include "InputFileInfo.h"

class FileLoaderTaskInterceptorSettings
{
	std::wstring settings_path;
	void read_settings();
	void read_settings_line(std::wstring &line);
public:
	std::map<FileInfo, InputFileInfo> file_replacements;
	FileLoaderTaskInterceptorSettings();
	FileLoaderTaskInterceptorSettings(std::wstring &settingsPath);
	~FileLoaderTaskInterceptorSettings();
	
};