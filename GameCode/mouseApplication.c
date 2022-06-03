#include <SDL.h>
#include <stdio.h>
#include "mouseApplication.h"
#include "application.h"

void mouseApplication(int *mouseReturn, int *close_requested)
{
    int x, y;
    Uint32 buttons;

    SDL_PumpEvents();  // make sure we have the latest mouse state.

    buttons = SDL_GetMouseState(&x, &y);

    /*SDL_Log("Mouse cursor is at %d, %d", x, y);
    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        SDL_Log("Mouse Button 1 (left) is pressed.");
    }*/

    //Exit button
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (x > 1076 && y > 348 && x < 1210 && y < 381)
        {
            soundAndMusic(0, 1);
            *close_requested = 1;
        }
    }
}

