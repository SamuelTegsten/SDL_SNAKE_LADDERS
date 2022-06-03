#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL_timer.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <stdlib.h>
#include <string.h>
#include "application.h"
#include "soundApplication.h"
#include <SDL_image.h>
#include "mouseApplication.h"
#include "textView.h"
#include "dice.h"
#include "playerTurn.h"
#include "spriteMoving.h"
#include "mapMovement.h"
#include "diceTotal.h"
#include "spriteMovementOnSnakeLadder.h"

//The flags to be sent to the server
#define FLAG_QUIT 0X01
#define FLAG_START 0X02
#define FLAG_ROLL 0X03
#define FLAG_ROLL_DICE1 0X04
#define FLAG_ROLL_DICE2 0X05
#define FLAG_INDEX 0x06
#define FLAG_CHOICE 0x07
#define FLAG_COLOUR1 0X08
#define FLAG_COLOUR2 0X09
#define FLAG_COLOUR3 0XA
#define FLAG_COLOUR4 0xB

//Public for availability in main and application
//Private for internal availability
#define PUBLIC /* empty */
#define PRIVATE static  

//Defined the maximum size for the data beeing sent and processed
#define MAX_PACKET 0xFF

//Screen dimensions
#define WINDOWWIDTH 1280
#define WINDOWHIEGHT 720

//Game struct
struct Application_type {
    SDL_Window* window;
    SDL_Surface* window_surface;

    //Event for gameloop
    SDL_Event window_event;

    //The renderer for the textures
    SDL_Renderer* rend;

    //All Surfaces to be read upon a texture
    SDL_Surface* image1;
    SDL_Surface* spriteChoose;
    SDL_Surface* sprite1;
    SDL_Surface* sprite2;
    SDL_Surface* sprite3;
    SDL_Surface* sprite4;
    //dices
    SDL_Surface* dice1;
    SDL_Surface* dice2;
    SDL_Surface* dice3;
    SDL_Surface* dice4;
    SDL_Surface* dice5;
    SDL_Surface* dice6;
    //ladders
    SDL_Surface* ladder1;
    SDL_Surface* ladder2;
    SDL_Surface* ladder3;
    SDL_Surface* ladder4;
    SDL_Surface* ladder5;
    SDL_Surface* ladder6;
    SDL_Surface* ladder7;
    //buttons
    SDL_Surface* buttonRoll;
    SDL_Surface* buttonStart;
    //sound buttons
    SDL_Surface* soundOn;
    SDL_Surface* soundOff;
    //winscreen for every player
    SDL_Surface* winScreen1;
    SDL_Surface* winScreen2;
    SDL_Surface* winScreen3;
    SDL_Surface* winScreen4;
    //who is wishing to start
    SDL_Surface* online1;
    SDL_Surface* online2;
    SDL_Surface* online3;
    SDL_Surface* online4;
    SDL_Surface* online5;
    //who is which player
    SDL_Surface* player1;
    SDL_Surface* player2;
    SDL_Surface* player3;
    SDL_Surface* player4;
    SDL_Surface* checkmark;

    //The rectangles that defines position for the textures
    SDL_Rect sprite_position1;
    SDL_Rect sprite_position2;
    SDL_Rect sprite_position3;
    SDL_Rect sprite_position4;
    //dice positions
    SDL_Rect diceposition1;
    SDL_Rect diceposition2;
     //who should roll the dice
    SDL_Surface* player1roll;       //tillagd!!
    SDL_Surface* player2roll;
    SDL_Surface* player3roll;
    SDL_Surface* player4roll;
    //All ladder/rotating ladders positions
    SDL_Rect ladder_position1;
    SDL_Rect ladder_position1_rotated;
    SDL_Rect ladder_position2;
    SDL_Rect ladder_position2_rotated;
    SDL_Rect ladder_position3;
    SDL_Rect ladder_position3_rotated;
    SDL_Rect ladder_position4;
    SDL_Rect ladder_position4_rotated;
    SDL_Rect ladder_position5;
    SDL_Rect ladder_position5_rotated;
    SDL_Rect ladder_position6;
    SDL_Rect ladder_position6_rotated;
    SDL_Rect ladder_position7;
    SDL_Rect ladder_position7_rotated;
    //the button positions
    SDL_Rect buttonposition1;
    SDL_Rect buttonposition2;
    //sound button positions
    SDL_Rect soundonposition;
    SDL_Rect soundoffposition;
    //dice roll turn position
    SDL_Rect diceTurnPos;       //tillagd!!
    //win screen position
    SDL_Rect winPosition;
    //Server data positions
    SDL_Rect onlinePos;
    SDL_Rect playerPos;
    //checkmark for choice of player sprite
    SDL_Rect chackmarkPos1;
    SDL_Rect chackmarkPos2;
    SDL_Rect chackmarkPos3;
    SDL_Rect chackmarkPos4;

    //The textures that the renderer has loaded surface upon surface
    SDL_Texture* board;
    SDL_Texture* choose_texture;
    SDL_Texture* sprite_texture1;
    SDL_Texture* sprite_texture2;
    SDL_Texture* sprite_texture3;
    SDL_Texture* sprite_texture4;
    //dices
    SDL_Texture* diceTexture1;
    SDL_Texture* diceTexture2;
    SDL_Texture* diceTexture3;
    SDL_Texture* diceTexture4;
    SDL_Texture* diceTexture5;
    SDL_Texture* diceTexture6;
    //the ladder
    SDL_Texture* ladderTexture;
    //buttons
    SDL_Texture* buttonTexture1;
    SDL_Texture* buttonTexture2;
    //sound button
    SDL_Texture* soundOnTexture;
    SDL_Texture* soundOffTexture;
    //winscreen
    SDL_Texture* winTexture1;
    SDL_Texture* winTexture2;
    SDL_Texture* winTexture3;
    SDL_Texture* winTexture4;
    //nr of logged in players
    SDL_Texture* onlineTex1;
    SDL_Texture* onlineTex2;
    SDL_Texture* onlineTex3;
    SDL_Texture* onlineTex4;
    SDL_Texture* onlineTex5;
    //id for each player
    SDL_Texture* playerTex1;
    SDL_Texture* playerTex2;
    SDL_Texture* playerTex3;
    SDL_Texture* playerTex4;
    //dice roll turn
    SDL_Texture* diceRollTurn1tex;          //tillagd!!
    SDL_Texture* diceRollTurn2tex;      
    SDL_Texture* diceRollTurn3tex;
    SDL_Texture* diceRollTurn4tex;
    SDL_Texture* checkmarkTex;

    //Client SDL NET 
    IPaddress ip;
    TCPsocket socket;
    SDLNet_SocketSet socket_set;

    //All server packets beeing checked
    int sumOfStarts;
    int sumOfChoices;
    int closeWindows;
    int roll;
    int diceOnline1;
    int diceOnline2;
    int playerID;
    int colour;
    int playerColour1;
    int playerColour2;
    int playerColour3;
    int playerColour4;
};

PRIVATE void draw(Application theApp, int playerCount, int* soundOnOrOff, int* dice1, int* dice2, int totalRounds, int turnPlayer1, int turnPlayer2, int turnPlayer3, int turnPlayer4, int timer, int readyToStart, int* endChoice, int* startFlip, int* diceRollFlip, int player1Win, int player2Win, int player3Win, int player4Win);
PRIVATE void InitNetwork(const char* ipHostAddress, Application theApp);
PUBLIC void SendData(uint8_t* data, uint16_t length, uint16_t flag, Application theApp);
PUBLIC uint8_t* RecvData(uint16_t* length, Application theApp);
PRIVATE void ProcessData(uint8_t* data, uint16_t* offset, Application theApp);
PRIVATE void CloseSocket(Application theApp);
PUBLIC bool CheckSocket(Application theApp);

