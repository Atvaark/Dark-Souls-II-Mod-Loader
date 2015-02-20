#include "AllocatorHook.h"


AllocatorHook::AllocatorHook()
{
}


AllocatorHook::~AllocatorHook()
{
}


void AllocatorHook::initialize()
{
	// TODO: Update offsets from 1.0.7 to 1.0.10
	vtables[0x0117C2C4] = "Allocator";
	vtables[0x0117C334] = "BackAllocator";
	vtables[0x011B0184] = "HeapAllocator<DebugHeap>";
	vtables[0x011AD10C] = "HeapAllocator<DynamicHeap<BiHeapStrategy<SmallObjectHeapWrapper<RobustHeap,0,2048,128,16>,MultiThreadingPolicy>>>";
	vtables[0x011ABF4C] = "HeapAllocator<DynamicHeap<DefaultHeapStrategy<RegularHeap,MultiThreadingPolicy>>>";
	vtables[0x011A972C] = "HeapAllocator<DynamicHeap<DefaultHeapStrategy<RegularHeap,SingleThreadingPolicy>>>";
	vtables[0x01185FCC] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<BiHeapStrategy<BiHeap,MultiThreadingPolicy>>>>";
	vtables[0x0119290C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<BiHeapStrategy<RobustHeap,MultiThreadingPolicy>>>>";
	vtables[0x0119297C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<RegularHeap,MultiThreadingPolicy>>>>";
	vtables[0x011860B4] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<SmallObjectHeapWrapper<RegularHeap,0,4096,128,16>,MultiThreadingPolicy>>>>";
	vtables[0x0120DB8C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<SmallObjectHeapWrapper<RegularHeap,0,4096,80,4>,MultiThreadingPolicy>>>>";
	vtables[0x011AB1CC] = "HeapAllocator<SystemHeapImpl>";
	vtables[0x011B01F4] = "HeapAllocator<DebugDynamicHeap<DefaultHeapStrategy<RegularHeap,SingleThreadingPolicy>>>";
	vtables[0x011ABE6C] = "HeapAllocator<Win32RuntimeHeapImpl>";
	vtables[0x0123B74C] = "HeapAllocator<SelfDestructibleLinearHeap>";
	vtables[0x01216734] = "GXLinearAllocator";
	vtables[0x011A440C] = "TemporaryAllocator";

	unsigned int virtual_method_count = 26;
	unsigned int method_pointer;
	for (auto i = vtables.begin(); i != vtables.end(); ++i)
	{
		for (size_t n = 0; n < virtual_method_count; n++)
		{
			method_pointer = i->first + n * sizeof(unsigned int);
			hook_method(method_pointer, n, i->second);
		}

	}

}

void AllocatorHook::hook_method(unsigned int method_pointer, unsigned int method_index, std::string &allocator_name)
{
	auto find = hooked_methods.find(method_pointer);
	if (find != hooked_methods.end())
	{
		hooked_methods[method_pointer] = allocator_name;
		// TODO: Hook the method.
	}

}