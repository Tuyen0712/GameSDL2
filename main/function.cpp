#include "function.h"
#include "button.h"
#include "texture.h"
#include "timer.h"
#include "func.h"


LButton backk;
LButton facee;
LButton music;
vector<vector<LButton>> buttons;
LTimer timer;

 bool init() {
	 bool success = true;

	 if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
		 printf("Could not initilize window! SDL_ Error: %s\n", SDL_GetError());
		 success = false;

	 }
	 else {
		 window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDHT, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		 if (window == NULL) {
			 printf("Window can not be created! SDl_Error: %s\n", SDL_GetError());
			 success = false;
		 }
		 else {
			 if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
				 printf("Could not be initilize renderer! SDLError: %s\n", SDL_GetError());
				 success = false;
			 }
			 else {
				 renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
				 if (renderer == NULL) {
					 printf("Fail to creat renderer! SDL_Error: %s\n", SDL_GetError());
					 success = false;
				 }
				 else {
					 SDL_SetRenderDrawColor(renderer, 0xFF, 0xFf, 0xFf, 0xFF);
					 int img = IMG_INIT_PNG;
					 if (!(IMG_Init(img) & img)) {
						 printf("Fail to initilize SDL_image! SDL_Error: %s\n", IMG_GetError());
						 success = false;
					 }
					 else {
						 if (TTF_Init() == -1) {
							 printf("Fail to creat SDL_ttf! SDL_Error: %s\n", TTF_GetError());
							 success = false;
						 }
						 if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
							 printf("SDL_Mixer could not! SDL_Error: %s\n", Mix_GetError());
							 success = false;
						 }
					 }
				 }

			 }
		 }
	 }
	 return success;
 }



bool loadMedia() {
	bool success = true;
	if (!gameImage.loadFromfile("oso.png")) {
		cout<<"Fail to load game image!"<<endl;
		success = false;
	}
	else {
		for (int i = 0; i < 12; i++) {
			gimage[i].x = i * sizeofTime;
			gimage[i].y = 0;
			gimage[i].h = sizeofTime;
			gimage[i].w = sizeofTime;
		}
	}

	if (!timeImage.loadFromfile("time.png")) {
		cout << "Fail to load time image!" << endl;
		success = false;
	}
	else {
		for (int i = 0; i < 10; i++) {
			mimage[i].x = i * sizeofTime;
			mimage[i].y = 0;
			mimage[i].h = 46;
			mimage[i].w = sizeofTime;
		}

	}

	if (!play.loadFromfile("play (2).png")) {
		cout << "Fail to load play!" << endl;
		success = false;
	}
	if (!play1.loadFromfile("play2.png")) {
		cout << "Fail to load play1" << endl;
		success = false;
	}
	if (!exxit.loadFromfile("exit (2).png")) {
		cout << "Fail to load exit" << endl;
		success = false;
	}
	if (!exit1.loadFromfile("exit2.png")) {
		cout << "Fail to load exit1" << endl;
		success = false;
	}
	if (!easy.loadFromfile("easy11.png")) {
		cout << "Fail to load easy" << endl;
		success = false;
	}
	if (!easyMode.loadFromfile("easy2.png")) {
		cout << "Fail to load easy mode" << endl;
		success = false;
	}
	if (!medium.loadFromfile("medium11.png")) {
		cout << "Fail to load medium!" << endl;
		success = false;
	}
	if (!mediumMode.loadFromfile("medium2.png")) {
		cout << "Fail to load medium mode" << endl;
		success = false;
	}
	if (!hard.loadFromfile("hard2.png")) {
		cout << "Fail to load hard!" << endl;
		success = false;
	}
	if (!hardMode.loadFromfile("hard11.png")) {
		cout << "Fail to load hard mode" << endl;
		success = false;
	}
	if (!back.loadFromfile("back.png")) {
		cout << "Fail to load back!" << endl;
		success = false;
	}
	if (!face.loadFromfile("face.png")) {
		cout << "Fail to load face!" << endl;
		success = false;
	}
	if (!loseface.loadFromfile("loseface.png")) {
		cout << "Fail to load lose face!" << endl;
		success = false;
	}
	if (!mutte.loadFromfile("mute.png")) {
		cout << "Fail to load mute!" << endl;
		success = false;
	}
	if (!mute_off.loadFromfile("mute1.png")) {
		cout << "Fail to load mute1!" << endl;
		success = false;
	}
	if (!menuBG.loadFromfile("menu.png")) {
		cout << "Fail to load menu!" << endl;
		success = false;
	}
	if (!menuInsdieBG.loadFromfile("background.png")) {
		cout << "Fail to load BG!" << endl;
		success = false;
	}
	if (!easyBroad.loadFromfile("easyBroad.png")) {
		cout << "Fail to load EB!" << endl;
		success = false;
	}
	if (!mediumBroad.loadFromfile("mediumBroad.png")) {
		cout << "Fail to load BG!" << endl;
		success = false;
	}
	if (!hardBroad.loadFromfile("hardBroad.png")) {
		cout << "Fail to load BG!" << endl;
		success = false;
	}
	if (!winface.loadFromfile("winface.png")) {
		cout << "Fail to load win face!" << endl;
		success = false;
	}
	return success;

	
}

