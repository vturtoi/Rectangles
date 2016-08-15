#pragma once
class Rectangle
{
public:
	Rectangle();
	Rectangle(int invalid);
	Rectangle(int x, int y, int w, int h);
	~Rectangle();

	//setters and getters
	void setX(int x);
	int getX();
	void setY(int y);
	int getY();
	void setW(int w);
	int getW();
	void setH(int y);
	int getH();

	// finds intersection with another rectangle
	Rectangle intersection(Rectangle& nextRectangle);

private:
	int x;
	int y;
	int w;
	int h;
};

