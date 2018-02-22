#ifndef main_hpp
#define main_hpp

#include <SFML/Graphics.hpp>

#include "TimeObject.hpp"
#include "TimeDisplay.hpp"
#include "PreviewEditor.hpp"

using namespace std;

#define INITIAL_DISPLAY_WIDTH 1280
#define INITIAL_DISPLAY_HEIGHT 720
#define INITIAL_SETUP_WIDTH 640
#define INITIAL_SETUP_HEIGHT 720

extern int globalBounds;

extern sf::RenderWindow displayWindow;
extern sf::Color displayWindowBackgroundColor;
extern sf::RenderWindow setupWindow;
extern sf::Color setupWindowBackgroundColor;
extern sf::Font fontForClock;
extern sf::Font fontForUI;
extern sf::Mouse mouse;
extern sf::RectangleShape lineBelowPreviewEditor;
extern sf::Rect<float> drawableArea;

extern TimeObject timer;
extern PreviewEditor previewEditor;
//extern TimeDisplay mainClock;
extern WhatDigitsToDisplay stringType;

#endif