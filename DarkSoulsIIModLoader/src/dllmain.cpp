#include "dllmain.h"
#include "FileLoaderTaskInterceptor.h"
#include "FileLoaderTaskDumper.h"
#include "RttiAcceptHelper.h"
#include "TestFileOperatorVisitor.h"
#include "DarkSoulsII/TaskManager.h"

#include "minhook.1.3/lib/native/include/Minhook.h"
#pragma comment(lib, "libMinHook.lib")

const unsigned int kIsTaskManagerInitialized = 0x158BC78;
const unsigned int kTaskManager = 0x158C290;
const unsigned int kFileLoader_ReadFile = 0x009C54F0;
const unsigned int kFileLoader_ReadFileInner = 0x009C6F00;
const unsigned int kFileLoader_AddNewFileToLoad = 0x009C5C60;
const unsigned int kHashFileName = 0x01227350;
const unsigned int kGetSystemHeapImpl = 0x00913CD0;
const unsigned int kPlainConditionSignal_SetEvent = 0x009739D0;

TaskManager* p_task_manager = reinterpret_cast<TaskManager*>(kTaskManager);
BOOL* p_is_file_manager_initialized = reinterpret_cast<BOOL*>(kIsTaskManagerInitialized);

tFileLoader_ReadFile FileLoader_ReadFile = reinterpret_cast<tFileLoader_ReadFile>(kFileLoader_ReadFile);
tFileLoader_ReadFileInner FileLoader_ReadFileInnenr = reinterpret_cast<tFileLoader_ReadFileInner>(kFileLoader_ReadFileInner);
tFileLoader_AddNewFileToLoad FileLoader_AddNewFileToLoad = reinterpret_cast<tFileLoader_AddNewFileToLoad>(kFileLoader_AddNewFileToLoad);
tHashFileName HashFileName = reinterpret_cast<tHashFileName>(kHashFileName);
tGetSystemHeapImpl GetSystemHeapImpl = reinterpret_cast<tGetSystemHeapImpl>(kGetSystemHeapImpl);
tPlainConditionSignal_SetEvent PlainConditionSignal_SetEvent = reinterpret_cast<tPlainConditionSignal_SetEvent>(kPlainConditionSignal_SetEvent);

tFileLoader_ReadFile oFileLoader_ReadFile = nullptr;
tFileLoader_ReadFileInner oFileLoader_ReadFileInner = nullptr;
tFileLoader_AddNewFileToLoad oFileLoader_AddNewFileToLoad = nullptr;
tHashFileName oHashFileName = nullptr;

FileLoaderTaskInterceptor interceptor;
FileLoaderTaskDumper dumper;
RttiAcceptHelper accept_helper;

HMODULE module_handle;
FILE* p_hash_log_file = nullptr;
std::string hash_log_file_path = "hash.log";
std::string hash_log_file_mode = "a";

bool are_deques_initialized = false;
std::deque<FileLoaderTask>* p_global_read_deque;
std::deque<FileLoaderTask>* p_global_unknown_deque1;
std::deque<FileLoaderInputTask>* p_global_input_deque;
std::deque<FileLoaderOutputTask>* p_global_output_deque;
std::deque<FileLoaderTask>* p_global_deque2;

void __fastcall hk_FileLoader_read_file(FileLoader* This, void* /*notUsed*/, std::deque<FileLoaderTask>* queue)
{
	if (queue->empty() == false)
	{
		FileLoaderTask& task = queue->front();
		oFileLoader_ReadFile(This, queue);
		if (interceptor.handle(task))
		{
			TestFileOperatorVisitor visitor;
			//FileLoaderOutputTask& front = This->mOutputDeque.front();
			//FileOperator* file_operator = front.pFileInputStream->pInner->pFileOperator;
			FileOperator* file_operator = task.p_file_input_stream->p_inner->p_fileOperator;
			accept_helper.accept_file_operator_visitor<int>(file_operator, &visitor);
		}
		else
		{
			dumper.handle(task);
		}
	}
	else
	{
		oFileLoader_ReadFile(This, queue);
	}
}

bool __fastcall hk_FileLoader_read_file_inner(FileLoader* This, void* /*notUsed*/, FileLoaderTask* task, int* totalBytesRead)
{
	bool result = oFileLoader_ReadFileInner(This, task, totalBytesRead);
	return result;
}

