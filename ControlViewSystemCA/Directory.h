#pragma once
#include "Element.h"
#include <vector>

class directory final :
	public element
{
public:
	std::vector<element*> list_of_elements;
	directory();
	directory(std::string name, element* prev_dir, int day, int month, int year);
	void getConfig(int depth, int d, int m, int y);
	virtual ~directory();
};

