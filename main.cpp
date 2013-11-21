#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int main(int argc, char* argv[])
{
	SDL_Surface* playerSurface = NULL;
	SDL_Surface* screen = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	playerSurface = IMG_Load("player.png");
	SDL_BlitSurface(playerSurface, NULL, screen, NULL);
	SDL_Flip(screen);
	SDL_Delay(2000);
	SDL_FreeSurface(playerSurface);
	SDL_Quit();
	return 0;
}