PUBLIC Application createApplication(const char* ipHostAddress)
{
    Application s = malloc(sizeof(struct Application_type));
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Failed to initialize the SDL2 library\n");
    }

    s->window = SDL_CreateWindow("Snakes & Ladders",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOWWIDTH, WINDOWHIEGHT,
        0);

    InitNetwork(ipHostAddress, s); //Init SDL_Net and connecting to given ip + port


    if (!s->window)
    {
        printf("Failed to create window\n");
        SDL_Quit();
    }

    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    s->rend = SDL_CreateRenderer(s->window, -1, render_flags);

    if (!s->rend)
    {
        printf("Error creating renderer\n");
        SDL_DestroyWindow(s->window);
        SDL_Quit();
    }
    s->image1 = IMG_Load("resources/board_Correct_size.png");
    s->spriteChoose = IMG_Load("resources/chooseSprite_2.png");
    s->sprite1 = IMG_Load("resources/piece_1.png");
    s->sprite2 = IMG_Load("resources/piece_2_black.png");
    s->sprite3 = IMG_Load("resources/piece_3_blue.png");
    s->sprite4 = IMG_Load("resources/piece_4_yellow.png");
    s->dice1 = IMG_Load("resources/dice_1.png");
    s->dice2 = IMG_Load("resources/dice_2.png");
    s->dice3 = IMG_Load("resources/dice_3.png");
    s->dice4 = IMG_Load("resources/dice_4.png");
    s->dice5 = IMG_Load("resources/dice_5.png");
    s->dice6 = IMG_Load("resources/dice_6.png");
    s->ladder1 = IMG_Load("resources/ladder.png");
    s->ladder2 = IMG_Load("resources/ladder.png");
    s->ladder3 = IMG_Load("resources/ladder.png");
    s->ladder4 = IMG_Load("resources/ladder.png");
    s->ladder5 = IMG_Load("resources/ladder.png");
    s->ladder6 = IMG_Load("resources/ladder.png");
    s->ladder7 = IMG_Load("resources/ladder.png");
    s->buttonRoll = IMG_Load("resources/Button_roll.png");
    s->buttonStart = IMG_Load("resources/Button_start.png");
    s->soundOn = IMG_Load("resources/soundOn.png");
    s->soundOff = IMG_Load("resources/soundOff.png");
    s->winScreen1 = IMG_Load("resources/Winscreen_1.png");
    s->winScreen2 = IMG_Load("resources/Winscreen_2.png");
    s->winScreen3 = IMG_Load("resources/Winscreen_3.png");
    s->winScreen4 = IMG_Load("resources/Winscreen_4.png");
    s->online1 = IMG_Load("resources/0_online.png");
    s->online2 = IMG_Load("resources/1_online.png");
    s->online3 = IMG_Load("resources/2_online.png");
    s->online4 = IMG_Load("resources/3_online.png");
    s->online5 = IMG_Load("resources/4_online.png");
    s->player1 = IMG_Load("resources/player_1.png");
    s->player2 = IMG_Load("resources/player_2.png");
    s->player3 = IMG_Load("resources/player_3.png");
    s->player4 = IMG_Load("resources/player_4.png");
    s->player1roll = IMG_Load("resources/pr1.png");                 //tillagd!!
    s->player2roll = IMG_Load("resources/p2r.png");
    s->player3roll = IMG_Load("resources/p3r.png");
    s->player4roll = IMG_Load("resources/p4r.png");
    s->checkmark = IMG_Load("resources/checkmark.png");


    if (!s->image1 || !s->sprite1 || !s->sprite2 || !s->sprite3 || !s->sprite4 || !s->dice1 || !s->dice2 || !s->dice3 || !s->dice4 || !s->dice5 || !s->dice6)
    {
        printf("Failed to load image\n");
        SDL_DestroyWindow(s->window);
        SDL_Quit();
    }

    //Load images data into memory
    s->sprite_texture1 = SDL_CreateTextureFromSurface(s->rend, s->sprite1);
    SDL_FreeSurface(s->sprite1);
    s->sprite_texture2 = SDL_CreateTextureFromSurface(s->rend, s->sprite2);
    SDL_FreeSurface(s->sprite2);
    s->sprite_texture3 = SDL_CreateTextureFromSurface(s->rend, s->sprite3);
    SDL_FreeSurface(s->sprite3);
    s->sprite_texture4 = SDL_CreateTextureFromSurface(s->rend, s->sprite4);
    SDL_FreeSurface(s->sprite4);
    s->board = SDL_CreateTextureFromSurface(s->rend, s->image1);
    SDL_FreeSurface(s->image1);
    s->diceTexture1 = SDL_CreateTextureFromSurface(s->rend, s->dice1);
    SDL_FreeSurface(s->dice1);
    s->diceTexture2 = SDL_CreateTextureFromSurface(s->rend, s->dice2);
    SDL_FreeSurface(s->dice2);
    s->diceTexture3 = SDL_CreateTextureFromSurface(s->rend, s->dice3);
    SDL_FreeSurface(s->dice3);
    s->diceTexture4 = SDL_CreateTextureFromSurface(s->rend, s->dice4);
    SDL_FreeSurface(s->dice4);
    s->diceTexture5 = SDL_CreateTextureFromSurface(s->rend, s->dice5);
    SDL_FreeSurface(s->dice5);
    s->diceTexture6 = SDL_CreateTextureFromSurface(s->rend, s->dice6);
    SDL_FreeSurface(s->dice6);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder1);
    SDL_FreeSurface(s->ladder1);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder2);
    SDL_FreeSurface(s->ladder2);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder3);
    SDL_FreeSurface(s->ladder3);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder4);
    SDL_FreeSurface(s->ladder4);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder5);
    SDL_FreeSurface(s->ladder5);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder6);
    SDL_FreeSurface(s->ladder6);
    s->ladderTexture = SDL_CreateTextureFromSurface(s->rend, s->ladder7);
    SDL_FreeSurface(s->ladder7);
    s->buttonTexture1 = SDL_CreateTextureFromSurface(s->rend, s->buttonRoll);
    SDL_FreeSurface(s->buttonRoll);
    s->buttonTexture2 = SDL_CreateTextureFromSurface(s->rend, s->buttonStart);
    SDL_FreeSurface(s->buttonStart);
    s->soundOnTexture = SDL_CreateTextureFromSurface(s->rend, s->soundOn);
    SDL_FreeSurface(s->soundOn);
    s->soundOffTexture = SDL_CreateTextureFromSurface(s->rend, s->soundOff);
    SDL_FreeSurface(s->soundOff);
    s->winTexture1 = SDL_CreateTextureFromSurface(s->rend, s->winScreen1);
    SDL_FreeSurface(s->winScreen1);
    s->winTexture2 = SDL_CreateTextureFromSurface(s->rend, s->winScreen2);
    SDL_FreeSurface(s->winScreen2);
    s->winTexture3 = SDL_CreateTextureFromSurface(s->rend, s->winScreen3);
    SDL_FreeSurface(s->winScreen3);
    s->winTexture4 = SDL_CreateTextureFromSurface(s->rend, s->winScreen4);
    SDL_FreeSurface(s->winScreen4);
    s->onlineTex1 = SDL_CreateTextureFromSurface(s->rend, s->online1);
    SDL_FreeSurface(s->online1);
    s->onlineTex2 = SDL_CreateTextureFromSurface(s->rend, s->online2);
    SDL_FreeSurface(s->online2);
    s->onlineTex3 = SDL_CreateTextureFromSurface(s->rend, s->online3);
    SDL_FreeSurface(s->online3);
    s->onlineTex4 = SDL_CreateTextureFromSurface(s->rend, s->online4);
    SDL_FreeSurface(s->online4);
    s->onlineTex5 = SDL_CreateTextureFromSurface(s->rend, s->online5);
    SDL_FreeSurface(s->online5);
    s->playerTex1 = SDL_CreateTextureFromSurface(s->rend, s->player1);
    SDL_FreeSurface(s->player1);
    s->playerTex2 = SDL_CreateTextureFromSurface(s->rend, s->player2);
    SDL_FreeSurface(s->player2);
    s->playerTex3 = SDL_CreateTextureFromSurface(s->rend, s->player3);
    SDL_FreeSurface(s->player3);
    s->playerTex4 = SDL_CreateTextureFromSurface(s->rend, s->player4);
    SDL_FreeSurface(s->player4);
    s->diceRollTurn1tex = SDL_CreateTextureFromSurface(s->rend, s->player1roll);        //tillagd!!
    SDL_FreeSurface(s->player1roll);
    s->diceRollTurn2tex = SDL_CreateTextureFromSurface(s->rend, s->player2roll);
    SDL_FreeSurface(s->player2roll);
    s->diceRollTurn3tex = SDL_CreateTextureFromSurface(s->rend, s->player3roll);
    SDL_FreeSurface(s->player3roll);
    s->diceRollTurn4tex = SDL_CreateTextureFromSurface(s->rend, s->player4roll);
    SDL_FreeSurface(s->player4roll);
    s->choose_texture = SDL_CreateTextureFromSurface(s->rend, s->spriteChoose);
    SDL_FreeSurface(s->spriteChoose);
    s->checkmarkTex = SDL_CreateTextureFromSurface(s->rend, s->checkmark);
    SDL_FreeSurface(s->checkmark);


    if (!s->sprite_texture1 || !s->sprite_texture2 || !s->sprite_texture3 || !s->sprite_texture4 || !s->diceTexture1 || !s->diceTexture2 || !s->diceTexture3 || !s->diceTexture4 || !s->diceTexture5 || !s->diceTexture6)
    {
        printf("Failed to load image\n");
        SDL_DestroyRenderer(s->rend);
        SDL_DestroyWindow(s->window);
        SDL_Quit();
    }

    //1st player
    s->sprite_position1.x = 770;
    s->sprite_position1.y = 550;
    s->sprite_position1.w = 45;
    s->sprite_position1.h = 75;

    //2nd player
    s->sprite_position2.x = 834;
    s->sprite_position2.y = 550;
    s->sprite_position2.w = 45;
    s->sprite_position2.h = 75;

    //3rd player
    s->sprite_position3.x = 898;
    s->sprite_position3.y = 550;
    s->sprite_position3.w = 45;
    s->sprite_position3.h = 75;

    //4th player
    s->sprite_position4.x = 952;
    s->sprite_position4.y = 550;
    s->sprite_position4.w = 45;
    s->sprite_position4.h = 75;

    //Dice 1
    s->diceposition1.x = 787;
    s->diceposition1.y = 248;
    s->diceposition1.w = 82;
    s->diceposition1.h = 109;

    //Dice 2
    s->diceposition2.x = 900;
    s->diceposition2.y = 248;
    s->diceposition2.w = 82;
    s->diceposition2.h = 109;

    //ladder 1
    s->ladder_position1.x = 47;
    s->ladder_position1.y = 305;
    s->ladder_position1.w = 55;
    s->ladder_position1.h = 290;

    //ladder 2
    s->ladder_position2.x = 347;
    s->ladder_position2.y = 502;
    s->ladder_position2.w = 30;
    s->ladder_position2.h = 100;

    //ladder 3
    s->ladder_position3.x = 216;
    s->ladder_position3.y = 370;
    s->ladder_position3.w = 45;
    s->ladder_position3.h = 145;

    //ladder 4
    s->ladder_position4.x = 435;
    s->ladder_position4.y = 387;
    s->ladder_position4.w = 40;
    s->ladder_position4.h = 130;

    //ladder 5
    s->ladder_position5.x = 589;
    s->ladder_position5.y = 247;
    s->ladder_position5.w = 43;
    s->ladder_position5.h = 137;

    //ladder 6
    s->ladder_position6.x = 375;
    s->ladder_position6.y = 130;
    s->ladder_position6.w = 40;
    s->ladder_position6.h = 130;

    //ladder 7
    s->ladder_position7.x = 278;
    s->ladder_position7.y = 72;
    s->ladder_position7.w = 43;
    s->ladder_position7.h = 137;

    //ladder 1 rotated
    s->ladder_position1_rotated.x = 50;
    s->ladder_position1_rotated.y = 305;
    s->ladder_position1_rotated.w = 55;
    s->ladder_position1_rotated.h = 290;

    //ladder 2 rotated
    s->ladder_position2_rotated.x = 314;
    s->ladder_position2_rotated.y = 455;
    s->ladder_position2_rotated.w = 30;
    s->ladder_position2_rotated.h = 130;

    //ladder 3 rotated
    s->ladder_position3_rotated.x = 140;
    s->ladder_position3_rotated.y = 300;
    s->ladder_position3_rotated.w = 45;
    s->ladder_position3_rotated.h = 250;

    //ladder 4 rotated
    s->ladder_position4_rotated.x = 470;
    s->ladder_position4_rotated.y = 320;
    s->ladder_position4_rotated.w = 40;
    s->ladder_position4_rotated.h = 210;

    //ladder 5 rotated
    s->ladder_position5_rotated.x = 625;
    s->ladder_position5_rotated.y = 140;
    s->ladder_position5_rotated.w = 43;
    s->ladder_position5_rotated.h = 250;

    //ladder 6 rotated 
    s->ladder_position6_rotated.x = 470;
    s->ladder_position6_rotated.y = 50;
    s->ladder_position6_rotated.w = 40;
    s->ladder_position6_rotated.h = 250;

    //ladder 7 rotated
    s->ladder_position7_rotated.x = 278;
    s->ladder_position7_rotated.y = 72;
    s->ladder_position7_rotated.w = 43;
    s->ladder_position7_rotated.h = 137;

    //Button Roll
    s->buttonposition1.x = 799;
    s->buttonposition1.y = 362;
    s->buttonposition1.w = 170;
    s->buttonposition1.h = 45;

    //Button Start
    s->buttonposition2.x = 1074;
    s->buttonposition2.y = 252;
    s->buttonposition2.w = 139;
    s->buttonposition2.h = 40;

     //Sound on
    s->soundonposition.x = 1200;
    s->soundonposition.y = 34;
    s->soundonposition.w = 50;
    s->soundonposition.h = 50;

    //Sound off
    s->soundoffposition.x = 1200;
    s->soundoffposition.y = 34;
    s->soundoffposition.w = 50;
    s->soundoffposition.h = 50;

    //Win screen
    s->winPosition.x = 180;
    s->winPosition.y = 145;
    s->winPosition.w = 950;
    s->winPosition.h = 415;

    //online Position
    s->onlinePos.x = 1074;
    s->onlinePos.y = 205;
    s->onlinePos.w = 139;
    s->onlinePos.h = 40;

    //PLayer ID Position
    s->playerPos.x = 1043;
    s->playerPos.y = 35;
    s->playerPos.w = 200;
    s->playerPos.h = 130;
    
    //Dice turn Position
    s->diceTurnPos.x = 740;                 //tillagd!!
    s->diceTurnPos.y = 400;
    s->diceTurnPos.w = 280;
    s->diceTurnPos.h = 130;

    //1 checkmark
    s->chackmarkPos1.x = 940;                 
    s->chackmarkPos1.y = 115;
    s->chackmarkPos1.w = 150;
    s->chackmarkPos1.h = 80;

    //2 checkmark
    s->chackmarkPos2.x = 940;
    s->chackmarkPos2.y = 260;
    s->chackmarkPos2.w = 150;
    s->chackmarkPos2.h = 80;

    //3 checkmark
    s->chackmarkPos3.x = 940;
    s->chackmarkPos3.y = 405;
    s->chackmarkPos3.w = 150;
    s->chackmarkPos3.h = 80;

    //4 checkmark
    s->chackmarkPos4.x = 940;
    s->chackmarkPos4.y = 550;
    s->chackmarkPos4.w = 150;
    s->chackmarkPos4.h = 80;

    return s;
}

