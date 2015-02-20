#pragma once
#include <unordered_set>
#include "FileInfo.h"
#include "FileInfoHasher.h"
#include "FileLoaderTaskDumperLog.h"
#include "DarkSoulsII/FileLoaderTask.h"

class FileLoaderTaskDumper
{
	std::unordered_set<FileInfo, FileInfoHasher> dumped_files; 
	FileLoaderTaskDumperLog dumper_log;

	void dump(FileLoaderTask &task, FileInfo &file);
	std::wstring sanitize_file_name(const std::wstring &fileName);
	void create_directories(const std::wstring &fileName);
public:
	std::wstring dump_path;
	bool enabled;

	FileLoaderTaskDumper();
	FileLoaderTaskDumper(std::wstring &dumpPath);
	FileLoaderTaskDumper(std::wstring &dumpPath, std::wstring &logFileName);
	~FileLoaderTaskDumper();

	bool handle(FileLoaderTask &task);

};

