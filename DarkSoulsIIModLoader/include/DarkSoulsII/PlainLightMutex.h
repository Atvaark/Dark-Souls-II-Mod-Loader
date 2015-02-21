#pragma once
class PlainLightMutex
{
public:
	virtual ~PlainLightMutex();
	virtual bool is_initialized();
	virtual void enter(int timeoutValue);
	virtual int try_enter();
	virtual void leave();

	CRITICAL_SECTION critical_section; //0x0004 
	unsigned char is_initialized_flag; //0x001C 
	char _0x001D[3];
};
