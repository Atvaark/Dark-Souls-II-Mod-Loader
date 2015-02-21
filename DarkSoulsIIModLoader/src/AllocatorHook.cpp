#include "AllocatorHook.h"


AllocatorHook::AllocatorHook()
{
}


AllocatorHook::~AllocatorHook()
{
}


void AllocatorHook::initialize()
{
	vtables[0x012BB4E4] = "Allocator";
	vtables[0x012BB554] = "BackAllocator";
	vtables[0x012EF7A4] = "HeapAllocator<DebugHeap>";
	vtables[0x012EC6CC] = "HeapAllocator<DynamicHeap<BiHeapStrategy<SmallObjectHeapWrapper<RobustHeap,0,2048,128,16>,MultiThreadingPolicy>>>";
	vtables[0x012EB50C] = "HeapAllocator<DynamicHeap<DefaultHeapStrategy<RegularHeap,MultiThreadingPolicy>>>";
	vtables[0x012E8CEC] = "HeapAllocator<DynamicHeap<DefaultHeapStrategy<RegularHeap,SingleThreadingPolicy>>>";
	vtables[0x012C529C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<BiHeapStrategy<BiHeap,MultiThreadingPolicy>>>>";
	vtables[0x012D1C6C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<BiHeapStrategy<RobustHeap,MultiThreadingPolicy>>>>";
	vtables[0x012D1CDC] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<RegularHeap,MultiThreadingPolicy>>>>";
	vtables[0x012C5384] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<SmallObjectHeapWrapper<RegularHeap,0,4096,128,16>,MultiThreadingPolicy>>>>";
	vtables[0x0134D30C] = "HeapAllocator<DynamicHeap<WinAssertHeapStrategy<DefaultHeapStrategy<SmallObjectHeapWrapper<RegularHeap,0,4096,80,4>,MultiThreadingPolicy>>>>";
	vtables[0x012EA78C] = "HeapAllocator<SystemHeapImpl>";
	vtables[0x012EF814] = "HeapAllocator<DebugDynamicHeap<DefaultHeapStrategy<RegularHeap,SingleThreadingPolicy>>>";
	vtables[0x012EB42C] = "HeapAllocator<Win32RuntimeHeapImpl>";
	vtables[0x0137AEDC] = "HeapAllocator<SelfDestructibleLinearHeap>";
	vtables[0x01355EB4] = "GXLinearAllocator";
	vtables[0x012E38FC] = "TemporaryAllocator";

	unsigned int virtual_method_count = 26;
	unsigned int method_pointer;
	for (auto i = vtables.begin(); i != vtables.end(); ++i)
	{
		for (size_t n = 0; n < virtual_method_count; n++)
		{
			method_pointer = i->first + n * sizeof(void*);
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