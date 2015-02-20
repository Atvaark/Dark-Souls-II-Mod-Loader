#pragma once
#include "FileOperator.h"

class EncryptedBinderLightFileOperator : public FileOperator
{
public:
	~EncryptedBinderLightFileOperator() override;
	DWORD unknown_4;
	DWORD unknown_5;
	DWORD unknown_6;
	unsigned int file_size;
	unsigned int read_file_size;

};