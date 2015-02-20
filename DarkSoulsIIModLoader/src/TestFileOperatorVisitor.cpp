#include "TestFileOperatorVisitor.h"

int TestFileOperatorVisitor::visitEncryptedBinderLightFileOperator(EncryptedBinderLightFileOperator* file_operator)
{
	return 5;
}

int TestFileOperatorVisitor::visitBinder4FileOperator(Binder4FileOperator* file_operator)
{
	return 4;
}

int TestFileOperatorVisitor::visitVirtualDiskFile(VirtualDiskFileOperator* file_operator)
{
	return 3;
}

int TestFileOperatorVisitor::visitMicrosoftDiskFileOperator(MicrosoftDiskFileOperator* file_operator)
{
	return 2;
}

int TestFileOperatorVisitor::visitCacheFileOperator(CacheFileOperator* file_operator)
{
	return 1;
}

int TestFileOperatorVisitor::visitFileOperator(FileOperator* file_operator)
{
	return 0;
}
