#include <stdio.h>
#include "application.h"
#include "startingScreen.h"

int main(void)
{
    int playerCount = 0;
    const char * ipHostAddress = "";
    char ipAddress[50];

    ipHostAddress = startingScreen(&playerCount);
    printf("%d\n", playerCount);
    printf("%s\n", ipHostAddress);

    if (playerCount > 0)
    {
        Application theApp = createApplication(ipHostAddress);
        applicationUpdate(theApp, playerCount);
        destoryApplication(theApp);
    }

    return 0;
}