PUBLIC void applicationUpdate(Application theApp, int playerCount)
{

    //set to 1 when windows close button is pressed
    PRIVATE int close_requested = 0;

    //set to 0 in mouse.c to turn sound off
    PRIVATE int soundOnOrOff = 0;
    PRIVATE int soundCounter = 0;

    //Return value from the mouse
    PRIVATE int mouseReturn = 0;

    //Sum of dice casts in position to tiles 0-100
    PRIVATE int diceTotalPlayer1 = 1;
    PRIVATE int diceTotalPlayer2 = 1;
    PRIVATE int diceTotalPlayer3 = 1;
    PRIVATE int diceTotalPlayer4 = 1;

    //Where is the player in its turn
    PRIVATE int stepPlayer1 = 0;
    PRIVATE int stepPlayer2 = 0;
    PRIVATE int stepPlayer3 = 0;
    PRIVATE int stepPlayer4 = 0;

    //Dices 1 & 2 for casting each turn
    PUBLIC int dice1 = 0;
    PUBLIC int dice2 = 0;
    PUBLIC int dSum = 0;

    //Turn counter for every time all players have made their turn
    PUBLIC int turnCounter = 0;
    //How many times mouse button for roll dice has been pressed
    PUBLIC int diceHitCount = 0;

    //Denoting whose turn it is to play
    PUBLIC int turnPlayer1 = 1;
    PUBLIC int turnPlayer2 = 0;
    PUBLIC int turnPlayer3 = 0;
    PUBLIC int turnPlayer4 = 0;
    PUBLIC int turnPlayerCounter = 0;

    //Starting posistion of sprites 1 for x and y coordinates
    PRIVATE int xSprite1 = 770;
    PRIVATE int ySprite1 = 560;
    //Starting posistion of sprites 2 for x and y coordinates
    PRIVATE int xSprite2 = 770;
    PRIVATE int ySprite2 = 560;
    //Starting posistion of sprites 3 for x and y coordinates
    PRIVATE int xSprite3 = 770;
    PRIVATE int ySprite3 = 560;
    //Starting posistion of sprites 4 for x and y coordinates
    PRIVATE int xSprite4 = 770;
    PRIVATE int ySprite4 = 560;

    //How many times have we moved in total
    PRIVATE int yCounter = 0;

    //Indicate that the game has started
    PRIVATE int startGame = 0;

    //Pressing start game button to activate roll dice button
    PRIVATE int readyToStart = 0;

    //Activate start game button
    PRIVATE int endChoice = 0;

    //How many rounds have passed
    PRIVATE int totalRounds = 1;

    //timer to count every sec passed
    PRIVATE int timer = 1800;

    //start button and roll dice button flip timer
    PUBLIC int startFlip = 0;
    PUBLIC int diceRollFlip = 0;

    //Who has won
    PRIVATE int player1Win = 0;
    PRIVATE int player2Win = 0;
    PRIVATE int player3Win = 0;
    PRIVATE int player4Win = 0;

    //All snake & ladder positions 
    PRIVATE int snakeLadder[15] = { 16, 18, 20, 23, 27, 29, 50, 55, 63, 66, 76, 83, 89, 99 };

    //Checking if it is a ladder or snake and updateing the coordinates
    PRIVATE int arrayPairCounter = 0;
    PRIVATE int changeSteps = 0;
    PRIVATE int snakeOrLadder = 0;
    PUBLIC int ladderRotationTurn;
    PRIVATE int updatedX = 0;
    PRIVATE int updatedY = 0;

    //turn check for whom shall move on the ladder and snake
    PRIVATE int totalPlayer1Ptr = 0;
    PRIVATE int turn1Ptr = 0;
    PRIVATE int totalPlayer2Ptr = 0;
    PRIVATE int turn2Ptr = 0;
    PRIVATE int totalPlayer3Ptr = 0;
    PRIVATE int turn3Ptr = 0;
    PRIVATE int totalPlayer4Ptr = 0;
    PRIVATE int turn4Ptr = 0;
    PRIVATE int counter = 0;

    //Sum of movements for the ladders and snakes
    PRIVATE int dSumPtr;
    PRIVATE int dSumMovement1 = 0;
    PRIVATE int dSumMovement2 = 0;
    PRIVATE int dSumMovement3 = 0;
    PRIVATE int dSumMovement4 = 0;

    //variables that check conditions from the server data that has been sent
    PRIVATE int startCounter = 0;
    PRIVATE int choiceCounter = 0;
    PRIVATE int idCounter = 0;
    PRIVATE int idSend = 0;

    //all the variables that stores the data sent from the server
    theApp-> sumOfStarts = 0;
    theApp-> sumOfChoices = 0;
    theApp-> closeWindows = 0;
    theApp-> roll = 0;
    theApp-> diceOnline1 = 0;
    theApp-> diceOnline2 = 0;
    theApp-> playerID = 0;
    theApp->colour = 0;
    theApp->playerColour1 = 0;
    theApp->playerColour2 = 0;
    theApp->playerColour3 = 0;
    theApp->playerColour4 = 0;


    while (!close_requested)
    {
        if (theApp->closeWindows == 1)
        {
            destoryApplication(theApp);
        }
        //checking if any data has been sent from the server and process it
        if (CheckSocket(theApp)) {
            uint16_t length;
            uint16_t flag;
            uint8_t* data = RecvData(&length, theApp);
            uint16_t offset = 0;
            while (offset < length) {
                ProcessData(data, &offset, theApp);
            }
            free(data);
        }
        //Fetch ID number from server upon login
        if(idSend == 0)
        { 
             SendData(NULL, 0, FLAG_INDEX, theApp);
             idSend++;
        }
        while (SDL_PollEvent(&theApp->window_event) > 0)
        {
            soundApplication(soundOnOrOff, 0);
            switch (theApp->window_event.type)
            {
            case SDL_QUIT:
                close_requested = 1;
                SendData(NULL, 0, FLAG_QUIT, theApp);
                break;
            case SDL_MOUSEBUTTONDOWN:
                //coordinates of 20 sprites
                if(theApp->playerID==0 && choiceCounter == 0)
                {
                    choiceCounter++;
                    if (theApp->window_event.button.x > 336 && theApp->window_event.button.y > 112 && theApp->window_event.button.x < 390 && theApp->window_event.button.y < 213)
                    {
                        theApp->colour = 1;
                    }
                    if (theApp->window_event.button.x > 475 && theApp->window_event.button.y > 112 && theApp->window_event.button.x < 528 && theApp->window_event.button.y < 213)
                    {
                        theApp->colour = 2;
                    }
                    if (theApp->window_event.button.x > 613 && theApp->window_event.button.y > 112 && theApp->window_event.button.x < 663 && theApp->window_event.button.y < 213)
                    {
                        theApp->colour = 3;
                    }
                    if (theApp->window_event.button.x > 754 && theApp->window_event.button.y > 112 && theApp->window_event.button.x < 807 && theApp->window_event.button.y < 213)
                    {
                        theApp->colour = 4;
                    }
                    if (theApp->window_event.button.x > 877 && theApp->window_event.button.y > 112 && theApp->window_event.button.x < 923 && theApp->window_event.button.y < 213)
                    {
                        theApp->colour = 5;
                    }
                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &theApp->colour, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(send_data, send_offset, FLAG_CHOICE, theApp);                    
                    SendData(NULL, 0, FLAG_COLOUR1, theApp);                              
                    break;
                }
                if(theApp->playerID==1 && choiceCounter == 0)
                {
                    choiceCounter++;
                    if (theApp->window_event.button.x > 336 && theApp->window_event.button.y > 271 && theApp->window_event.button.x < 390 && theApp->window_event.button.y < 373)
                    {
                        theApp->colour = 1;
                    }
                    if (theApp->window_event.button.x > 475 && theApp->window_event.button.y > 271 && theApp->window_event.button.x < 528 && theApp->window_event.button.y < 373)
                    {
                        theApp->colour = 2;
                    }
                    if (theApp->window_event.button.x > 613 && theApp->window_event.button.y > 271 && theApp->window_event.button.x < 663 && theApp->window_event.button.y < 373)
                    {
                        theApp->colour = 3;
                    }
                    if (theApp->window_event.button.x > 754 && theApp->window_event.button.y > 271 && theApp->window_event.button.x < 807 && theApp->window_event.button.y < 373)
                    {
                        theApp->colour = 4;
                    }
                    if (theApp->window_event.button.x > 877 && theApp->window_event.button.y > 271 && theApp->window_event.button.x < 923 && theApp->window_event.button.y < 373)
                    {
                        theApp->colour = 5;
                    }
                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &theApp->colour, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(send_data, send_offset, FLAG_CHOICE, theApp);                    
                    SendData(NULL, 0, FLAG_COLOUR2, theApp);                              
                    break;
                }
                if(theApp->playerID==2 && choiceCounter == 0)
                {
                    choiceCounter++;
                    if (theApp->window_event.button.x > 336 && theApp->window_event.button.y > 477 && theApp->window_event.button.x < 390 && theApp->window_event.button.y < 535)
                    {
                        theApp->colour = 1;
                    }
                    if (theApp->window_event.button.x > 475 && theApp->window_event.button.y > 477 && theApp->window_event.button.x < 528 && theApp->window_event.button.y < 535)
                    {
                        theApp->colour = 2;
                    }
                    if (theApp->window_event.button.x > 613 && theApp->window_event.button.y > 477 && theApp->window_event.button.x < 663 && theApp->window_event.button.y < 535)
                    {
                        theApp->colour = 3;
                    }
                    if (theApp->window_event.button.x > 754 && theApp->window_event.button.y > 477 && theApp->window_event.button.x < 807 && theApp->window_event.button.y < 535)
                    {
                        theApp->colour = 4;
                    }
                    if (theApp->window_event.button.x > 877 && theApp->window_event.button.y > 477 && theApp->window_event.button.x < 923 && theApp->window_event.button.y < 535)
                    {
                        theApp->colour = 5;
                    }
                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &theApp->colour, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(send_data, send_offset, FLAG_CHOICE, theApp);                    
                    SendData(NULL, 0, FLAG_COLOUR3, theApp);                              
                    break;
                }
                if(theApp->playerID==3 && choiceCounter == 0)
                {
                    choiceCounter++;
                    if (theApp->window_event.button.x > 336 && theApp->window_event.button.y > 577 && theApp->window_event.button.x < 390 && theApp->window_event.button.y < 687)
                    {
                        theApp->colour = 1;
                    }
                    if (theApp->window_event.button.x > 475 && theApp->window_event.button.y > 577 && theApp->window_event.button.x < 528 && theApp->window_event.button.y < 687)
                    {
                        theApp->colour = 2;
                    }
                    if (theApp->window_event.button.x > 613 && theApp->window_event.button.y > 577 && theApp->window_event.button.x < 663 && theApp->window_event.button.y < 687)
                    {
                        theApp->colour = 3;
                    }
                    if (theApp->window_event.button.x > 754 && theApp->window_event.button.y > 577 && theApp->window_event.button.x < 807 && theApp->window_event.button.y < 687)
                    {
                        theApp->colour = 4;
                    }
                    if (theApp->window_event.button.x > 877 && theApp->window_event.button.y > 577 && theApp->window_event.button.x < 923 && theApp->window_event.button.y < 687)
                    {
                        theApp->colour = 5;
                    }
                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &theApp->colour, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(send_data, send_offset, FLAG_CHOICE, theApp);                    
                    SendData(NULL, 0, FLAG_COLOUR4, theApp);                              
                    break;
                }
                if (theApp->window_event.button.x > 1205 && theApp->window_event.button.y > 37 && theApp->window_event.button.x < 1244 && theApp->window_event.button.y < 64)
                {
                    if (soundOnOrOff == 1)
                    {
                        soundOnOrOff = 0;
                        break;
                    }
                    else if (soundOnOrOff == 0)
                    {
                        soundOnOrOff = 1;
                        break;
                    }
                }

                //If you press start, send to server that you are ready to play the game and wait for all other clients
                if (endChoice == 1 && theApp->window_event.button.x > 1085 && theApp->window_event.button.y > 253 && theApp->window_event.button.x < 1200 && theApp->window_event.button.y < 288 && startCounter == 0)
                {
                    SendData(NULL, 0, FLAG_START, theApp);
                    startCounter++;
                }
                //sound of exit button & send exit to all clients
                if (endChoice == 1 && theApp->window_event.button.x > 1076 && theApp->window_event.button.y > 348 && theApp->window_event.button.x < 1210 && theApp->window_event.button.y < 381)
                {
                    soundApplication(soundOnOrOff, 1);
                    SendData(NULL, 0, FLAG_QUIT, theApp);
                    break;
                }
                //If it is your turn and pressing the roll button --> roll
                if (theApp->window_event.button.x > 810 && theApp->window_event.button.y > 366 && theApp->window_event.button.x < 955 && theApp->window_event.button.y < 402 && turnPlayerCounter == theApp->playerID && readyToStart == 1)
                {
                    SendData(NULL, 0, FLAG_ROLL, theApp);
                    SendData(NULL, 0, FLAG_ROLL_DICE1, theApp);
                }
            }
        }
        if (readyToStart == 1)
        {
            //If someone of all 4 players have pressed roll dice, roll dice for all players
            if (theApp->roll == 1)
            {
                int steps = 1;
                int i = 1;
                diceRollFlip = 1;

                dice1 = theApp->diceOnline1;
                dice2 = theApp->diceOnline2;
                dSum = diceSum(dice1, dice2);

                soundApplication(soundOnOrOff, 3);
                turnPlayerCounter++;
                idCounter++;

                dSumPtr = dSum;

                for (i; steps <= dSum; steps++)
                {
                    if (turnPlayer1 == 1) {

                        stepPlayer1++;
                        squareMoving(i, stepPlayer1, &theApp->sprite_position1.x, &theApp->sprite_position1.y);
                        timer = 1800;

                        totalPlayer1Ptr = diceTotalPlayer1;
                        turn1Ptr = turnPlayer1;
                    }
                    if (turnPlayer2 == 1) {

                        stepPlayer2++;
                        squareMoving(i, stepPlayer2, &theApp->sprite_position2.x, &theApp->sprite_position2.y);
                        timer = 1800;

                        totalPlayer2Ptr = diceTotalPlayer2;
                        turn2Ptr = turnPlayer2;
                    }
                    if (turnPlayer3 == 1) {

                        stepPlayer3++;
                        squareMoving(i, stepPlayer3, &theApp->sprite_position3.x, &theApp->sprite_position3.y);
                        timer = 1800;

                        totalPlayer3Ptr = diceTotalPlayer3;
                        turn3Ptr = turnPlayer3;
                    }
                    else if (turnPlayer4 == 1) {

                        stepPlayer4++;
                        squareMoving(i, stepPlayer4, &theApp->sprite_position4.x, &theApp->sprite_position4.y);
                        timer = 1800;

                        totalPlayer4Ptr = diceTotalPlayer4;
                        turn4Ptr = turnPlayer4;
                    }
                    if (stepPlayer1 == 99)
                    {
                        player1Win = 1;
                        break;
                    }
                    if (stepPlayer2 == 99)
                    {
                        player2Win = 1;
                        break;
                    }
                    if (stepPlayer3 == 99)
                    {
                        player3Win = 1;
                        break;
                    }
                    if (stepPlayer4 == 99)
                    {
                        player4Win = 1;
                        break;
                    }
                    soundApplication(soundOnOrOff, 6);
                    draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
                    diceRollFlip = 0;
                    SDL_Delay(400);
                }
                updateDiceTotal(dSum, &turnPlayer1, &turnPlayer2, &turnPlayer3, &turnPlayer4, &diceTotalPlayer1, &diceTotalPlayer2, &diceTotalPlayer3, &diceTotalPlayer4);

                if (turn1Ptr == 1)
                {
                    dSumMovement1 = dSumPtr;
                }
                if (turn2Ptr == 1)
                {
                    dSumMovement2 = dSumPtr;
                }
                if (turn3Ptr == 1)
                {
                    dSumMovement3 = dSumPtr;
                }
                if (turn4Ptr == 1)
                {
                    dSumMovement4 = dSumPtr;
                }
                if (totalRounds % 2 == 0)
                {
                    ladderRotationTurn = 2;
                }
                else
                {
                    ladderRotationTurn = 1;
                }

                if (stepPlayer1 + 1 == diceTotalPlayer1)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (stepPlayer1 + 1 == snakeLadder[i])
                        {
                            do
                            {
                                int position = diceTotalPlayer1;

                                snakeLadderSlide(position, &updatedX, &updatedY, &arrayPairCounter, ladderRotationTurn, &changeSteps, &snakeOrLadder, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4);

                                for (int i = 0; i < 15; i++)
                                {
                                    if (totalPlayer1Ptr + dSumMovement1 == snakeLadder[i])
                                    {
                                        theApp->sprite_position1.x = updatedX;
                                        theApp->sprite_position1.y = updatedY;
                                    }
                                }

                                draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
                                SDL_Delay(1 / 60);

                                if (snakeOrLadder == 1) //1 är en snake
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer1 -= changeSteps;
                                        diceTotalPlayer1 -= changeSteps;
                                        counter++;
                                    }
                                }
                                if (snakeOrLadder == 2) // 2 är en ladder 
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer1 += changeSteps;
                                        diceTotalPlayer1 += changeSteps;
                                        counter++;
                                    }
                                }

                            } while (arrayPairCounter != 0);
                        }
                    }
                    if (snakeOrLadder == 1) //1 är en snake
                    {
                        soundApplication(soundOnOrOff, 4);
                    }
                    if (snakeOrLadder == 2) // 2 är en ladder 
                    {
                        soundApplication(soundOnOrOff, 5);
                    }
                    counter = 0;
                    snakeOrLadder = 0;
                }

                if (stepPlayer2 + 1 == diceTotalPlayer2)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (stepPlayer2 + 1 == snakeLadder[i])
                        {
                            do
                            {
                                int position = diceTotalPlayer2;

                                snakeLadderSlide(position, &updatedX, &updatedY, &arrayPairCounter, ladderRotationTurn, &changeSteps, &snakeOrLadder, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4);

                                for (int i = 0; i < 15; i++)
                                {
                                    if (totalPlayer2Ptr + dSumMovement2 == snakeLadder[i])
                                    {
                                        theApp->sprite_position2.x = updatedX;
                                        theApp->sprite_position2.y = updatedY;
                                    }
                                }

                                draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
                                SDL_Delay(1 / 60);

                                if (snakeOrLadder == 1) //1 är en snake
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer2 -= changeSteps;
                                        diceTotalPlayer2 -= changeSteps;
                                        counter++;
                                    }
                                }
                                if (snakeOrLadder == 2) // 2 är en ladder 
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer2 += changeSteps;
                                        diceTotalPlayer2 += changeSteps;
                                        counter++;
                                    }
                                }

                            } while (arrayPairCounter != 0);
                        }
                    }
                    if (snakeOrLadder == 1) //1 är en snake
                    {
                        soundApplication(soundOnOrOff, 4);
                    }
                    if (snakeOrLadder == 2) // 2 är en ladder 
                    {
                        soundApplication(soundOnOrOff, 5);
                    }
                    counter = 0;
                    snakeOrLadder = 0;
                }

                if (stepPlayer3 + 1 == diceTotalPlayer3)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (stepPlayer3 + 1 == snakeLadder[i])
                        {
                            do
                            {
                                int position = diceTotalPlayer3;

                                snakeLadderSlide(position, &updatedX, &updatedY, &arrayPairCounter, ladderRotationTurn, &changeSteps, &snakeOrLadder, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4);

                                for (int i = 0; i < 15; i++)
                                {
                                    if (totalPlayer3Ptr + dSumMovement3 == snakeLadder[i])
                                    {
                                        theApp->sprite_position3.x = updatedX;
                                        theApp->sprite_position3.y = updatedY;
                                    }
                                }

                                draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
                                SDL_Delay(1 / 60);

                                if (snakeOrLadder == 1) //1 är en snake
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer3 -= changeSteps;
                                        diceTotalPlayer3 -= changeSteps;
                                        counter++;
                                    }
                                }
                                if (snakeOrLadder == 2) // 2 är en ladder 
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer3 += changeSteps;
                                        diceTotalPlayer3 += changeSteps;
                                        counter++;
                                    }
                                }

                            } while (arrayPairCounter != 0);
                        }
                    }
                    if (snakeOrLadder == 1) //1 är en snake
                    {
                        soundApplication(soundOnOrOff, 4);
                    }
                    if (snakeOrLadder == 2) // 2 är en ladder 
                    {
                        soundApplication(soundOnOrOff, 5);
                    }
                    counter = 0;
                    snakeOrLadder = 0;
                }

                if (stepPlayer4 + 1 == diceTotalPlayer4)
                {
                    for (int i = 0; i < 15; i++)
                    {
                        if (stepPlayer4 + 1 == snakeLadder[i])
                        {
                            do
                            {
                                int position = diceTotalPlayer4;

                                snakeLadderSlide(position, &updatedX, &updatedY, &arrayPairCounter, ladderRotationTurn, &changeSteps, &snakeOrLadder, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4);

                                for (int i = 0; i < 15; i++)
                                {
                                    if (totalPlayer4Ptr + dSumMovement4 == snakeLadder[i])
                                    {
                                        theApp->sprite_position4.x = updatedX;
                                        theApp->sprite_position4.y = updatedY;
                                    }
                                }

                                draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
                                SDL_Delay(1 / 60);

                                if (snakeOrLadder == 1) //1 är en snake
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer4 -= changeSteps;
                                        diceTotalPlayer4 -= changeSteps;
                                        counter++;
                                    }
                                }
                                if (snakeOrLadder == 2) // 2 är en ladder 
                                {
                                    if (counter == 0)
                                    {
                                        stepPlayer4 += changeSteps;
                                        diceTotalPlayer4 += changeSteps;
                                        counter++;
                                    }
                                }
                            } while (arrayPairCounter != 0);
                        }
                    }
                    if (snakeOrLadder == 1) //1 är en snake
                    {
                        soundApplication(soundOnOrOff, 4);
                    }
                    if (snakeOrLadder == 2) // 2 är en ladder 
                    {
                        soundApplication(soundOnOrOff, 5);
                    }
                    counter = 0;
                    snakeOrLadder = 0;
                }
                if (turnPlayer4 == 1)
                {
                    totalRounds++;
                }

                printf("DiceSum %d \n", dSum);
                turn(&turnPlayer1, &turnPlayer2, &turnPlayer3, &turnPlayer4, &turnPlayerCounter);
                theApp->roll = 0;
                theApp->diceOnline1 = 0;
                theApp->diceOnline2 = 0;
                if (idCounter == 4)
                {
                    idCounter = 0;
                }
            }
        }
        //If all 4 players selected sprites , start game
        if (theApp->sumOfChoices == 4 && choiceCounter == 1)
        {
            endChoice = 1;
        }

        //If all 4 players are logged in, start game upon all 4 pressed start
        if (theApp->sumOfStarts == 4 && startCounter == 1)
        {
            startFlip = 1;
            readyToStart = 1;
            soundApplication(soundOnOrOff, 8);

            //Only 1 press on start
            if (startGame == 1)
            {
                break;
            }

            //All starting positions
            if (startGame == 0)
            {
                startGame = 1;

                xSprite1 = 43;
                ySprite1 = 620;
                xSprite2 = 62;
                ySprite2 = 620;
                xSprite3 = 53;
                ySprite3 = 620;
                xSprite4 = 72;
                ySprite4 = 620;

                theApp->sprite_position1.x = xSprite1;
                theApp->sprite_position1.y = ySprite1;
                theApp->sprite_position1.w = 33;
                theApp->sprite_position1.h = 55;
                theApp->sprite_position2.x = xSprite2;
                theApp->sprite_position2.y = ySprite2;
                theApp->sprite_position2.w = 33;
                theApp->sprite_position2.h = 55;
                theApp->sprite_position3.x = xSprite3;
                theApp->sprite_position3.y = ySprite3;
                theApp->sprite_position3.w = 33;
                theApp->sprite_position3.h = 55;
                theApp->sprite_position4.x = xSprite4;
                theApp->sprite_position4.y = ySprite4;
                theApp->sprite_position4.w = 33;
                theApp->sprite_position4.h = 55;
                startCounter++;
            }
        }
        //End of roll dice 

        //Function for mouse x & y coordinates. 
        //And if left button is pressed, may resturn a specific value for leftclick

        mouseApplication(&mouseReturn, &close_requested);
        //find mouse position
    PRIVATE int x, y;
    Uint32 buttons;

    SDL_PumpEvents();  // make sure we have the latest mouse state.

    buttons = SDL_GetMouseState(&x, &y);

    SDL_Log("Mouse cursor is at %d, %d", x, y);

        //Timer control for every round
        if (readyToStart == 1)
        {
            timer -= 1000 / 500;
            if (timer < 0 && turnPlayer1 == 1)
            {
                timer = 1800;
                turnPlayer1 = 0;
                turnPlayer2 = 1;
            }
            if (timer < 0 && turnPlayer2 == 1)
            {
                timer = 1800;
                turnPlayer2 = 0;
                turnPlayer3 = 1;
            }
            if (timer < 0 && turnPlayer3 == 1)
            {
                timer = 1800;
                turnPlayer3 = 0;
                turnPlayer4 = 1;
            }
            if (timer < 0 && turnPlayer4 == 1)
            {
                timer = 1800;
                turnPlayer4 = 0;
                turnPlayer1 = 1;
            }
        }
        if (startFlip == 10)
        {
            startFlip = 0;
        }

        //Draw all textures upon the screen
        draw(theApp, playerCount, &soundOnOrOff, &dice1, &dice2, totalRounds, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, timer, readyToStart, &endChoice, &startFlip, &diceRollFlip, player1Win, player2Win, player3Win, player4Win);
        diceRollFlip = 0;
        
        //wait 1/60th of a sec
        SDL_Delay(1000 / 60);
    }
}

