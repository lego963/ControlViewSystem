#include "pch.h"
#include "Version.h"
#include <chrono>


version::version()
{
}

version::version(const std::string& data, int d, int m, int y)
{
	this->data = data;
	commit_date.dd = d;
	commit_date.mm = m;
	commit_date.yyyy = y;
}


version::~version()
{
}