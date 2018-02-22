#include <SFML/Graphics.hpp>
#include <iostream>

#include "main.hpp"
#include "StartPauseButton.hpp"

using namespace std;

StartPauseButton::StartPauseButton()
{
	this->setSize(sf::Vector2f(80, 40));
	this->setPosition(sf::Vector2f(10, 50));
	backgroundStillColor = sf::Color(100, 100, 100, 255);
	this->setHoverColor(sf::Color(100, 0, 0, 255));
	this->setClickColor(sf::Color(0, 100, 0, 255));
	this->setOutlineColor(sf::Color::Black);

	playImg.loadFromFile("img/play-button.png");
	pauseImg.loadFromFile("img/pause-button.png");
}

void StartPauseButton::update(sf::RenderWindow &win)
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

	if (timer.getStartedStatus())
	{
		playPauseImg.setTexture(pauseImg);
	}
	else
	{
		playPauseImg.setTexture(playImg);
	}

	sf::Rect<float> r = playPauseImg.getLocalBounds();
	playPauseImg.setOrigin(sf::Vector2f(
		r.left + r.width / 2,
		r.top + r.height / 2));

	playPauseImg.setPosition(sf::Vector2f(
		objectSpace.left + objectSpace.width / 2,
		objectSpace.top + objectSpace.height / 2));

	float scaleX = (objectSpace.height - 10) / playPauseImg.getTextureRect().height;
	playPauseImg.setScale(sf::Vector2f(scaleX, scaleX));

	if (asClicked()) {
		if (timer.getStartedStatus())
			timer.pause();
		else
			timer.start();
	}
}

void StartPauseButton::draw(sf::RenderWindow &win)
{
	this->update(win);
	win.draw(background);
	win.draw(playPauseImg);
}