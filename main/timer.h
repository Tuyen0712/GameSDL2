#pragma once
#include <SDL.h>

#ifndef TIMER_H
#define TIMER_H


class LTimer {
public:
	LTimer();
	void start();
	void stop();
	void pause();

	Uint32 getTick();
	bool isStarted();
	bool isPaused();
private:
	Uint32 mStartTciks;
	Uint32 mPausedTciks;

	bool mStart;
	bool mPaused;

};

//LTimer timer;

#endif // !TIMER.H
