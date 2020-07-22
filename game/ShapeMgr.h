#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "split.h"
#include "Shape.h"
using namespace std;
using namespace sf;


class ShapeMgr
{
private:
	//v: vector of pointers to DrawingShapes made by mouse
	//newShape: pointer to add to vector when new shape added
	//shape: which shape is currently being drawn
	//color: current color of shape
	vector<DrawingShape*> v;
	DrawingShape *newShape;
	char shape;
	Color color;
public:
	//processMouseMove
	//sets new shape position to draw on screen later
	void processMouseMove(RenderWindow& win, SettingsMgr& settings, 
		int mouseX, int mouseY)
	{
		shape = settings.getShape();
		color = settings.getColor();

		if (shape == 's')
		{
			newShape = new Square(mouseX, mouseY, color);
			v.push_back(newShape);
		}
		else
		{
			newShape = new Circle(mouseX, mouseY, color);
			v.push_back(newShape);
		}
	}
	//draw function
	void draw(RenderWindow& win)
	{
		for (int i = 0; i < v.size(); i++)
		{
			v[i]->draw(win);
		}
	}
	//write function
	void writeToFile(ofstream& file)
	{
		string str;
		
		for (int i = 0; i < v.size(); i++)
		{
			str = v[i]->toString();
			file << str << endl;
		}

	}
	//read function
	void readFromFile(ifstream& file)
	{
		string str;
		DrawingShape *newShape;

		while(file >> str)
		{
			vector<string> settings = split(str);

			if (settings[0] == "square")
			{
				Color col(stoi(settings[1]));
				Vector2f pos(stoi(settings[2]), stoi(settings[3]));
				newShape = new Square(pos.x, pos.y, col);
				v.push_back(newShape);
			}
			else
			{
				Color col(stoi(settings[1]));
				Vector2f pos(stoi(settings[2]), stoi(settings[3]));
				newShape = new Circle(pos.x, pos.y, col);
				v.push_back(newShape);
			}
		}
	}
};
