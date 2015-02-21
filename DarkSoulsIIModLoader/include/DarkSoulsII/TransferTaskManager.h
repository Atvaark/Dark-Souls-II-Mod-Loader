#pragma once
#include "PlainConditionSignal.h"
#include "PlainLightMutex.h"
#include "CacheableFileLoader.h"
#include "FileLoader.h"
#include "PostProcessor.h"

class TransferTaskManager : public Runnable
{
public:
	TransferTaskManager();
	virtual void run() override;
	virtual ~TransferTaskManager() override;
	char _0x0004[12];
	PlainConditionSignal signal; //0x0010 
	PlainLightMutex mutex1; //0x0018 
	PlainLightMutex mutex2; //0x0038 
	char _0x0058[4];
	int sleep_time; //0x005C 
	char _0x0060[56];
	CacheableFileLoader cacheable_file_loader; //0x0098 
	char _0x02DC[28];
	FileLoader file_loader; //0x02F8 
	char _0x0424[20];
	PostProcessor post_processor; //0x0438 
	char _0x06CC[120];
};
