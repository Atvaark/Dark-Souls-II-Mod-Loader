#include <windows.h> 
#include <tlhelp32.h> 
#include <shlwapi.h> 
#include <iostream>

BOOL inject_dll(DWORD process_id, const char * dll_path);
int get_process_id_from_process_name(const char * process_name);

char loading_animation_characters[] = { '\\', '|', '/', '-' };

int main(int /*argc*/, char * /*argv*/[])
{
	std::cout << "Searching the process list for DarkSoulsII.exe" << std::endl;
	DWORD process_id = 0;
	int loading_animation_index = 0;
	while (!process_id)
	{
		process_id = get_process_id_from_process_name("DarkSoulsII.exe");			
		std::cout << "\b" << loading_animation_characters[loading_animation_index] << std::flush;
		loading_animation_index = (loading_animation_index + 1) % 4;
		Sleep(50);
	}
	std::cout << std::endl;
	std::cout << "Found DarkSoulsII.exe (ID: " << process_id << ")" << std::endl;
	std::cout << "Injecting DarkSoulsIIModLoader.dll" << std::endl;
	char dll_path_buffer[MAX_PATH] = { 0 };
	GetFullPathNameA("DarkSoulsIIModLoader.dll", MAX_PATH, dll_path_buffer, nullptr);

	if (inject_dll(process_id, dll_path_buffer) == false)
	{
		std::cout << "Could not inject DarkSoulsIIModLoader.dll" << std::endl;
		return 1;
	}
	std::cout << "DarkSoulsIIModLoader.dll injected successfully" << std::endl;
	return 0;
}

int inject_dll(DWORD process_id, const char* dll_name)
{
	// The following antivirus engines report this as risks/not malicious: Cyren, F-Prot and VIPRE
	HANDLE process_handle;
	LPVOID remote_string;
	LPVOID load_library_address;

	if (!process_id)
		return 0;

	process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, process_id);
	if (!process_handle)
		return 0;

	load_library_address = static_cast<LPVOID>(GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA"));
	remote_string = static_cast<LPVOID>(VirtualAllocEx(process_handle, nullptr, strlen(dll_name), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE));
	WriteProcessMemory(process_handle, static_cast<LPVOID>(remote_string), dll_name, strlen(dll_name), nullptr);
	CreateRemoteThread(process_handle, nullptr, NULL, static_cast<LPTHREAD_START_ROUTINE>(load_library_address), static_cast<LPVOID>(remote_string), NULL, nullptr);
	CloseHandle(process_handle);
	return 1;
}

int get_process_id_from_process_name(const char* process_name)
{
	PROCESSENTRY32 process_entry;
	HANDLE snapshot_handle;

	snapshot_handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot_handle == INVALID_HANDLE_VALUE)
		return 0;

	process_entry.dwSize = sizeof(PROCESSENTRY32);

	while (Process32Next(snapshot_handle, &process_entry))
	{
		if (StrStrIA(process_entry.szExeFile, process_name))
		{
			return process_entry.th32ProcessID;
		}
	}
	return 0;
}