#ifndef spriteMovementOnSnakeLadder_h  
#define spriteMovementOnSnakeLadder_h

void snakeLadderSlide(int currentPositionOnBoard, int *spriteX, int *spriteY, int *slideCounter, int ladderRotationTurn, int *changeDiceTotalBy, int *snakeOrLadder, int turnPlayer1, int turnPlayer2, int turnPlayer3, int turnPlayer4);

#endif


/*DEFINTIONER & FÖRKLARING
- case(ladderRotationTurn) är en switch för vilken rotation stegarna är i! 1 (start state) 2 (roteringen)
- *slideCounter är en ptr du skickar med till funktionen som håller koll på hur vart den är i koordinaternas arrayer, den ska räkna uppot inom game loopen
när den  == 0 så slutar draw. 
- koordinaterna börjar INTE från start punkt, dvs första koordinatparet är ett hopp


När funktionen ska kallas:

theApp->sprite_position1.x = spriteX; etc

>>>RÄKNA NER DICE TOTAL & STEP PLAYER! && håll koll på vad vi är. 
    

!!!!Du må märka att funktionen är väldigt upprepade, ja det är den MEN det går ej att göra på annat sätt som är
lika läsbart som detta om jag inte vill använda array adresser. 

*/
