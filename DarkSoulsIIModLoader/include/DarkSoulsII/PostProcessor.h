#pragma once
#include "PlainConditionSignal.h"
#include "PlainLightMutex.h"

class PostProcessor
{
public:
	char _0x0000[584];
	PlainConditionSignal signal; //0x0248 
	PlainLightMutex mutex1; //0x0250 
	PlainLightMutex mutex2; //0x0270 
	char _0x0290[4];
};

