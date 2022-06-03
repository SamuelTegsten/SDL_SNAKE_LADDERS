#include <stdio.h>
#include "application.h"

void updateDiceTotal(int dSum, int *turnPlayer1, int *turnPlayer2, int *turnPlayer3, int *turnPlayer4, int *diceTotalPlayer1, int *diceTotalPlayer2, int *diceTotalPlayer3, int *diceTotalPlayer4){
            
    if (*turnPlayer4 == 1)
            {
                (*diceTotalPlayer4) = dSum + (*diceTotalPlayer4);
                printf("Player 4 total : %d\n", *diceTotalPlayer4);
            }
    else if (*turnPlayer3 == 1)
            {
                (*diceTotalPlayer3) = dSum + (*diceTotalPlayer3);
                printf("Player 3 total : %d\n", *diceTotalPlayer3);
            }
    else if (*turnPlayer2 == 1)
            {
                (*diceTotalPlayer2) = dSum + (*diceTotalPlayer2);
                printf("Player 2 total : %d\n", *diceTotalPlayer2);
            }
    else if (*turnPlayer1 == 1)
            {
                (*diceTotalPlayer1) = dSum + (*diceTotalPlayer1);
                printf("Player 1 total : %d\n", *diceTotalPlayer1);
            }
}