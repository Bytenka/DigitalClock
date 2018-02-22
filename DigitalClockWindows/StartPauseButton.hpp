#ifndef StartPauseButton_hpp
#define StartPauseButton_hpp

#include <SFML/Graphics.hpp>

#include "Interactable.hpp"

using namespace std;

class StartPauseButton : public Interactable
{
	sf::Texture playImg;
	sf::Texture pauseImg;

	sf::Sprite playPauseImg;

	bool isPlayed;

public:
	StartPauseButton();
	void update(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

#endif