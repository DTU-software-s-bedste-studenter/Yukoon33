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
    cmdList gameCmds = {};
    cmdList *gameCmdsptr = &gameCmds;
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
            if(eval == 5){
                for(int i = 0; i < strlen(gameCmds.current->next->cmd); ++i) {
                    command[i] = gameCmdsptr->current->next->cmd[i];
                }

            }
            if(eval == 1 || eval == 5) {
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
                        int visible = moveCard(fromCard, fromlist, toList, messagesptr);
                        messagesptr->lastCmd = command;
                        if(visible == 1 || visible == 2 || visible == 3) {
                            addCmdNode(command, gameCmdsptr, visible);
                        }
                    } else {
                        messagesptr->lastCmd = command;
                        messagesptr->message = "Invalid move";
                    }
                } else{
                    messagesptr->lastCmd = command;
                    messagesptr->message = "Invalid move";
                }
                if(eval == 5) {
                    if (gameCmds.current->next->cmd[0] == gameCmds.tail->cmd[0]) {
                        messagesptr->lastCmd = "R\n";
                        messagesptr->message = "Can't redo, there is nothing to redo";
                    } else {
                        messagesptr->lastCmd = "R\n";
                        messagesptr->message = "OK";
                        gameCmds.current = gameCmds.current->next;
                        gameCmds.size = gameCmds.size + 1;
                    }
                }
            } else if(eval == 2) {
                messagesptr->lastCmd = command;
                messagesptr->message = "OK, game started";
            } else if(eval == 3){
            messagesptr->lastCmd = "P\n";
            messagesptr->message = "Invalid move";
            } else if(eval == 4){
                reverseMove(gameCmdsptr->current->cmd, gameCmdsptr, thisGame, messagesptr);
            } else {
                messagesptr->lastCmd = command;
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