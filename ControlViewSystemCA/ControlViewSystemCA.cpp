#include "pch.h"
#include <iostream>
#include "Element.h"
#include "Directory.h"
#include "File.h"
#include <vector>
#include "fileSystem.h"


std::string get_chars_tree(int depth);
void print_tree(std::vector<element*> pwd, int depth);
void print_tree_date(std::vector<element*> pwd, int depth, int d, int m, int y);

void main()
{
	file_system fs;
	//std::vector<element*> root;
	fs.root.push_back(new directory("/", nullptr, 13, 11, 2009));
	dynamic_cast<directory*>(fs.root[0])->list_of_elements.push_back(new directory("master", fs.root[0], 10, 11, 2016));
	dynamic_cast<directory*>(dynamic_cast<directory*>(fs.root[0])->list_of_elements[0])->list_of_elements.push_back(new file("project.cpp", dynamic_cast<directory*>(fs.root[0])->list_of_elements[0], "void foo(){}; void bar(){};", 13, 11, 2017));
	dynamic_cast<directory*>(dynamic_cast<directory*>(fs.root[0])->list_of_elements[0])->list_of_elements.push_back(new file("readme.txt", dynamic_cast<directory*>(fs.root[0])->list_of_elements[0], "try hard and read readme files", 13, 11, 2018));
	dynamic_cast<directory*>(fs.root[0])->list_of_elements.push_back(new directory("dev", fs.root[0], 14, 12, 2005));
	dynamic_cast<directory*>(dynamic_cast<directory*>(fs.root[0])->list_of_elements[1])->list_of_elements.push_back(new file("readme.txt", dynamic_cast<directory*>(fs.root[0])->list_of_elements[1], "new dev documentation", 15, 12, 2006));
	dynamic_cast<directory*>(fs.root[0])->list_of_elements.push_back(new directory("fix0987", fs.root[0], 05, 06, 2009));
	dynamic_cast<directory*>(dynamic_cast<directory*>(fs.root[0])->list_of_elements[2])->list_of_elements.push_back(new file("project.cpp", dynamic_cast<directory*>(fs.root[0])->list_of_elements[2], "void foo1Fixed(){};", 06, 07, 2010));
	dynamic_cast<directory*>(dynamic_cast<directory*>(fs.root[0])->list_of_elements[2])->list_of_elements.push_back(new file("readme.txt", dynamic_cast<directory*>(fs.root[0])->list_of_elements[2], "fix bug // 1line", 9, 10, 2019));

	auto current_root = fs.root[0];
	auto pwd = fs.root[0]->name;
	while (true)
	{
		std::cout << pwd << ": ";
		std::string cmd;
		std::getline(std::cin, cmd);
		if (cmd == "cmds")
		{
			std::cout << "1. cd - move\n2. ls - show current folder\n3. add - d - directory, f - file\n4. cmds - see all commands\n5. edit - add new version to file\n6. exit - close\n";
			continue;
		} //update if add some features
		if (cmd == "cd")
		{
			std::string dir;
			std::cout << "Enter dir name: ";
			std::getline(std::cin, dir);
			if (dir == "..")
			{
				if (current_root->prev_node == nullptr)
				{
					std::cout << "root dir!\n";
					continue;
				}
				pwd = pwd.erase(pwd.rfind(current_root->name), current_root->name.length() + 1);
				current_root = current_root->prev_node;
				continue;
			}
			if (dir.empty())
			{
				current_root = fs.root[0];
				pwd = "/";
				continue;
			}
			auto ind = 0;
			for (auto element : dynamic_cast<directory*>(current_root)->list_of_elements)
			{
				if (element->name != dir)
				{
					ind++;
					continue;
				}
				if (element->name == dir)
					break;
			}
			if (ind < dynamic_cast<directory*>(current_root)->list_of_elements.capacity())
			{
				current_root = dynamic_cast<directory*>(current_root)->list_of_elements[ind];
				pwd += current_root->name + "/";
				continue;
			}
			std::cout << "invalid dir name";

		}
		if (cmd == "conf")
		{
			int d, m, y;
			std::cout << "enter day: ";
			std::cin >> d >> m >> y;
			if ((d >= 1 && d <= 31) && (m >= 1 && m <= 12))
			{
				print_tree_date(dynamic_cast<directory*>(current_root)->list_of_elements, 1, d, m, y);
			}
			continue;
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
				dynamic_cast<directory*>(current_root)->list_of_elements.push_back(new directory(name, current_root, 8, 4, 2019));
				continue;
			}
			if (type == "f")
			{
				std::cout << "Enter text: ";
				std::string tmp_data;
				std::getline(std::cin, tmp_data);
				dynamic_cast<directory*>(current_root)->list_of_elements.push_back(new file(name, current_root, tmp_data, 8, 4, 2019));
				continue;
			}
		}
		if (cmd == "ls") //Need to update with version
		{
			print_tree(dynamic_cast<directory*>(current_root)->list_of_elements, 0);
			continue;
		}
		if (cmd == "edit")
		{
			std::cout << "Enter filename: ";
			std::string file_name;
			std::getline(std::cin, file_name);
			for (auto element : dynamic_cast<directory*>(current_root)->list_of_elements)
			{
				if (element->type == file_type && element->name == file_name)
				{
					std::string tmp_data;
					std::cout << "Add new data: ";
					std::getline(std::cin, tmp_data);
					version* new_ver = new version(tmp_data, 25, 03, 2019);
					dynamic_cast<file*>(element)->commits.push_back(new_ver);
				}
			}
			continue;
		}
		if (cmd == "exit")
		{

			break;
		}
	}
	fs.~file_system();

}

