#ifndef mouseApplication_h
#define mouseApplication_h

/*
* Return mouse position in cmd as x and y coordinates
* Makes returning a specific value if pressed within specific coordinates
* - example: startGame = 1 if pressed within x- x+ y- y+ -
*/

void mouseApplication(int* mouseReturn, int *close_requested);

#endif