//Drawing all textures upon the screen
PRIVATE void draw(Application theApp, int playerCount, int* soundOnOrOff, int* dice1, int* dice2, int totalRounds, int turnPlayer1, int turnPlayer2, int turnPlayer3, int turnPlayer4, int timer, int readyToStart, int* endChoice, int* startFlip, int* diceRollFlip, int player1Win, int player2Win, int player3Win, int player4Win)
{
    SDL_RenderClear(theApp->rend);
    SDL_RenderCopy(theApp->rend, theApp->board, NULL, 0);

    //Flpping buttons
    if (*startFlip >= 1)
    {
        SDL_RenderCopyEx(theApp->rend, theApp->buttonTexture2, NULL, &theApp->buttonposition2, 180, NULL, SDL_FLIP_VERTICAL);
        (*startFlip)++;
    }
    if (*startFlip == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->buttonTexture2, NULL, &theApp->buttonposition2);
    }
    if (*diceRollFlip == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->buttonTexture1, NULL, &theApp->buttonposition1);
    }
    if (*diceRollFlip == 1)
    {
        SDL_RenderCopyEx(theApp->rend, theApp->buttonTexture1, NULL, &theApp->buttonposition1, 180, NULL, SDL_FLIP_VERTICAL);
        (*diceRollFlip)++;
    }

    if (totalRounds % 2 == 0)
    {
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position1, 42, &theApp->ladder_position1_rotated, SDL_FLIP_NONE);
        SDL_RenderCopy(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position2_rotated);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position3_rotated, -20, NULL, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position4_rotated, 20, NULL, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopy(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position5_rotated);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position6_rotated, 45, NULL, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position7, -27, NULL, SDL_FLIP_HORIZONTAL);
    }
    else
    {
        SDL_RenderCopy(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position1);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position2, 45, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position3, 30, NULL, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopy(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position4);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position5, -25, NULL, SDL_FLIP_HORIZONTAL);
        SDL_RenderCopy(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position6);
        SDL_RenderCopyEx(theApp->rend, theApp->ladderTexture, NULL, &theApp->ladder_position7, -27, NULL, SDL_FLIP_HORIZONTAL);
    }

    textView(theApp->rend, turnPlayer1, turnPlayer2, turnPlayer3, turnPlayer4, totalRounds, timer, readyToStart);

    if (playerCount == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture1, NULL, &theApp->sprite_position1);
        //draw only 1 player
    }
    if (playerCount == 2)
    {
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture1, NULL, &theApp->sprite_position1);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture2, NULL, &theApp->sprite_position2);
        //draw 2 players
    }
    if (playerCount == 3)
    {
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture1, NULL, &theApp->sprite_position1);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture2, NULL, &theApp->sprite_position2);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture3, NULL, &theApp->sprite_position3);
        //draw 3 players
    }
    if (playerCount == 4)
    {
        //player 1 chooses colour between knights
        if(theApp->playerColour1==1)
        {
            theApp->sprite1 = IMG_Load("resources/Piece_1_red.png");
            theApp->sprite_texture1 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite1);
            SDL_FreeSurface(theApp->sprite1);
        }
        if(theApp->playerColour1==2)
        {
            theApp->sprite1 = IMG_Load("resources/Piece_1_blue.png");
            theApp->sprite_texture1 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite1);
            SDL_FreeSurface(theApp->sprite1);
        }
        if(theApp->playerColour1==3)
        {
            theApp->sprite1 = IMG_Load("resources/Piece_1_black.png");
            theApp->sprite_texture1 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite1);
            SDL_FreeSurface(theApp->sprite1);
        }
        if(theApp->playerColour1==4)
        {
            theApp->sprite1 = IMG_Load("resources/Piece_1_yellow.png");
            theApp->sprite_texture1 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite1);
            SDL_FreeSurface(theApp->sprite1);
        }
        if(theApp->playerColour1==5)
        {
            theApp->sprite1 = IMG_Load("resources/Piece_1.png");
            theApp->sprite_texture1 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite1);
            SDL_FreeSurface(theApp->sprite1);
        }
        //player 2 chooses colour between rooks
        if(theApp->playerColour2==1)
        {
            theApp->sprite2 = IMG_Load("resources/Piece_2_red.png");
            theApp->sprite_texture2 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite2);
            SDL_FreeSurface(theApp->sprite2);
        }
        if(theApp->playerColour2==2)
        {
            theApp->sprite2 = IMG_Load("resources/Piece_2_blue.png");
            theApp->sprite_texture2 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite2);
            SDL_FreeSurface(theApp->sprite2);
        }
        if(theApp->playerColour2==3)
        {
            theApp->sprite2 = IMG_Load("resources/Piece_2_black.png");
            theApp->sprite_texture2 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite2);
            SDL_FreeSurface(theApp->sprite2);
        }
        if(theApp->playerColour2==4)
        {
            theApp->sprite2 = IMG_Load("resources/Piece_2_yellow.png");
            theApp->sprite_texture2 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite2);
            SDL_FreeSurface(theApp->sprite2);
        }
        if(theApp->playerColour2==5)
        {
            theApp->sprite2 = IMG_Load("resources/Piece_2.png");
            theApp->sprite_texture2 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite2);
            SDL_FreeSurface(theApp->sprite2);
        }
        //player 3 chooses colour between bishops
        if(theApp->playerColour3==1)
        {
            theApp->sprite3 = IMG_Load("resources/Piece_3_red.png");
            theApp->sprite_texture3 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite3);
            SDL_FreeSurface(theApp->sprite3);
        }
        if(theApp->playerColour3==2)
        {
            theApp->sprite3 = IMG_Load("resources/Piece_3_blue.png");
            theApp->sprite_texture3 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite3);
            SDL_FreeSurface(theApp->sprite3);
        }
        if(theApp->playerColour3==3)
        {
            theApp->sprite3 = IMG_Load("resources/Piece_3_black.png");
            theApp->sprite_texture3 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite3);
            SDL_FreeSurface(theApp->sprite3);
        }
        if(theApp->playerColour3==4)
        {
            theApp->sprite3 = IMG_Load("resources/Piece_3_yellow.png");
            theApp->sprite_texture3 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite3);
            SDL_FreeSurface(theApp->sprite3);
        }
        if(theApp->playerColour3==5)
        {
            theApp->sprite3 = IMG_Load("resources/Piece_3.png");
            theApp->sprite_texture3 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite3);
            SDL_FreeSurface(theApp->sprite3);
        }
        //player 4 chooses colour between pawns
        if(theApp->playerColour4==1)
        {
            theApp->sprite4 = IMG_Load("resources/Piece_4_red.png");
            theApp->sprite_texture4 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite4);
            SDL_FreeSurface(theApp->sprite4);
        }
        if(theApp->playerColour4==2)
        {
            theApp->sprite4 = IMG_Load("resources/Piece_4_blue.png");
            theApp->sprite_texture4 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite4);
            SDL_FreeSurface(theApp->sprite4);
        }
        if(theApp->playerColour4==3)
        {
            theApp->sprite4 = IMG_Load("resources/Piece_4_black.png");
            theApp->sprite_texture4 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite4);
            SDL_FreeSurface(theApp->sprite4);
        }
        if(theApp->playerColour4==4)
        {
            theApp->sprite4 = IMG_Load("resources/Piece_4_yellow.png");
            theApp->sprite_texture4 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite4);
            SDL_FreeSurface(theApp->sprite4);
        }
        if(theApp->playerColour4==5)
        {
            theApp->sprite4 = IMG_Load("resources/Piece_4.png");
            theApp->sprite_texture4 = SDL_CreateTextureFromSurface(theApp->rend, theApp->sprite4);
            SDL_FreeSurface(theApp->sprite4);
        }
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture1, NULL, &theApp->sprite_position1);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture2, NULL, &theApp->sprite_position2);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture3, NULL, &theApp->sprite_position3);
        SDL_RenderCopy(theApp->rend, theApp->sprite_texture4, NULL, &theApp->sprite_position4);
        //draw 4 players
    }
    
    if(turnPlayer1 == 1)                                                  //tillagd!!
    {
        SDL_RenderCopy(theApp->rend, theApp->diceRollTurn1tex, NULL, &theApp->diceTurnPos);
    }
    if(turnPlayer2 == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceRollTurn2tex, NULL, &theApp->diceTurnPos);
    }
    if(turnPlayer3 == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceRollTurn3tex, NULL, &theApp->diceTurnPos);
    }
    if(turnPlayer4 == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceRollTurn4tex, NULL, &theApp->diceTurnPos);
    }

    //Draw dice
    if (*dice1 == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture1, NULL, &theApp->diceposition1);
    }
    if (*dice2 == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture2, NULL, &theApp->diceposition2);
    }
    if (*dice1 == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture1, NULL, &theApp->diceposition1);
    }
    if (*dice1 == 2)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture2, NULL, &theApp->diceposition1);
    }
    if (*dice1 == 3)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture3, NULL, &theApp->diceposition1);
    }
    if (*dice1 == 4)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture4, NULL, &theApp->diceposition1);
    }
    if (*dice1 == 5)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture5, NULL, &theApp->diceposition1);
    }
    if (*dice1 == 6)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture6, NULL, &theApp->diceposition1);
    }
    if (*dice2 == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture1, NULL, &theApp->diceposition2);
    }
    if (*dice2 == 2)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture2, NULL, &theApp->diceposition2);
    }
    if (*dice2 == 3)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture3, NULL, &theApp->diceposition2);
    }
    if (*dice2 == 4)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture4, NULL, &theApp->diceposition2);
    }
    if (*dice2 == 5)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture5, NULL, &theApp->diceposition2);
    }
    if (*dice2 == 6)
    {
        SDL_RenderCopy(theApp->rend, theApp->diceTexture6, NULL, &theApp->diceposition2);
    }
    if (*soundOnOrOff == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->soundOnTexture, NULL, &theApp->soundonposition);
    }
    if (*soundOnOrOff == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->soundOffTexture, NULL, &theApp->soundoffposition);
    }

    if (theApp->sumOfStarts == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->onlineTex1, NULL, &theApp->onlinePos);
    }
    if (theApp->sumOfStarts == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->onlineTex2, NULL, &theApp->onlinePos);
    }
    if (theApp->sumOfStarts == 2)
    {
        SDL_RenderCopy(theApp->rend, theApp->onlineTex3, NULL, &theApp->onlinePos);
    }
    if (theApp->sumOfStarts == 3)
    {
        SDL_RenderCopy(theApp->rend, theApp->onlineTex4, NULL, &theApp->onlinePos);
    }
    if (theApp->sumOfStarts == 4)
    {
        SDL_RenderCopy(theApp->rend, theApp->onlineTex5, NULL, &theApp->onlinePos);
    }

    if (theApp->playerID == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->playerTex1, NULL, &theApp->playerPos);
    }
    if (theApp->playerID == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->playerTex2, NULL, &theApp->playerPos);
    }
    if (theApp->playerID == 2)
    {
        SDL_RenderCopy(theApp->rend, theApp->playerTex3, NULL, &theApp->playerPos);
    }
    if (theApp->playerID == 3)
    {
        SDL_RenderCopy(theApp->rend, theApp->playerTex4, NULL, &theApp->playerPos);
    }

    //Render screen for who has won
    if (player1Win == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->winTexture1, NULL, &theApp->winPosition);
        soundApplication(soundOnOrOff, 7);
        SDL_RenderPresent(theApp->rend);
        SDL_Delay(10000);
        destoryApplication(theApp);
    }
    if (player2Win == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->winTexture2, NULL, &theApp->winPosition);
        soundApplication(soundOnOrOff, 7);
        SDL_RenderPresent(theApp->rend);
        SDL_Delay(10000);
        destoryApplication(theApp);
    }
    if (player3Win == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->winTexture3, NULL, &theApp->winPosition);
        soundApplication(soundOnOrOff, 7);
        SDL_RenderPresent(theApp->rend);
        SDL_Delay(10000);
        destoryApplication(theApp);
    }
    if (player4Win == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->winTexture4, NULL, &theApp->winPosition);
        soundApplication(soundOnOrOff, 7);
        SDL_RenderPresent(theApp->rend);
        SDL_Delay(10000);
        destoryApplication(theApp);
    }
     if(*soundOnOrOff == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->soundOnTexture, NULL, &theApp->soundonposition);
    }
    if(*soundOnOrOff == 1)
    {
        SDL_RenderCopy(theApp->rend, theApp->soundOffTexture, NULL, &theApp->soundoffposition);
    }
    if(*endChoice == 0)
    {
        SDL_RenderCopy(theApp->rend, theApp->choose_texture, NULL, 0);
        if (theApp->sumOfChoices >= 1)
        {
            SDL_RenderCopy(theApp->rend, theApp->checkmarkTex, NULL, &theApp->chackmarkPos1);
        }
        if (theApp->playerColour2 > 0)
        {
            SDL_RenderCopy(theApp->rend, theApp->checkmarkTex, NULL, &theApp->chackmarkPos2);
        }
        if (theApp->playerColour3 > 0)
        {
            SDL_RenderCopy(theApp->rend, theApp->checkmarkTex, NULL, &theApp->chackmarkPos3);
        }
        if (theApp->playerColour4 > 0)
        {
            SDL_RenderCopy(theApp->rend, theApp->checkmarkTex, NULL, &theApp->chackmarkPos4);
        }
    }
    SDL_RenderPresent(theApp->rend);
}

