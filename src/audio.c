#include "../includes/audio.h"

AudioHandle *create_audio_handle(SDL_RWops *file)
{
    AudioHandle *handle = malloc(sizeof(AudioHandle));

    if (!SDL_LoadWAV_RW(file, 1, &handle->spec, &handle->buffer, &handle->length))
    {
        printf("SDL_LoadWAV_RW Error: %s\n", SDL_GetError());
        exit(-1);
    }

    handle->device_id = SDL_OpenAudioDevice(NULL, 0, &handle->spec, NULL, 0);
    if (!handle->device_id)
    {
        printf("SDL_OpenAudioDevice: %s\n", SDL_GetError());
        SDL_FreeWAV(handle->buffer);
        exit(-1);
    }

    if (SDL_QueueAudio(handle->device_id, handle->buffer, handle->length) != 0)
    {
        printf("SDL_QueueAudio: %s\n", SDL_GetError());
        SDL_CloseAudioDevice(handle->device_id);
        SDL_FreeWAV(handle->buffer);
        exit(-1);
    }


    return handle;
}


void destroy_audio_handle(AudioHandle *audio_handle)
{
    SDL_CloseAudioDevice(audio_handle->device_id);
    SDL_FreeWAV(audio_handle->buffer);
}