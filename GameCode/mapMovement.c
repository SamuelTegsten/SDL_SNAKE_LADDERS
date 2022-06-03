#include <stdio.h>
#include "mapMovement.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int nextCoordinateX = 0;
PRIVATE int nextCoordinateY = 0;

void squareMoving(int diceRoll, int currentPositionOnBoard, int *currentCoordinateX, int *currentCoordinateY) //!!! Jag antar att positionOnBoard (totalvärde) ska vara en pointer i andra funktioner, men jag ändrar inte något med den så skicka EJ en pointer hit!!!
{
    int oneJumpX = 64, destinationRightX, destinationLeftX; //Att förflytta sig uppåt i y led ger -#

    PRIVATE int Right[51] = {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
    61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
    PRIVATE int Left[51] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 51, 52, 53, 54, 55, 56, 57, 58, 
    59, 60, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 91, 92, 93, 94, 95, 96, 97, 98 , 99, 100};

    PUBLIC destinationRightX = *currentCoordinateX + (diceRoll * oneJumpX); 
    PUBLIC destinationLeftX = *currentCoordinateX - (diceRoll * oneJumpX);

    if(currentPositionOnBoard == 10)
    {
        *currentCoordinateY = *currentCoordinateY - 64; //Ett hopp upp. -# förflyttas ^ i Y led. 
        return;
    }
    if (currentPositionOnBoard == 20 || currentPositionOnBoard == 40 || currentPositionOnBoard == 60 || currentPositionOnBoard == 80)
    {
        *currentCoordinateY = *currentCoordinateY - 64; //Ett hopp upp. -# förflyttas ^ i Y led. 
        return;
    }
    if(currentPositionOnBoard == 30 || currentPositionOnBoard == 50  ||currentPositionOnBoard == 70 || currentPositionOnBoard == 90)
    {
        *currentCoordinateY = *currentCoordinateY - 64; //Ett hopp upp. -# förflyttas ^ i Y led. 
        return;
    }
    
    PUBLIC for(int i = 0; i<51; i++) //OBS! Här kan det bli problem med data i real tid när det gäller animering. 
    {
        if(currentPositionOnBoard == Right[i]) // Notering: Tar mycket minne & tid då den loopar genom 50 värden även när det är == true, men break är inte användbart här och goto är mindre ok. 
        {
            nextCoordinateX = destinationRightX;
            nextCoordinateY = *currentCoordinateY;
            break;
        }
        else if(currentPositionOnBoard == Left[i])
        {
            nextCoordinateX = destinationLeftX;
            nextCoordinateY = *currentCoordinateY;
            break;
        }
    }
    PUBLIC *currentCoordinateX = nextCoordinateX;  
    PUBLIC *currentCoordinateY = nextCoordinateY;

}
