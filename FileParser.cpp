#include "StdAfx.h"
#include "FileParser.h"
#include <fstream>
#include <iostream>
#include <string>

FileParser::FileParser(void)
{
}


FileParser::~FileParser(void)
{
}

std::vector<Rectangle> FileParser::loadRectangles(const char* fileName)
{
	std::vector<Rectangle> rectangles;

	if (fileName == NULL)
	{
		return rectangles;
	}

	std::string line;
	std::ifstream dataFile(fileName);
	bool start = false;

	if (dataFile.bad())
	{
		return rectangles;
	}
	Rectangle r;
	while ( getline(dataFile, line) )
	{
		std::cout << line << "\n";
		if (start == false)
		{
			if (line.find("rects") != std::string::npos)
			{
				start = true;
			}
			continue;
		}
		if (line.find("{") == std::string::npos)
		{
			continue;
		}
		int x = getValue(line, 'x');
		int y = getValue(line, 'y');
		int w = getValue(line, 'w');
		int h = getValue(line, 'h');
		if (x != -1 && y != -1 && w != -1 && h != -1)
		{
			r.setX(x);
			r.setY(y);
			r.setH(h);
			r.setW(w);
			rectangles.push_back(r);
		}
	}

	dataFile.close();

	printf("total rectangles no %d\n", rectangles.size());
	return rectangles;
}

int FileParser::getValue(std::string line, char parameter)
{
	char buffer[20];
	std::string s;
	int nPos;
	switch (parameter)
	{
	case 'x':
		nPos = line.find("x");
		break;
	case 'y':
		nPos = line.find("y");
		break;
	case 'w':
		nPos = line.find("w");
		break;
	case 'h':
		nPos = line.find("h");
		break;
	default:
		return -1;
	}

	if (nPos == -1)
	{
		return -1;
	}
	nPos = line.find(":", nPos);
	if (nPos == -1)
	{
		return -1;
	}
	int nPos2 = line.find(",", nPos);
	if (nPos2 == -1)
	{
		nPos2 = line.find("}",nPos);
		if (nPos2 == -1)
		{
			return -1;
		}
	}
	if (nPos2 - nPos > 10)
	{
		return -1;
	}
	s = line.substr(nPos + 1, nPos2 - nPos - 1);
	if (isNumber(s.c_str()))
	{
		return atoi(s.c_str());
	}
	return -1;
}

bool FileParser::isNumber(const char* s)
{
    char* p;
    strtol(s, &p, 10);
    return *p == 0;
}