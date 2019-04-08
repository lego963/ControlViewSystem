#include "pch.h"
#include "Directory.h"
#include <iostream>

directory::directory() :element()
{
}

directory::directory(const std::string name, element* prev_dir, int day, int month, int year) : element(name)
{
	prev_node = prev_dir;
	type = directory_type;
	d = day;
	m = month;
	y = year;
}

void directory::getConfig(int depth, int d, int m, int y)
{
	std::cout << std::string(depth, ' ') << name << std::endl;
	for (auto elem : list_of_elements)
	{
		if (elem->d < d && elem->m < m && elem->y < y)
		{
			if (elem->type == file_type)
			{
				continue;
			}
			else
			{
				if (dynamic_cast<directory*>(elem)->list_of_elements.capacity() != 0)
				{
					for (auto element : dynamic_cast<directory*>(elem)->list_of_elements)
					{
						std::cout << std::string(depth + 1, ' ') << name << std::endl;
					}
				}
			}
		}
	}
}

directory::~directory()
{
	for (auto item : list_of_elements)
	{
		delete item;
	}
}
