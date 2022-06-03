#ifndef mapMovement_h
#define mapMovement_h

void squareMoving(int diceRoll, int positionOnBoard, int *currentCoordinateX, int *currentCoordinateY);

#endif


//NOTES!!

/* #Varje färgad ruta är 57x57 där ramarna utgör 10 pixlar, vilket lägger ett hop på 64 pixlar från mitt till mitt. 
57/2 = 28.5 (men vi kan inte gå en halv pixel så jag rundar ner) 28 x 2  = 56 + 10 = 66 (66 blir ojämt så jag rundade ner och såg att 64 var perfekt)

DestinationLeft & DestinationRight utgör om man går mot höger vänster då de alterneras på brädan.

10 > 20 > 30 etc är när man befinner sig på en ruta som kräver att man hoppar upp. 11/21/31/41 är riktningar V/H. 

Denna funktion hanterar ej speciella rutor.

*/ 