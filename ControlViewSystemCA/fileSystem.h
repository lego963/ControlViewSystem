#pragma once
#include <vector>
#include "Element.h"

class file_system
{
public:
	std::vector<element*> root;
	file_system();
	virtual ~file_system();
};