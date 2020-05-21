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
std::ofstream f("text.txt");

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
		f << "<!DOCTYPE HTML>" << '\n' << "<html>" << '\n';
		std::cout << "<!DOCTYPE HTML>" << '\n' << "<html>" << '\n';
		ObjectExpand(json);
		std::cout << "</html>";
		f << "</html>";
	}

};

void sizeStyle(Json json)
{
	for (auto &m : json.object_items())
	{
		std::cout << m.second.string_value() << " ";
		f << m.second.string_value() << " ";
	}
}

void paddingStyle(Json json)
{
	for (auto &m : json.object_items())

		if (m.first == "top")
		{
			std::cout << "padding-top:" << m.second.string_value() << ";";
			f << "padding-top:" << m.second.string_value() << ";";
		}
		else
			if (m.first == "bottom")
			{
				std::cout << "padding-bottom:" << m.second.string_value() << ";";
				f << "padding-bottom:" << m.second.string_value() << ";";
			}
			else if (m.first == "left")
			{
				std::cout << "padding-left:" << m.second.string_value() << ";";
				f << "padding-left:" << m.second.string_value() << ";";
			}
			else if (m.first == "right")
			{
				std::cout << "padding-right:" << m.second.string_value() << ";";
				f << "padding-right:" << m.second.string_value() << ";";
			}
}

void marginStyle(Json json)
{
	for (auto &m : json.object_items())
	{
		if (m.first == "top")
		{
			std::cout << "margin-top:" << m.second.string_value() << ";";
			f << "margin-top:" << m.second.string_value() << ";";
		}
		else
			if (m.first == "bottom")
			{
				std::cout << "margin-bottom:" << m.second.string_value() << ";";
				f << "margin-bottom:" << m.second.string_value() << ";";
			}
			else if (m.first == "left")
			{
				std::cout << "margin-left:" << m.second.string_value() << ";";
				f << "margin-left:" << m.second.string_value() << ";";
			}
			else if (m.first == "right")
			{
				std::cout << "margin-right:" << m.second.string_value() << ";";
				f << "margin-right:" << m.second.string_value() << ";";
			}
	}
}

void horizontalType(Json json)
{
	std::cout<< "<hr style=" << (char)042;
	f << "<hr style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type")
		{
			std::cout << m.first << ":" << m.second.string_value() << ";";
			f << m.first << ":" << m.second.string_value() << ";";
		}
	std::cout<< (char)042 << "/>" << '\n';
	f << (char)042 << "/>" << '\n';
}

void titleType(Json json)
{
	std::cout<< "<text style=" << (char)042;
	f << "<text style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type" && m.first != "text")
		{
			std::cout << m.first << ":" << m.second.string_value() << ";";
			f << m.first << ":" << m.second.string_value() << ";";
		}
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</text>" << '\n';
	f << (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</text>" << '\n';
}


