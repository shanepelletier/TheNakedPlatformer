#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

SDL_Surface* loadImage(const char* filename)
{
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(filename);
	if (loadedImage != NULL)
	{
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	return optimizedImage;
}

void applySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(source, NULL, destination, &offset);
}

int main(int argc, char* argv[])
{
	SDL_Surface* playerSurface = NULL;
	SDL_Surface* screen = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("The Naked Platformer", NULL);
	playerSurface = loadImage("player.png");
	int x = 0;
	int y = 0;
	bool quit = false;
	SDL_Event event;
	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		Uint8* keystates = SDL_GetKeyState(NULL);
		if (keystates[SDLK_UP])
		{
			y--;
		}
		else if (keystates[SDLK_DOWN])
		{
			y++;
		}
		else if (keystates[SDLK_LEFT])
		{
			x--;
		}
		else if (keystates[SDLK_RIGHT])
		{
			x++;
	        }
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
		applySurface(x, y, playerSurface, screen);
		SDL_Flip(screen);
	}
	SDL_FreeSurface(playerSurface);
	SDL_Quit();
	return 0;
}
