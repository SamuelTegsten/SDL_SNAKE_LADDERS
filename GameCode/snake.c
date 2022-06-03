#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include "soundApplication.h"

int snakePosition(int *spritePositionX, int *spritePositionY)
{ 
    if (*spritePositionY >= 553 && *spritePositionY  <= 609 && *spritePositionX >= 171 && *spritePositionX  <= 227)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =317;
        *spritePositionY =624;
        return 13;
    }
    if (*spritePositionY >= 490 && *spritePositionY  <= 545 && *spritePositionX >= 553 && *spritePositionX  <= 611)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =514;
        *spritePositionY =624;
        return 21;
    }
    if (*spritePositionY >= 297 && *spritePositionY  <= 355 && *spritePositionX >= 363 && *spritePositionX  <= 419)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =385;
        *spritePositionY =368;
        return 9;
    }
    if (*spritePositionY >= 235 && *spritePositionY  <= 291 && *spritePositionX >= 171 && *spritePositionX  <= 227)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =194;
        *spritePositionY =368;
        return 20;
    }
    if (*spritePositionY >= 107 && *spritePositionY  <= 163 && *spritePositionX >= 171 && *spritePositionX  <= 227)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =66;
        *spritePositionY =368;
        return 42;
    }
    if (*spritePositionY >= 106 && *spritePositionY  <= 163 && *spritePositionX >= 553 && *spritePositionX  <= 611)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =514;
        *spritePositionY =240;
        return 21;
    }
    if (*spritePositionY >= 43 && *spritePositionY  <= 100 && *spritePositionX >= 107 && *spritePositionX  <= 165)     //test
    {
        SDL_Delay(1000);      
        soundApplication(0, 4);
        *spritePositionX =322;
        *spritePositionY =304;
        return 43;
    }
    return 0;
}