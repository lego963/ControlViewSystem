#include "pch.h"
#include "Directory.h"


directory::directory() :element()
{
}

directory::directory(const std::string name, directory* prev_dir) : element(name)
{
	prev_node = prev_dir;
	type = directory_type;
}


directory::~directory()
= default;
