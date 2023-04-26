#include <stdio.h>
#include "../headders/view.h"
#include "../headders/initcmds.h"


int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printInitialView();
    deck firstDeck = {};
    deck *deckptr = &firstDeck;
    messages gameMessages;
    messages *messagesptr = &gameMessages;
    deckInit(firstDeck);
    phase gamePhase = I;
    phase* currentPhase = &gamePhase;
    gameBoard thisGameptr;
    gameBoard* thisGame = &thisGameptr;
    char command[MAX_INPUT];
    while(1) {
        takeInput(command);
        if(!evaluateCmd(command, deckptr, messagesptr, thisGame, currentPhase)){
            break;
        }
        if(*currentPhase == I) {
            printCurrentView(deckptr, messagesptr);
        }
        if(*currentPhase == G){
            printCurrentGame(thisGame, messagesptr);
        }
    }
    printf("%s", gameMessages.message);
    return 0;
}