//====================================================
// McKenna Gameros
// 3 April 2017
// Programming Assignment #6
// Description: Drawing Application
//====================================================

#include <iostream>
#include <fstream>
using namespace std;
#include <SFML/Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
using namespace sf;


int main()
{
	//initialize graphics

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing");
	window.setFramerateLimit(60);

	
	SettingsMgr settingsMgr;
	ShapeMgr    shapeMgr;

	// open ifstream
	ifstream read;
	read.open("shapes.txt");
	if(read)
	{
		settingsMgr.readFromFile(read);
		shapeMgr.readFromFile(read);
	}
	read.close();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
			{
				ofstream write;
				write.open("shapes.txt");
				settingsMgr.writeToFile(write);
				shapeMgr.writeToFile(write);
				window.close();
				write.close();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// handle clicking on one of the settings buttons
				settingsMgr.processClick(window);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left) && event.mouseMove.x > 200)
			{
				// add a shape to our list based on current settings
				shapeMgr.processMouseMove(window, settingsMgr, event.mouseMove.x, event.mouseMove.y);
			}
		}

		// Now render one frame based on new state of settings and new state of drawn shapes
		window.clear();
		settingsMgr.draw(window);
		shapeMgr.draw(window);

		window.display();

	} // end body of animation loop

	return 0;
}