#include <fstream>
#include "FileLoaderTaskDumper.h"

FileLoaderTaskDumper::FileLoaderTaskDumper()
{

}


FileLoaderTaskDumper::FileLoaderTaskDumper(std::wstring &dumpPath) : dump_path(dumpPath)
{

}

FileLoaderTaskDumper::FileLoaderTaskDumper(std::wstring &dumpPath, std::wstring &logFileName) : dumper_log(FileLoaderTaskDumperLog(logFileName)), dump_path(dumpPath)
{

}

FileLoaderTaskDumper::~FileLoaderTaskDumper()
{

}

void FileLoaderTaskDumper::dump(FileLoaderTask &task, FileInfo &file)
{
	std::ofstream stream;
	std::wstring path;
	path.append(dump_path);
	path.append(sanitize_file_name(file.get_file_name()));
	create_directories(path);

	stream.open(path, std::ios::binary);
	stream.write(task.p_buffer, file.get_file_size());
	stream.close();
	dumped_files.insert(file);
	dumper_log.log(file);
}

std::wstring FileLoaderTaskDumper::sanitize_file_name(const std::wstring &fileName)
{
	std::wstring result = fileName;
	std::wstring to_replace = L"/";
	std::wstring replacement = L"\\";
	std::wstring to_remove = L":";
	std::wstring::size_type pos = 0;

	while ((pos = result.find(to_remove)) != std::string::npos)
	{
		result.erase(pos, to_remove.size());
	}

	pos = 0;
	while ((pos = result.find(to_replace, pos)) != std::string::npos)
	{
		result.replace(pos, to_replace.size(), replacement);
		pos += replacement.length();
	}
	return result;
}

void FileLoaderTaskDumper::create_directories(const std::wstring &fileName)
{
	std::wstring separator = L"\\";
	std::wstring::size_type pos = 0;
	while ((pos = fileName.find(separator, pos)) != std::string::npos)
	{
		pos += separator.length();
		CreateDirectory(fileName.substr(0, pos).c_str(), nullptr);
	}
}

bool FileLoaderTaskDumper::handle(FileLoaderTask &task)
{
	if (enabled)
	{
		if (task.read_file_size == task.total_file_size)
		{
			FileInfo file = FileInfo(std::wstring(task.p_file_name), task.total_file_size);

			auto result = dumped_files.find(file);
			if (result == dumped_files.end())
			{
				dump(task, file);
				return true;
			}
		}
	}
	return false;
}