void print_tree(std::vector<element*> pwd, int depth)
{
	for (auto element : pwd)
	{
		switch (element->type)
		{
		case directory_type:
			std::cout << get_chars_tree(depth) << element->name << " (dir) \n";
			break;
		case file_type:
			std::cout << get_chars_tree(depth) << element->name << " version " << dynamic_cast<file*>(element)->commits.capacity() << " (file) \n";
			break;
		}

		if (element->type == directory_type && dynamic_cast<directory*>(element)->list_of_elements.capacity() != 0)
		{
			depth++;
			print_tree(dynamic_cast<directory*>(element)->list_of_elements, depth);
			depth--;
		}
	}
}

void print_tree_date(std::vector<element*> pwd, int depth, int d, int m, int y)
{
	for (auto element : pwd)
	{
		if (element->y < y)
		{
			switch (element->type)
			{
			case directory_type:
				std::cout << get_chars_tree(depth) << element->name << " (dir) \n";
				break;
			case file_type:
				std::cout << get_chars_tree(depth) << element->name << " version " << dynamic_cast<file*>(element)->commits.capacity() << " (file) \n";
				break;
			}

			if (element->type == directory_type && dynamic_cast<directory*>(element)->list_of_elements.capacity() != 0)
			{
				depth++;
				print_tree_date(dynamic_cast<directory*>(element)->list_of_elements, depth, d, m, y);
				depth--;
			}
		}
		else if (element->y == y && element->m < m)
		{
			switch (element->type)
			{
			case directory_type:
				std::cout << get_chars_tree(depth) << element->name << " (dir) \n";
				break;
			case file_type:
				std::cout << get_chars_tree(depth) << element->name << " version " << dynamic_cast<file*>(element)->commits.capacity() << " (file) \n";
				break;
			}

			if (element->type == directory_type && dynamic_cast<directory*>(element)->list_of_elements.capacity() != 0)
			{
				depth++;
				print_tree_date(dynamic_cast<directory*>(element)->list_of_elements, depth, d, m, y);
				depth--;
			}
		}
		else if (element->y == y && element->m == m && element->d < d)
		{
			switch (element->type)
			{
			case directory_type:
				std::cout << get_chars_tree(depth) << element->name << " (dir) \n";
				break;
			case file_type:
				std::cout << get_chars_tree(depth) << element->name << " version " << dynamic_cast<file*>(element)->commits.capacity() << " (file) \n";
				break;
			}

			if (element->type == directory_type && dynamic_cast<directory*>(element)->list_of_elements.capacity() != 0)
			{
				depth++;
				print_tree_date(dynamic_cast<directory*>(element)->list_of_elements, depth, d, m, y);
				depth--;
			}
		}
	}
}

std::string get_chars_tree(const int depth)
{
	return std::string(depth * 2, '-');
}