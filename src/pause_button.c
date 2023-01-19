#include "../includes/pause_button.h"


void draw_pause_button(Window *window, AudioHandle *audio_handle)
{
    SDL_Rect squareRect;

    squareRect.w = SCREEN_HEIGHT / 2;
    squareRect.h = SCREEN_HEIGHT / 2;

    squareRect.x = SCREEN_WIDTH / 2 - squareRect.w / 2;
    squareRect.y = SCREEN_HEIGHT / 2 - squareRect.h / 2;

    SDL_Rect pauseRect1, pauseRect2;

    pauseRect1.h = squareRect.h / 2;
    pauseRect1.w = 40;
    pauseRect1.x = squareRect.x + (squareRect.w - pauseRect1.w * 3) / 2;
    pauseRect1.y = squareRect.y + squareRect.h / 4;
    pauseRect2 = pauseRect1;
    pauseRect2.x += pauseRect1.w * 2;

    if (SDL_GetAudioDeviceStatus(audio_handle->device_id) == SDL_AUDIO_PAUSED)
    {
        SDL_SetRenderDrawColor(window->renderer, 0x19, 0x71, 0xA9, 0xFF);
        SDL_RenderFillRect(window->renderer, &squareRect);

        SDL_SetRenderDrawColor(window->renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(window->renderer, &pauseRect1);
        SDL_RenderFillRect(window->renderer, &pauseRect2);

    }
}