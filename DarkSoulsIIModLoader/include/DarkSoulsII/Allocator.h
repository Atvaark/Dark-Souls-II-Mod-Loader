#pragma once

class Allocator
{
public:
	virtual ~Allocator();
	virtual int method_1();
	virtual int method_2();
	virtual int method_3(int* a1, int a2);
	virtual int method_4();
	virtual int method_5();
	virtual int method_6();
	virtual int method_7();
	virtual int method_8(int a1);
	virtual int set_size(unsigned int size);
	virtual char* allocate(unsigned int size, unsigned int alignment);
	virtual int method_11(int a1, int a2);
	virtual int method_12(int a1, int a2, int a3);
	virtual int deallocate(char* pointer);
	virtual int method_14(int a1);
	virtual int method_15(int a1);
	virtual int method_16(int a1, int a2);
	virtual int method_17(int a1, int a2);
	virtual int method_18(int a1, int a2, int a3);
	virtual int method_19(int a1);
	virtual char method_20();
	virtual char method_21(int a1);
	virtual char method_22(int a1);
	virtual int enter_mutex();
	virtual int leave_mutex();
	virtual int method_25(int a1);
};