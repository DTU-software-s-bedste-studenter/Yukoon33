#include <stdio.h>
#include "src/headders/view.h"
#include "src/headders/cmds.h"


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printInitialView();
    deck firstDeck = {};
    deck *deckptr = &firstDeck;
    messages gameMessages;
    messages *messagesptr = &gameMessages;
    //deckInit(firstDeck);

    char command[MAX_INPUT];
    while(1) {
        takeInput(command);
        if(!evaluateCmd(command, deckptr, messagesptr)){
            break;
        }
        printCurrentView(deckptr, messagesptr);
    }
    printf("%s", gameMessages.message);
    return 0;
}