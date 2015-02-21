#pragma once
#include <deque>
#include "Allocator.h"
#include "FileLoaderTask.h"
#include "FileLoaderOutputTask.h"
#include "Runnable.h"
#include "CacheManager.h"
#include "PlainConditionSignal.h"
#include "PlainLightMutex.h"
#include "PostProcessor.h"

class FileLoader : public Runnable
{
public:
	virtual void run() override;
	virtual ~FileLoader() override;
	virtual void open_file();
	virtual void set_settings();
	virtual void method_5();
	virtual void uninitialize();
	Allocator* p_allocator; //0x0004 
	PostProcessor* p_postProcessor; //0x0008 
	CacheManager* p_cacheManager; //0x000C cacheable?
	std::deque<FileLoaderTask> read_deque; //0x0010 
	void* p_read_deque_allocator1; //0x0024 
	void* p_read_deque_allocator2; //0x0028 
	unsigned char is_read_deque_initialized; //0x002C 
	char _0x002D[3];
	std::deque<FileLoaderTask> unput_deque; //0x0030 
	void* p_input_deque_allocator1; //0x0044 
	void* p_input_deque_allocator2; //0x0048 
	unsigned char is_input_deque_initialized; //0x004C 
	char _0x004D[3];
	std::deque<FileLoaderOutputTask> output_deque; //0x0050 
	void* p_output_deque_allocator1; //0x0064 
	void* p_output_deque_allocator2; //0x0068 
	unsigned char is_output_deque_initialized; //0x006C 
	char _0x006D[3];
	PlainConditionSignal signal1; //0x0070 
	PlainConditionSignal signal2; //0x0078 
	PlainLightMutex mutex1; //0x0080 
	void * p_thread; //0x00A0 
	unsigned char is_running; //0x00A4 
	unsigned char do_use_system_cache; //0x00A5 
	char _0x00A6[10];
	int read_chunk_size; //0x00B0 
	char _0x00B4[8];
	int sleep_time; //0x00BC 
	int sleep_or_wait; //0x00C0 
	char _0x00C4[92];
	int performance_count; //0x0120 
	char _0x0124[4];

};
