#pragma once
#include <deque>
#include <SDKDDKVer.h>
#include <windows.h>

#include "DarkSoulsII/FileLoader.h"
#include "DarkSoulsII/FileLoaderInputTask.h"
#include "DarkSoulsII/FileLoaderOutputTask.h"
#include "DarkSoulsII/HeapAllocator.h"
#include "DarkSoulsII/SystemHeapImpl.h"
#include "DarkSoulsII/PlainConditionSignal.h"


typedef void(__thiscall *tFileLoader_ReadFile)(FileLoader* This, std::deque<FileLoaderTask>* queue);
typedef bool(__thiscall *tFileLoader_ReadFileInner)(FileLoader* This, FileLoaderTask* task, int* total_bytes_read);
typedef void(__thiscall *tFileLoader_AddNewFileToLoad)(FileLoader* This,
	std::deque<FileLoaderTask>* read_queue,
	std::deque<FileLoaderTask>* unknown_deque1,
	std::deque<FileLoaderInputTask>* input_deque,
	std::deque<FileLoaderOutputTask>* output_deque,
	std::deque<FileLoaderTask>* unknown_deque2);

typedef int(__thiscall *tPlainConditionSignal_SetEvent)(PlainConditionSignal* This, char set_event);

typedef bool(__thiscall *tHashFileName)(wchar_t *fileName, unsigned int *out_hash);
typedef HeapAllocator<SystemHeapImpl>*(__cdecl *tGetSystemHeapImpl)();

void __fastcall hk_FileLoader_read_file(FileLoader* This, void* notUsed, std::deque<FileLoaderTask>* queue);
bool __fastcall hk_FileLoader_read_file_inner(FileLoader* This, void* notUsed, FileLoaderTask* task, int* total_bytes_read);
void __fastcall hk_FileLoader_add_new_file_to_load(FileLoader* This,
	void* notUsed,
	std::deque<FileLoaderTask>* read_deque,
	std::deque<FileLoaderTask>* unknown_deque1,
	std::deque<FileLoaderInputTask>* input_deque,
	std::deque<FileLoaderOutputTask>* output_deque,
	std::deque<FileLoaderTask>* unknown_deque2);

void __stdcall log_hash(wchar_t* file_name, unsigned int hash);

int initialize_hooks();

std::wstring get_executable_path();

std::wstring get_module_path();

std::wstring get_default_log_path();

std::wstring get_default_hash_log_path();

std::wstring get_default_dump_path();

std::wstring get_default_interceptor_settings_path();

void initialize();

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
	);