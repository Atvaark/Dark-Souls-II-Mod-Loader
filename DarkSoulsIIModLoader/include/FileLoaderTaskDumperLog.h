#pragma once
#include "FileInfo.h"

class FileLoaderTaskDumperLog
{
	std::wstring log_file_name;
public:
	FileLoaderTaskDumperLog();
	FileLoaderTaskDumperLog(std::wstring &logFileName);
	~FileLoaderTaskDumperLog();
	
	void log(FileInfo &fileInfo);
};