void linkType(Json json)
{
	auto n = json.object_items().find("url")->second.string_value();
	std::cout<< "<a href=" << n << " style=" << (char)042;
	f << "<a href=" << n << " style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "url" && m.first != "text" && m.first != "type")
			if (m.first == "padding")
				paddingStyle(m.second);
			else
			{
				std::cout << m.first << ":" << m.second.string_value() << ";";
				f << m.first << ":" << m.second.string_value() << ";";
			}
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</a>" << '\n';
	f << (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</a>" << '\n';
}


void paragraphType(Json json)
{
	std::cout<< "<p style=" << (char)042;
	f << "<p style=" << (char)042;
	for (auto &m : json.object_items())
		if (m.first != "type" && m.first != "text")
		{
			std::cout << m.first << ":" << m.second.string_value() << ";";
			f << m.first << ":" << m.second.string_value() << ";";
		}
	std::cout<< (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</p>" << '\n';
	f << (char)042 << ">" << json.object_items().find("text")->second.string_value() << "</p>" << '\n';

}


void menuType(Json json)
{
	std::cout<< "<menu style=" << (char)042;
	f << "<menu style=" << (char)042;
	for (auto &m : json.object_items())
	{
		if (m.first != "type" && m.first != "elements")
			if (m.first == "size")
			{
				std::cout<< m.first << ":";
				f << m.first << ":";
				sizeStyle(m.second);
				std::cout<< ";";
				f << ";";
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
				{
					std::cout << m.first << ":" << m.second.string_value() << ";";
					f << m.first << ":" << m.second.string_value() << ";";
				}
	}
	std::cout<< (char)042 << ">" << '\n';
	f << (char)042 << ">" << '\n';
	auto it = json.object_items().find("elements");
	if (it != json.object_items().end())
	{
		elementsExpand(it->second);
	}
	std::cout<< "</menu>" << '\n';
	f << "</menu>" << '\n';

}

void contentType(Json json)
{
	std::cout<< "<content style=" << (char)042;
	f << "<content style=" << (char)042;
	for (auto &m : json.object_items())
	{
		if (m.first != "type" && m.first != "elements")
			if (m.first == "size")
			{
				std::cout<< m.first << ":";
				f << m.first << ":";
				sizeStyle(m.second);
				std::cout<< ";";
				f << ";";
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
				{
					std::cout << m.first << ":" << m.second.string_value() << ";";
					f << m.first << ":" << m.second.string_value() << ";";
				}
	}
	std::cout<< (char)042 << ">" << '\n';
	f << (char)042 << ">" << '\n';
	auto it = json.object_items().find("elements");
	if (it != json.object_items().end())
	{
		elementsExpand(it->second);
	}
	std::cout<< "</content>" << '\n';
	f << "</content>" << '\n';
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
	f << "<main>" << '\n';
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
	f << "<head>" << '\n';
	auto it = json.object_items().find("metadata");
	if (it != json.object_items().end())
	{
		for (auto &m : json.object_items().find("metadata")->second.object_items())
		{
			std::cout<< "<meta name=" << (char)042 << m.first << (char)042 << " content=" << (char)042 << m.second.string_value() << (char)042 << "/>" << '\n';
			f << "<meta name=" << (char)042 << m.first << (char)042 << " content=" << (char)042 << m.second.string_value() << (char)042 << "/>" << '\n';
		}
	}
	std::cout<< "</head>" << '\n';
	std::cout<< "<body>" << '\n';
	f << "</head>" << '\n';
	f << "<body>" << '\n';
	for (auto &m : json.object_items())
	{
		if (m.first != "metadata" && m.first != "main")
		{

			std::cout<< "<" << m.first << " style =" << (char)042 << '\n';
			f << "<" << m.first << " style =" << (char)042 << '\n';

			if (!m.second.is_null())
			{

				for (auto &n : m.second.object_items())
					if (n.first != "elements")
					{
						if (n.first == "size")
						{
							std::cout<< n.first << ":";
							f << n.first << ":";
							sizeStyle(n.second);
							std::cout<< ";";
							f << ";";
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
							{
								std::cout << n.first << ":" << n.second.string_value() << ";";
								f << n.first << ":" << n.second.string_value() << ";";
							}
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
			f << "</" << m.first << ">" << '\n';
		}
		if (m.first == "main")
		{
			mainExpand(m.second);
		}
	}
	std::cout<< "</body>" << '\n';
	f << "</body>" << '\n';

}
void subTable(Json json)
{
	std::cout << "<tr>";
		f << "<tr>";
	for (auto &i : json.object_items())
	{
		std::cout << "<td>" << i.first << ": " << i.second.string_value() << "</td>" << '\n';
		f << "<td>" << i.first << ": " << i.second.string_value() << "</td>" << '\n';
	}
	std::cout << "</tr>";
	f << "</tr>";
}

void tableExpand(Json json)
{
	std::cout << "<table>" << '\n' << "<tr>";
	f << "<table>" << '\n' << "<tr>";
	for (auto &n : json.object_items())
	{

		std::cout <<"<td>"<< n.first<<"</td>"<<std::endl;
		f << "<td>" << n.first << "</td>" << std::endl;

		if (!n.second.is_null())
			tableExpand(n.second.object_items());
	}
	std::cout << "</tr>" << '\n'<<"</table>";
	f << "</tr>" << '\n' << "</table>";
}

void tableelementsExpand(Json json)
{

	for (auto &i : json.array_items())
	{
		std::cout << "<table>";
		f << "<table>";
			for (auto &j : i.object_items())

			{
				std::cout << "<tr>";
				f << "<tr>";
				if (!j.second.is_array())
				{
					if (j.second.object_items().empty())
					{
						std::cout << "<td>";
						f << "<td>";
						std::cout << j.first << " : " << j.second.string_value() << '\n';
						std::cout << "</td>";
						f << j.first << " : " << j.second.string_value() << '\n';
						f << "</td>";
					}
					else
					{
						if (j.first == "size" || j.first == "padding")
							subTable(j.second);
						else
						{
							std::cout << j.first<<'\n';
							f << j.first << '\n';
							tableExpand(j.second);
						}
					}
				}
				else 
				{
					tableelementsExpand(j.second);
				
				}
				
			}

		std::cout << "</tr>";
		f << "</tr>";
		std::cout << "</table>";
		f << "</table>";
	}

}



void JSONtoHTML::MainWindow::startTable(std::vector<std::string>* input)
{
	std::cout << "<html>" << '\n' << "<head>" << '\n' << "<style>" << '\n' << "table, th, td{border: 1px solid black;border - collapse: collapse;}" << '\n' << "</style>" << '\n' << "</head>";
	f << "<html>" << '\n' << "<head>" << '\n' << "<style>" << '\n' << "table, th, td{border: 1px solid black;border - collapse: collapse;}" << '\n' << "</style>" << '\n' << "</head>";
	for (auto file = input->begin(); file != input->end(); file++)
	{
		std::ifstream inputFile(*file);
		std::string content((std::istreambuf_iterator<char>(inputFile)),
			(std::istreambuf_iterator<char>()));// reading the whole file at once
		std::string err;
		const auto json = Json::parse(content, err);
		std::cout << "<table >" << '\n';
		f << "<table>" << '\n';
		for (auto &m : json.object_items())
		{
			std::cout << "<table >" << '\n';
			f << "<table>" << '\n';
			std::cout << "<th>" << m.first << "</th>" << '\n'<<"<tr>";
			f << "<th>" << m.first << "</th>" << '\n'<<"<tr>";
			if(m.second.is_object())
			for (auto &n : m.second.object_items())
			{

				if (n.second.is_array())
				{
					tableelementsExpand(n.second);
				}
				else
					if (n.second.object_items().empty())
					{
						std::cout <<"<td>"<<n.first << ": " << n.second.string_value()<<"</td>"<<'\n';
						f << "<td>" << n.first << ": " << n.second.string_value() << "</td>" << '\n';
					}
					else
					{
						if (n.first == "size")
						{
							std::cout << "<table>" << '\n' << "<th>"<<n.first<<"</th>"<<'\n';
							f << "<table>" << '\n' << "<th>" << n.first << "</th>" << '\n';
							subTable(n.second);

							std::cout << "</table>";
							f << "</table>";
						}
						else
							if (n.first != "size")
							{
								std::cout << n.first << ": " << n.second.string_value();
								f << n.first << ": " << n.second.string_value();
								tableExpand(n.second);
							}
					}
			}
			else
			{
				std::cout << "<table>" << '\n' << "<tr>";
				f << "<table>" << '\n' << "<tr>";
				tableelementsExpand(m.second);
			}
			std::cout << "</tr>";
			f << "</tr>";
		}

		std::cout << "</tr></table>";
		f << "</tr></table>";
	}
}

