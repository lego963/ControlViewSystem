#include "pch.h"
#include "Element.h"
#include <chrono>
#include <string>


element::element() : prev_node(nullptr)
{
	creation_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	name = "/";
	name += std::time(&creation_time);
}

element::element(const std::string name) : prev_node(nullptr)
{
	this->name = name;
	creation_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

element::~element()
= default;