#include "pch.h"
#include "fileSystem.h"
#include "File.h"


file_system::file_system()
{
}


file_system::~file_system()
{
	for (auto element : root)
	{
		delete element;
	}
}
