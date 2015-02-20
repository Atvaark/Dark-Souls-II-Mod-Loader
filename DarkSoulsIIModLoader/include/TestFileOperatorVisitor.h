#pragma once
#include "FileOperatorVisitor.h"

class TestFileOperatorVisitor :	public FileOperatorVisitor<int>
{
public:
	int visitEncryptedBinderLightFileOperator(EncryptedBinderLightFileOperator* file_operator) override;
	int visitBinder4FileOperator(Binder4FileOperator* file_operator) override;
	int visitVirtualDiskFile(VirtualDiskFileOperator* file_operator) override;
	int visitMicrosoftDiskFileOperator(MicrosoftDiskFileOperator* file_operator) override;
	int visitCacheFileOperator(CacheFileOperator* file_operator) override;
	int visitFileOperator(FileOperator* file_operator) override;

};