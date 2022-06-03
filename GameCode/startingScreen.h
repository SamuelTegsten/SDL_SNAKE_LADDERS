#ifndef startingScreen_h   /* Include guard */
#define startingScreen_h

/*
* Initiate SDL and create a starting screen
* Initiate function mouse to choose the alternative options
* Initate function renderStart to load the image to the window & destroy upon full use
* Initate function textStart in order to enter the ipAdress of the host
* Return number of players and ipAdress input to main for future use in game application
*/

const char * startingScreen(int *playerCount);

#endif
