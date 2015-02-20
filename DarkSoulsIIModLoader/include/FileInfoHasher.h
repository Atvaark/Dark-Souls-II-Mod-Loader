#pragma once
#include "FileInfo.h"

struct FileInfoHasher
{
	size_t operator()(const FileInfo& f) const;
};

