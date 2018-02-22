#include <SFML/Graphics.hpp>
#include <iostream>

#include "TimeObject.hpp"
#include "main.hpp"

using namespace std;

TimeObject::TimeObject()
{
	this->stop();
}

bool TimeObject::getStartedStatus()
{
	return isStarted;
}

void TimeObject::start()
{
	begin = chrono::high_resolution_clock::now();
	if (!isPaused && internalMode != chronometer)
		pauseTime = finalTime;
	isPaused = false;
	isStarted = true;
	cout << pauseTime.count() << endl;
}

void TimeObject::pause()
{
	isPaused = true;
	isStarted = false;
	pauseTime = currentTime;
	//cout << pauseTime.count() << endl;
}

void TimeObject::stop()
{
	isPaused = false;
	isStarted = false;
	pauseTime = 0ms;
	currentTime = finalTime;
}

void TimeObject::setFinalTime(chrono::milliseconds m)
{
	finalTime = m;
	if (!isStarted)
		currentTime = finalTime;
}

chrono::milliseconds TimeObject::getCurrentTime()
{
	if (isStarted)
	{
		end = chrono::high_resolution_clock::now();
		this->updateTime();
	}
	return currentTime;
}

void TimeObject::updateTime() {
	switch (internalMode)
	{
	case chronometer:
		currentTime = (pauseTime + chrono::duration_cast<chrono::milliseconds>(end - begin));
		if (finalTime - currentTime <= 0ms)
		{
			currentTime = pauseTime;
			this->stop();
		}
		cout << currentTime.count() << endl;

		if (currentTime < 0ms) {
			currentTime = 0ms;
			pauseTime = 0ms;
		}

		break;
	case countdown:
		currentTime = (pauseTime - chrono::duration_cast<chrono::milliseconds>(end - begin));
		if (currentTime <= 0ms)
		{
			currentTime = 0ms;
			this->stop();
		}
		break;
	}
}

void TimeObject::addTime(chrono::milliseconds m)
{
	pauseTime += m;
}

void TimeObject::removeTime(chrono::milliseconds m)
{
	pauseTime -= m;
}

void TimeObject::setMode(ClockMode c)
{
	internalMode = c;
}

ClockMode TimeObject::getMode()
{
	return internalMode;
}

string TimeObject::getStringCurrentTime()
{
	chrono::milliseconds timeToConvert = getCurrentTime();
	long long s = chrono::duration_cast<chrono::seconds>(timeToConvert).count();
	string dispMil = to_string(timeToConvert.count() - s * 1000);
	string dispSec = to_string(s % 60);
	string dispMin = to_string((s / 60) % 60);
	string dispHou = to_string((s / 3600) % 60);

	if (atoi(dispMil.c_str()) < 10)
		dispMil = "00" + dispMil;
	else if (atoi(dispMil.c_str()) < 100)
		dispMil = "0" + dispMil;

	if (atoi(dispSec.c_str()) < 10)
		dispSec = "0" + dispSec;
	if (atoi(dispMin.c_str()) < 10)
		dispMin = "0" + dispMin;
	if (atoi(dispHou.c_str()) < 10)
		dispHou = "0" + dispHou;

	string dTime = "";
	switch (stringType)
	{
	case all:
		dTime += dispHou + ":" + dispMin + ":" + dispSec + ":" + dispMil;
		break;
	case hours_minutes_seconds:
		dTime += dispHou + ":" + dispMin + ":" + dispSec;
		break;
	case minutes_seconds_milliseconds:
		dTime += dispMin + ":" + dispSec + ":" + dispMil;
		break;
	case hours_minutes:
		dTime += dispHou + ":" + dispMin;
		break;
	case minutes_seconds:
		dTime += dispMin + ":" + dispSec;
		break;
	case seconds_milliseconds:
		dTime += dispSec + ":" + dispMil;
		break;
	}
	return dTime;
}
