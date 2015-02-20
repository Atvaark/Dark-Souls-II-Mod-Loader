#include <windows.h>
#include <fstream>
#include "FileLoaderTaskInterceptorSettings.h"
#include "InputFileInfo.h"

FileLoaderTaskInterceptorSettings::FileLoaderTaskInterceptorSettings()
{

}

FileLoaderTaskInterceptorSettings::FileLoaderTaskInterceptorSettings(std::wstring &settingsPath) : settings_path(settingsPath)
{
	read_settings();
}

FileLoaderTaskInterceptorSettings::~FileLoaderTaskInterceptorSettings()
{

}

void FileLoaderTaskInterceptorSettings::read_settings()
{
	std::wstring line;
	char buff[MAX_PATH];

	WideCharToMultiByte(0, 0, settings_path.c_str(), -1, buff, MAX_PATH, nullptr, nullptr);
	std::wifstream stream(buff, std::ios::in);
	if (stream)
	{
		while (getline(stream, line))
		{
			read_settings_line(line);
		}

		stream.close();
	}

}

void FileLoaderTaskInterceptorSettings::read_settings_line(std::wstring &line)
{

	std::wstring file_to_replace_name;
	int file_to_replace_size = 0;
	std::wstring replacement_file_name;

	std::wstring::size_type offset = 0;
	std::wstring::size_type pos;
	pos = line.find_first_of(';', offset);
	if (pos == std::wstring::npos)
		return;
	file_to_replace_name = line.substr(0, pos);
	replacement_file_name = line.substr(pos + 1, line.size() - pos - 1);


	FileInfo file_to_replace(file_to_replace_name, file_to_replace_size);
	InputFileInfo replacement_file(file_to_replace_name, replacement_file_name);

	// HACK: This updates the file size manually
	replacement_file.get_file_size();


	file_replacements.insert(std::pair<FileInfo, InputFileInfo>(file_to_replace, replacement_file));
}
