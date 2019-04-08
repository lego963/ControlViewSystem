#pragma once
#include "Element.h"
#include "Directory.h"
#include "Version.h"

class file final :
	public element
{
public:
	std::vector<version*> commits;
	int get_version_number();
	file();
	file(std::string name, element* prev_dir, std::string data, int day, int month, int year);
	void getConfig(int depth, int d, int m, int y) override;
	virtual ~file();
};
