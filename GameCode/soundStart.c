#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include "startingScreen.h"
#include "soundStart.h"
#include "renderStart.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int startMusic = 0;
PRIVATE int closeMusic = 0;

void soundAndMusic(int closeAudio, int clickSound)
{
	//Init variabel effect and background music
	Mix_Chunk* effect1;
	Mix_Chunk* effect2;
	Mix_Music* music;

	//Init SDL_MIX
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("resources/soundtrack.mp3");
	effect1 = Mix_LoadWAV("resources/click.mp3");
	effect2 = Mix_LoadWAV("resources/keyboard.mp3");

	//Set Volume to 20/164
	Mix_VolumeMusic(10);

	//Starting Background music
	if (closeAudio == 0)
	{
		if (startMusic == 0)
		{
			Mix_PlayMusic(music, -1);
			startMusic = 1;
		}
	}

	//if a click make clicksound
	if (clickSound == 1)
	{
		Mix_PlayChannel(-1, effect1, 0);
		clickSound = 0;
	}

	//if typing make typing sound
	if (clickSound == 2)
	{
		Mix_PlayChannel(-1, effect2, 0);
		clickSound = 0;
	}

	//Close SDL MIX and free bytes
	if(closeAudio == 1)
	{ 
		Mix_FreeChunk(effect1);
		Mix_FreeChunk(effect2);
		Mix_FreeMusic(music);
		while (closeMusic < 500)
		{
			Mix_CloseAudio();
			closeMusic++;
		}
		closeMusic = 0;
		closeAudio = 0;
		startMusic = 0;
	}
}