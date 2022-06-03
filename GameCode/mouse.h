#ifndef mouse_h   /* Include guard */
#define mouse_h

/* 
* Get mouse position on screen
* Click with left mouse button
* Choose the alternatives on the starting screen
*/

int mousePosition(int *ipTextEnable, int *soundOnOrOff, int *nrOfPlayers, int* eraseText, SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex2, SDL_Texture* tex3, SDL_Texture* tex4, SDL_Texture* tex5, SDL_Texture* tex6);

#endif 