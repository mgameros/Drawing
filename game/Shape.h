#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class DrawingShape 
{
	private:
	//size: size of object
	//xPosition: x position of object
	//yPosition: y position of object
	//color: color of object
		int size, xPosition, yPosition;
		Color color;
	public:
	//default constructor (mostly for ShapeMgr)
	DrawingShape()
	{
		size = 10;
		xPosition = 300;
		yPosition = 0;
		color = Color::Red;
	}
	//overloaded constructor
	//takes position and color and assigns
	//them to xPosition, yPosition, and color
	DrawingShape(int x, int y, Color c)
	{
		size = 10;
		xPosition = x;
		yPosition = y;
		color = c;
	}
	//getter function for size
	int getSize()
		{return size;}
	//setter function for size
	void setSize(int s)
		{size = s;}
	//getter function for xPosition
	int getX()
		{return xPosition;}
	//setter function for xPosition
	void setX(int x)
		{xPosition = x;}
	//getter function for yPosition
	int getY()
		{return yPosition;}
	//setter function for yPosition
	void setY(int y)
		{yPosition = y;}
	//getter function for color
	Color getColor()
		{return color;}
	//setter function for color
	void setColor(Color c)
		{color = c;}
	//pure virtual draw function
	virtual void draw(RenderWindow &win) = 0;
	//pure virtual to string function
	virtual string toString() = 0;
};

class Circle : public DrawingShape
{
	private:
	CircleShape c;
	public:
	//default constructor
	Circle() : DrawingShape()
	{
		c.setRadius(getSize());
		c.setPosition(Vector2f(getX(), getY()));
		c.setOutlineThickness(2);
		c.setOutlineColor(getColor());
		c.setFillColor(Color::Transparent);
	}
	//overloaded constructor
	//takes position and color and assigns those to circle
	Circle(int x, int y, Color col): DrawingShape(x, y, col)
	{
		c.setRadius(getSize());
		c.setPosition(Vector2f(x, y));
		c.setOutlineThickness(2);
		c.setOutlineColor(col);
		c.setFillColor(Color::Transparent);
	}
	//setter function for circle color
	void setCircleColor(Color col)
	{
		setColor(col);
		c.setOutlineColor(col);
	}
	//overloaded draw function
	void draw(RenderWindow &win)
	{
		c.setRadius(getSize());
		c.setPosition(Vector2f(getX(), getY()));
		c.setOutlineThickness(2);
		c.setOutlineColor(getColor());
		c.setFillColor(Color::Transparent);
		win.draw(c);
	}
	//to string function
	string toString()
	{
		string str = "circle,";
		Color color = getColor();
		str += to_string(color.toInteger());
		str += ",";
		str += to_string(getX());
		str += ",";
		str += to_string(getY());

		return str;
	}
};

class Square : public DrawingShape
{
	private:
	RectangleShape s;
	public:
	//default constructor
	Square() : DrawingShape()
	{
		s.setPosition(Vector2f(getX(), getY()));
		s.setOutlineColor(getColor());
		s.setOutlineThickness(2);
		s.setSize(Vector2f(getSize() * 2, getSize() * 2));
		s.setFillColor(Color::Transparent);
	}
	//overloaded constructor
	//takes position and color
	//and sets it as square values
	Square(int x, int y, Color col) : DrawingShape(x, y, col)
	{
		s.setPosition(Vector2f(x, y));
		s.setOutlineColor(col);
		s.setOutlineThickness(2);
		s.setSize(Vector2f(getSize() * 2, getSize() * 2));
		s.setFillColor(Color::Transparent);
	}
	//setter function for square color
	void setSquareColor(Color col)
	{
		setColor(col);
		s.setOutlineColor(col);
	}
	//draw function
	void draw(RenderWindow &win)
	{
		s.setPosition(Vector2f(getX(), getY()));
		s.setOutlineColor(getColor());
		s.setOutlineThickness(2);
		s.setSize(Vector2f(getSize() * 2, getSize() * 2));
		s.setFillColor(Color::Transparent);
		win.draw(s);
	}
	//to string function
	string toString()
	{
		string str = "circle,";
		Color color = getColor();
		str += to_string(color.toInteger());
		str += ",";
		str += to_string(getX());
		str += ",";
		str += to_string(getY());

		return str;
	}

};

