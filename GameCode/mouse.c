#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include "mouse.h"
#include "soundStart.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int gameChoise = 0;

//show current mouse position and choose window
int mousePosition(int *ipTextEnable, int *soundOnOrOff, int *nrOfPlayers, int *eraseText, SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex2, SDL_Texture* tex3, SDL_Texture* tex4, SDL_Texture* tex5, SDL_Texture* tex6)
{
    //find mouse position
    PRIVATE int x, y;
    PRIVATE Uint32 buttons_location;

    SDL_PumpEvents();  // make sure we have the latest mouse state.

    int buttons = SDL_GetMouseState(&x, &y);

    /*SDL_Log("Mouse cursor is at %d, %d", x, y);
    if ((buttons & SDL_BUTTON_LMASK) != 0) {
        SDL_Log("Mouse Button 1 (left) is pressed.");
    }*/

    //exit button
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT) && gameChoise == 0)
    {
        if (x > 498 && y > 406 && x < 559 && y < 425)
        {
            if (*soundOnOrOff == 1)
            {
                soundAndMusic(0, 1);
            }
            copyTexture(2, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
        }
    }

    //start button
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (x > 491 && y > 281 && x < 567 && y < 300)
        {
            if (gameChoise != 2 && gameChoise != 5 && gameChoise != 6 && gameChoise != 7)
            {
                gameChoise = 1;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

    //screen to choose number if players
    if (gameChoise == 1)
    {
        copyTexture(1, win, rend, tex, tex2, tex3, tex4, tex5, tex6);

        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            if (x > 545 && y > 428 && x < 628 && y < 464)
            {
                gameChoise = 0;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
            //1
            if (x > 462 && y > 310 && x < 480 && y < 340)
            {
                *nrOfPlayers = 11;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
                return 1;
            }
            //2
            if (x > 500 && y > 310 && x < 525 && y < 340)
            {
                *nrOfPlayers = 12;
                gameChoise = 6;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
            //3
            if (x > 550 && y > 310 && x < 570 && y < 340)
            {
                *nrOfPlayers = 13;
                gameChoise = 6;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
            //4
            if (x > 590 && y > 310 && x < 610 && y < 340)
            {
                *nrOfPlayers = 14;
                gameChoise = 6;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

     //credit button
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (x > 480 && y > 360 && x < 580 && y < 387)
        {
            if (gameChoise != 5 && gameChoise != 1 && gameChoise != 6 && gameChoise != 7)
            {
                gameChoise = 2;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

    //screen to show credits
    if (gameChoise == 2)
    {
        copyTexture(3, win, rend, tex, tex2, tex3, tex4, tex5, tex6);

        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            if (x > 545 && y > 428 && x < 628 && y < 464)
            {
                gameChoise = 0;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

    //options button
    if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        if (x > 471 && y > 318 && x < 593 && y < 347)
        {
            if(gameChoise != 2 && gameChoise != 1 && gameChoise != 6 && gameChoise != 7)
            { 
                gameChoise = 5;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

    //screen to show options
    if (gameChoise == 5)
    {
        copyTexture(5, win, rend, tex, tex2, tex3, tex4, tex5, tex6);

        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            if (x > 545 && y > 428 && x < 628 && y < 464)
            {
                gameChoise = 0;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
            //Sound On
            if (x > 527 && y > 287 && x < 552 && y < 301)
            {
                *soundOnOrOff = 1;
                soundAndMusic(0, 1);
                printf("%d\n", *soundOnOrOff);
            }
            //Sound Off
            if (x > 563 && y > 287 && x < 595 && y < 301)
            {
                *soundOnOrOff = 0;
                printf("%d\n", *soundOnOrOff);
            }
        }
    }

    //screen to enter Ip host address
    if (gameChoise == 6)
    {
        copyTexture(6, win, rend, tex, tex2, tex3, tex4, tex5, tex6);

        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            if (x > 545 && y > 428 && x < 628 && y < 464)
            {
                gameChoise = 0;
                *nrOfPlayers = 0;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
            if (x > 464 && y > 307 && x < 620 && y < 350)
            {
                gameChoise = 7;
                *ipTextEnable = 1;
                if (*soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }
    if (gameChoise == 7)
    {
        copyTexture(7, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
        if (buttons & SDL_BUTTON(SDL_BUTTON_LEFT))
        {
            if (x > 545 && y > 428 && x < 628 && y < 464)
            {
                gameChoise = 0;
                *nrOfPlayers = 0;
                *eraseText = 1;
                if (soundOnOrOff == 1)
                {
                    soundAndMusic(0, 1);
                }
            }
        }
    }

    //default screen
    if (gameChoise == 0)
    {
        copyTexture(0, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
    }
}