bool loadMute() {
	bool success = true;
	winMusic = Mix_LoadWAV("win.wav");
	if (winMusic == NULL) {
		cout << "Fail to load win music!" << endl;
		success = false;
	}
	loseMusic = Mix_LoadWAV("lose.wav");
	if (loseMusic == NULL) {
		cout << "Fail to load lose music!" << endl;
		success = false;
	}
	click = Mix_LoadWAV("lickk.wav");
	if ( click == NULL) {
		cout << "Fail to load click music!" << endl;
		success = false;
	}
	bombMusic = Mix_LoadWAV("bomb.wav");
	if (winMusic == NULL) {
		cout << "Fail to load bomb music!" << endl;
		success = false;
	}
	return success;
}

void showMenu() {
	menuBG.render(0,0, NULL);
	play.render(150, 300, NULL);
	exxit.render(450, 300, NULL);
}

void showInside() {
	menuInsdieBG.render(0, 0, NULL);
	easy.render( 300,150 , NULL);
	medium.render(300, 250 , NULL);
	hard.render(300,  350 , NULL);

}

void MENU() {
	showMenu();
	bool playy = false;
	bool exitt = false;
	bool showing = true;
	while (showing) {
		SDL_Event e ;
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				mainn = false;
				showing = false;

			}
			else {
				if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
					int x, y;
					SDL_GetMouseState(&x, &y);

					if (x > 150 && x < 150 + play.height()* 2 && y > 300 && y < 300 + play.widht()*2)  playy = true;
					else playy = false;

					if (x > 450 && x < 450 + exxit.height()* 2 && y > 300 && y < 300 + exxit.widht()* 2)  exitt = true;
					else exitt = false;


					if (e.type == SDL_MOUSEBUTTONDOWN) {
						if (e.button.button == SDL_BUTTON_LEFT) {
							if (playy) {

								showing = false;

							}
							if (exitt) {
								mainn = false;
								showing = false;
							}
						}
					}

					if (e.type == SDL_MOUSEMOTION) {
						if (playy) play1.render(150, 300, NULL);
						else play.render(150, 300, NULL);

						if (exitt) exit1.render(450, 300, NULL);
						else exxit.render(450, 300, NULL);
					}
				}
			}
			SDL_RenderPresent(renderer);
		}
	}
}

