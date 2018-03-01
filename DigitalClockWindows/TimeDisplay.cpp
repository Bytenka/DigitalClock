#include <SFML/Graphics.hpp>

#include "main.hpp"
#include "TimeDisplay.hpp"

using namespace std;

TimeDisplay::TimeDisplay()
{
	insideText.setFont(fontForClock);
	insideText.setCharacterSize(characterSize);
	insideText.setColor(textColor);
	//motherRect = win;

	this->update();
}

void TimeDisplay::update()
{
	insideText.setString(timer.getStringCurrentTime());

	// Set the origin at the center of the text
	sf::Rect<float> bounds = insideText.getLocalBounds();
	sf::Vector2f ori = sf::Vector2f(
		bounds.left + bounds.width / 2,
		bounds.top + bounds.height / 2);
	insideText.setOrigin(ori);

	// Set the text in the middle of the motherRect
	sf::Vector2f pos = sf::Vector2f(
		internalMotherRect.left + internalMotherRect.width / 2,
		internalMotherRect.top + internalMotherRect.height / 2);
	insideText.setPosition(pos);
}

void TimeDisplay::update(sf::Rect<float> &mRect)
{
	internalMotherRect = mRect;
}

void TimeDisplay::setTextColor(sf::Color c)
{
	insideText.setColor(c);
}

sf::Color TimeDisplay::getTextColor()
{
	return insideText.getColor();
}

void TimeDisplay::setCharSize(int s)
{
	insideText.setCharacterSize(s);
}

int TimeDisplay::getCharSize()
{
	return insideText.getCharacterSize();
}

void TimeDisplay::draw(sf::RenderWindow &win)
{
	this->update();
	win.draw(insideText);
}

void TimeDisplay::setInternalMotherRect(sf::Rect<float> &rect)
{
	internalMotherRect = rect;
}

sf::Rect<float> &TimeDisplay::getInternalMotherRect()
{
	return internalMotherRect;
}