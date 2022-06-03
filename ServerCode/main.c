#include <stdlib.h>
#include <stdio.h>
#ifndef _MSC_VER
#include <unistd.h>
#endif
#include "SDL.h"
#include "SDL_net.h"

#define MAX_PACKET 0xFF
#define MAX_SOCKETS 0x04

#define PUBLIC /* empty */
#define PRIVATE static

//The flags to be sent to the clients
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


//server data beeing sent to clients and id for every logged in client
typedef struct {
    int in_use;
    uint8_t start;
    uint8_t select;
    uint8_t colour;  
    uint8_t closeWindows;
    uint8_t rollDice;
    uint8_t diceRolling1;
    uint8_t diceRolling2;
    uint8_t playerIDnum;
} Client;

//All conditions beeing recived from the clients
PRIVATE int playerID = 0;
PRIVATE int startingGame = 0;
PRIVATE int selectSprite = 0;
PRIVATE int colourSelected = 0;
PRIVATE int next_ind = 0;
PRIVATE int closingWindows = 0;
PRIVATE int roll = 0;
PUBLIC int diceOnline1 = 0;
PUBLIC int diceOnline2 = 0;
PUBLIC int colour = 0;

//Rolling the dices random 1-6 for each
PUBLIC int dice1 = 0;
PUBLIC int dice2 = 0;
PUBLIC int counter = 0;
PUBLIC int counter2 = 0;

TCPsocket server_socket;
Client clients[MAX_SOCKETS];
SDLNet_SocketSet socket_set;
TCPsocket sockets[MAX_SOCKETS];

void CloseSocket(int index);
int AcceptSocket(int index);
uint8_t* RecvData(int index, uint16_t* length);
void SendData(int index, uint8_t* data, uint16_t length, uint16_t flag);
void ProcessData(int index, uint8_t* data, uint16_t* offset, int* running);
int rollDice1();
int rollDice2();

