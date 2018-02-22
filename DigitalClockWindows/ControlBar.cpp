#include <SFML/Graphics.hpp>
#include <iostream>

#include "ControlBar.hpp"
#include "main.hpp"

using namespace std;

ControlBar::ControlBar()
{
	this->update();
}

void ControlBar::update()
{
	area.left = drawableArea.left;
	area.top = drawableArea.top + previewEditor.objectSpace.height + globalBounds + lineBelowPreviewEditor.getSize().y + globalBounds;
	area.width = drawableArea.width;
	area.height = 100;

	startPause.setPosition(sf::Vector2f(
		area.width / 2,
		area.top
	));

	stop.setPosition(sf::Vector2f(
		area.width / 2,
		area.top + startPause.getSize().y
	));

	minus10.setPosition(sf::Vector2f(
		area.width / 2 - startPause.getSize().x / 2 - globalBounds - minus10.getSize().x / 2,
		area.top + 5
	));
}

void ControlBar::draw(sf::RenderWindow &win)
{
	this->update();

	// background of the area
	sf::RectangleShape r;
	r.setPosition(sf::Vector2f(area.left, area.top));
	r.setSize(sf::Vector2f(area.width, area.height));
	r.setFillColor(sf::Color(0, 0, 127, 100)); // @CUSTOMISATION

											   /*cout << objectSpace.left << " "
											   << objectSpace.width << endl
											   << objectSpace.top << " "
											   << objectSpace.height << endl
											   << r.getPosition().x << " "
											   << r.getSize().x << endl
											   << r.getPosition().y << " "
											   << r.getSize().y << endl
											   << endl;*/

	win.draw(r);
	startPause.draw(win);
	stop.draw(win);
	minus10.draw(win);
}