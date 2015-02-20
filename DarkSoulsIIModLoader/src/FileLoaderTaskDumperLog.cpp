#include "FileLoaderTaskDumperLog.h"
#include <fstream>

FileLoaderTaskDumperLog::FileLoaderTaskDumperLog()
{

}

FileLoaderTaskDumperLog::FileLoaderTaskDumperLog(std::wstring &logFileName) : log_file_name(logFileName)
{

}
	
FileLoaderTaskDumperLog::~FileLoaderTaskDumperLog()
{

}

void FileLoaderTaskDumperLog::log(FileInfo &fileInfo)
{
	std::wfstream stream;
	stream.open(log_file_name, std::ios::app);
	if (stream.is_open() == false)
		return;
	stream << fileInfo.get_file_name() << L"\t" << fileInfo.get_file_size() << L"\n";
	stream.close();
}