int main(void)
{
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
        fprintf(stderr, "ER: SDL_Init: %sn", SDL_GetError());
        exit(-1);
    }

    if (SDLNet_Init() == -1) {
        fprintf(stderr, "ER: SDLNet_Init: %sn", SDLNet_GetError());
        exit(-1);
    }

    IPaddress ip;
    if (SDLNet_ResolveHost(&ip, NULL, 1234) == -1) {
        fprintf(stderr, "ER: SDLNet_ResolveHost: %sn", SDLNet_GetError());
        exit(-1);
    }

    server_socket = SDLNet_TCP_Open(&ip);
    if (server_socket == NULL) {
        fprintf(stderr, "ER: SDLNet_TCP_Open: %sn", SDLNet_GetError());
        exit(-1);
    }
    
    socket_set = SDLNet_AllocSocketSet(MAX_SOCKETS + 1);
    if (socket_set == NULL) {
        fprintf(stderr, "ER: SDLNet_AllocSocketSet: %sn", SDLNet_GetError());
        exit(-1);
    }

    if (SDLNet_TCP_AddSocket(socket_set, server_socket) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_AddSocket: %sn", SDLNet_GetError());
        exit(-1);
    }

    int running = 1;
    while (running) 
    {
        int num_rdy = SDLNet_CheckSockets(socket_set, 50);

        //if any client is ready connected, send the data to all logged clients
        if (num_rdy <= 0) {
            int ind;
            for (ind = 0; ind < MAX_SOCKETS; ++ind) {
                if (!clients[ind].in_use) continue;
                
                //Send packet to close all screens upon someone exiting
                if(closingWindows == 1)
                { 
                    clients[ind].closeWindows += 1;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].closeWindows, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_QUIT);
                }
                //Send packet to start the game (all players must enter start before beeing able to play)
                if (startingGame == 1)
                {
                    clients[ind].start += 1;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].start, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_START);
                }
                //Send packet to start the game (all players must select sprites before beeing able to play)
                if (selectSprite == 1)
                {
                    clients[ind].select += 1;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].select, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_CHOICE);
                }
                if (selectSprite == 1)
                {
                    clients[ind].colour = colour;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].colour, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);
                    
                    if(colourSelected==1)
                    {
                        SendData(ind, send_data, send_offset, FLAG_COLOUR1);
                    }
                    else if(colourSelected==2)
                    {
                        SendData(ind, send_data, send_offset, FLAG_COLOUR2);
                    }  
                    else if(colourSelected==3)
                    {
                        SendData(ind, send_data, send_offset, FLAG_COLOUR3);
                    }
                    else if(colourSelected==4)
                    {
                        SendData(ind, send_data, send_offset, FLAG_COLOUR4);
                    }                    
                }

                ////Send packet to roll the dice for all players
                if (roll == 1)
                {
                    clients[ind].rollDice = 1;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].rollDice, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_ROLL);
                }
                //Send packet for the 1:st dice
                if (roll == 1)
                {
                    clients[ind].diceRolling1 = diceOnline1;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].diceRolling1, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_ROLL_DICE1);
                }
                //Send packet for the 2:nd dice
                if (roll == 1)
                {
                    clients[ind].diceRolling2 = diceOnline2;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].diceRolling2, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_ROLL_DICE2);
                }
                //Send packet to indicate whom is player 1/2/3/4
                if (playerID == 1)
                {
                    clients[ind].playerIDnum = ind;

                    uint16_t send_offset = 0;
                    uint8_t send_data[MAX_PACKET];

                    memcpy(send_data + send_offset, &clients[ind].playerIDnum, sizeof(uint8_t));
                    send_offset += sizeof(uint8_t);

                    SendData(ind, send_data, send_offset, FLAG_INDEX);
                }
            }
            roll = 0;
            closingWindows = 0;
            startingGame = 0;
            colourSelected = 0;
            selectSprite = 0;
            diceOnline1 = 0;
            diceOnline2 = 0;
            playerID = 0;
        }
        //If no client is logged, check for incomming packets and give the client an id
        else {
            if (SDLNet_SocketReady(server_socket)) {
                int got_socket = AcceptSocket(next_ind);
                if (!got_socket) {
                    num_rdy--;
                    continue;
                }

                // NOTE: get a new index
                int chk_count;
                for (chk_count = 0; chk_count < MAX_SOCKETS; ++chk_count) {
                    if (sockets[(next_ind + chk_count) % MAX_SOCKETS] == NULL) break;
                }

                next_ind = (next_ind + chk_count) % MAX_SOCKETS;
                printf("DB: new connection (next_ind = %d)\n", next_ind);

                num_rdy--;
            }

            int ind;
            for (ind = 0; (ind < MAX_SOCKETS) && num_rdy; ++ind) {
                if (sockets[ind] == NULL) continue;
                if (!SDLNet_SocketReady(sockets[ind])) continue;

                uint8_t* data;
                uint16_t length;

                data = RecvData(ind, &length);
                if (data == NULL) {
                    num_rdy--;
                    continue;
                }

                int num_processed = 0;

                uint16_t offset = 0;
                while (offset < length) {
                    num_processed++;
                    ProcessData(ind, data, &offset, &running);
                }

                printf("num_processed from ID: %d was %d\n", ind, num_processed);
                fflush(stdout);

                free(data);
                num_rdy--;
            }
        }
    }

    if (SDLNet_TCP_DelSocket(socket_set, server_socket) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_DelSocket: %s\n", SDLNet_GetError());
        exit(-1);
    } SDLNet_TCP_Close(server_socket);

    int i;
    for (i = 0; i < MAX_SOCKETS; ++i) {
        if (sockets[i] == NULL) continue;
        CloseSocket(i);
    }

    SDLNet_FreeSocketSet(socket_set);
    SDLNet_Quit();
    SDL_Quit();

}

/*
* Below is all functions that handles packets from clients to server and back
* //////////////////////////////////////////////////////////////////////////// *
* data: a unsigned 8x char storing bytes of the data beeing handled or sent
* length: a unsigned 16x short for storing total length of bytes beeing handled or sent
* flag: a hex number indicating what is beeing sent/recived and how to process it
* offset:  a unsigned 16x short for masking the to a int
* index: a number indicating to which client the server is currently sending/recieving packets
*/

