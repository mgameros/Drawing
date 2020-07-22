#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "split.h"
using namespace std;
using namespace sf;


class SettingsMgr
{
private:
	//currentColor: the current shape color
	//shape: the current shape to be drawn
	//redBtn, bluBtn, grnBtn: buttons for color choices
	//circChoice, sqChoice: buttons for shape choices
	Color currentColor;
	char shape;
	CircleShape redBtn, bluBtn, grnBtn, circChoice;
	RectangleShape sqChoice;
public:
	//default (and only) constructor
	SettingsMgr()
	{
		currentColor = Color::Red;
		shape = 'c';
		
		//set red button
		redBtn.setPosition(10, 30);
		redBtn.setRadius(10);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Red);

		//set blue button
		bluBtn.setPosition(10, 60);
		bluBtn.setRadius(10);
		bluBtn.setOutlineThickness(2);
		bluBtn.setOutlineColor(Color::Blue);
		bluBtn.setFillColor(Color::Transparent);

		//set green button
		grnBtn.setPosition(10, 90);
		grnBtn.setRadius(10);
		grnBtn.setOutlineThickness(2);
		grnBtn.setOutlineColor(Color::Green);
		grnBtn.setFillColor(Color::Transparent);

		//set circle choice button
		circChoice.setPosition(10, 150);
		circChoice.setRadius(10);
		circChoice.setOutlineThickness(2);
		circChoice.setOutlineColor(Color::White);
		circChoice.setFillColor(Color::White);

		//set square choice button
		sqChoice.setPosition(10, 180);
		sqChoice.setSize(Vector2f(20,20));
		sqChoice.setOutlineThickness(2);
		sqChoice.setOutlineColor(Color::White);
		sqChoice.setFillColor(Color::Transparent);
	}

	//function to deal with when a button is pressed
	void processClick(RenderWindow& win)
	{
		if (Mouse::isButtonPressed)
		{
			Vector2f mouse = win.mapPixelToCoords(Mouse::getPosition(win));
			//if blue button is pressed, blue button fills in
			if (bluBtn.getGlobalBounds().contains(mouse))
			{
				bluBtn.setFillColor(Color::Blue);
				redBtn.setFillColor(Color::Transparent);
				grnBtn.setFillColor(Color::Transparent);

				currentColor = Color::Blue;
			}
			//if red button is pressed, red button fills in
			if (redBtn.getGlobalBounds().contains(mouse))
			{
				bluBtn.setFillColor(Color::Transparent);
				redBtn.setFillColor(Color::Red);
				grnBtn.setFillColor(Color::Transparent);

				currentColor = Color::Red;
			}
			//if green button is pressed, green button fills in
			if (grnBtn.getGlobalBounds().contains(mouse))
			{
				bluBtn.setFillColor(Color::Transparent);
				redBtn.setFillColor(Color::Transparent);
				grnBtn.setFillColor(Color::Green);

				currentColor = Color::Green;
			}
			//if circle is chosen, circle will fill in
			if (circChoice.getGlobalBounds().contains(mouse))
			{
				circChoice.setFillColor(Color::White);
				sqChoice.setFillColor(Color::Transparent);

				shape = 'c';
			}
			//if square is chosen, square will fill in
			if (sqChoice.getGlobalBounds().contains(mouse))
			{
				circChoice.setFillColor(Color::Transparent);
				sqChoice.setFillColor(Color::White);

				shape = 's';
			}
		}
	}

	//draw function
	void draw(RenderWindow& win)
	{
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		Text title("Drawing Color", font, 25);
		title.setPosition(0, 0);
		win.draw(title);

		win.draw(redBtn);
		win.draw(bluBtn);
		win.draw(grnBtn);

		Text sh("Drawing Shape", font, 25);
		sh.setPosition(0, 120);
		win.draw(sh);

		win.draw(circChoice);
		win.draw(sqChoice);

		Vector2f start(200, 0);
		Vector2f end(200, 600);

		Vertex line[] = { start, end };
		win.draw(line, 2, sf::Lines);
	}

	//write function
	void writeToFile(ofstream& file)
	{
		string str;

		if (shape == 's')
		{
			str = "square,";
			str += to_string(currentColor.toInteger());
		}
		else
		{
			str = "circle,";
			str += to_string(currentColor.toInteger());
		}

		file << str << endl;
	}

	//read function
	void readFromFile(ifstream& file)
	{
		string str;
		file >> str;
		vector<string> settings = split(str);

		if (settings[0] == "square")
		{
			shape = 's';
			sqChoice.setFillColor(Color::White);
			circChoice.setFillColor(Color::Transparent);
		}
		else
		{
			shape = 'c';
			sqChoice.setFillColor(Color::Transparent);
			circChoice.setFillColor(Color::White);
		}

		Color color(stoi(settings[1]));
		currentColor = color;

		if (currentColor == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
			bluBtn.setFillColor(Color::Transparent);
			grnBtn.setFillColor(Color::Transparent);
		}
		else if (currentColor == Color::Blue)
		{
			redBtn.setFillColor(Color::Transparent);
			bluBtn.setFillColor(Color::Blue);
			grnBtn.setFillColor(Color::Transparent);
		}
		else
		{
			redBtn.setFillColor(Color::Transparent);
			bluBtn.setFillColor(Color::Transparent);
			grnBtn.setFillColor(Color::Green);
		}

	}

	//die function in case something goes wrong
	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	//getter function for shape
	char getShape()
	{
		return shape;
	}

	//getter function for color
	Color getColor()
	{
		return currentColor;
	}
};
