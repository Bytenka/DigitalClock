#include <SFML/Graphics.hpp>
#include <iostream>

#include "main.hpp"
#include "Interactable.hpp"

using namespace std;

void Interactable::setPosition(sf::Vector2f top_center)
{
	objectSpace.left = top_center.x - objectSpace.width / 2;
	objectSpace.top = top_center.y;
}

sf::Vector2f Interactable::getPosition()
{
	return sf::Vector2f(objectSpace.left, objectSpace.top);
}

void Interactable::setSize(sf::Vector2f s)
{
	objectSpace.width = s.x;
	objectSpace.height = s.y;
}

sf::Vector2f Interactable::getSize()
{
	return sf::Vector2f(objectSpace.width, objectSpace.height);
}

void Interactable::setFillColor(sf::Color c)
{
	background.setFillColor(c);
}

sf::Color Interactable::getFillColor()
{
	return background.getFillColor();
}

void Interactable::setHoverColor(sf::Color c)
{
	hoverColor = c;
}

sf::Color Interactable::getHoverColor()
{
	return hoverColor;
}

void Interactable::setClickColor(sf::Color c)
{
	clickColor = c;
}

sf::Color Interactable::getClickColor()
{
	return clickColor;
}

void Interactable::setOutlineColor(sf::Color c)
{
	background.setOutlineColor(c);
}

sf::Color Interactable::getOutlineColor()
{
	return background.getOutlineColor();
}

void Interactable::setOutlineThickness(float t)
{
	background.setOutlineThickness(t);
}

int Interactable::getOutlineThickness()
{
	return background.getOutlineThickness();
}

bool Interactable::checkIsHovered(sf::RenderWindow &win)
{
	bool status = objectSpace.contains(sf::Vector2f(mouse.getPosition(win))) && win.hasFocus();
	isHovered = status;
	return status;
}

bool Interactable::checkIsClicked(sf::RenderWindow &win)
{
	return checkIsHovered(win) && mouse.isButtonPressed(sf::Mouse::Button::Left);
}

bool Interactable::asClicked()
{
	bool c = clicked && !mouse.isButtonPressed(sf::Mouse::Button::Left);
	if (c)
		clicked = false;
	return c;
}

void Interactable::update(sf::RenderWindow &win)
{
	background.setSize(sf::Vector2f(objectSpace.width, objectSpace.height));
	background.setPosition(sf::Vector2f(objectSpace.left, objectSpace.top));

	background.setFillColor(backgroundStillColor);

	if (this->checkIsClicked(win))
	{
		background.setFillColor(clickColor);
		clicked = true;
	}
	else if (this->checkIsHovered(win))
		background.setFillColor(hoverColor);
}

void Interactable::draw(sf::RenderWindow &win)
{
	this->update(win);
	win.draw(background);

	/*cout << objectSpace.left << " "
	<< objectSpace.width << endl
	<< objectSpace.top << " "
	<< objectSpace.height << endl
	<< background.getPosition().x << " "
	<< background.getSize().x << endl
	<< background.getPosition().y << " "
	<< background.getSize().y << endl << endl;*/
}