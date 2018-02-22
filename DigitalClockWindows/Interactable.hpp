#ifndef Interactable_hpp
#define Interactable_hpp

#include <SFML/Graphics.hpp>

using namespace std;

class Interactable
{
protected:
	sf::Rect<float> objectSpace;
	sf::RectangleShape background;
	sf::Color backgroundStillColor;
	sf::Color hoverColor;
	sf::Color clickColor;
	bool isHovered;
	bool clicked = false;

public:
	void setPosition(sf::Vector2f);
	sf::Vector2f getPosition();

	void setSize(sf::Vector2f);
	sf::Vector2f getSize();

	void setFillColor(sf::Color);
	sf::Color getFillColor();

	void setHoverColor(sf::Color);
	sf::Color getHoverColor();

	void setClickColor(sf::Color);
	sf::Color getClickColor();

	void setOutlineColor(sf::Color);
	sf::Color getOutlineColor();

	void setOutlineThickness(float);
	int getOutlineThickness();

	bool checkIsHovered(sf::RenderWindow &win);
	bool checkIsClicked(sf::RenderWindow &win);
	bool asClicked();

	virtual void update(sf::RenderWindow &win) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
};

#endif