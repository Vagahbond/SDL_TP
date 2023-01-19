#ifndef AUDIO_H
#define AUDIO_H

#include <SDL2/SDL.h>

typedef struct {
    SDL_AudioSpec spec;
    Uint32 length;
    Uint8 *buffer;
    SDL_AudioDeviceID device_id;
} AudioHandle;

AudioHandle *create_audio_handle(SDL_RWops *file);

void destroy_audio_handle(AudioHandle *handle);

#endif