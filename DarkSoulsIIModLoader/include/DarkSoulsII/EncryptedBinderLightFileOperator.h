#pragma once
#include "FileOperator.h"

class EncryptedBinderLightFileOperator : public FileOperator
{
public:
	~EncryptedBinderLightFileOperator() override;
	int unknown_4;
	int unknown_5;
	int unknown_6;
	unsigned int file_size;
	unsigned int read_file_size;

};
