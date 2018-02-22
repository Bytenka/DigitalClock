#include <SFML/Graphics.hpp>
#include <iostream>

#include "PreviewEditor.hpp"
#include "main.hpp"

using namespace std;

PreviewEditor::PreviewEditor()
{
	background.setFillColor(sf::Color::Black);
	this->update();
}

void PreviewEditor::computeMaxSize(int bounds)
{
	int w = (int)drawableArea.width;
	//cout << w << endl;
	objectSpace = sf::Rect<float>(
		drawableArea.left,
		drawableArea.top,
		(float) w,
		w * (float) 9 / 16.
		);
}

void PreviewEditor::computeSize()
{
	float w = displayWindow.getSize().x * objectSpace.height / displayWindow.getSize().y;
	float h = displayWindow.getSize().y * objectSpace.width / displayWindow.getSize().x;
	if (w > objectSpace.width)
		background.setSize(sf::Vector2f(objectSpace.width, h));
	else
		background.setSize(sf::Vector2f(w, objectSpace.height));
}

void PreviewEditor::update()
{
	this->computeMaxSize(globalBounds);
	this->computeSize();

	background.setOrigin(
		background.getSize().x / 2,
		background.getSize().y / 2);

	background.setPosition(sf::Vector2f(
		objectSpace.left + objectSpace.width / 2,
		objectSpace.top + objectSpace.height / 2));
}

void PreviewEditor::draw(sf::RenderWindow &win)
{
	this->update();
	win.draw(background);
	text.setInternalMotherRect(objectSpace);
	text.draw(win);
	/*cout << background.getPosition().x << " "
	<< background.getPosition().y << endl
	<< background.getSize().x << " "
	<< background.getSize().y << endl
	<< objectSpace.left << " "
	<< objectSpace.width << endl
	<< objectSpace.top << " "
	<< objectSpace.height << endl << endl;*/
}