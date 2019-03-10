#pragma once
#include <ctime>
#include <string>
#include <vector>

class element
{
public:
	element* prev_node;
	std::string name;
	std::time_t creation_time;
	std::vector<element*> list_of_elements;
	element();
	explicit element(const std::string name);
	virtual ~element();
};