#pragma once

#ifndef FUNCTION_H
#define FUNCTION_H


#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <vector>
#include "const.h"
#include "texture.h"

using namespace std;

extern int sizes_x;
extern int sizes_y; 
extern int mines;

extern  vector<vector<int> >broad;
extern vector<vector<int>> realbroad;
//extern int broad[max_size][max_size];
//extern int realbroad[max_size][max_size];
extern int moves_left;
extern int mines_left;

extern int PlaceofMines_x;
extern int PlaceofMines_y;
extern int PlaceofSec_x;
extern int PlaceofSec_y;
extern int digits;


extern bool easyInside;
extern bool mediumInside;
extern bool hardInside;

 

extern bool isrunning;
extern bool playerwin;
extern bool islosing;
extern bool mute;
extern bool isRunning;
extern bool mainn;




extern SDL_Window* window;
extern SDL_Renderer* renderer;

extern LTexture timeImage;
extern LTexture gameImage;
extern LTexture play;
extern LTexture play1;
extern LTexture exxit;
extern LTexture exit1;
extern LTexture easy; 
extern LTexture medium;
extern LTexture hard;
extern LTexture back;
extern LTexture mutte;
extern LTexture mute_off;
extern LTexture face;
extern LTexture menuBG;
extern LTexture menuInsdieBG;
extern LTexture loseface;
extern LTexture winface;


extern LTexture easyMode;
extern LTexture mediumMode;
extern LTexture hardMode;

extern LTexture easyBroad;
extern LTexture mediumBroad;
extern LTexture hardBroad;

extern Mix_Chunk* winMusic;
extern Mix_Chunk* loseMusic;
extern Mix_Chunk* click ;
extern Mix_Chunk* bombMusic ;

extern SDL_Rect gimage[12];
extern SDL_Rect mimage[10];


#endif // !FUNCTION.H
