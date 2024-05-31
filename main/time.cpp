#include "timer.h"

LTimer::LTimer() {
	mStartTciks = 0;
	mPausedTciks = 0;

	mStart = false;
	mPaused = false;
}

void LTimer::start() {
	mStart = true;
	mPaused = false;

	mStartTciks = SDL_GetTicks();
	mPausedTciks = 0;
}

void LTimer::stop() {
	mStart = false;
	mPaused = false;

	mStartTciks = 0;
	mPausedTciks = 0;
}

void LTimer::pause() {
	if (mStart == true && mPaused == false) {
		mPaused = true;

		mPausedTciks = SDL_GetTicks() - mStartTciks;
		mStartTciks = 0;
	}
}

bool LTimer::isStarted() {
	return mStart;
}

bool LTimer::isPaused() {
	return mStart && mPaused;
}

Uint32 LTimer::getTick() {
	Uint32 time = 0;

	if (mStart) {
		if (mPaused) {
			time = mPausedTciks;
		}
		else time = SDL_GetTicks() - mStartTciks;
	}

	return time;
}






