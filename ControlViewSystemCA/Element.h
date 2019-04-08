#pragma once
#include <ctime>
#include <string>
#include <vector>
#include "Version.h"

enum element_type { file_type, directory_type };

class element
{
public:
	int d;
	int m;
	int y;
	element_type type;
	element* prev_node;
	std::string name;
	std::time_t creation_time;
	element();
	element(std::string name);
	virtual void getConfig(int depth, int d, int m, int y) = 0;
	virtual ~element();
};