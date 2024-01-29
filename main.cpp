#include <iostream>
#include <fstream>
#include <sstream>

static std::string loadFile(std::string path)
{
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string page = buffer.str();
	return page;
}

int main() 
{
	auto page = loadFile("www/index.html");
	std::cout << page << std::endl;
}