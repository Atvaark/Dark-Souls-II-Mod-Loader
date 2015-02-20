#pragma once
#include "FileOperator.h"
#include "FileInputStream.h"

class TransferTaskInner
{
public:
	char _0x0000[4];
	FileOperator* p_file_operator; //0x0004 
	char _0x0008[8];
	FileInputStream input_stream; //0x0010 
	wchar_t* file_name; //0x001C 
	char _0x0020[12];
	unsigned int file_name_len; //0x002C 
	char _0x0030[24];
	unsigned int  file_size1; //0x0048 
	char _0x004C[12];
	unsigned int  file_size2; //0x0058 
	char _0x005C[4];

};//Size=0x0060