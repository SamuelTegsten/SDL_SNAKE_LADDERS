#include <SDL.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include "mouse.h"
#include "renderStart.h"
#include "textStart.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int copyChoise;

//copy current image upon window
void copyTexture(int startValue, SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex2, SDL_Texture* tex3, SDL_Texture* tex4, SDL_Texture* tex5, SDL_Texture* tex6)
{
    copyChoise = startValue;

    //1:st Texture
    if (copyChoise == 0)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex, NULL, 0);
        SDL_RenderPresent(rend);
    }

    //2:nd Texture
    if (copyChoise == 1)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex2, NULL, 0);
        SDL_RenderPresent(rend);
    }

    //Destroy all textures/renderer/window & quit
    if (copyChoise == 2)
    {
        SDL_DestroyTexture(tex);
        SDL_DestroyTexture(tex2);
        SDL_DestroyTexture(tex3);
        SDL_DestroyTexture(tex4);
        SDL_DestroyTexture(tex5);
        SDL_DestroyTexture(tex6);
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
        TTF_Quit();
        SDL_Quit();
    }

    //3:rd Texture
    if (copyChoise == 3)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex3, NULL, 0);
        SDL_RenderPresent(rend);
    }

    //Destroy all textures/renderer/window & not quit
    if (copyChoise == 4)
    {
        SDL_DestroyTexture(tex);
        SDL_DestroyTexture(tex2);
        SDL_DestroyTexture(tex3);
        SDL_DestroyTexture(tex4);
        SDL_DestroyTexture(tex5);
        SDL_DestroyTexture(tex6);
        SDL_DestroyRenderer(rend);
        SDL_DestroyWindow(win);
    }

    //4:th Texture
    if (copyChoise == 5)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex4, NULL, 0);
        SDL_RenderPresent(rend);
    }

    //5:th Texture
    if (copyChoise == 6)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex5, NULL, 0);
        SDL_RenderPresent(rend);
    }

    //Render loop for writing text
    if (copyChoise == 7)
    {
        SDL_RenderPresent(rend);
    }

    //if backspace button is pressed after writing text update window
    if (copyChoise == 8)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex5, NULL, 0);
        SDL_RenderPresent(rend);
    }
    //render loading screen
    if (copyChoise == 9)
    {
        SDL_RenderClear(rend);
        SDL_RenderCopy(rend, tex6, NULL, 0);
        SDL_RenderPresent(rend);
    }
}