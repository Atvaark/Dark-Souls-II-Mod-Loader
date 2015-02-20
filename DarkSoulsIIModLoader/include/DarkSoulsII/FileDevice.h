#pragma once
#include "FileEnumeratorSPI.h"
#include "DriveType.h"

class FileDevice
{
public:
	virtual ~FileDevice();
	virtual FileDevice* __thiscall method_2(int a1, int a2, int a3, int a4, char a5);
	virtual FileEnumeratorSPI*__thiscall get_enumerator();
	virtual DriveType __thiscall get_drive_type(wchar_t* str, int a3);
	virtual int method_5();
	virtual bool method_6(wchar_t *a1, void* a2, void* a3);
};