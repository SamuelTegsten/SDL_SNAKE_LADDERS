#include <stdio.h>
#include "spriteMovementOnSnakeLadder.h"

void snakeLadderSlide(int currentPositionOnBoard, int *spriteX, int *spriteY, int *slideCounter, int ladderRotationTurn, int *changeDiceTotalBy, int *snakeOrLadder, int turnPlayer1, int turnPlayer2, int turnPlayer3, int turnPlayer4) //loops för turer...håll koll vart vi är, nollställ, draw, lika måga intrevaller
{
    int condition = 2; 

    switch(currentPositionOnBoard)
    {
        case 16: //ladder 1
        {
            switch(ladderRotationTurn)

            case 1:
            {
                if(turnPlayer1 == 1)
                {
                    int slidingXList[] = {335, 350, 365, 380, 361};
                    int slidingYList[] = {545, 530, 514, 501, 488};                 
                    
                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 10;
                    *snakeOrLadder = 2;

                    break;
                }

                if(turnPlayer2 == 1)
                {
                    int slidingXList[] = {335, 350, 365, 380, 380};
                    int slidingYList[] = {545, 530, 514, 501, 488}; 

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 10;
                    *snakeOrLadder = 2;

                    break;
                }
                if(turnPlayer3 == 1)
                {
                    int slidingXList[] = {335, 350, 365, 380, 371};
                    int slidingYList[] = {545, 530, 514, 501, 488}; 

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 10;
                    *snakeOrLadder = 2;

                    break;
                }
                if(turnPlayer4 == 1)
                {
                    int slidingXList[] = {335, 350, 365, 380, 390};
                    int slidingYList[] = {545, 530, 514, 501, 488}; 

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 10;
                    *snakeOrLadder = 2;

                    break;
                }
                break;             
            }
            case 2:
            {
                if(turnPlayer1 == 1)
                {
                    int slidingXList[] = {325, 325, 325, 325, 296};
                    int slidingYList[] = {512, 502, 481, 454, 424};  

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 20;
                    *snakeOrLadder = 2;

                    break;
                }
                if(turnPlayer2 == 1)
                {
                    int slidingXList[] = {325, 325, 325, 325, 315};
                    int slidingYList[] = {512, 502, 481, 454, 424};  

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 20;
                    *snakeOrLadder = 2;

                    break;
                }
                if(turnPlayer3 == 1)
                {
                    int slidingXList[] = {325, 325, 325, 325, 306};
                    int slidingYList[] = {512, 502, 481, 454, 424};  

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 20;
                    *snakeOrLadder = 2;

                    break;
                }
                if(turnPlayer4 == 1)
                {
                    int slidingXList[] = {325, 325, 325, 325, 325};
                    int slidingYList[] = {512, 502, 481, 454, 424};  

                    if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                    {
                        *spriteX = slidingXList[*slideCounter];
                        *spriteY = slidingYList[*slideCounter];  
                        (*slideCounter)++; 
                        
                        break; //here
                    }
                    *slideCounter = 0; //when finished
                    *changeDiceTotalBy = 20;
                    *snakeOrLadder = 2;

                    break;
                }               
            }
            break; 
        }
        case 18:      //1st snake
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {230, 245, 260, 275, 290, 297};
                int slidingYList[] = {558, 563, 569, 587, 610, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 13;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {230, 245, 260, 275, 290, 316};
                int slidingYList[] = {558, 563, 569, 587, 610, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 13;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {230, 245, 260, 275, 290, 307};
                int slidingYList[] = {558, 563, 569, 587, 610, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 13;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {230, 245, 260, 275, 290, 326};
                int slidingYList[] = {558, 563, 569, 587, 610, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 13;
                *snakeOrLadder = 1;

                break;
            }
        }
        case 20: //ladder 2
        {
            switch(ladderRotationTurn)
            {
                case 1:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {70, 70, 70, 70, 70, 70, 70, 70, 70, 41};
                        int slidingYList[] = {530, 509, 488, 466, 443, 427, 399, 369, 334, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {70, 70, 70, 70, 70, 70, 70, 70, 70, 60};
                        int slidingYList[] = {530, 509, 488, 466, 443, 427, 399, 369, 334, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {70, 70, 70, 70, 70, 70, 70, 70, 70, 51};
                        int slidingYList[] = {530, 509, 488, 466, 443, 427, 399, 369, 334, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {70, 70, 70, 70, 70, 70, 70, 70, 70, 70};
                        int slidingYList[] = {530, 509, 488, 466, 443, 427, 399, 369, 334, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
                case 2: 
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {105, 126, 148, 167, 185, 205, 127, 241, 231};
                        int slidingYList[] = {540, 520, 486, 468, 448, 426, 405, 385, 365};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 24;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {105, 126, 148, 167, 185, 205, 127, 241, 250};
                        int slidingYList[] = {540, 520, 486, 468, 448, 426, 405, 385, 365};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 24;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {105, 126, 148, 167, 185, 205, 127, 241, 241};
                        int slidingYList[] = {540, 520, 486, 468, 448, 426, 405, 385, 365};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 24;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {105, 126, 148, 167, 185, 205, 127, 241, 260};
                        int slidingYList[] = {540, 520, 486, 468, 448, 426, 405, 385, 365};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 24;
                        *snakeOrLadder = 2;

                        break;
                    }                   
                }
            }
            break;
        }
        case 23: //ladder 3
        {
            switch(ladderRotationTurn)
            {
                case 1:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {215, 225, 235, 245, 255, 236};
                        int slidingYList[] = {455, 435, 425, 417, 384, 364};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {215, 225, 235, 245, 255, 255};
                        int slidingYList[] = {455, 435, 425, 417, 384, 364};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {215, 225, 235, 245, 255, 246};
                        int slidingYList[] = {455, 435, 425, 417, 384, 364};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {215, 225, 235, 245, 255, 265};
                        int slidingYList[] = {455, 435, 425, 417, 384, 364};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
                case 2:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {185, 166, 150, 140, 102};
                        int slidingYList[] = {463, 418, 368, 333, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                            {
                                *spriteX = slidingXList[*slideCounter];
                                *spriteY = slidingYList[*slideCounter];  
                                (*slideCounter)++; 
                                
                                break; //here
                            }
                            *slideCounter = 0; //when finished
                            *changeDiceTotalBy = 36;
                            *snakeOrLadder = 2;

                            break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {185, 166, 150, 140, 121};
                        int slidingYList[] = {463, 418, 368, 333, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                            {
                                *spriteX = slidingXList[*slideCounter];
                                *spriteY = slidingYList[*slideCounter];  
                                (*slideCounter)++; 
                                
                                break; //here
                            }
                            *slideCounter = 0; //when finished
                            *changeDiceTotalBy = 36;
                            *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {185, 166, 150, 140, 112};
                        int slidingYList[] = {463, 418, 368, 333, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                            {
                                *spriteX = slidingXList[*slideCounter];
                                *spriteY = slidingYList[*slideCounter];  
                                (*slideCounter)++; 
                                
                                break; //here
                            }
                            *slideCounter = 0; //when finished
                            *changeDiceTotalBy = 36;
                            *snakeOrLadder = 2;

                            break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[]= {185, 166, 150, 140, 131};
                        int slidingYList[] = {463, 418, 368, 333, 302};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                            {
                                *spriteX = slidingXList[*slideCounter];
                                *spriteY = slidingYList[*slideCounter];  
                                (*slideCounter)++; 
                                
                                break; //here
                            }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 36;
                        *snakeOrLadder = 2;

                        break;
                    }
                }                 
            }
            break;
        }
        case 27:  //ladder 4
        {
            switch(ladderRotationTurn)
            {
                case 1: //20-60 start
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {455, 455, 455, 455, 455, 455, 426};
                        int slidingYList[] = {468, 450, 430, 420, 413, 497, 358};   //468, 450, 430, 420, 413, 497, 363

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {455, 455, 455, 455, 455, 455, 445};
                        int slidingYList[] = {468, 450, 430, 420, 413, 497, 358};   //468, 450, 430, 420, 413, 497, 363

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {455, 455, 455, 455, 455, 455, 436};
                        int slidingYList[] = {468, 450, 430, 420, 413, 497, 358};   //468, 450, 430, 420, 413, 497, 363

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {455, 455, 455, 455, 455, 455, 455};
                        int slidingYList[] = {468, 450, 430, 420, 413, 497, 358};   //468, 450, 430, 420, 413, 497, 363

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    } 
                }
                case 2:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {464, 471, 483, 491, 502, 508, 491};
                        int slidingYList[] = {460, 435, 405, 382, 376, 332, 305};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {464, 471, 483, 491, 502, 508, 510};
                        int slidingYList[] = {460, 435, 405, 382, 376, 332, 305};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {464, 471, 483, 491, 502, 508, 501};
                        int slidingYList[] = {460, 435, 405, 382, 376, 332, 305};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {464, 471, 483, 491, 502, 508, 520};
                        int slidingYList[] = {460, 435, 405, 382, 376, 332, 305};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                } 
            }
            break;
        }
        case 29: //snake 2
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {625, 630, 626, 620, 606, 575, 545, 489};
                int slidingYList[] = {497, 520, 525, 550, 565, 580, 585, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {625, 630, 626, 620, 606, 575, 545, 508};
                int slidingYList[] = {497, 520, 525, 550, 565, 580, 585, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {625, 630, 626, 620, 606, 575, 545, 499};
                int slidingYList[] = {497, 520, 525, 550, 565, 580, 585, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;

                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {625, 630, 626, 620, 606, 575, 545, 518};
                int slidingYList[] = {497, 520, 525, 550, 565, 580, 585, 620};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                        
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;

                break;
            }         
        }
        case 50: //ladder 5
        {
            switch(ladderRotationTurn)
            {
                case 1:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {627, 621, 612, 603, 598, 556};
                        int slidingYList[] = {328, 312, 3294, 278, 263, 233};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 19;     //ändrat till 19!
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {627, 621, 612, 603, 598, 575};
                        int slidingYList[] = {328, 312, 3294, 278, 263, 233};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 19;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {627, 621, 612, 603, 598, 566};
                        int slidingYList[] = {328, 312, 3294, 278, 263, 233};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 19;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {627, 621, 612, 603, 598, 585};
                        int slidingYList[] = {328, 312, 3294, 278, 263, 233};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 19;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
                case 2: 
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[]= {646, 646, 646, 646, 646, 617};
                        int slidingYList[] = {323, 303, 256, 212, 178, 110};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; 
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[]= {646, 646, 646, 646, 646, 636};
                        int slidingYList[] = {323, 303, 256, 212, 178, 110};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; 
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {646, 646, 646, 646, 646, 627};
                        int slidingYList[] = {323, 303, 256, 212, 178, 110};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; 
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;

                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {646, 646, 646, 646, 646, 646};
                        int slidingYList[] = {323, 303, 256, 212, 178, 110};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; 
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 40;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
            }
            break;
        }
        case 55: //snake 3
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {380, 371, 361};
                int slidingYList[] = {340, 353, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 9;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {380, 371, 380};
                int slidingYList[] = {340, 353, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 9;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {380, 371, 371};
                int slidingYList[] = {340, 353, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 9;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {380, 371, 390};
                int slidingYList[] = {340, 353, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 9;
                *snakeOrLadder = 1;
                
                break;
            }
            break;
        }
        case 63: //snake
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {162, 146, 150, 166, 182, 169};
                int slidingYList[] = {216, 246, 279, 302, 316, 364};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 20;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {162, 146, 150, 166, 182, 188};
                int slidingYList[] = {216, 246, 279, 302, 316, 364};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 20;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {162, 146, 150, 166, 182, 179};
                int slidingYList[] = {216, 246, 279, 302, 316, 364};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 20;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {162, 146, 150, 166, 182, 198};
                int slidingYList[] = {216, 246, 279, 302, 316, 364};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 20;
                *snakeOrLadder = 1;
                
                break;
            } 
	        break;  
        }
        case 66: //ladder
        {
            switch(ladderRotationTurn)
            {
                case 1:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {394, 393, 390, 390, 361};
                        int slidingYList[] = {204, 188, 159, 142, 109};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {394, 393, 390, 390, 380};
                        int slidingYList[] = {204, 188, 159, 142, 109};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {394, 393, 390, 390, 371};
                        int slidingYList[] = {204, 188, 159, 142, 109};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {394, 393, 390, 390, 390};
                        int slidingYList[] = {204, 188, 159, 142, 109};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 20;
                        *snakeOrLadder = 2;

                        break;
                    }
                    //break;
                }
                case 2: 
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {430, 450, 490, 516, 542, 554};
                        int slidingYList[] = {202, 276, 142, 118, 91, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                                
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {430, 450, 490, 516, 542, 573};
                        int slidingYList[] = {202, 276, 142, 118, 91, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                                
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {430, 450, 490, 516, 542, 564};
                        int slidingYList[] = {202, 276, 142, 118, 91, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                                
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                         break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {430, 450, 490, 516, 542, 583};
                        int slidingYList[] = {202, 276, 142, 118, 91, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                                
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 26;
                        *snakeOrLadder = 2;

                        break;
                    }                  
                }
            }
            break;
        }
        case 76: //ladder
        {
            switch(ladderRotationTurn)
            {
                case 1:
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {310, 301, 295, 285, 280, 233};
                        int slidingYList[] = {137, 119, 105, 88, 75, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {310, 301, 295, 285, 280, 252};
                        int slidingYList[] = {137, 119, 105, 88, 75, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {310, 301, 295, 285, 280, 243};
                        int slidingYList[] = {137, 119, 105, 88, 75, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {310, 301, 295, 285, 280, 262};
                        int slidingYList[] = {137, 119, 105, 88, 75, 45};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
                case 2: 
                {
                    if(turnPlayer1 == 1)
                    {
                        int slidingXList[] = {315, 304, 197, 188, 280, 137};
                        int slidingYList[] = {146, 128, 108, 91, 74, 46};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer2 == 1)
                    {
                        int slidingXList[] = {315, 304, 197, 188, 280, 156};
                        int slidingYList[] = {146, 128, 108, 91, 74, 46};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer3 == 1)
                    {
                        int slidingXList[] = {315, 304, 197, 188, 280, 147};
                        int slidingYList[] = {146, 128, 108, 91, 74, 46};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                    if(turnPlayer4 == 1)
                    {
                        int slidingXList[] = {315, 304, 197, 188, 280, 166};
                        int slidingYList[] = {146, 128, 108, 91, 74, 46};

                        if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                        {
                            *spriteX = slidingXList[*slideCounter];
                            *spriteY = slidingYList[*slideCounter];  
                            (*slideCounter)++; 
                            
                            break; //here
                        }
                        *slideCounter = 0; //when finished
                        *changeDiceTotalBy = 21;
                        *snakeOrLadder = 2;

                        break;
                    }
                }
            }
            break;
        }
        case 83: //snake
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {158, 165, 151, 107, 110, 123, 114, 73, 53, 41};
                int slidingYList[] = {114, 154, 180, 195, 234, 274, 316, 328, 352, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 42;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {158, 165, 151, 107, 110, 123, 114, 73, 53, 60};
                int slidingYList[] = {114, 154, 180, 195, 234, 274, 316, 328, 352, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 42;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {158, 165, 151, 107, 110, 123, 114, 73, 53, 51};
                int slidingYList[] = {114, 154, 180, 195, 234, 274, 316, 328, 352, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 42;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {158, 165, 151, 107, 110, 123, 114, 73, 53, 70};
                int slidingYList[] = {114, 154, 180, 195, 234, 274, 316, 328, 352, 365};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 42;
                *snakeOrLadder = 1;
                
                break;
            }
            break;
        }
        case 89: //snake
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {590, 566, 539, 500, 489};
                int slidingYList[] = {153, 166, 175, 191, 240};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {590, 566, 539, 500, 508};
                int slidingYList[] = {153, 166, 175, 191, 240};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {590, 566, 539, 500, 499};
                int slidingYList[] = {153, 166, 175, 191, 240};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {590, 566, 539, 500, 518};
                int slidingYList[] = {153, 166, 175, 191, 240};

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 21;
                *snakeOrLadder = 1;
                
                break;
            }
            break;
        }
        case 99: //snake
        {
            if(turnPlayer1 == 1)
            {
                int slidingXList[] = {188, 195, 220, 249, 269, 266, 262, 293, 325, 346, 297};
                int slidingYList[] = {32, 68, 101, 103, 143, 171, 212, 237, 241, 266, 301}; //32, 68, 101, 103, 143, 171, 212, 237, 241, 266, 311

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 43; 
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer2 == 1)
            {
                int slidingXList[] = {188, 195, 220, 249, 269, 266, 262, 293, 325, 346, 316};
                int slidingYList[] = {32, 68, 101, 103, 143, 171, 212, 237, 241, 266, 301}; 

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 43; 
                *snakeOrLadder = 1;
                
                break;
            }
            if(turnPlayer3 == 1)
            {
                int slidingXList[] = {188, 195, 220, 249, 269, 266, 262, 293, 325, 346, 307};
                int slidingYList[] = {32, 68, 101, 103, 143, 171, 212, 237, 241, 266, 301}; 

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 43; 
                *snakeOrLadder = 1;     

                break;
            }
            if(turnPlayer4 == 1)
            {
                int slidingXList[] = {188, 195, 220, 249, 269, 266, 262, 293, 325, 346, 326};
                int slidingYList[] = {32, 68, 101, 103, 143, 171, 212, 237, 241, 266, 301};         

                if (*slideCounter < sizeof(slidingXList)/sizeof(slidingXList[0]))
                {
                    *spriteX = slidingXList[*slideCounter];
                    *spriteY = slidingYList[*slideCounter];  
                    (*slideCounter)++; 
                            
                    break; //here
                }
                *slideCounter = 0; //when finished
                *changeDiceTotalBy = 43; 
                *snakeOrLadder = 1;
                
                break;
            } 
            break;        
        }
    }
}
