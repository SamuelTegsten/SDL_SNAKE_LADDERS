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

//Turn counter for every time all players have made their turn
PUBLIC int turnCounter = 0;
//How many times mouse button for roll dice has been pressed
PUBLIC int diceHitCount = 0;
//How many rounds have passed where all players have made their turn
PRIVATE char charRound[256];
//Timer display
PRIVATE char timerDisp[256];

void textView(SDL_Renderer* rend, int turnPlayer1, int turnPlayer2, int turnPlayer3, int turnPlayer4, int totalRounds, int timer, int readyToStart)
{
    //Init TTF
    if (TTF_Init() == -1)
    {
        printf("SDL could not initialize TTF! SDL_Error: %s\n", SDL_GetError());
    }

    //Color of text to black
    SDL_Color black = { 255, 255, 255 };
    //Makes font of ttf
    TTF_Font* textScreen;
    TTF_Font* textScreen2;
    textScreen = TTF_OpenFont("SHOWG_.ttf.ttf", 24);
    textScreen2 = TTF_OpenFont("SHOWG_.ttf.ttf", 72);
    SDL_Surface* turn=0;
    SDL_Surface* rounds = 0;
    SDL_Surface* timerSurf = 0;
    //Init surface with white font and text
  
    //start button
    SDL_Surface* start = TTF_RenderText_Solid(textScreen, "START", black);
    //Set texture to font surface
    SDL_Texture* startTexture = SDL_CreateTextureFromSurface(rend, start);

    SDL_Rect startRect;
    startRect.x = 1113;
    startRect.y = 260;
    startRect.h = 30;
    startRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(startTexture, NULL, NULL, &startRect.w, &startRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, startTexture, NULL, &startRect);

    //exit button
    SDL_Surface* exit= TTF_RenderText_Solid(textScreen, "EXIT", black);
    //Set texture to font surface
    SDL_Texture* exitTexture = SDL_CreateTextureFromSurface(rend, exit);

    SDL_Rect exitRect;
    exitRect.x = 1110;
    exitRect.y = 351;
    exitRect.h = 30;
    exitRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(exitTexture, NULL, NULL, &exitRect.w, &exitRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, exitTexture, NULL, &exitRect);

//roll button
    SDL_Surface* roll= TTF_RenderText_Solid(textScreen, "ROLL", black);
    //Set texture to font surface
    SDL_Texture* rollTexture = SDL_CreateTextureFromSurface(rend, roll);

    SDL_Rect rollRect;
    rollRect.x = 864;
    rollRect.y = 374;
    rollRect.h = 30;
    rollRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(rollTexture, NULL, NULL, &rollRect.w, &rollRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, rollTexture, NULL, &rollRect);

//round
    SDL_Surface* round = TTF_RenderText_Solid(textScreen, "ROUND:", black);
    //Set texture to font surface
    SDL_Texture* roundTexture = SDL_CreateTextureFromSurface(rend, round);

    SDL_Rect roundRect;
    roundRect.x = 777;
    roundRect.y = 55;
    roundRect.h = 30;
    roundRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(roundTexture, NULL, NULL, &roundRect.w, &roundRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, roundTexture, NULL, &roundRect);

//player
    SDL_Surface* player = TTF_RenderText_Solid(textScreen, "PLAYER", black);
    //Set texture to font surface
    SDL_Texture* playerTexture = SDL_CreateTextureFromSurface(rend, player);

    SDL_Rect playerRect;
    playerRect.x = 777;
    playerRect.y = 100;
    playerRect.h = 30;
    playerRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(playerTexture, NULL, NULL, &playerRect.w, &playerRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, playerTexture, NULL, &playerRect);


if(turnPlayer1 == 1)
{
   turn = TTF_RenderText_Solid(textScreen, "1", black);
}
if(turnPlayer2 == 1)
{
   turn = TTF_RenderText_Solid(textScreen, "2", black);
}
if(turnPlayer3 == 1)
{
   turn = TTF_RenderText_Solid(textScreen, "3", black);
}
if(turnPlayer4 == 1)
{
   turn = TTF_RenderText_Solid(textScreen, "4", black);
}

SDL_Texture* turnTexture = SDL_CreateTextureFromSurface(rend, turn);

    SDL_Rect turnRect;
    turnRect.x = 895;
    turnRect.y = 100;
    turnRect.h = 30;
    turnRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(turnTexture, NULL, NULL, &turnRect.w, &turnRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, turnTexture, NULL, &turnRect);

    sprintf(charRound, "%d", totalRounds);

    rounds = TTF_RenderText_Solid(textScreen, &charRound[0], black);
    SDL_Texture* roundsTexture = SDL_CreateTextureFromSurface(rend,rounds);

    SDL_Rect roundsRect;
    roundsRect.x = 895;
    roundsRect.y = 55;
    roundsRect.h = 30;
    roundsRect.w = 30;

    //Loads rect upon window
    SDL_QueryTexture(roundsTexture, NULL, NULL, &roundsRect.w, &roundsRect.h);

    //Render rect with font text
    SDL_RenderCopy(rend, roundsTexture, NULL, &roundsRect);

    if(readyToStart == 1)
    { 
        timer /= 60;
        sprintf(timerDisp, "%d", timer);

        timerSurf = TTF_RenderText_Solid(textScreen2, &timerDisp[0], black);
        SDL_Texture* timerTexture = SDL_CreateTextureFromSurface(rend, timerSurf);

        SDL_Rect timerRect;
        timerRect.x = 850;
        timerRect.y = 555;
        timerRect.h = 90;
        timerRect.w = 90;

        //Loads rect upon window
        SDL_QueryTexture(timerTexture, NULL, NULL, &timerRect.w, &timerRect.h);

        //Render rect with font text
        SDL_RenderCopy(rend, timerTexture, NULL, &timerRect);
    }
}