#include <iostream>
#include <fstream>
#include <sstream>

int main() 
{
	std::ifstream file("www/index.html");
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string page = buffer.str();
	std::cout << "Hello, World!" << std::endl;
	std::cout << page << std::endl;
	return 0;
}