#include <windows.h>
#include <fstream>
#include "FileLoaderTaskInterceptorSettings.h"
#include "InputFileInfo.h"

FileLoaderTaskInterceptorSettings::FileLoaderTaskInterceptorSettings()
{

}

FileLoaderTaskInterceptorSettings::FileLoaderTaskInterceptorSettings(std::wstring &mods_path, std::wstring &settings_path) :  mods_path(mods_path), settings_path(settings_path)
{
	read_settings();
}

FileLoaderTaskInterceptorSettings::~FileLoaderTaskInterceptorSettings()
{

}

void FileLoaderTaskInterceptorSettings::read_settings()
{
	std::wstring line;
	char path_buffer[MAX_PATH];

	WideCharToMultiByte(0, 0, settings_path.c_str(), -1, path_buffer, MAX_PATH, nullptr, nullptr);
	
	std::wifstream stream(path_buffer, std::ios::in);
	if (stream)
	{
		while (getline(stream, line))
		{
			if (line.length() == 0 || line.substr(0, 1) == L"#")
				continue;
			parse_replacement_file(line);
		}

		stream.close();
	}

}

void FileLoaderTaskInterceptorSettings::parse_replacement_file(std::wstring &line)
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
	InputFileInfo replacement_file(file_to_replace_name, mods_path + replacement_file_name);

	// HACK: This updates the file size manually
	replacement_file.get_file_size();

	file_replacements.insert(std::pair<FileInfo, InputFileInfo>(file_to_replace, replacement_file));
}