//Destroying all initiated textures and functions
PUBLIC void destoryApplication(Application theApp) {
    SDL_FreeSurface(theApp->window_surface);
    SDL_DestroyRenderer(theApp->rend);
    SDL_DestroyTexture(theApp->sprite_texture1);
    SDL_DestroyTexture(theApp->sprite_texture2);
    SDL_DestroyTexture(theApp->sprite_texture3);
    SDL_DestroyTexture(theApp->sprite_texture4);
    SDL_DestroyTexture(theApp->diceTexture1);
    SDL_DestroyTexture(theApp->diceTexture2);
    SDL_DestroyTexture(theApp->diceTexture3);
    SDL_DestroyTexture(theApp->diceTexture4);
    SDL_DestroyTexture(theApp->diceTexture5);
    SDL_DestroyTexture(theApp->diceTexture6);
    SDL_DestroyTexture(theApp->ladderTexture);
    SDL_DestroyTexture(theApp->soundOnTexture);
    SDL_DestroyTexture(theApp->soundOffTexture);
    SDL_DestroyTexture(theApp->buttonTexture1);
    SDL_DestroyTexture(theApp->buttonTexture2);
    SDL_DestroyTexture(theApp->winTexture1);
    SDL_DestroyTexture(theApp->winTexture2);
    SDL_DestroyTexture(theApp->winTexture3);
    SDL_DestroyTexture(theApp->winTexture4);
    SDL_DestroyTexture(theApp->onlineTex1);
    SDL_DestroyTexture(theApp->onlineTex2);
    SDL_DestroyTexture(theApp->onlineTex3);
    SDL_DestroyTexture(theApp->onlineTex4);
    SDL_DestroyTexture(theApp->onlineTex5);
    SDL_DestroyTexture(theApp->diceRollTurn1tex);       //tillagd!!
    SDL_DestroyTexture(theApp->diceRollTurn2tex);
    SDL_DestroyTexture(theApp->diceRollTurn3tex);
    SDL_DestroyTexture(theApp->diceRollTurn4tex);
    SDL_DestroyTexture(theApp->choose_texture);
    SDL_DestroyTexture(theApp->checkmark);
    SDL_DestroyWindow(theApp->window);
    TTF_Quit();
    SDLNet_Quit();
    soundApplication(1, 0);
    SDL_Quit();
}

