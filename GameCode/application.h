#ifndef application_h
#define application_h

/*
* Load the application after initalization of the starting screen
* Initiate SDL & load the tiles/sprites in struct Application
* Update the game upon call of applicationUpdate
* Destroy window/renderer/textures upon call of destroyApplication
*/


typedef struct Application_type* Application;

Application createApplication();
void applicationUpdate(Application theApp, int playerCount);
void destoryApplication(Application theApp);

#endif
