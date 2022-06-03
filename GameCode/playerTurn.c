#include <stdio.h>
#include "playerTurn.h"
#include "dice.h"

#define PUBLIC /*empty*/
#define PRIVATE static

void turn(int *turnPlayer1, int *turnPlayer2, int *turnPlayer3, int *turnPlayer4, int *turnPlayerCounter){
//void turn(int dSum, int *turnPlayer1, int *turnPlayer2, int *turnPlayer3, int *turnPlayer4, int *turnPlayerCounter, int *diceTotalPlayer1, int *diceTotalPlayer2, int *diceTotalPlayer3, int *diceTotalPlayer4, int dice1, int dice2){
    
    if (*turnPlayerCounter == 4)
            {
                (*turnPlayer1) = 1;
                (*turnPlayer4) = 0;               
                (*turnPlayerCounter) = 0;
            }
    else if (*turnPlayer4 == 1)
            {
                
            }
    else if (*turnPlayer3 == 1)
            {
                (*turnPlayer4) = 1;
                (*turnPlayer3) = 0; 
            }
    else if (*turnPlayer2 == 1)
            {
                (*turnPlayer2) = 0;
                (*turnPlayer3) = 1;
            }
    else if (*turnPlayer1 == 1)
            {
                (*turnPlayer1) = 0;
                (*turnPlayer2) = 1;
            }
}