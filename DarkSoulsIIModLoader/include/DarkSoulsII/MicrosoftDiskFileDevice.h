#pragma once
#include "FileDevice.h"
#include "MicrosoftDiskFileEnumeratorSPI.h"

class MicrosoftDiskFileDevice : public FileDevice
{
    MicrosoftDiskFileEnumeratorSPI enumerator;
};