#ifndef ControlBar_hpp
#define ControlBar_hpp

#include <SFML/Graphics.hpp>

#include "Button.hpp"
#include "StartPauseButton.hpp"
#include "StopButton.hpp"

using namespace std;

class ControlBar
{
	sf::Rect<float> area;
	StartPauseButton startPause;
	StopButton stop;
	Button minusCustom;
	Button minus30 = Button("-30");
	Button minus10 = Button("-10");
	Button plus10  = Button("+10");
	Button plus30  = Button("+30");
	Button plusCustom;
	int minusCustomValue;
	int plusCustomValue;

public:
	ControlBar();
	void draw(sf::RenderWindow&);
	void update();
};

#endif