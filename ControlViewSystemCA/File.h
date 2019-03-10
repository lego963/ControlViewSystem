#pragma once
#include "Element.h"
#include "Directory.h"

class file final :
	public element
{
public:
	file();
	explicit file(std::string name, element* prev_dir);
	virtual ~file();
};
