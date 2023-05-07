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
            if(evalMoveInput(command)){
                list* fromlist = getListByName(command[0], command[1], thisGame);
                list* toList = getListByName(command[7], command[8], thisGame); // if else for toList, else should be command[3], command[4], thisGame
                node* fromCard = getCardByName(command[4], command[3],fromlist);
                if(fromCard != 0) {
                    moveCard(fromCard, fromlist, toList);
                } else{
                    //error
                }
            } else{

            }
            printCurrentGame(thisGame, messagesptr);
            if(winnerFound(thisGame)){
                //winner message here
                cmdQ(currentPhase);
            }
        }
    }
    printf("%s", gameMessages.message);
    return 0;
}