/*
* Below is all functions that handles packets from clients to server and back
* //////////////////////////////////////////////////////////////////////////// *
* data: a unsigned 8x char storing bytes of the data beeing handled or sent
* length: a unsigned 16x short for storing total length of bytes beeing handled or sent
* flag: a hex number indicating what is beeing sent/recived and how to process it
* offset:  a unsigned 16x short for masking the to a int
*/

//Send the data using a flag to tell the server what to do
PUBLIC void SendData(uint8_t* data, uint16_t length, uint16_t flag, Application theApp) {
    uint8_t temp_data[MAX_PACKET];

    int offset = 0;
    memcpy(temp_data + offset, &flag, sizeof(uint16_t));
    offset += sizeof(uint16_t);
    memcpy(temp_data + offset, data, length);
    offset += length;

    int num_sent = SDLNet_TCP_Send(theApp->socket, temp_data, offset);
    if (num_sent < offset) {
        fprintf(stderr, "ER: SDLNet_TCP_Send: %sn", SDLNet_GetError());
        CloseSocket(0);
    }
}

//Recives the data sent from server and processes it to ProcessData
PUBLIC uint8_t* RecvData(uint16_t* length, Application theApp) {
    uint8_t temp_data[MAX_PACKET];
    int num_recv = SDLNet_TCP_Recv(theApp->socket, temp_data, MAX_PACKET);

    if (num_recv <= 0) {
        CloseSocket(0);

        const char* err = SDLNet_GetError();
        if (strlen(err) == 0) {
            printf("DB: server shutdownn");
        }
        else {
            fprintf(stderr, "ER: SDLNet_TCP_Recv: %sn", err);
        }

        return NULL;
    }
    else {
        *length = num_recv;

        uint8_t* data = (uint8_t*)malloc(num_recv * sizeof(uint8_t));
        memcpy(data, temp_data, num_recv);
        return data;
    }
}

