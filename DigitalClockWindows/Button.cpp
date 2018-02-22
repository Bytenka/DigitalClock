#include <SFML/Graphics.hpp>
#include <iostream>

#include "Button.hpp"
#include "main.hpp"

using namespace std;
// Test

Button::Button(string txt)
{
	this->setSize(sf::Vector2f(40, 30));
	this->setPosition(sf::Vector2f());
	backgroundStillColor = sf::Color(100, 100, 100, 255);
	this->setHoverColor(sf::Color(100, 0, 0, 255));
	this->setClickColor(sf::Color(0, 100, 0, 255));
	this->setOutlineColor(sf::Color::Black);

	this->setTextString(txt);
	insideText.setFont(fontForUI);
}

Button::Button() {
	this->setSize(sf::Vector2f(40, 40));
	this->setPosition(sf::Vector2f());
	backgroundStillColor = sf::Color(100, 100, 100, 255);
	this->setHoverColor(sf::Color(100, 0, 0, 255));
	this->setClickColor(sf::Color(0, 100, 0, 255));
	this->setOutlineColor(sf::Color::Black);

	this->setTextString("");
	insideText.setFont(fontForUI);

	sf::Rect<float> r = insideText.getLocalBounds();
	insideText.setOrigin(sf::Vector2f(
		r.left + r.width / 2,
		r.top + r.height / 2));

}

void Button::setTextString(string s) {
	insideText.setString(s);
}

string Button::getTextString() {
	return insideText.getString();
}

void Button::setTextSize(int s)
{
	insideText.setCharacterSize(s);
}

void Button::setTextSize() {
	int charSize = 1;
	int bounds = 7;
	sf::Rect<float> r;
	do {
		insideText.setCharacterSize(charSize);
		r.width = objectSpace.width - (2 * bounds);
		r.height = objectSpace.height - (2 * bounds);
		charSize++;
	} while (charSize < 500 && (insideText.getLocalBounds().width <= r.width && insideText.getLocalBounds().height <= r.height));

}

int Button::getTextSize()
{
	return insideText.getCharacterSize();
}

void Button::setTextColor(sf::Color) {
}

sf::Color Button::getTextColor() {
	return insideText.getFillColor();
}

void Button::update(sf::RenderWindow &win)
{
	background.setSize(sf::Vector2f(objectSpace.width, objectSpace.height));
	background.setPosition(sf::Vector2f(objectSpace.left, objectSpace.top));

	background.setFillColor(backgroundStillColor);

	if (this->checkIsClicked(win)) {
		background.setFillColor(clickColor);
		clicked = true;
	}
	else if (this->checkIsHovered(win))
		background.setFillColor(hoverColor);

	this->setTextSize();

	insideText.setOrigin(sf::Vector2f(
		insideText.getLocalBounds().left + insideText.getLocalBounds().width / 2,
		insideText.getLocalBounds().top + insideText.getLocalBounds().height / 2
	));

	insideText.setPosition(sf::Vector2f(
		objectSpace.left + objectSpace.width / 2,
		objectSpace.top + objectSpace.height / 2));

		//cout << checkIsClicked(win) << " " << asClicked() << endl;
	if (asClicked() && timer.getStartedStatus()) {
		timer.removeTime(10s);
		timer.updateTime();
	}
}

void Button::draw(sf::RenderWindow &win)
{
	this->update(win);
	win.draw(background);
	win.draw(insideText);
}