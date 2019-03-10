#include "pch.h"
#include "Directory.h"


directory::directory() :element()
{
}

directory::directory(const std::string name, element* prev_dir) : element(name)
{
	prev_node = prev_dir;
}


directory::~directory()
= default;
