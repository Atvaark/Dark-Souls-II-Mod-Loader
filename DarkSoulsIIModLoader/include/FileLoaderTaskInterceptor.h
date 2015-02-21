#pragma once
//#include <unordered_map>
#include "FileInfo.h"
#include "InputFileInfo.h"
//#include "FileInfoHasher.h"
#include "FileLoaderTaskInterceptorSettings.h"
#include "DarkSoulsII/FileLoaderTask.h"

class FileLoaderTaskInterceptor
{
	//std::unordered_map<FileInfo, FileInfo, FileInfoHasher> fileReplacements;
	bool replace_file(FileLoaderTask &task, InputFileInfo &replacement);
	FileLoaderTaskInterceptorSettings settings;
public:
	FileLoaderTaskInterceptor();
	FileLoaderTaskInterceptor(std::wstring settingsFilePath);
	~FileLoaderTaskInterceptor();

	void add_replacement(FileInfo &file, InputFileInfo &replacement);
	bool handle(FileLoaderTask &task);
};
