#include "button.h"
#include "function.h"
#include "const.h"
#include "func.h"

LButton::LButton() {
	mPoint.x = 0;
	mPoint.y = 0;
}

void LButton::mPosition(int x, int y) {
	mPoint.x = x;
	mPoint.y = y;
}


void LButton::handleBack(SDL_Event* e) {
	if (e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPoint.x) {
			inside = false;
		}
		else if (x > mPoint.x + 50) {
			inside = false;
		}
		else if (y < mPoint.y) {
			inside = false;
		}
		else if (y > mPoint.y + 50) {
			inside = false;
		}
		if (inside) {
			if (e->button.button == SDL_BUTTON_LEFT) {
				SDL_SetWindowSize(window, 807, 452);
			
				isRunning = true;
				isrunning = false;
				easyInside = false;
				hardInside = false;
				mediumInside = false;
				islosing = false;
				playerwin = false;
				Mix_HaltChannel(-1);
			}
		}
	}
}

void LButton::handleEvent(SDL_Event* e) {
	if (e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEMOTION) {
		int x, y;
		int i, j;
	    
		SDL_GetMouseState(&x, &y);
		i = (x - 21) / 28;
		j = (y - 163) / 28;
		bool inside = true;
		if (x < mPoint.x) {
			inside = false;
		}
		else if (x > mPoint.x + 28) {
			inside = false;
		}
		else if (y < mPoint.y) {
			inside = false;
		}
		else if (y > mPoint.y + 28) {
			inside = false;
		}
		if (inside) {
			if (e->type == SDL_MOUSEBUTTONDOWN) {
				switch (e->button.button) {
				case SDL_BUTTON_LEFT:
					real(i, j);

					if (broad[i][j] == 9)
					{
						Mix_PlayChannel(-1, bombMusic, 0);
						islosing = true;
					}
					else
					{
						Mix_PlayChannel(-1, click, 0);
					}
					break;
				case SDL_BUTTON_RIGHT:
					Mix_PlayChannel(-1, click, 0);
						if (broad[i][j] == 11)
						{
							broad[i][j] = 10;
							mines_left++;
						}
						else if (broad[i][j] == 10)
						{
							broad[i][j] = 11;
							mines_left--;
						}
					break;
				}
			}
			
		}
	}
}

void LButton::handleFace(SDL_Event* e) {
	if ( e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = false;
		if (x > mPoint.x && x < mPoint.x + 42 && y > mPoint.y && y < mPoint.y + 42) inside = true;

		if (inside) {
			if (e->button.button == SDL_BUTTON_LEFT) {
				playAgian();
			}
		}
	}
}

void LButton::handleMute(SDL_Event* e) {
	if ( e->type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		bool inside = true;
		if (x < mPoint.x) {
			inside = false;
		}
		else if (x > mPoint.x + 50) {
			inside = false;
		}
		else if (y < mPoint.y) {
			inside = false;
		}
		else if (y > mPoint.y + 50) {
			inside = false;
		}

		if (inside) {
			if (e->button.button == SDL_BUTTON_LEFT) {
				if (mute) mute = false;
				else mute = true;
			}
		}
	}
}

void LButton::render(int i, int j) {
	gameImage.render(mPoint.x, mPoint.y, &gimage[broad[i][j]]);
}

void LButton::renderr(int x, int y) {
	gameImage.render(mPoint.x, mPoint.y, &gimage[realbroad[x][y]]);

}