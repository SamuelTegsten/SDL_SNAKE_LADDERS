#ifndef renderStart_h   /* Include guard */
#define renderStart_h

/*
* Copy the loaded texture from startingScreen 
* Load the texture upon the window
* Destroy textures/window/renderer upon exit
*/

void copyTexture(int startValue, SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex2, SDL_Texture* tex3, SDL_Texture* tex4, SDL_Texture* tex5, SDL_Texture* tex6);

#endif
