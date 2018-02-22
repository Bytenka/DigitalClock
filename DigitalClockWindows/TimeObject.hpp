#ifndef TimeObject_hpp
#define TimeObject_hpp

#include <SFML/Graphics.hpp>
#include <chrono>
#include <string>

using namespace std;

enum WhatDigitsToDisplay
{
	all,
	hours_minutes_seconds,
	minutes_seconds_milliseconds,
	hours_minutes,
	minutes_seconds,
	seconds_milliseconds
};

enum ClockMode
{
	chronometer,
	countdown
};

class TimeObject
{
public:
	TimeObject();
	void setMode(ClockMode);
	ClockMode getMode();
	void setFinalTime(chrono::milliseconds);
	void addTime(chrono::milliseconds);
	void removeTime(chrono::milliseconds);
	void start();
	void pause();
	void stop();
	chrono::milliseconds getCurrentTime();
	void updateTime();
	string getStringCurrentTime();
	bool getStartedStatus();

private:
	void resume();
	bool isStarted = false;
	bool isPaused = false;
	ClockMode internalMode = countdown;
	std::chrono::high_resolution_clock::time_point begin;
	std::chrono::high_resolution_clock::time_point end;
	chrono::milliseconds currentTime; // For chronometer
	chrono::milliseconds pauseTime = 0ms; // For toggeling pause
	chrono::milliseconds finalTime = 10min; // For countdown
};

#endif