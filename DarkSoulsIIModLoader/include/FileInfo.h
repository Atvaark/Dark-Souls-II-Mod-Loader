#pragma once
#include <string>

class FileInfo
{
protected:
	std::wstring file_name;
	unsigned int file_size;
public:
	FileInfo();
	FileInfo(const std::wstring &fileName);
	FileInfo(const std::wstring &fileName, const unsigned int fileSize);
	virtual ~FileInfo();

	std::wstring get_file_name() const;
	virtual unsigned int get_file_size() const;

	bool operator==(const FileInfo& other) const;
	bool operator!=(const FileInfo& other) const;
	bool operator<(const FileInfo& r) const;
};

