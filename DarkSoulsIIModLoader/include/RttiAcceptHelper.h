#pragma once
#include "FileOperatorVisitor.h"
#include "DarkSoulsII/FileOperator.h"
#include "DarkSoulsII/EncryptedBinderLightFileOperator.h"

class RttiAcceptHelper
{
	static unsigned int get_vtable(void* object)
	{
		return reinterpret_cast<unsigned int*>(object)[0];
	}
public:

	template <typename T>
	static T accept_file_operator_visitor(FileOperator* file_operator, FileOperatorVisitor<T>* file_operator_visitor)
	{
		const unsigned int kEncryptedBinderLightFileOperator = 0x013EDE14;
		const unsigned int kBinder4FileOperator = 0x012F94FC;
		const unsigned int kVirtualDiskFileOperator = 0x012F93F4;
		const unsigned int kMicrosoftDiskFileOperator = 0x012F823C;
		const unsigned int kCacheFileOperator = 0x012F1F84;
		const unsigned int kFileOperator = 0x012EC35C;

		unsigned int vtable_address = get_vtable(file_operator);

		switch (vtable_address)
		{
		case kEncryptedBinderLightFileOperator:
			return file_operator_visitor->visitEncryptedBinderLightFileOperator(reinterpret_cast<EncryptedBinderLightFileOperator*>(file_operator));
		case kBinder4FileOperator:
			return file_operator_visitor->visitBinder4FileOperator(reinterpret_cast<Binder4FileOperator*>(file_operator));
		case kVirtualDiskFileOperator:
			return file_operator_visitor->visitVirtualDiskFile(reinterpret_cast<VirtualDiskFileOperator*>(file_operator));
		case kMicrosoftDiskFileOperator:
			return file_operator_visitor->visitMicrosoftDiskFileOperator(reinterpret_cast<MicrosoftDiskFileOperator*>(file_operator));
		case kCacheFileOperator:
			return file_operator_visitor->visitCacheFileOperator(reinterpret_cast<CacheFileOperator*>(file_operator));
		case kFileOperator:
			return file_operator_visitor->visitFileOperator(file_operator);
		}
		return false;
	}

};
