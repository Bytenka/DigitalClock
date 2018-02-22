#include <SFML/Graphics.hpp>

#include "main.hpp"
#include "StopButton.hpp"



StopButton::StopButton()
{
	this->setSize(sf::Vector2f(35, 35));
	this->setPosition(sf::Vector2f());
	backgroundStillColor = sf::Color(100, 100, 100, 255);
	this->setHoverColor(sf::Color(100, 0, 0, 255));
	this->setClickColor(sf::Color(0, 100, 0, 255));
	this->setOutlineColor(sf::Color::Black);

	texture.loadFromFile("img/stop-button.png");
}

void StopButton::update(sf::RenderWindow& win) {
	background.setSize(sf::Vector2f(objectSpace.width, objectSpace.height));
	background.setPosition(sf::Vector2f(objectSpace.left, objectSpace.top));

	background.setFillColor(backgroundStillColor);

	stopImg.setTexture(texture);

	if (this->checkIsClicked(win))
	{
		background.setFillColor(clickColor);
		clicked = true;
	}
	else if (this->checkIsHovered(win))
		background.setFillColor(hoverColor);

	sf::Rect<float> r = stopImg.getLocalBounds();
	stopImg.setOrigin(sf::Vector2f(
		r.left + r.width / 2,
		r.top + r.height / 2));

	stopImg.setPosition(sf::Vector2f(
		objectSpace.left + objectSpace.width / 2,
		objectSpace.top + objectSpace.height / 2));

	float scaleX = (objectSpace.height - 15) / stopImg.getTextureRect().height;
	stopImg.setScale(sf::Vector2f(scaleX, scaleX));

	if (asClicked()) {
		timer.stop();
	}
}

void StopButton::draw(sf::RenderWindow& win) {
	this->update(win);
	win.draw(background);
	win.draw(stopImg);
}
