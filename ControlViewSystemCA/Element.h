#pragma once
#include <ctime>
#include <string>
#include <vector>

enum element_type { file_type, directory_type };

class element
{
public:
	element_type type;
	element* prev_node;
	std::string name;
	std::time_t creation_time;
	std::vector<element*> list_of_elements;
	element();
	explicit element(std::string name);
	virtual ~element();
};