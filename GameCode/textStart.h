#ifndef textStart_h   /* Include guard */
#define textStart_h
/*
* Initiate textinput and import c files to c++ text-reader
* Return textinput after pressing enter
* Render text upon ipAdressHost window on screen
*/
const char* textStart(SDL_Event event, SDL_Renderer* rend, SDL_Window* win, int *backspace, int *eraseText);
#endif 
