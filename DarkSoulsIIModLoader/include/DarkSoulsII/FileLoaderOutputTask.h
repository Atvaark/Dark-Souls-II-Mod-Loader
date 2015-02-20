#pragma once
#include <Windows.h>
#include "FileInputStream.h"

class FileLoaderOutputTask
{
public:
	wchar_t* p_file_name; //0x0000 
	FileInputStream* p_file_input_stream; //0x0004 
	int* p_status; //0x0008 
	DWORD unknown; //0x000C 
	bool* p_is_in_output_queue; //0x0010 

};//Size=0x0014