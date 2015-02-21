#pragma once
#include "FileInputStream.h"
#include "FileTransferTask.h"

class FileLoaderTask
{
public:
	wchar_t* p_file_name; //0x0000 
	char _0x0004[4];
	char* p_buffer; //0x0008 
	int total_file_size; //0x000C 
	int read_file_size; //0x0010 
	FileInputStream* p_file_input_stream; //0x0014 
	char _0x0018[52];
	FileTransferTask* p_file_transfer_task; //0x004C 
	char _0x0050[16];
};//Size=0x0060
