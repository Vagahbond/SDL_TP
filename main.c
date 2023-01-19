#include <stdio.h>
#include <string.h>

#include "includes/window.h"


int main(int argc, char const *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    Window *window = create_window();


    destroy_window(window);

    SDL_Quit();

    return 0;
}
