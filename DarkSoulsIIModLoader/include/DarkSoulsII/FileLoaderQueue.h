#pragma once

#include "FileLoaderTask.h"


class FileLoaderQueue
{
public:
	void* p_unknown; //0x0000 
	FileLoaderTask** p_p_file_loader_tasks; //0x0004 Map

	// 0, 8 or 24
	int file_count; //0x0008 

	// offset of element
	int next_index; //0x000C 

	// 0-15, 23
	int files_to_read; //0x0010 

};
