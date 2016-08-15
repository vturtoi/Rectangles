#pragma once
#include <vector>
#include "Rectangle.h"

class FileParser
{
public:
	FileParser(void);
	~FileParser(void);
	std::vector<Rectangle> loadRectangles(const char* fileName);

private:
	int getValue(std::string line, char parameter);
	bool isNumber(const char* s);
};

