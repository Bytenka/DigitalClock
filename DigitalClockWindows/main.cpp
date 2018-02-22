#include <SFML/Graphics.hpp>
#include <iostream>

#include "TimeObject.hpp"
#include "TimeDisplay.hpp"
#include "PreviewEditor.hpp"
#include "Interactable.hpp"
#include "ControlBar.hpp"
#include "main.hpp"

using namespace std;

// Objects for the two windows
sf::RenderWindow displayWindow;
sf::Color displayWindowBackgroundColor;
sf::RenderWindow setupWindow;
sf::Color setupWindowBackgroundColor;

//////////////////////////////

int globalBounds = 10;

sf::Rect<float> drawableArea;
sf::Mouse mouse;
sf::Font fontForClock;
sf::Font fontForUI;
sf::RectangleShape lineBelowPreviewEditor;
TimeObject timer;            // = TimeObject();
TimeDisplay mainClock;       // = TimeDisplay();
PreviewEditor previewEditor; // = PreviewEditor();
ControlBar controlBar;

WhatDigitsToDisplay stringType;

void refreshDisplayWindow();
void refreshSetupWindow();
void updateDisplayWindowFrame(sf::Rect<float> &);

int main()
{
	displayWindow.create(sf::VideoMode(INITIAL_DISPLAY_WIDTH, INITIAL_DISPLAY_HEIGHT), "Digital clock main");
	displayWindowBackgroundColor = sf::Color::Black; // @UI
	setupWindow.create(sf::VideoMode(INITIAL_SETUP_WIDTH, INITIAL_SETUP_HEIGHT), "Digital clock setup");
	setupWindowBackgroundColor = sf::Color(127, 127, 127, 255); // @UI

	fontForClock.loadFromFile("fonts/unispace bd.ttf");
	fontForUI.loadFromFile("fonts/nk57-monospace-no-rg.ttf");

	timer = TimeObject();
	mainClock = TimeDisplay();
	previewEditor = PreviewEditor();
	controlBar = ControlBar();

	timer.setMode(chronometer);
	timer.setFinalTime(5min);

	stringType = minutes_seconds_milliseconds; // @UI

	while (displayWindow.isOpen() && setupWindow.isOpen())
	{
		{ // WINDOWS EVENT HANDELING
			sf::Event event;
			while (displayWindow.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					displayWindow.close();
					break;
				case sf::Event::Resized:
					displayWindow.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
					break;
				}
			}

			while (setupWindow.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					setupWindow.close();
					break;
				case sf::Event::Resized:
					setupWindow.setView(sf::View(sf::FloatRect(0, 0, (float)event.size.width, (float)event.size.height)));
					break;
				}
			}
		} // WINDOWS EVENT HANDELING

		refreshDisplayWindow();
		refreshSetupWindow();
	}
	return 0;
}

void refreshDisplayWindow()
{
	displayWindow.clear(displayWindowBackgroundColor);

	sf::Rect<float> displayWindowFrame = sf::Rect<float>(
		0,
		0,
		(float)displayWindow.getSize().x,
		(float)displayWindow.getSize().y);

	mainClock.update(displayWindowFrame);
	mainClock.draw(displayWindow);

	displayWindow.display();
}

void refreshSetupWindow()
{
	setupWindow.clear(setupWindowBackgroundColor);

	drawableArea = sf::Rect<float>(
		(float)globalBounds,
		(float)globalBounds,
		(float)setupWindow.getSize().x - 2 * globalBounds,
		(float)setupWindow.getSize().y - 2 * globalBounds);

	previewEditor.draw(setupWindow);
	{ // Draw separation line
		lineBelowPreviewEditor.setSize(sf::Vector2f(
			drawableArea.width,
			1));

		lineBelowPreviewEditor.setOrigin(sf::Vector2f(
			lineBelowPreviewEditor.getSize().x / 2,
			lineBelowPreviewEditor.getSize().y / 2));

		lineBelowPreviewEditor.setPosition(sf::Vector2f(
			previewEditor.objectSpace.left + previewEditor.objectSpace.width / 2,
			previewEditor.objectSpace.top + previewEditor.objectSpace.height + globalBounds));

		lineBelowPreviewEditor.setFillColor(sf::Color(0, 0, 0, 200)); // @CUSTOMISATION

		setupWindow.draw(lineBelowPreviewEditor);
	} // Draw separation line

	controlBar.draw(setupWindow);

	setupWindow.display();
}