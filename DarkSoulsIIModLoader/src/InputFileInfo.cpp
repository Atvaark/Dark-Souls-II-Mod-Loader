#include "InputFileInfo.h"
#include <fstream>

InputFileInfo::InputFileInfo()
{
}

InputFileInfo::InputFileInfo(const std::wstring &file_name, const std::wstring &file_path) : FileInfo(file_name), file_path(file_path), file_size_read(false)
{
}

InputFileInfo::~InputFileInfo()
{
}

unsigned int InputFileInfo::get_file_size()
{
	if (file_size_read)
		return file_size;

	std::ifstream in(file_path, std::ifstream::ate | std::ifstream::binary);
	if (in)
	{
		file_size = static_cast<unsigned int>(in.tellg());
		file_size_read = true;
		return file_size;
	}
	return 0;
}

std::wstring InputFileInfo::get_file_path() const
{
	return file_path;
}

InputFileInfo& InputFileInfo::operator = (const InputFileInfo& rhs)
{
	if (this != &rhs)
	{
		file_name = rhs.file_name;
		file_size = rhs.file_size;
		file_path = rhs.file_path;
	}
	return *this;
}
