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

    int quit = 0;
    SDL_Event event;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        SDL_RenderClear(window->renderer);


        SDL_RenderPresent(window->renderer);
    }

    destroy_window(window);

    SDL_Quit();

    return 0;
}
