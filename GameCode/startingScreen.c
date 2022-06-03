#include <SDL.h>
#include <stdio.h>
#include <SDL_timer.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <string.h>
#include "mouse.h"
#include "renderStart.h"
#include "startingScreen.h"
#include "textStart.h"
#include "soundStart.h"

#define PUBLIC /* empty */
#define PRIVATE static

PUBLIC const char * startingScreen(int *playerCount)
{
    //Initialize SDL & Timer
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }

    //Window
    SDL_Window* win = SDL_CreateWindow("Snakes & Ladders",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
        480, 0);

    if (!win)
    {
        printf("Failed to create window\n");
        SDL_Quit();
    }

    // Create a renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(win, -1, render_flags);

    if (!rend)
    {
        printf("Error creating renderer\n");
        SDL_DestroyWindow(win);
        SDL_Quit();
    }

    // Load Images from library
    SDL_Surface* surface = IMG_Load("resources/starting_screen2.png");
    SDL_Surface* surface2 = IMG_Load("resources/player_choose.png");
    SDL_Surface* surface3 = IMG_Load("resources/credit_screen.png");
    SDL_Surface* surface4 = IMG_Load("resources/player_options.png");
    SDL_Surface* surface5 = IMG_Load("resources/player_iphost.png");
    SDL_Surface* surface6 = IMG_Load("resources/jungle.png");

    if (!surface || !surface2 || !surface3 || !surface4 || !surface5 || !surface6)
    {
        printf("Failed to get the surfaces from the window\n");
        SDL_DestroyWindow(win);
        SDL_DestroyRenderer(rend);
        SDL_Quit();
    }

    //Load images data into memory
    SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
    SDL_FreeSurface(surface);
    SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface2);
    SDL_FreeSurface(surface2);
    SDL_Texture* tex3 = SDL_CreateTextureFromSurface(rend, surface3);
    SDL_FreeSurface(surface3);
    SDL_Texture* tex4 = SDL_CreateTextureFromSurface(rend, surface4);
    SDL_FreeSurface(surface4);
    SDL_Texture* tex5 = SDL_CreateTextureFromSurface(rend, surface5);
    SDL_FreeSurface(surface5);
    SDL_Texture* tex6 = SDL_CreateTextureFromSurface(rend, surface6);
    SDL_FreeSurface(surface6);

    if (!tex || !tex2 || !tex3 || !tex4 || !tex5 || !tex6)
    {
        printf("Failed to load image\n");
        copyTexture(2, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
    }

    //set to 1 when windows close button is pressed
    PRIVATE int close_requested = 0;
    //nrOfPlayers set to 1/2/3/4 in mouse.c
    PUBLIC int nrOfPlayers = 0;
    //set to 0 in mouse.c to turn sound off
    PRIVATE int soundOnOrOff = 1;
    PRIVATE int soundCounter = 0;
    //set to 1 to enable textinput if ipadress and 0 to send to main
    PRIVATE int ipTextEnable = 2;
    //create a const char * ipAdress to return from textStart.cpp
    PUBLIC const char * ipAdress = "";
    //Checks for backspace
    PRIVATE int backspace = 0;
    //Checks for return after textinput
    PRIVATE int eraseText = 0;

    // animation loop
    while (!close_requested)
    {
        //process events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_RETURN:
                    //Enter button to send information to main after textinput
                    if (ipTextEnable == 1)
                    {
                        ipTextEnable = 0;
                        break;
                    }
                }
            }

            //Function for mouse and choise off buttons on screen
            mousePosition(&ipTextEnable, &soundOnOrOff, &nrOfPlayers,&eraseText, win, rend, tex, tex2, tex3, tex4, tex5, tex6);

            //Function for sound and music
            if (soundOnOrOff == 1)
            {
                soundAndMusic(0, 0);
                soundCounter = 0;
            }
            if (soundOnOrOff == 0)
            {
                if(soundCounter < 1)
                {
                    soundAndMusic(1, 0);
                    soundCounter = 1;
                }
            }

            //Enables in mouse.c after chosing player count 2/3/4
            if (ipTextEnable == 1)
            {
                ipAdress = textStart(event, rend, win, &backspace, &eraseText);
                *playerCount = nrOfPlayers - 10;
            }

            //After textinput of ipAdress & enter button pressed send to main 
            if (ipTextEnable == 0)
            {
                SDL_StopTextInput();
                TTF_Quit();
                copyTexture(9, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
                SDL_Delay(2000);
                soundAndMusic(1, 0);
                copyTexture(4, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
                return ipAdress;
            }

            //if single player return only 1 player count and no ipAdress
            if (nrOfPlayers == 11)
            {
                SDL_StopTextInput();
                TTF_Quit();
                copyTexture(9, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
                SDL_Delay(2000);
                soundAndMusic(1, 0);
                copyTexture(4, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
                *playerCount = nrOfPlayers - 10;
                return 0;
            }

            if (backspace == 1)
            {
                copyTexture(8, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
                backspace = 0;
            }

            //wait 1/60th of a sec
            SDL_Delay(1000 / 60);
        }
    }

    //Clean up recources
    soundAndMusic(1, 0);
    copyTexture(2, win, rend, tex, tex2, tex3, tex4, tex5, tex6);
    return 0;
}