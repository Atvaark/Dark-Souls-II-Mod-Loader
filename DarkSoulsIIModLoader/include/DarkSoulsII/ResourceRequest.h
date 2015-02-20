#pragma once

class ResourceRequest
{
public:
	virtual ~ResourceRequest(); 
	virtual void check_file_name(); 

	char _0x0004[48];
	wchar_t* file_name; //0x0034  resourceName (std::wstring resourceName)
	DWORD unknown1; //0x0038 
	DWORD unknown2; //0x003C 
	DWORD unknown3; //0x0040 
	DWORD file_name_length_; //0x0044 
	DWORD file_name_capacity; //0x0048 
	std::allocator<wchar_t>* p_file_name_allocator; //0x004C 
	DWORD file_name_ref_count_state; //0x0050 
	DWORD load_state; //0x0054 loadState
	char _0x0058[104];

};//Size=0x00C0