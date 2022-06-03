#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "application.h"
#include "spriteMoving.h"
#include "dice.h"
#include "mouseApplication.h"
#include "mapMovement.h"

void moveSprite(int diceSum, int *sprite_positionX, int *sprite_positionY)
{      
    (*sprite_positionX) = (*sprite_positionX)+64;
}