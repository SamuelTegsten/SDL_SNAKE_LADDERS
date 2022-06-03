#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int dice1 = 0;
PRIVATE int dice2 = 0;
PRIVATE int counter = 0;
PRIVATE int counter2 = 0;

    int rollDice1(){
        srand(time(NULL));
        dice1=rand()%6+1; 
        return dice1;
    }
    int rollDice2()
    {
        while(counter < 100)
        { 
            srand(time(NULL));
            dice2 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            counter++;
        }
        counter = 0;
        return dice2;
    }
    int diceSum(int dice1, int dice2){
        int sum = dice1 + dice2;
        return sum;
    }