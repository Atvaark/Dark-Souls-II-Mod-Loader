#pragma once
#include <string>
#include "Allocator.h"
#include "FileDevice.h"

class FileOperator
{
public:
	virtual ~FileOperator();
	virtual void method_4();
	virtual void method_8();
	virtual void method_C();
	virtual void method_10();
	virtual void method_14();
	virtual void method_18();
	virtual void method_1C();
	virtual void method_20();
	virtual void method_24();
	virtual void method_28();
	virtual void method_2C();
	virtual void method_30();
	virtual void method_34();
	virtual void method_38();
	virtual void method_3C();
	virtual void method_40();
	virtual void method_44();
	virtual void method_48();
	virtual void method_4C();
	virtual void create_file();
	virtual void close_handle();
	virtual void method_58();
	virtual void set_file_pointer();
	virtual void get_field_78();
	virtual void read_file();
	virtual void method_68();
	virtual void method_6C();
	virtual void method_70();
	virtual void method_74();
	virtual void method_78();
	virtual void method_7C();
	virtual void method_80();
	virtual void method_84();
	virtual void method_88();
	virtual void method_8C();
	virtual void method_90();
	virtual void method_94();
	virtual void method_98();
	virtual void method_9C();

	Allocator* p_allocator;
	DWORD unknown1; // 0 when truncated/extender, else -1 , or 0xFFFFFFFAu, -1 when write error
	void* unknown2;
	DWORD unknown3; // gets masked with &1
	FileDevice* p_file_device;
	std::wstring str;
};

