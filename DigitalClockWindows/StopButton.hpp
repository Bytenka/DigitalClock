#ifndef StopButton



#include "Interactable.hpp"
class StopButton : public Interactable {
	sf::Texture texture;
	sf::Sprite stopImg;

  public:
	StopButton();
	void update(sf::RenderWindow&);
	void draw(sf::RenderWindow&);
};

#endif
