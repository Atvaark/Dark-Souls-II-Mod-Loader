#include "FileInfoHasher.h"

size_t FileInfoHasher::operator()(const FileInfo& file_info) const
{
	std::wstring file_name = file_info.get_file_name();
	std::hash<std::wstring> hash_fn;
	return hash_fn(file_name);
}
