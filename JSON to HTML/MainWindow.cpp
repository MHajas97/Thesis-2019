#include "MainWindow.h"
#include <iostream>
#include <fstream>
#include"json11.hpp"
#include <stdio.h>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

using namespace json11;
std::FILE* tmpf = std::tmpfile();

void ObjectExpand(Json json);
void elementsExpand(Json json);

void JSONtoHTML::MainWindow::startProgram(std::vector<std::string>* input)
{
	for (auto file= input->begin();file!= input->end(); ++file)
	{
		std::ifstream inputFile(*file);

		std::string content((std::istreambuf_iterator<char>(inputFile)),
			(std::istreambuf_iterator<char>()));// reading the whole file at once
		std::string err;
		const auto json = Json::parse(content, err);
		std::fputs("<!DOCTYPE HTML>\n<html>\n ", tmpf);
		std::cout << "<!DOCTYPE HTML>" << '\n' << "<html>" << '\n';
		ObjectExpand(json);
		std::cout << "</html>";
	}

};

void sizeStyle(Json json)
{	for (auto &m : json.object_items())

		std::cout<< m.second.string_value() << " ";
}

void paddingStyle(Json json)
{
	for (auto &m : json.object_items())

		if (m.first == "top")
			std::cout<< "padding-top:" << m.second.string_value() << ";";
		else
			if (m.first == "bottom")
				std::cout<< "padding-bottom:" << m.second.string_value() << ";";
			else if (m.first == "left")
				std::cout<< "padding-left:" << m.second.string_value() << ";";
			else if (m.first == "right")
				std::cout<< "padding-right:" << m.second.string_value() << ";";
}

void marginStyle(Json json)
{
	for (auto &m : json.object_items())
	{
		if (m.first == "top")
			std::cout<< "margin-top:" << m.second.string_value() << ";";
		else
			if (m.first == "bottom")
				std::cout<< "margin-bottom:" << m.second.string_value() << ";";
			else if (m.first == "left")
				std::cout<< "margin-left:" << m.second.string_value() << ";";
			else if (m.first == "right")
				std::cout<< "margin-right:" << m.second.string_value() << ";";
	}
}

void horizontalType(Json json)
{
	std::cout<< "<hr style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type")
			std::cout<< m.first << ":" << m.second.string_value() << ";";
	std::cout<< (char)042 << "/>" << '\n';
}

void titleType(Json json)
{
	std::cout<< "<text style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type" && m.first != "text")
			std::cout<< m.first << ":" << m.second.string_value() << ";";
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</text>" << '\n';
}


void linkType(Json json)
{
	auto n = json.object_items().find("url")->second.string_value();
	std::cout<< "<a href=" << n << " style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "url" && m.first != "text" && m.first != "type")
			if (m.first == "padding")
				paddingStyle(m.second);
			else
				std::cout<< m.first << ":" << m.second.string_value() << ";";
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</a>" << '\n';
}


void paragraphType(Json json)
{
	std::cout<< "<p style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type" && m.first != "text")
			std::cout<< m.first << ":" << m.second.string_value() << ";";
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</p>" << '\n';

}


void menuType(Json json)
{
	std::cout<< "<menu style=" << (char)042;
	for (auto &m : json.object_items())
	{
		if (m.first != "type" && m.first != "elements")
			if (m.first == "size")
			{
				std::cout<< m.first << ":";
				sizeStyle(m.second);
				std::cout<< ";";
			}
			else
				if (m.first == "margin")
				{
					marginStyle(m.second);
				}
				else if (m.first == "padding")
				{
					paddingStyle(m.second);
				}
				else
					std::cout<< m.first << ":" << m.second.string_value() << ";";
	}
	std::cout<< (char)042 << ">" << '\n';
	auto it = json.object_items().find("elements");
	if (it != json.object_items().end())
	{
		elementsExpand(it->second);
	}
	std::cout<< "</menu>" << '\n';

}

