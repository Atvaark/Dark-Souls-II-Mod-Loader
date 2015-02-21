#pragma once
#include <map>

class AllocatorHook
{
	std::map<unsigned int, std::string> vtables;
	std::map<unsigned int, std::string> hooked_methods;
public:
	AllocatorHook();
	~AllocatorHook();

	void initialize();
	void hook_method(unsigned int method_pointer, unsigned int method_index, std::string &allocator_name);
};
