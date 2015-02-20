#pragma once
#include <string>
#include <Windows.h>

class FileEnumeratorSPI
{
public:
	virtual ~FileEnumeratorSPI();
	virtual bool find_first_file(wchar_t *file_name, HANDLE* handle_out, std::wstring* string_out);
	virtual HANDLE close_handle(HANDLE* handle);
	virtual bool find_next_file(HANDLE* handle, std::wstring* string_out);
};