//Takes the data from RecvData and checks flags sent and enters data sent into ints
PRIVATE void ProcessData(uint8_t* data, uint16_t* offset, Application theApp) {
    if (data == NULL) return;

    uint16_t flag = *(uint16_t*)&data[*offset];
    *offset += sizeof(uint16_t);

    switch (flag) {

    case FLAG_QUIT: {
        theApp->closeWindows = *(uint8_t*)&data[*offset];
        printf("Closing all windows: %d\n", theApp->closeWindows);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_START: {
        theApp->sumOfStarts = *(uint8_t*)&data[*offset];
        printf("Number of Players pressed Start: %d\n", theApp->sumOfStarts);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_CHOICE: {
        theApp->sumOfChoices = *(uint8_t*)&data[*offset];
        printf("Number of Players chosed sprites: %d\n", theApp->sumOfChoices);
        *offset += sizeof(uint8_t);
    } break; 
    case FLAG_COLOUR1: {
        theApp->playerColour1 = *(uint8_t*)&data[*offset];
        printf("Player1 colour: %d\n", theApp->playerColour1);
        *offset += sizeof(uint8_t);
    } break; 
    case FLAG_COLOUR2: {
        theApp->playerColour2 = *(uint8_t*)&data[*offset];
        printf("Player2 colour: %d\n", theApp->playerColour2);
        *offset += sizeof(uint8_t);
    } break; 
    case FLAG_COLOUR3: {
        theApp->playerColour3 = *(uint8_t*)&data[*offset];
        printf("Player3 colour: %d\n", theApp->playerColour3);
        *offset += sizeof(uint8_t);
    } break; 
    case FLAG_COLOUR4: {
        theApp->playerColour4 = *(uint8_t*)&data[*offset];
        printf("Player4 colour: %d\n", theApp->playerColour4);
        *offset += sizeof(uint8_t);
    } break; 
    case FLAG_ROLL: {
        theApp->roll = *(uint8_t*)&data[*offset];
        printf("Rolling Dice: %d\n", theApp->roll);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_ROLL_DICE1: {
        theApp->diceOnline1 = *(uint8_t*)&data[*offset];
        printf("DICE 1 ROLLED: %d\n", theApp->diceOnline1);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_ROLL_DICE2: {
        theApp->diceOnline2 = *(uint8_t*)&data[*offset];
        printf("DICE 2 ROLLED: %d\n", theApp->diceOnline2);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_INDEX: {
        theApp->playerID = *(uint8_t*)&data[*offset];
        printf("MY PLAYER INDEX: %d\n", theApp->playerID);
        *offset += sizeof(uint8_t);
    } break;
    }
}

//Init SDL Net, sockets & sockets set 
PRIVATE void InitNetwork(const char * ipHostAddress, Application theApp) {
    
    if (SDLNet_Init() == -1)
    {
        printf("SDLNet_Init: %s\n", SDLNet_GetError());
        exit(2);
    }

    if (SDLNet_ResolveHost(&theApp->ip, ipHostAddress, 1234) == -1) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }

    theApp->socket = SDLNet_TCP_Open(&theApp->ip);
    if (theApp->socket == NULL) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }

    theApp->socket_set = SDLNet_AllocSocketSet(1);
    if (theApp->socket_set == NULL) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }

    if (SDLNet_TCP_AddSocket(theApp->socket_set, theApp->socket) == -1) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }
}

//Closes all sockets in use
PRIVATE void CloseSocket(Application theApp) {
    if (SDLNet_TCP_DelSocket(theApp->socket_set, theApp->socket) == -1) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }

    SDLNet_FreeSocketSet(theApp->socket_set);
    SDLNet_TCP_Close(theApp->socket);
}

//Checks if any sockets is sending/receving packets
PUBLIC bool CheckSocket(Application theApp) {
    if (SDLNet_CheckSockets(theApp->socket_set, 0) == -1) {
        fprintf(stderr, "%sn", SDLNet_GetError());
        system("pause");
        exit(-1);
    }
    return SDLNet_SocketReady(theApp->socket);
}
