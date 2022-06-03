#ifndef soundApplication_h   /* Include guard */
#define soundApplication_h

/*
* Init SDL mixer lib
* First input for on or off: 0 is sound is on, 1 is sound is off
* Secound input to choose what plays, 0 to activate background music
* 1 for clicking sound
* 2 for typing sound
* 3 for dice sound
* 4 for snake sound
* 5 for ladder sound
* 6 for walking sound
*/

void soundApplication(int onOrOff, int soundChoise);

#endif 