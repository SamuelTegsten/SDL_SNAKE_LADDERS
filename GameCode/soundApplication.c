#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include "application.h"
#include "soundApplication.h"
#include "renderStart.h"

#define PUBLIC /* empty */
#define PRIVATE static

PRIVATE int startMusic = 0;
PRIVATE int closeMusic = 0;

void soundApplication(int onOrOff, int soundChoise)
{
	//Init variabel effect and background music
	Mix_Chunk* effect1;
	Mix_Chunk* effect2;
	Mix_Chunk* effect3;
	Mix_Chunk* effect4;
	Mix_Chunk* effect5;
	Mix_Chunk* effect6;
	Mix_Chunk* effect7;
	Mix_Chunk* effect8;
	Mix_Music* music;

	//Init SDL_MIX
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
	music = Mix_LoadMUS("resources/soundtrack.mp3");
	effect1 = Mix_LoadWAV("resources/click.mp3");
	effect2 = Mix_LoadWAV("resources/keyboard.mp3");
	effect3 = Mix_LoadWAV("resources/dice.mp3");
	effect4 = Mix_LoadWAV("resources/snake.mp3");
	effect5 = Mix_LoadWAV("resources/ladder.mp3");
	effect6 = Mix_LoadWAV("resources/footstep.mp3");
	effect7 = Mix_LoadWAV("resources/winning.mp3");
	effect8 = Mix_LoadWAV("resources/startButton.mp3");

	Mix_VolumeMusic(10); //Volume of music 10/128
	Mix_VolumeChunk(effect8, 32);  //Volume of start button
	Mix_VolumeChunk(effect6, 64); //Volume of footsteps 64/128
	Mix_VolumeChunk(effect5, 64); //Volume of ladder 64/128
	Mix_VolumeChunk(effect4, 128); //Volume of snake 128/128
	Mix_VolumeChunk(effect3, 128); //Volume of dice 128/128

	//Starting Background music
	if (onOrOff == 0)
	{
		if (startMusic == 0)
		{
			Mix_PlayMusic(music, -1);
			startMusic = 1;
		}
	}

	//if a click make clicksound
	if (soundChoise == 1)
	{
		Mix_PlayChannel(-1, effect1, 0);
		soundChoise = 0;
	}

	//if typing make typing sound
	if (soundChoise == 2)
	{
		Mix_PlayChannel(-1, effect2, 0);
		soundChoise = 0;
	}

	//if rolling dice make rolling sound
	if (soundChoise == 3)
	{
		Mix_PlayChannel(-1, effect3, 0);
		soundChoise = 0;
	}

	//if rolling on snake make hissing sound
	if (soundChoise == 4)
	{
		Mix_PlayChannel(-1, effect4, 0);
		soundChoise = 0;
	}

	//if rolling on ladder make ladder sound
	if (soundChoise == 5)
	{
		Mix_PlayChannel(-1, effect5, 0);
		soundChoise = 0;
	}

	//if walking on board make walking sound
	if (soundChoise == 6)
	{
		Mix_PlayChannel(-1, effect6, 0);
		soundChoise = 0;
	}

	//if won play winning music
	if (soundChoise == 7)
	{
		Mix_PlayChannel(-1, effect7, 0);
		soundChoise = 0;
	}
	//if start button
	if (soundChoise == 8)
	{
		Mix_PlayChannel(-1, effect8, 0);
		soundChoise = 0;
	}

	//Close SDL MIX and free bytes
	if (onOrOff == 1)
	{
		Mix_FreeChunk(effect1);
		Mix_FreeChunk(effect2);
		Mix_FreeChunk(effect3);
		Mix_FreeChunk(effect4);
		Mix_FreeChunk(effect5);
		Mix_FreeChunk(effect6);
		Mix_FreeChunk(effect7);
		Mix_FreeChunk(effect8);
		Mix_FreeMusic(music);
		while (closeMusic < 500)
		{
			Mix_CloseAudio();
			closeMusic++;
		}
		closeMusic = 0;
		onOrOff = 0;
		startMusic = 0;
	}
}
