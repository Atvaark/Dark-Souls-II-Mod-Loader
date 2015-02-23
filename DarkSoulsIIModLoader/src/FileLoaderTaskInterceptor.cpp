#include "FileLoaderTaskInterceptor.h"
#include <fstream>

FileLoaderTaskInterceptor::FileLoaderTaskInterceptor()
{
}

FileLoaderTaskInterceptor::FileLoaderTaskInterceptor(FileLoaderTaskInterceptorSettings& settings) : settings(settings)
{

}

FileLoaderTaskInterceptor::~FileLoaderTaskInterceptor()
{
}

bool FileLoaderTaskInterceptor::replace_file(FileLoaderTask &task, InputFileInfo &replacement)
{
	bool intercepted = false;
	unsigned int replacementFileSize = replacement.get_file_size();
	
	if(task.read_file_size == task.total_file_size)
	{

		if (task.total_file_size < replacementFileSize)
		{
			// BUG: The old buffer isn't getting deallocated and there are still references to it.
			task.p_buffer = new char[replacementFileSize];
			task.total_file_size = replacementFileSize;
			task.read_file_size = 0;
		}
		std::ifstream file(replacement.get_file_path(), std::ios::binary);
		if (file)
		{
			file.read(task.p_buffer, replacementFileSize);
			task.read_file_size = replacementFileSize;
			intercepted = true;
		}
	}
	return intercepted;
}

void FileLoaderTaskInterceptor::add_replacement(FileInfo &file, InputFileInfo &replacement)
{
	settings.file_replacements[file] = replacement;
}

bool FileLoaderTaskInterceptor::handle(FileLoaderTask &task)
{
	if (!enabled)
		return false;

	FileInfo file = FileInfo(std::wstring(task.p_file_name), 0);
	if (task.read_file_size == task.total_file_size)
	{
		auto result = settings.file_replacements.find(file);
		if (result != settings.file_replacements.end())
		{
			return replace_file(task, result->second);
		}
		else
		{
			return false;
		}
	}
	return false;
}
