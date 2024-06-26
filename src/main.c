#include <stdio.h>
#include <SDL2/SDL.h>

void init_window(void){
	if (SDL_Init(SDL_INIT_VIDEO) > 0) {
		fprintf(stderr, "Error init SDL... \n");
		exit(0);
	}
}

int main(){
	init_window();
	// printf("this is the main");/
	return 0;
}