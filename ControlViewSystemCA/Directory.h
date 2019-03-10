#pragma once
#include "Element.h"
#include <vector>

class directory final :
	public element
{
public:
	directory();
	explicit directory(std::string name, element* prev_dir);
	virtual ~directory();
};

