#include <SDL.h>
#include <SDL_ttf.h>
#include "textStart.h"
#include "startingScreen.h"
#include "soundStart.h" 
#include <string.h>
#include <stdio.h>
#pragma warning(disable : 4996)

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE char text[100];
PUBLIC const char * ipAdress= "";
PRIVATE int enter = 0;
PRIVATE int inputCounter = 0;

const char* textStart(SDL_Event event, SDL_Renderer* rend, SDL_Window* win, int *backspace, int *eraseText)
{
    //Init TTF
    if (TTF_Init() == -1)
    {
        printf("SDL could not initialize TTF! SDL_Error: %s\n", SDL_GetError());
    }

    //Color of text to white
    SDL_Color white = { 255, 255, 255 };
    //Makes font of ttf
    TTF_Font* textScreen;
    textScreen = TTF_OpenFont("SHOWG_.ttf.ttf", 24);
    //Init surface with white font and text
    SDL_Surface* message = TTF_RenderText_Solid(textScreen, &text[0], white);
    //Set texture to font surface
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(rend, message);

    //Rect in coordinates of ip window
    SDL_Rect textRect;
    textRect.x = 465;
    textRect.y = 315;
    textRect.h = 30;
    textRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(textTexture, NULL, NULL, &textRect.w, &textRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, textTexture, NULL, &textRect);
    SDL_RenderPresent(rend);

    //Enables text input
    SDL_StartTextInput();

    //text input read and writes to text and cmd ||
    // * Max 14 characters for ipadress 
    if (event.type == SDL_TEXTINPUT)
    {
        if (inputCounter < 14)
        {
            fprintf(stderr, "Keyboard: text input \"%s\"\n", event.text.text);

            if (SDL_strlen(text) + SDL_strlen(event.text.text) < sizeof(text))
                SDL_strlcat(text, event.text.text, sizeof(text));

            fprintf(stderr, "text inputed: %s\n", text);
            inputCounter++;
            soundAndMusic(0, 2);
        }
    }
    //if backspace remove latest text input
    else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE)
    {
        int textlen = SDL_strlen(text);

        do {
            if (textlen == 0)
            {
                break;
            }
            if ((text[textlen - 1] & 0x80) == 0x00)
            {
                /* One byte */
                text[textlen - 1] = 0x00;
                break;
            }
            if ((text[textlen - 1] & 0xC0) == 0x80)
            {
                /* Byte from the multibyte sequence */
                text[textlen - 1] = 0x00;
                textlen--;
            }
            if ((text[textlen - 1] & 0xC0) == 0xC0)
            {
                /* First byte of multibyte sequence */
                text[textlen - 1] = 0x00;
                break;
            }
        } while (1);

        inputCounter--;
        soundAndMusic(0, 2);
        if (inputCounter < 0)
        {
            inputCounter = 0;
        }
        *backspace = 1;
    }
    //if enter is pressed return text string input to startingScreen.c as a const char *
    if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDL_SCANCODE_RETURN)
    {
        enter = 1;
        if (enter == 1)
        {
            SDL_FreeSurface(message);
            SDL_DestroyTexture(textTexture);
            strcpy(text, ipAdress);
            return text;
        }
    }

    //when entering text and pressing to go back, remove all prevoius text from memory and window
    if (*eraseText == 1)
    {
        SDL_RenderClear(rend);
        SDL_FreeSurface(message);
        SDL_DestroyTexture(textTexture);
        for(inputCounter; inputCounter > 0; inputCounter--)
        {
            int textlen = SDL_strlen(text);
            do {
                if (textlen == 0)
                {
                    break;
                }
                if ((text[textlen - 1] & 0x80) == 0x00)
                {
                    /* One byte */
                    text[textlen - 1] = 0x00;
                    break;
                }
                if ((text[textlen - 1] & 0xC0) == 0x80)
                {
                    /* Byte from the multibyte sequence */
                    text[textlen - 1] = 0x00;
                    textlen--;
                }
                if ((text[textlen - 1] & 0xC0) == 0xC0)
                {
                    /* First byte of multibyte sequence */
                    text[textlen - 1] = 0x00;
                    break;
                }
            } while (1);
        }
        *eraseText = 0;
    }
    ipAdress = &text[0];
    printf("testing: %s\n", ipAdress);
    strcpy(text, ipAdress);
    return text;
}