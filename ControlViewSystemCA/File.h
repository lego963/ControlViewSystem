#pragma once
#include "Element.h"
#include "Directory.h"

class file final :
	public element
{
public:
	file();
	file(std::string name, directory* prev_dir);
	virtual ~file();
};