//Closes all sockets in use
void CloseSocket(int index) {
    if (sockets[index] == NULL) {
        fprintf(stderr, "ER: Attempted to delete a NULL socket.\n");
        return;
    }

    if (SDLNet_TCP_DelSocket(socket_set, sockets[index]) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_DelSocket: %s\n", SDLNet_GetError());
        exit(-1);
    }

    memset(&clients[index], 0x00, sizeof(Client));
    SDLNet_TCP_Close(sockets[index]);
    sockets[index] = NULL;
}

//Checks if any sockets is sending/receving packets and accepts the incomming socket for the index related
int AcceptSocket(int index) {
    if (sockets[index]) {
        fprintf(stderr, "ER: Overriding socket at index %d.\n", index);
        CloseSocket(index);
    }

    sockets[index] = SDLNet_TCP_Accept(server_socket);
    if (sockets[index] == NULL) return 0;

    clients[index].in_use = 1;
    if (SDLNet_TCP_AddSocket(socket_set, sockets[index]) == -1) {
        fprintf(stderr, "ER: SDLNet_TCP_AddSocket: %s\n", SDLNet_GetError());
        exit(-1);
    }

    return 1;
}

//Recives the data sent from the clientID and processes it to ProcessData
uint8_t* RecvData(int index, uint16_t* length) {
    uint8_t temp_data[MAX_PACKET];
    int num_recv = SDLNet_TCP_Recv(sockets[index], temp_data, MAX_PACKET);
    printf("What is recived: %d\n", num_recv);
    if (num_recv <= 0) {
        CloseSocket(index);

        const char* err = SDLNet_GetError();
        if (strlen(err) == 0) {
            printf("DB: client disconnected\n");
        }
        else {
            fprintf(stderr, "ER: SDLNet_TCP_Recv: %s\n", err);
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

//Send the data using a flag to tell the clients what to do
void SendData(int index, uint8_t* data, uint16_t length, uint16_t flag) {
    uint8_t temp_data[MAX_PACKET];

    int offset = 0;
    memcpy(temp_data + offset, &flag, sizeof(uint16_t));
    offset += sizeof(uint16_t);
    memcpy(temp_data + offset, data, length);
    offset += length;

    int num_sent = SDLNet_TCP_Send(sockets[index], temp_data, offset);
    if (num_sent < offset) {
        fprintf(stderr, "ER: SDLNet_TCP_Send: %s\n", SDLNet_GetError());
        CloseSocket(index);
    }
}

//Takes the data from RecvData and checks flags sent and changes conditions depending upon flag sent
void ProcessData(int index, uint8_t* data, uint16_t* offset, int *running) {
    if (data == NULL) return;

    uint16_t flag = *(uint16_t*)&data[*offset];
    *offset += sizeof(uint16_t);

    switch (flag) {
    case FLAG_QUIT: {
        closingWindows = 1;
    } break;
    case FLAG_START: {
        startingGame = 1;
    } break;
    case FLAG_CHOICE: {
        selectSprite = 1;
        colour = *(uint8_t*)&data[*offset];
        printf("chosed colour: %d\n", colour);
        *offset += sizeof(uint8_t);
    } break;
    case FLAG_COLOUR1: {
        colourSelected=1;
    }break;
    case FLAG_COLOUR2: {
        colourSelected=2;
    }break;
    case FLAG_COLOUR3: {
        colourSelected=3;
    }break;
    case FLAG_COLOUR4: {
        colourSelected=4;
    }break;
    case FLAG_ROLL: {
        roll = 1;
    } break;
    case FLAG_ROLL_DICE1: {
        diceOnline1 = rollDice1();
        diceOnline2 = rollDice2();
    } break;
    case FLAG_INDEX: {
        playerID = 1;
    } break;
    case 0: {
        *running = 0;
        printf("DB: shutdown by client id: %dn", index);
    } break;
    }
}

//roll 1:st dice
int rollDice1() {
    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    return dice1;
}

//roll 2:nd dice
int rollDice2()
{
    while (counter < 100)
    {
        srand(time(NULL));
        dice2 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        counter++;
    }
    counter = 0;
    return dice2;
}