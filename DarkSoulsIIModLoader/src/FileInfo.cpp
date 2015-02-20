#include "FileInfo.h"

FileInfo::FileInfo() : file_name(L""), file_size(0)
{

}

FileInfo::FileInfo(const std::wstring &fileName) : file_name(fileName), file_size(0)
{

}

FileInfo::FileInfo(const std::wstring &fileName, const unsigned int fileSize) : file_name(fileName), file_size(fileSize)
{

}


FileInfo::~FileInfo()
{
}


std::wstring FileInfo::get_file_name() const
{
	return file_name;
}

unsigned int FileInfo::get_file_size() const
{
	return file_size;
}


bool FileInfo::operator==(const FileInfo& other) const
{
	return file_name.compare(other.file_name) == 0;
}

bool FileInfo::operator!=(const FileInfo& other) const
{
	return !(*this == other);
}

bool FileInfo::operator<(const FileInfo& r) const
{
	return get_file_name() < r.get_file_name();
}
