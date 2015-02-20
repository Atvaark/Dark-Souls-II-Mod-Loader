#pragma once
#include "FileOperator.h"
#include "MicrosoftDiskFileOperatorFlag.h"

class MicrosoftDiskFileOperator : public FileOperator
{
public:
	~MicrosoftDiskFileOperator() override;
	DWORD unknown4;
	HANDLE h_file;
	MicrosoftDiskFileOperatorFlag flags;
	BY_HANDLE_FILE_INFORMATION file_information; 
	DWORD unknown6;
	unsigned int offset_1;
	unsigned int offset_2;
	OVERLAPPED overlapped;
	DWORD number_of_bytes_to_read;
	DWORD unknown15;
	DWORD unknown16;

};