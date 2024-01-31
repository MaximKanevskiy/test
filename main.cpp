#include <iostream>
#include <fstream>
#include <sstream>
#include <httplib.h>

using namespace httplib;

static std::string loadFile(std::string path)
{
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string page = buffer.str();
	return page;
}

void handler(const Request& req, Response& res)
{
	if (req.method == "GET")
	{
		std::string page = loadFile("www/index.html");
		res.set_content(page, "text/html");
	}
}

void js_handler(const Request& req, Response& res)
{
	if (req.method == "GET")
	{
		std::string js = loadFile("www/script.js");
		res.set_content(js, "application/javascript");
	}
}

void greeting_handler(const Request& req, Response& res)
{
	if (req.method == "GET")
	{
		std::string message = "Hello!";
		res.set_content(message, "text/plain");
	}
}

int main() 
{
	std::cout << "Server started" << std::endl;
	Server server;
	server.Get("/", handler);
	server.Get("/script.js", js_handler);
	server.Get("/say-hello", greeting_handler);
	server.listen("0.0.0.0", 8080);
}