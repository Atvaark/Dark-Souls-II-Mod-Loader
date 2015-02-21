#pragma once
#include "FileOperator.h"
#include "MicrosoftDiskFileOperatorFlag.h"

class MicrosoftDiskFileOperator : public FileOperator
{
public:
	~MicrosoftDiskFileOperator() override;
	int unknown4;
	HANDLE h_file;
	MicrosoftDiskFileOperatorFlag flags;
	BY_HANDLE_FILE_INFORMATION file_information; 
	int unknown6;
	unsigned int offset_1;
	unsigned int offset_2;
	OVERLAPPED overlapped;
	int number_of_bytes_to_read;
	int unknown15;
	int unknown16;
};