void __fastcall hk_FileLoader_add_new_file_to_load(FileLoader* This,
	void* /*notUsed*/,
	std::deque<FileLoaderTask>* readDeque,
	std::deque<FileLoaderTask>* unknownDeque1,
	std::deque<FileLoaderInputTask>* inputDeque,
	std::deque<FileLoaderOutputTask>* outputDeque,
	std::deque<FileLoaderTask>* unknownDeque2)
{
	if (are_deques_initialized == false)
	{
		p_global_read_deque = readDeque;
		p_global_unknown_deque1 = unknownDeque1;
		p_global_input_deque = inputDeque;
		p_global_output_deque = outputDeque;
		p_global_deque2 = unknownDeque2;
		are_deques_initialized = true;
	}

	oFileLoader_AddNewFileToLoad(This, readDeque, unknownDeque1, inputDeque, outputDeque, unknownDeque2);
}

char __fastcall hFileLoader_Run(FileLoader *This, void* /*notUsed*/, int /*a2*/)
{
	std::deque<FileLoaderTask> readDeque;
	std::deque<FileLoaderTask> unknownDeque1;
	std::deque<FileLoaderInputTask> inputDeque;
	std::deque<FileLoaderOutputTask> outputDeque;
	std::deque<FileLoaderTask> unknownDeque2;

	while (This->is_running)
	{
		FileLoader_AddNewFileToLoad(This, &readDeque, &unknownDeque1, &inputDeque, &outputDeque, &unknownDeque2);
		if (readDeque.empty() && unknownDeque1.empty() && inputDeque.empty() && outputDeque.empty() && unknownDeque2.empty())
		{
			This->mutex1.enter(-1);
			if (readDeque.empty() && inputDeque.empty() && outputDeque.empty())
			{
				PlainConditionSignal_SetEvent(&This->signal1, 0);
				//UpdateExecutionTime(&This->field_C4);
			}
			This->mutex1.leave();
			if (This->is_running == false)
				break;
			This->signal1.wait(-1);
			//UpdateExecutionTime2(&This->field_C4);
		}
		else
		{
			if (This->sleep_or_wait == 1)
			{
				if (This->sleep_time > 0)
				{
					Sleep((This->sleep_time + 999) / 1000);
				}
			}
			else
			{
				This->signal2.wait(-1);
			}
			if (readDeque.empty() && unknownDeque1.empty())
			{
				if (outputDeque.empty() != false || inputDeque.empty() != false)
				{
					//FileLoader::UpdateOutputDeque(This, &output_deque);
					//FileLoader::UpdateInputDeque(This, &input_deque);
				}
				else
				{
					//LARGE_INTEGER performanceCount1;
					//LARGE_INTEGER performanceCount2;
					//if (This->m_pCacheManager)
					//{
					//	performanceCount2 = This->m_pCacheManager.performanceCount;
					//}

					//QueryPerformanceCounter(&performanceCount1);
					//if (...)
					//	Sleep((1000 + 999) / 1000);
					//else
					//    FileLoader_ReadFile(This, &unknown_deque2);
				}
			}
			//FileLoader_ReadFile(This, &readDeque);
			//FileLoader::UpdateDeque1(This, &unknown_deque1);
		}
	}
	return 0;
}

__declspec(naked) bool __fastcall hHashFileName(wchar_t* /*fileName*/, void* /*notUsedDcx*/, unsigned int* /*out_hash*/)
{
	__asm
	{
		push ebp
		mov	ebp, esp		

		push ecx // Save the file name on the stack

	GET_NEXT_CHARACTER :
		movzx	eax, word ptr [ecx]
		test	ax, ax
		jz	short ERROR_INVALID_FILENAME
		add	ecx, 2
		cmp	eax, 3Ah 
		jnz	short GET_NEXT_CHARACTER
		movzx	eax, word ptr [ecx]
		xor	edx, edx
		test	eax, eax
		jz	short SUCCESS
		push	esi
		lea	ecx, [ecx+0]

	GET_NEXT_CHARACTER_TO_HASH:
		lea	esi, [eax-41h]
		cmp	esi, 19h
		ja	short LOWERCASE_CHARACTER
		add	eax, 20h
		jmp	short HASH_CHARACTER


	LOWERCASE_CHARACTER:
		cmp	eax, 5Ch
		jnz	short HASH_CHARACTER
		mov	eax, 2Fh

	HASH_CHARACTER :

		imul	edx, 25h
		add	ecx, 2
		add	edx, eax
		movzx	eax, word ptr [ecx]
		test	eax, eax
		jnz	short GET_NEXT_CHARACTER_TO_HASH  
		pop	esi

	SUCCESS:
		mov	eax, [ebp+8]
		mov	[eax], edx

		pop eax // Remove the file name from the stack
		push edx // log_hash 2nd argument
		push eax // log_hash 1st argument
		call log_hash

		mov	eax, 1
		pop	ebp
		retn

	ERROR_INVALID_FILENAME :
		pop eax // Remove the file name from the stack
		xor	eax, eax
		pop	ebp
		retn
	}
}

