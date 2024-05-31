#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class LTexture {
public:
	LTexture(SDL_Texture* _mTexture, int _mWidth, int _mHeight);
	~LTexture();
	bool loadFromfile(std::string path);
	void free();

	void render(int x, int y, SDL_Rect* clip);
	int height();
	int widht();
private:
	int mHeight;
	int mWidht;
	SDL_Texture* mTexture;
};


#endif // !TEXTURE_H
