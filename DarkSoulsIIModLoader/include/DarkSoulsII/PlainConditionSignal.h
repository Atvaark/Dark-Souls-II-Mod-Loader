#pragma once
#include <windows.h>

class PlainConditionSignal
{
public:
	virtual ~PlainConditionSignal(); 
	virtual bool is_handle_set();
	virtual unsigned int wait(signed int dwMilliseconds);
	virtual unsigned int wait_without_timeout(); 
	virtual void reset_sync_object(); 
	HANDLE sync_object; //0x0004 
};

