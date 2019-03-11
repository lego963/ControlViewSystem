#pragma once
#include "Element.h"
#include <vector>

class directory final :
	public element
{
public:
	std::vector<element*> list_of_elements;
	directory();
	directory(std::string name, directory* prev_dir);
	virtual ~directory();
};

