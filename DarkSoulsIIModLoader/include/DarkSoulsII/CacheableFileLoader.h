#pragma once
#include "FileLoader.h"

class CacheableFileLoader: public FileLoader
{
public:
	CacheableFileLoader();
	virtual void run() override;
	virtual ~CacheableFileLoader();
	virtual void open_file() override;
	virtual void set_settings() override;
	virtual void method_5() override;
	virtual void initialize();
	char _0x012C[32];
	PlainLightMutex mutex_2; //0x014C 
	char _0x016C[68];
	PlainLightMutex mutex_3; //0x01B0 
	char _0x01D0[116];
};