void contentType(Json json)
{
	std::cout<< "<content style=" << (char)042;
	for (auto &m : json.object_items())
	{
		if (m.first != "type" && m.first != "elements")
			if (m.first == "size")
			{
				std::cout<< m.first << ":";
				sizeStyle(m.second);
				std::cout<< ";";
			}
			else
				if (m.first == "margin")
				{
					marginStyle(m.second);
				}
				else if (m.first == "padding")
				{
					paddingStyle(m.second);
				}
				else
					std::cout<< m.first << ":" << m.second.string_value() << ";";
	}
	std::cout<< (char)042 << ">" << '\n';
	auto it = json.object_items().find("elements");
	if (it != json.object_items().end())
	{
		elementsExpand(it->second);
	}
	std::cout<< "</content>" << '\n';
}

void searchType(std::string type, Json json)
{
	if (type == "horizontal_rule")
		horizontalType(json);
	else if (type == "title")
		titleType(json);
	else if (type == "menu")
		menuType(json);
	else if (type == "link")
		linkType(json);
	else if (type == "content")
		contentType(json);
	else if (type == "paragraph")
		paragraphType(json);
	else if (type == "menu")
		menuType(json);
	else if (type == "content")
		contentType(json);
}

// going deeper one level at a time if the json.is_array returns 1
void mainExpand(Json json)
{
	std::cout<< "<main>" << '\n';
	for (auto &m : json.array_items())

	{
		auto it = m.object_items().find("type");
		if (it != m.object_items().end())
			searchType(it->second.string_value(), m.object_items());
	}
}

void elementsExpand(Json json)
{
	for (auto &i : json.array_items())
	{
		auto it = i.object_items().find("type");
		if (it != i.object_items().end())
			searchType(it->second.string_value(), i.object_items());
	}
}

// going deeper one level at a time if the json.is_object returns 1
void ObjectExpand(Json json)
{
	std::cout<< "<head>" << '\n';
	auto it = json.object_items().find("metadata");
	if (it != json.object_items().end())
	{
		for (auto &m : json.object_items().find("metadata")->second.object_items())
		{
			std::cout<< "<meta name=" << (char)042 << m.first << (char)042 << " content=" << (char)042 << m.second.string_value() << (char)042 << "/>" << '\n';
		}
	}
	std::cout<< "</head>" << '\n';
	std::cout<< "<body>" << '\n';
	for (auto &m : json.object_items())
	{
		if (m.first != "metadata" && m.first != "main")
		{

			std::cout<< "<" << m.first << " style =" << (char)042 << '\n';

			if (!m.second.is_null())
			{

				for (auto &n : m.second.object_items())
					if (n.first != "elements")
					{
						if (n.first == "size")
						{
							std::cout<< n.first << ":";
							sizeStyle(n.second);
							std::cout<< ";";
						}
						else
							if (n.first == "margin")
							{
								marginStyle(n.second);
							}
							else if (n.first == "padding")
							{
								paddingStyle(n.second);
							}
							else
								std::cout<< n.first << ":" << n.second.string_value() << ";";
					}
				std::cout<< (char)042;
				std::cout<< ">" << '\n';
				auto it = m.second.object_items().find("elements");
				if (it != m.second.object_items().end())
				{

					elementsExpand(it->second);
				}
			}
			std::cout<< "</" << m.first << ">" << '\n';
		}
		if (m.first == "main")
		{
			mainExpand(m.second);
		}
	}
	std::cout<< "</body>" << '\n';

}

void tableExpand(Json json)
{
	std::cout << "<table>" << '\n' << "<tr>";
	for (auto &n : json.object_items())
	{

		std::cout <<"<td>"<< n.first<<"</td>"<<std::endl;

		if (!n.second.is_null())
			tableExpand(n.second.object_items());
	}
	std::cout << "</tr>" << '\n'<<"</table>";
}

void JSONtoHTML::MainWindow::startTable(std::vector<std::string>* input)
{
	for (auto file = input->begin(); file != input->end(); file++)
	{
		std::ifstream inputFile(*file);
		std::string content((std::istreambuf_iterator<char>(inputFile)),
			(std::istreambuf_iterator<char>()));// reading the whole file at once
		std::string err;
		const auto json = Json::parse(content, err);
		std::cout << "<table>" << std::endl;
		for (auto &m : json.object_items())
		{
			std::cout << "<td>" << m.first << "</td>" << '\n';
			std::cout << "<td>";
			for (auto &n : m.second.object_items())
			{

				tableExpand(n.second);
			}
			std::cout << "</tr>";
		}
		std::cout << "</table>";
	}
}

