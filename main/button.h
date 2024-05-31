#include <SDL.h>
#include <vector>

#pragma once
#ifndef BUTTON_H
#define BUTTON_H

class LButton {
public:
	LButton();
	void handleEvent(SDL_Event* e);
	void handleBack(SDL_Event* e);
	void handleFace(SDL_Event* e);
	void handleMute(SDL_Event* e);
	void render(int x, int y);
	void renderr(int x, int y);
	void mPosition(int x, int y);
private:
	SDL_Point mPoint;
};



#endif // !BUTTON.H
