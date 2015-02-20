#pragma once
#include "DarkSoulsII/FileOperator.h"
#include "DarkSoulsII/MicrosoftDiskFileOperator.h"
#include "DarkSoulsII/EncryptedBinderLightFileOperator.h"
#include "DarkSoulsII/CacheFileOperator.h"
#include "DarkSoulsII/VirtualDiskFileOperator.h"
#include "DarkSoulsII/Binder4FileOperator.h"

template <typename T>
class FileOperatorVisitor
{
protected:
	~FileOperatorVisitor()
	{
	}

public:
	virtual T visitEncryptedBinderLightFileOperator(EncryptedBinderLightFileOperator* file_operator) = 0;
	virtual T visitBinder4FileOperator(Binder4FileOperator* file_operator) = 0;
	virtual T visitVirtualDiskFile(VirtualDiskFileOperator* file_operator) = 0;
	virtual T visitMicrosoftDiskFileOperator(MicrosoftDiskFileOperator* file_operator) = 0;
	virtual T visitCacheFileOperator(CacheFileOperator* file_operator) = 0;
	virtual T visitFileOperator(FileOperator* file_operator) = 0;
};
