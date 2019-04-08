#include "pch.h"
#include "File.h"
#include "Directory.h"
#include <iostream>


int file::get_version_number()
{
	return commits.capacity();
}

file::file() :element()
{
}

file::file(const std::string name, element* prev_dir, std::string data, int day, int month, int year) : element(name)
{
	prev_node = prev_dir;
	type = file_type;
	commits.push_back(new version(data, day, month, year));
	d = day;
	m = month;
	y = year;
}

file::~file()
{

	for (auto item : commits)
	{
		delete item;
	}
}

void file::getConfig(int depth, int d, int m, int y)
{
	std::cout << std::string(depth * 4, ' ') << name << std::endl;
	for (auto item : commits)
	{
		if (item->commit_date.dd < d && item->commit_date.mm < m && item->commit_date.yyyy < y)
		{
			std::cout << std::string(depth, '-') << "Version number: " << this->get_version_number() << " Data: "
				<< item->data << " Date: " << item->commit_date.dd
				<< "." << item->commit_date.mm << "." << item->commit_date.yyyy << std::endl;
		}
	}
}