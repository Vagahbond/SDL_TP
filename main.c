#include <stdio.h>
#include <string.h>

#include "includes/window.h"
#include "includes/audio.h"
#include "includes/pause_button.h"

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(-1);
    }

    SDL_RWops *file = SDL_RWFromFile(argv[1], "rb");

    if (file == NULL)
    {
        printf("Could not open file: %s", argv[1]);
        return -1;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    Window *window = create_window();
    AudioHandle *audio_handle = create_audio_handle(file);

    int quit = 0;
    SDL_Event event;

    SDL_PauseAudioDevice(audio_handle->device_id, 0);

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
            else if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.sym)
                {
                case SDLK_SPACE:
                    if (SDL_GetAudioDeviceStatus(audio_handle->device_id) == SDL_AUDIO_PLAYING)
                        SDL_PauseAudioDevice(audio_handle->device_id, 1);
                    else
                        SDL_PauseAudioDevice(audio_handle->device_id, 0);
                    break;

                default:
                    break;
                }
            }
        }

        SDL_RenderClear(window->renderer);

        draw_pause_button(window, audio_handle);

        SDL_RenderPresent(window->renderer);
    }

    destroy_audio_handle(audio_handle);
    destroy_window(window);

    SDL_Quit();

    return 0;
}
