#include "stdafx.h"
#include "Rectangle.h"
#include <math.h>

Rectangle::Rectangle()
{
	this->x = 0;
	this->y = 0;
	this->w = 0;
	this->h = 0;
}

Rectangle::Rectangle(int x, int y, int w, int h)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

Rectangle::Rectangle(int invalid)
{
	this->x = invalid;
}

Rectangle::~Rectangle()
{
}

void Rectangle::setX(int x)
{
	this->x = x;
}

void Rectangle::setY(int y)
{
	this->y = y;
}

void Rectangle::setW(int w)
{
	this->w = w;
}

void Rectangle::setH(int h)
{
	this->h = h;
}

int Rectangle::getX()
{
	return this->x;
}

int Rectangle::getY()
{
	return this->y;
}

int Rectangle::getW()
{
	return this->w;
}

int Rectangle::getH()
{
	return this->h;
}

Rectangle Rectangle::intersection(Rectangle & nextRectangle)
{
	Rectangle intersect;
	int x = nextRectangle.getX();
	int y = nextRectangle.getY();
	int w = nextRectangle.getW();
	int h = nextRectangle.getH();

	if ((this->x + this->w < x) || (this->x > x + w))
	{
		return -1;
	}
	if ((this->y + this->h < y) || (this->y > y + h))
	{
		return -1;
	}
	if (this->x >= x)
	{
		intersect.setX(this->x);
	}
	else
	{
		intersect.setX(x);
	}
	if (this->y >= y)
	{
		intersect.setY(this->y);
	}
	else
	{
		intersect.setY(y);
	}
	if (this->x + this->w > x + w)
	{
		intersect.setW(x+w - intersect.getX());
	}
	else
	{
		intersect.setW(this->x + this->w - intersect.getX());
	}
	if (this->y + this->h > y +h)
	{
		intersect.setH(y + h - intersect.getY());
	}
	else
	{
		intersect.setH(this->y + this->h - intersect.getY());
	}

	return intersect;
}
