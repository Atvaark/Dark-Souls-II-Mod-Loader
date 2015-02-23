#include <windows.h>
#include <fstream>
#include "ModLoaderSettings.h"

ModLoaderSettings::ModLoaderSettings()
{
	set_default_settings();
}

ModLoaderSettings::ModLoaderSettings(std::wstring& settings_path) : settings_path(settings_path)
{
	set_default_settings();
	read_settings();
}

ModLoaderSettings::~ModLoaderSettings()
{
}

void ModLoaderSettings::set_default_settings()
{
	replace_files = false;
	log_hashes = false;
	dump_files = false;
	dump_directory = L"";
	mods_path = L"";
}

void ModLoaderSettings::read_settings()
{
	std::wstring line;
	char path_buffer[MAX_PATH];

	WideCharToMultiByte(0, 0, settings_path.c_str(), -1, path_buffer, MAX_PATH, nullptr, nullptr);

	std::wifstream stream(path_buffer, std::ios::in);
	if (stream)
	{
		while (getline(stream, line))
		{
			if (line.length() == 0 || line.find(L"#") == 0)
				continue;
			parse_settings_line(line);
		}

		stream.close();
	}
}

void ModLoaderSettings::parse_settings_line(std::wstring& line)
{
	std::wstring replace_files_option = L"replace_files=";
	std::wstring log_hashes_option = L"log_hashes=";
	std::wstring dump_files_option = L"dump_files=";
	std::wstring dump_directory_option = L"dump_directory=";
	std::wstring mods_directory_option = L"mods_directory=";

	if (line.find(replace_files_option) == 0)
	{
		replace_files = line.substr(replace_files_option.length()) == L"true";
	}
	else if (line.find(log_hashes_option) == 0)
	{
		log_hashes = line.substr(log_hashes_option.length()) == L"true";
	}
	else if (line.find(dump_files_option) == 0)
	{
		dump_files = line.substr(dump_files_option.length()) == L"true";
	}
	else if (line.find(dump_directory_option) == 0)
	{
		dump_directory = line.substr(dump_directory_option.length());
		if (dump_directory.length() > 0 && dump_directory.back() != L'\\')
			dump_directory = dump_directory + L'\\';
	}
	else if (line.find(mods_directory_option) == 0)
	{
		mods_path = line.substr(mods_directory_option.length());
		if (mods_path.length() > 0 && mods_path.back() != L'\\')
			mods_path = mods_path + L'\\';
	}
}