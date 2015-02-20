#pragma once
#include "FileOperator.h"

class FileInputStreamInner
{
public:
	FileInputStreamInner();
	~FileInputStreamInner();
	void* p_allocator; //0x0000
	FileOperator* p_fileOperator; //0x0004 
	void* p_unknown_1; //0x0008
	void* p_unknown_2; //0x000C
};

