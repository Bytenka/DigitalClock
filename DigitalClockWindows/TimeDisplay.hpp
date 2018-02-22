#ifndef TimeDisplay_hpp
#define TimeDisplay_hpp

#include <SFML/Graphics.hpp>

using namespace std;

/*
This class needs a base rectangle to correctly place the text
on the frame. Be sure that the rect passed is never destroyed.
If needed, use the setMotherRect() method.
*/
class TimeDisplay
{
	sf::Text insideText;
	sf::Color textColor = sf::Color::Red;
	sf::Rect<float> internalMotherRect = sf::Rect<float>(0, 0, 100, 100);
	int characterSize = 100;

public:
	TimeDisplay();
	void update(sf::Rect<float>&);
	void update();
	void draw(sf::RenderWindow &);
	void setInternalMotherRect(sf::Rect<float>&);
	sf::Rect<float>& getInternalMotherRect();
	void setTextColor(sf::Color);
	sf::Color getTextColor();
	void setCharSize(int);
	int getCharSize();
};

#endif