void MenuInside() {
	showInside();
	easyInside = false;
	mediumInside = false;
	hardInside = false;
	SDL_Event e;
	while (isRunning) {
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				mainn = false;
				isRunning = false;
			}
			else {
				if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					
					if (x > 300  && x < 300 + easy.widht() && y > 150 && y < 150 + easy.height())  easyInside = true;
					else easyInside = false;

					if (x > 300  && x < 300 + medium.widht() && y > 250 && y < 250 + medium.height())  mediumInside = true;
					else mediumInside = false;

					if (x > 300 && x < 300 + hard.widht() && y > 350 && y <  350  + hard.height())  hardInside = true;
					else hardInside = false;

					if (e.type == SDL_MOUSEBUTTONDOWN) {
						if (e.button.button == SDL_BUTTON_LEFT) {
							if (easyInside) {
								timer.start();
								mediumInside = false;
								hardInside = false;
								isrunning = true;
								isRunning = false;
								SDL_SetWindowSize(window, 294, 436);
								sizes_x = 9; sizes_y = 9;
								mines = mines_left = 10;
								digits = 235;
								createBroad();
								createBomb();
							}
							if (mediumInside) {
								timer.start();
								easyInside = false;
								hardInside = false;
								isrunning = true;
								isRunning = false;
								SDL_SetWindowSize(window, 488, 630);
								sizes_x = 16; sizes_y = 16;
								mines = mines_left = 40;
								digits = 430;
								createBroad();
								createBomb();
							}
							if (hardInside) {
								timer.start();
								easyInside = false;
								mediumInside = false;
								isrunning = true;
								isRunning = false;
								SDL_SetWindowSize(window, 590, 740 );
								sizes_x = 20; sizes_y = 20;
								mines = mines_left = 99;
								digits = 542;
								createBroad();
								createBomb();

							}
						}
					}

					if (e.type == SDL_MOUSEMOTION) {
						if (easyInside) {
							easyMode.render(300 - 10, 160, NULL);
						}
						else easy.render(300, 150, NULL);

						if (mediumInside) {
							mediumMode.render(300, 250, NULL);

						}
						else medium.render(300, 250, NULL);

						if (hardInside) {
							hard.render(300, 350, NULL);
						}
						else hardMode.render(290, 340, NULL);
					}

				}
			}
			SDL_RenderPresent(renderer);
		}
	}
}



void createBroad() {
	

	broad.resize(sizes_y);
	for (int i = 0; i < sizes_x; i++) {
		broad[i].resize(sizes_y);

	}

	realbroad.resize(sizes_y);
	for (int i = 0; i < sizes_x; i++) {
		realbroad[i].resize(sizes_y);
	}

	buttons.resize(sizes_y); 
	for (int i = 0; i < sizes_x; i++) {
			buttons[i].resize(sizes_y);
	}
	
}

void createBomb() {
	srand(time(0));
	for (int i = 0; i < sizes_x; i++) {
		for (int j = 0; j < sizes_y; j++) {
			broad[i][j] = 10;
			realbroad[i][j] = 0;
		}
	}
	int placeofMines = 0;
	while (placeofMines < mines) {
		int x = rand() % sizes_x;
		int y = rand() % sizes_y;
		if (realbroad[x][y] != 9) {
			realbroad[x][y] = 9;
			placeofMines++;
		}
	}


	for (int i = 0; i < sizes_x; i++){
		for (int j = 0; j < sizes_y; j++){

			if (realbroad[i][j] == 9) continue;
			for (int x = -1; x <= 1; x++){
				for (int y = -1; y <= 1; y++){
					int n = i + x;
					int m = j + y;
					if (n < 0 || n > sizes_x - 1 || m < 0 || m > sizes_y - 1) continue;
					if (realbroad[n][m] == 9) realbroad[i][j]++;
				}
			}
		}
	}

	/*for (int i = 0; i < sizes_x; i++) {
		for (int j = 0; j < sizes_y; j++) {
			if (realbroad[i][j] == 9) continue;
			int count = 0;
			for (int x = i - 1; x <= i + 1; x++) {
				for (int y = j - 1; j <= j + 1; y++) {

					if (x < 0 || y < 0 || x >= sizes_x || y >= sizes_y) continue;

					if (x == i && y == j) continue;

					if (realbroad[x][y] == 9) count++;
				}
			}
			realbroad[i][j] = count;
		}
	}*/
}


void real(int i, int j){
	if (broad[i][j] == 10 || realbroad[i][j] == 11){
		if (broad[i][j] == 11){
			return;
		}
		broad[i][j] = realbroad[i][j];

		if (broad[i][j] != 9) moves_left--;

		if (broad[i][j] == 0){
			for (int x = -1; x <= 1; x++){
				for (int y = -1; y <= 1; y++){
					int n = i + x;
					int m = j + y;
					if (n < 0 || n > sizes_x - 1 || m < 0 || m > sizes_y - 1) continue;
					real(n, m);
				}
			}
		}
	}
}


