#include "function.h"

extern int sizes_x = 0;
extern int sizes_y = 0;
extern int mines = 0;


extern vector<vector<int> >broad(1, vector<int>(1,0)) ;
extern vector<vector<int>> realbroad (1, vector<int>(1,0));
//extern int broad[max_size][max_size] = { 0 };
//extern int realbroad[max_size][max_size] = { 0 };
extern int moves_left = sizes_x * sizes_y;
extern int mines_left = mines;

extern int PlaceofMines_x = 50;
extern int PlaceofMines_y = 90;
extern int PlaceofSec_x = 25;
extern int PlaceofSec_y = 80;
extern int digits = 0;
extern int firstClick = 0;



extern bool easyInside = false;
extern bool mediumInside = false;
extern bool hardInside = false;



extern bool isrunning = false;
extern bool playerwin = false;
extern bool islosing = false;
extern bool mute = true;
extern bool isRunning = true;
extern bool mainn = true;


extern LTexture timeImage(NULL, 0, 0);
extern LTexture gameImage(NULL, 0, 0);
extern LTexture play(NULL, 0, 0);
extern LTexture play1(NULL, 0, 0);
extern LTexture exxit(NULL, 0, 0);
extern LTexture exit1(NULL, 0, 0);
extern LTexture easy(NULL, 0, 0);
extern LTexture medium(NULL, 0, 0);
extern LTexture hard(NULL, 0, 0);
extern LTexture back(NULL, 0, 0);
extern LTexture mutte(NULL, 0, 0);
extern LTexture mute_off(NULL, 0, 0);
extern LTexture face(NULL, 0, 0);
extern LTexture menuBG(NULL, 0, 0);
extern LTexture menuInsdieBG(NULL, 0, 0);
extern LTexture loseface(NULL, 0, 0);
extern LTexture winface(NULL, 0, 0);
extern LTexture easyMode(NULL, 0, 0);
extern LTexture mediumMode(NULL, 0, 0);
extern LTexture hardMode(NULL, 0, 0);

extern LTexture easyBroad(NULL, 0, 0);
extern LTexture mediumBroad(NULL, 0, 0);
extern LTexture hardBroad(NULL, 0, 0);

extern Mix_Chunk* winMusic = NULL;
extern Mix_Chunk* loseMusic = NULL;
extern Mix_Chunk* click = NULL;
extern Mix_Chunk* bombMusic = NULL;

extern SDL_Rect gimage[12] = {};
extern SDL_Rect mimage[10] = {};