void __stdcall log_hash(wchar_t* fileName, unsigned int hash)
{
	if (p_hash_log_file == nullptr)
	{
		fopen_s(&p_hash_log_file, hash_log_file_path.c_str(), hash_log_file_mode.c_str());
	}

	fwprintf_s(p_hash_log_file, L"%010u;%s\n", hash, fileName);
}

int initialize_hooks()
{
	if (MH_Initialize() != MH_OK)
		return -1;

	if (MH_CreateHook(static_cast<void*>(FileLoader_ReadFile), &hk_FileLoader_read_file, reinterpret_cast<void**>(&oFileLoader_ReadFile)) != MH_OK)
		return -1;
	if (MH_EnableHook(static_cast<void*>(FileLoader_ReadFile)) != MH_OK)
		return -1;

	if (MH_CreateHook(static_cast<void*>(FileLoader_ReadFileInnenr), &hk_FileLoader_read_file_inner, reinterpret_cast<void**>(&oFileLoader_ReadFileInner)) != MH_OK)
		return -1;
	if (MH_EnableHook(static_cast<void*>(FileLoader_ReadFileInnenr)) != MH_OK)
		return -1;

	if (MH_CreateHook(static_cast<void*>(FileLoader_AddNewFileToLoad), &hk_FileLoader_add_new_file_to_load, reinterpret_cast<void**>(&oFileLoader_AddNewFileToLoad)) != MH_OK)
		return -1;
	if (MH_EnableHook(static_cast<void*>(FileLoader_AddNewFileToLoad)) != MH_OK)
		return -1;

	//if (MH_CreateHook((void*)HashFileName, &hHashFileName, reinterpret_cast<void**>(&oHashFileName)) != MH_OK)
	//	return -1;
	//if (MH_EnableHook((void*)HashFileName) != MH_OK)
	//	return -1;

	return 1;
}


std::wstring get_executable_path()
{
	wchar_t buff[MAX_PATH];
	GetModuleFileName(nullptr, buff, MAX_PATH);
	return std::wstring(buff);
}

std::wstring get_module_path()
{
	wchar_t buff[MAX_PATH];
	GetModuleFileName(module_handle, buff, MAX_PATH);
	return std::wstring(buff);
}

std::wstring get_default_log_path()
{
	std::wstring path = get_module_path();
	std::wstring::size_type pos = path.find_last_of(L".");
	if (pos != std::wstring::npos)
		path = path.substr(0, pos);
	return path.append(L".log");
}

std::wstring get_default_dump_path()
{
	std::wstring path = get_executable_path();
	std::wstring::size_type pos = path.find_last_of(L"\\/");
	if (pos != std::wstring::npos) 
		path = path.substr(0, pos);
	return path.append(L"\\dump\\");
}

std::wstring get_default_interceptor_settings_path()
{
	std::wstring path = get_module_path();
	std::wstring::size_type pos = path.find_last_of(L".");
	if (pos != std::wstring::npos)
		path = path.substr(0, pos);
	return path.append(L".ini");
}

void initialize()
{
	while (!p_is_file_manager_initialized)
	{
		Sleep(10);
	}
	interceptor = FileLoaderTaskInterceptor(get_default_interceptor_settings_path());
	std::wstring default_dump_path = get_default_dump_path();
	std::wstring default_log_path = get_default_log_path();
	dumper = FileLoaderTaskDumper(default_dump_path, default_log_path);

	initialize_hooks();
	dumper.enabled = true;
}

// TODO: Implement a deinitialize method that unhooks the functions
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID /*lpReserved*/
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		module_handle = hModule;
		initialize();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

