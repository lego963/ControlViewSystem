#include "pch.h"
#include <iostream>
#include "Element.h"
#include "Directory.h"
#include "File.h"
#include <vector>

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
	root[0]->list_of_elements.push_back(new directory("testDir", root[0]));

	auto tmp_root = root[0];
	auto current_path = root[0]->name;
	while (true)
	{
		std::cout << current_path << ": ";
		std::string cmd;
		std::getline(std::cin, cmd);
		if (cmd == "cmds")
		{
			std::cout << "cd\nedit\nls\nadd\ncmds";
			continue;
		}
		if (cmd == "cd")
		{
			std::string dir;
			std::cout << "Enter dir name: ";
			std::getline(std::cin, dir);
			if (dir == "..")
			{
				try
				{
					//std::string tmp_name = tmp_root->prev_node->name;
					//auto isdasd = current_path.rfind();
					//tmp_root = tmp_root->prev_node->list_of_elements;
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
				current_path = "/";
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
				current_path += tmp_root->name + "/";
				continue;
			}
			catch (...)
			{
				std::cout << "invalid dir name";
			}

		}
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
		if (cmd == "ls")
		{

		}
		else
		{
			std::cout << "Invalid command!\n";
		}

	}

	return 0;
}
