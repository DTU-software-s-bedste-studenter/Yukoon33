//
// Created by Anthon Hertz Bie on 23/04/2023.
//


#include "../headders/utils.h"
int randomNum(){
    return (rand() % 52);
}

void initializeGame(deck* currentDeck, gameBoard* board){
    int k = 1;
    int j = 2;
    int p = 5;
    for(int i = 0; i<52; i++){
        if(i < 7) {
            if(i == 0){
                currentDeck->deck[i].visible = 1;
            } else{
                currentDeck->deck[i].visible = 0;
            }
            addNode(currentDeck->deck[i], &board->board[i % 7]);
        }else if(i < 37){
            if((1 + (i % 6)) <= k){
                currentDeck->deck[i].visible = 1;
            } else{
                currentDeck->deck[i].visible = 0;
            }
            addNode(currentDeck->deck[i], &board->board[1 + (i % 6)]);
            if(i % 6 == 0){
                k++;
            }

        } else{
            currentDeck->deck[i].visible = 1;
            addNode(currentDeck->deck[i], &board->board[j + (i % p)]);
            if(i == 41 || i == 45 || i == 48 || i == 50 || i == 51) {
                j++;
                p--;
            }
        }

    }
}

int wrongPhaseErr(messages* display){
    display->lastCmd = "wrong phase";
}
