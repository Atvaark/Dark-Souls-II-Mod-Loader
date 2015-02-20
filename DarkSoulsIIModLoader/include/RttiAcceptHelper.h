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
		const unsigned int kEncryptedBinderLightFileOperator = 0x012AE494;
		const unsigned int kBinder4FileOperator = 0x011B9ED4;
		const unsigned int kVirtualDiskFileOperator = 0x011B9DCC;
		const unsigned int kMicrosoftDiskFileOperator = 0x011B8C1C;
		const unsigned int kCacheFileOperator = 0x011B2964;
		const unsigned int kFileOperator = 0x011ACD9C;

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
