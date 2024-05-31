#pragma once
#ifndef FUNC_H
#define FUNC_H


bool init();
bool loadMedia();
bool loadMute();

void createBroad();
void createBomb();
void real( int i, int j);
void minesleft();
void countBomb();
void showMenu();
void showInside();

void MENU();
void MenuInside();

void lose();
void playAgian();
void playerWin();
void setButton();
void renderButton();
void handleButton();
void renderGAme();
void showBroad();
void TimeinGame();
void change(int x, int y);
void close();
#endif // !FUNC_H
