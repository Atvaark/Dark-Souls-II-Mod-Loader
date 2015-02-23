#pragma once
#include "FileInfo.h"
#include "InputFileInfo.h"
#include "FileLoaderTaskInterceptorSettings.h"
#include "DarkSoulsII/FileLoaderTask.h"

class FileLoaderTaskInterceptor
{
	bool replace_file(FileLoaderTask &task, InputFileInfo &replacement);
	FileLoaderTaskInterceptorSettings settings;
public:
	bool enabled;
	FileLoaderTaskInterceptor();
	FileLoaderTaskInterceptor(FileLoaderTaskInterceptorSettings &settings);
	~FileLoaderTaskInterceptor();

	void add_replacement(FileInfo &file, InputFileInfo &replacement);
	bool handle(FileLoaderTask &task);
};
