
#include "texture.h"

extern SDL_Window* window = NULL;
extern SDL_Renderer* renderer = NULL;

LTexture :: LTexture( SDL_Texture* _mTexture, int _mWidth, int _mHeight){
	mHeight =_mHeight ;
	mWidht = _mWidth;
	mTexture = _mTexture;
}

bool LTexture::loadFromfile(std::string path) {
	free();
	bool success = true;
	SDL_Texture* gTexture = NULL;

	SDL_Surface* mSurface = IMG_Load(path.c_str());
	if (mSurface == NULL) {
		printf("Could not load image! %s\n", IMG_GetError());
		success = false;
	}
	else {
		gTexture = SDL_CreateTextureFromSurface(renderer, mSurface);
		if (gTexture == NULL) {
			printf("Fail tp create texture! SDL_Error(): %s\n", SDL_GetError());
			success = false;
		}
		else {
			mWidht = mSurface->w;
			mHeight = mSurface->h;
		}
		SDL_FreeSurface(mSurface);
	}
	mTexture = gTexture;
	return success;
}

LTexture::~LTexture() {
	free();
}

int LTexture::height() {
	return mHeight;
}

int LTexture::widht() {
	return mWidht;
}

void LTexture::free() {
	if (mTexture != NULL) {
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
		mHeight = 0;
		mWidht = 0;
	}
}
void LTexture::render(int x, int y, SDL_Rect* clip) {
	SDL_Rect renderQuad = { x,y, mWidht, mHeight };

	if (clip != NULL) {
		renderQuad.h = clip->h;
		renderQuad.w = clip->w;

	}
	SDL_RenderCopy(renderer, mTexture, clip, &renderQuad);
}
