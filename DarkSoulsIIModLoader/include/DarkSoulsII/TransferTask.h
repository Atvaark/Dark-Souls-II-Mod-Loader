#pragma once
#include "TransferTaskInner.h"

class TransferTask
{
public:
	virtual void method_1(); //
	virtual void method_2(); //
	virtual void method_3(); //
	virtual void method_4(); //
	virtual void method_5(); //
	virtual void method_6(); //
	virtual void method_7(); //
	virtual void method_8(); //
	virtual void method_9(); //
	virtual void method_10(); //

	char _0x0004[52];
	unsigned int state1; //0x0038 
	char _0x003C[12];
	unsigned int status; //0x0048 
	char _0x004C[4];
	unsigned int state2; //0x0050 
	char _0x0054[12];
	TransferTaskInner inner; //0x0060 
	char _0x00C0[32];
	unsigned int  flag_field1; //0x00E0 
	unsigned int  is_in_output_queue; //0x00E4 

};//Size=0x00E8