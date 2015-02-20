#pragma once
#include "FileEnumeratorSPI.h"

class MicrosoftDiskFileEnumeratorSPI : public FileEnumeratorSPI
{
    int last_error;
};