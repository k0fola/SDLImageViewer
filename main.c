#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#define WIDTH 500
#define HEIGHT 500

int main(int argc, char *argv[]){
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Texture *texture;
	SDL_Surface *img1;
	char name[20];
	if(!SDL_Init(SDL_INIT_VIDEO)){
		printf("failed to initialise video");
		return 3;
	}
	if(!SDL_CreateWindowAndRenderer("Testing",WIDTH,HEIGHT,SDL_WINDOW_RESIZABLE,&window,&renderer)){
		printf("Failed to create window and renderer");
		return 3;
	}
	printf(argv[1]);
	img1 = IMG_Load(argv[1]);
	texture = SDL_CreateTextureFromSurface(renderer,img1);
	while(1){
		SDL_RenderClear(renderer);
		SDL_RenderTexture(renderer,texture,NULL,NULL);
		SDL_RenderPresent(renderer);
		SDL_PollEvent(&event);
		if(event.type == SDL_EVENT_QUIT){
			break;
		}
	}

	return 0;
}

