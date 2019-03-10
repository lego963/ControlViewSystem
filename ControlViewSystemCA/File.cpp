#include "pch.h"
#include "File.h"
#include "Directory.h"


file::file() :element()
{
}

file::file(const std::string name, element* prev_dir) : element(name)
{
	prev_node = prev_dir;
	type = file_type;
}


file::~file()
= default;