#include "pch.h"
#include <iostream>
#include "Element.h"
#include "Directory.h"
#include "File.h"
#include <vector>


std::string get_chars_tree(int depth);
void print_tree(std::vector<element*> pwd, int depth);

int main()
{
	std::vector<element*> root;
	root.push_back(new directory("/", nullptr));
	root[0]->list_of_elements.push_back(new directory("master", root[0]));
	root[0]->list_of_elements[0]->list_of_elements.push_back(new file("project.cpp", root[0]->list_of_elements[0]));
	root[0]->list_of_elements[0]->list_of_elements.push_back(new file("readme.txt", root[0]->list_of_elements[0]));
	root[0]->list_of_elements.push_back(new directory("dev", root[0]));
	root[0]->list_of_elements[1]->list_of_elements.push_back(new file("readme.txt", root[0]->list_of_elements[1]));
	root[0]->list_of_elements.push_back(new directory("fix0987", root[0]));
	root[0]->list_of_elements[2]->list_of_elements.push_back(new file("project.cpp", root[0]->list_of_elements[2]));
	root[0]->list_of_elements[2]->list_of_elements.push_back(new file("readme.txt", root[0]->list_of_elements[2]));
	//root[0]->list_of_elements.push_back(new directory("testDir", root[0]));

	auto tmp_root = root[0];
	auto pwd = root[0]->name;
	while (true)
	{
		std::cout << pwd << ": ";
		std::string cmd;
		std::getline(std::cin, cmd);
		if (cmd == "cmds")
		{
			std::cout << "1. cd\n2. edit\n3. ls\n4. add\n5. cmds\n6. exit\n7. touch\n";
			continue;
		} //update if add some features
		if (cmd == "cd")
		{
			std::string dir;
			std::cout << "Enter dir name: ";
			std::getline(std::cin, dir);
			if (dir == "..")
			{
				try
				{
					//int tmp_data = ;
					pwd = pwd.erase(pwd.rfind(tmp_root->name), tmp_root->name.length() + 1);
					tmp_root = tmp_root->prev_node;
					continue;
				}
				catch (...)
				{
					std::cout << "root dir!\n";
				}
			}
			if (dir.empty())
			{
				tmp_root = root[0];
				pwd = "/";
				continue;
			}
			auto ind = 0;
			for (auto element : tmp_root->list_of_elements)
			{
				if (element->name != dir)
				{
					ind++;
					continue;
				}
				if (element->name == dir)
					break;
			}
			try
			{
				tmp_root = tmp_root->list_of_elements[ind];
				pwd += tmp_root->name + "/";
				continue;
			}
			catch (...)
			{
				std::cout << "invalid dir name";
			}

		}//i guess it's all
		if (cmd == "edit")
		{

		}
		if (cmd == "add")
		{
			std::string name;
			std::cout << "Enter type: ";
			std::string type;
			std::getline(std::cin, type);
			std::cout << "Enter name: ";
			std::getline(std::cin, name);
			if (type == "d")
			{
				tmp_root->list_of_elements.push_back(new directory(name, tmp_root));
				continue;
			}
			if (type == "f")
			{
				tmp_root->list_of_elements.push_back(new file(name, tmp_root));
				continue;
			}
		}
		if (cmd == "ls") //Need to update with version
		{
			print_tree(tmp_root->list_of_elements, 0);
			continue;
		}
		if (cmd == "exit")
		{
			break;
		}
		std::cout << "Invalid command!\n";
	}

	return 0;
}

void print_tree(std::vector<element*> pwd, int depth)
{
	for (auto element : pwd)
	{
		switch (element->type)
		{
		case directory_type:
			std::cout << get_chars_tree(depth) << element->name << " (d) \n";
			break;
		case file_type:
			std::cout << get_chars_tree(depth) << element->name << " (file) \n";
			break;
		}

		if (element->list_of_elements.capacity() != 0)
		{
			depth++;
			print_tree(element->list_of_elements, depth);
			depth--;
		}
	}
}

std::string get_chars_tree(const int depth)
{
	return std::string(depth * 2, '-');
}