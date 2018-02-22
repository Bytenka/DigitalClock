#ifndef Button_hpp
#define Button_hpp

#include <SFML/Graphics.hpp>

#include "Interactable.hpp"

using namespace std;

class Button : public Interactable
{
	sf::Text insideText;

public:
	Button(string);
	Button();
	void setTextSize(int);
	void setTextSize();
	int getTextSize();
	void setTextColor(sf::Color);
	sf::Color getTextColor();
	void setTextString(string s);
	string getTextString();
	void update(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

#endif