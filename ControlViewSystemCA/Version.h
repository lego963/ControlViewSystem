#pragma once
#include <vector>
#include <ctime>
#include "CustomDate.h"
#include <string>

class version
{
public:
	std::string data;
	CustomDate commit_date;
	version();
	version(const std::string& data, int d, int m, int y);
	~version();
};
