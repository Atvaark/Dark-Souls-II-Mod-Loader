#pragma once
#include <Windows.h>
#include "FileInputStream.h"
#include "FileInputStreamInner.h"

class FileLoaderInputTask
{
public:
	wchar_t* p_file_name; //0x0000 
	FileInputStreamInner* p_file_input_stream_inner; //0x0004 
	FileInputStream* p_file_input_stream; //0x0008 
	int unknown_flag; //0x000C 2,4
	int unknown_1; //0x0010 
	int unknown_2; //0x0014 
	int status; //0x0018 12 = handle created, 18=?
	int unknown_3; //0x001C 
	int unknown_4; //0x0020 
	int unknown_5; //0x0024 

};
