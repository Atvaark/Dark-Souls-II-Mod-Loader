#pragma once
#include <string>

class ModLoaderSettings
{
	std::wstring settings_path;
	void set_default_settings();
	void read_settings();
	void parse_settings_line(std::wstring &line);
public:
	bool replace_files;
	bool log_hashes;
	bool dump_files;
	std::wstring dump_directory;
	std::wstring mods_path;

	ModLoaderSettings();
	ModLoaderSettings(std::wstring &settings_path);
	~ModLoaderSettings();

};

