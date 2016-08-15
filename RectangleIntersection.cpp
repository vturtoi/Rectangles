// RectangleIntersection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ColisionDetector.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ColisionDetector c;
	if (argv[1] == NULL)
	{
		c.findIntersections("d:\\rectangles.txt");
	}
	else
	{
		c.findIntersections((char*)argv[1]);
	}
	return 0;
}

