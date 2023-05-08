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
            int eval = evalMoveInput(command);
            if(eval == 1) {
                list *fromlist = getListByName(command[0], command[1], thisGame);
                list *toList;
                node *fromCard;
                if (command[2] == '-' && command[3] == '>') {
                    toList = getListByName(command[4], command[5], thisGame);
                    fromCard = fromlist->tail->prev;
                } else if (command[2] == ':') {
                    toList = getListByName(command[7], command[8], thisGame);
                    fromCard = getCardByName(command[4], command[3], fromlist);
                } else {
                    toList = NULL;
                }
                if (toList != NULL) {
                    if (fromCard != 0) {
                        moveCard(fromCard, fromlist, toList, messagesptr);
                        messagesptr->lastCmd = command;
                    } else {
                        messagesptr->lastCmd = command;
                        messagesptr->message = "Invalid move";
                    }
                } else{
                    messagesptr->lastCmd = command;
                    messagesptr->message = "Invalid move";
                }
            }else if(eval == 2) {
                messagesptr->lastCmd = command;
                messagesptr->message = "OK, game started";
            }else if(eval == 3){
            messagesptr->lastCmd = "P";
            messagesptr->message = "Invalid move";
            }
            if(winnerFound(thisGame)){
                messagesptr->lastCmd = command;
                messagesptr->message = "Congratulations, you won the game!";
                cmdQ(currentPhase, deckptr);
            }
            printCurrentGame(thisGame, messagesptr);
        }
    }
    printf("%s", gameMessages.message);
    return 0;
}