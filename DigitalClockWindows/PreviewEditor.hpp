#ifndef PreviewEditor_hpp
#define PreviewEditor_hpp

#include <SFML/Graphics.hpp>

#include "TimeDisplay.hpp"

using namespace std;

class PreviewEditor {
	sf::RectangleShape background;
	TimeDisplay text;
	int internalBounds;

public:
	sf::Rect<float> objectSpace;
	PreviewEditor();
	void setPosition();
	sf::Vector2f getPosition();
	void computeMaxSize(int);
	void computeSize();
	void update();
	int getInternalBounds();
	void draw(sf::RenderWindow&);

	sf::Vector2f getSize();
};

#endif