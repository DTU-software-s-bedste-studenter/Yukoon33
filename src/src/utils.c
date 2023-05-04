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
            char temp = i + 1;
            char temp2[2] = {'C', temp};
            initList(&board->board[i], temp2);
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
        for (int l = 7; l < 11 ; ++l) {
            char temp = l - 6;
            char temp2[2] = {'F', temp};
            initList(&board->board[i], temp2);
        }

    }
}

int evalMoveInput(char* moveCommand){
    if(moveCommand[0] == 'C'){
        if(moveCommand[1] < 49 && moveCommand > 55){
            return 0; //error
        }
    } else if( moveCommand[0] == 'F'){
        if(moveCommand[1] < 49 && moveCommand[1] > 52){
            return 0;
        }
    }
    if(moveCommand[2] != ':'){
        return 0; //error
    }
    if( !(moveCommand[3] == 'H' || moveCommand[3] == 'S' || moveCommand[3] == 'D' || moveCommand[3] == 'C') ){
        return 0; // error
    }
    if(!(moveCommand[4] > 48 && moveCommand[4] < 58 || moveCommand[4] == 'T'|| moveCommand[4] == 'J'|| moveCommand[4] == 'Q'|| moveCommand[4] == 'K')){
        return 0; //error
    }
    if(moveCommand[5] != '-'){
        return 0; //error
    }
    if(moveCommand[6] != '>'){
        return 0; //error
    }
    if(moveCommand[7] == 'C'){
        if(moveCommand[8] < 49 && moveCommand > 55){
            return 0; //error
        }
    } else if( moveCommand[7] == 'F'){
        if(moveCommand[8] < 49 && moveCommand[1] > 52){
            return 0; // error
        }
    }
    return 1;
}

int wrongPhaseErr(messages* display){
    display->lastCmd = "wrong phase";
}