void minesleft() {
	int n = mines_left;
	if (n <= 9) {
		for (int i = 0; i <= 9; i++) {
			if (i == n) {
				timeImage.render(PlaceofMines_x, PlaceofMines_y, &mimage[i]);
			}
		}
	}
	else {
		int i = 0;
		while(n > 0) {
			int x = n % 10;
			n = n / 10;
			timeImage.render(PlaceofMines_x - i * 28, PlaceofMines_y, &mimage[x]);
			i++;
		}
	}
}

void setButton() {
	facee.mPosition(sizes_x* 28 / 2, 0);
	backk.mPosition(0, 0);
	music.mPosition( digits - 10, 0);
	for (int i = 0; i < sizes_x; i++) {
		for (int j = 0; j < sizes_y; j++) {
			buttons[i][j].mPosition( i * 28 + 21 , j * 28 + 163);
		}
	}
}

void renderButton() {
	face.render(sizes_x * 28 / 2, 0, NULL);
	back.render(0, 0, NULL);
	
	for (int i = 0; i < sizes_x; i++) {
		for (int j = 0; j < sizes_y; j++) {
			buttons[i][j].render(i ,j);
		}
	}
}

void handleButton() {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			isrunning = false;
			mainn = false;
		}
		else
		{
			facee.handleFace(&e);
			backk.handleBack(&e);
			music.handleMute(&e);
			for (int i = 0; i < sizes_x; i++) {
				for (int j = 0; j < sizes_y; j++) {

					buttons[i][j].handleEvent(&e);
				}
			}
		}
	}
}

void renderGAme() {
	if (mute) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		mutte.render(digits - 10, 0, NULL);
		winMusic = Mix_LoadWAV("win.wav");
		loseMusic = Mix_LoadWAV("lose.wav");
		click = Mix_LoadWAV("lickk.wav");
		bombMusic = Mix_LoadWAV("bomb.wav");
	}
	else {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);
		mute_off.render(digits - 10, 0, NULL);
		Mix_HaltChannel(-1);
		winMusic = NULL;
		loseMusic = NULL;
		click = NULL;
		bombMusic = NULL;
	}
	
}
void TimeinGame() {

	int n = timer.getTick() / 1000;

	if (n <= 9) {
		for (int i = 0; i <= 9; i++) {
			if (i == n) {
				timeImage.render(digits, PlaceofSec_y, &mimage[n]);
			}
		}
	}
	else {
		int i = 0;
		while (n > 0) {
			int x = n % 10;
			n = n / 10;

			timeImage.render(digits - i * 28, PlaceofSec_y, &mimage[x]);
			i++;
		}
	}

}

void showBroad() {
	if (easyInside) {
		easyBroad.render(0, 50, NULL);
	}
	if (mediumInside) {
		mediumBroad.render(0, 50, NULL);
	}
	if (hardInside) {
		hardBroad.render(7, 27, NULL);
	}
	handleButton();
	setButton();
	renderButton();
	minesleft();
	TimeinGame();
	lose();
	playerWin();
	SDL_RenderPresent(renderer);
}


void lose() {
	if (islosing == true) {
		timer.pause();
		Mix_PlayChannel(-1, loseMusic, 0);
		loseface.render(sizes_x * 28 / 2, 0, NULL);
		for (int i = 0; i < sizes_x; i++) {
			for (int j = 0; j < sizes_y; j++) {
				buttons[i][j].renderr(i, j);
			}
		}

	}
}

void playerWin() {
	if (moves_left == mines) playerwin = true;
	if (playerwin == true){
		timer.pause();
		Mix_PlayChannel(-1, winMusic, 0);
		winface.render(sizes_x * 28 / 2, 0, NULL);
	}
}

void playAgian() {
	timer.start();
	Mix_HaltChannel(-1);
	createBomb();
	moves_left = sizes_x * sizes_y;
	mines_left = mines;
	islosing = false;
	playerwin = false;

}

void close() {
	timeImage.free();
	gameImage.free();

	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	IMG_Quit();
	SDL_Quit();
}