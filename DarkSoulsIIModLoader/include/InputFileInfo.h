#pragma once
#include "FileInfo.h"
class InputFileInfo : public FileInfo
{
	std::wstring file_path;
	bool file_size_read;
public:
	InputFileInfo();
	InputFileInfo(const std::wstring &file_name, const std::wstring &file_path);
	~InputFileInfo();

	virtual unsigned int get_file_size();
	std::wstring get_file_path() const;

	InputFileInfo& operator=(const InputFileInfo& rhs);
};

