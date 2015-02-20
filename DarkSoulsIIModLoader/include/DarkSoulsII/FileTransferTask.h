#pragma once
#include "TransferTask.h"
#include "PlainLightMutex.h"
#include "ChainedFileRsrcRequest.h"

class FileTransferTask : public TransferTask
{
public:
	char _0x00E8[24];
	ChainedFileRsrcRequest chained_file_rsrc_request; //0x0100 chainedFileRsrcRequestVtable
	char _0x01C0[8];
	PlainLightMutex mutex; //0x01C8 
	char _0x01E8[56];

};//Size=0x0220