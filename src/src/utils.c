//
// Created by Anthon Hertz Bie on 23/04/2023.
//


#include "../headders/utils.h"
void initializeGame(deck* currentDeck, gameBoard* board){
    int k = 1;
    int j = 2;
    int p = 5;
    for(int i = 0; i<52; i++) {
        if (i < 7) {
            char temp = i + 1 + '0';
            char temp2[2] = {'C', temp};
            initList(&board->board[i], temp2);
            if (i == 0) {
                currentDeck->deck[i].visible = 1;
            } else {
                currentDeck->deck[i].visible = 0;
            }
            addNode(currentDeck->deck[i], &board->board[i % 7]);
        } else if (i < 37) {
            if ((1 + (i % 6)) <= k) {
                currentDeck->deck[i].visible = 1;
            } else {
                currentDeck->deck[i].visible = 0;
            }
            addNode(currentDeck->deck[i], &board->board[1 + (i % 6)]);
            if (i % 6 == 0) {
                k++;
            }

        } else {
            currentDeck->deck[i].visible = 1;
            addNode(currentDeck->deck[i], &board->board[j + (i % p)]);
            if (i == 41 || i == 45 || i == 48 || i == 50 || i == 51) {
                j++;
                p--;
            }
        }
    }
        for (int l = 7; l < 11 ; ++l) {
            char temp = l - 6 + '0';
            char temp2[2] = {'F', temp};
            initList(&board->board[l], temp2);
        }

    }
/**
 *
 * @param moveCommand
 * @param display
 * @return IF function returns false then invalid move
 */
int evalMoveInput(char* moveCommand){
    if(moveCommand[0] == 'C'){
        if(!(moveCommand[1] > 48 && moveCommand[1] < 56)){
            return 0;
        }
    } else if( moveCommand[0] == 'F'){
        if(!(moveCommand[1] > 48 && moveCommand[1] < 53)){
            return 0;
        }
    }
    if(moveCommand[2] == ':'){
        if( !(moveCommand[4] == 'H' || moveCommand[4] == 'S' || moveCommand[4] == 'D' || moveCommand[4] == 'C'||moveCommand[4] >= 49 && moveCommand[4] <= 55) ){
            return 0;
        }
        if(!(moveCommand[3] > 48 && moveCommand[3] < 58 ||moveCommand[3] == 'A' || moveCommand[3] == 'T'|| moveCommand[3] == 'J'|| moveCommand[3] == 'Q'|| moveCommand[3] == 'K' || moveCommand[3] == 'C'|| moveCommand[3] == 'F')){
            return 0;
        }
        if(moveCommand[5] != '-'){
            return 0;
        }
        if(moveCommand[6] != '>'){
            return 0;
        }
        if(moveCommand[7] == 'C'){
            if(!(moveCommand[8] > 48 && moveCommand[8] < 56)){
                return 0;
            }
        } else if( moveCommand[7] == 'F'){
            if(!(moveCommand[8] > 48 && moveCommand[1] < 53)){
                return 0;
            }
        }
        if(moveCommand[0] == moveCommand[7] && moveCommand[1] == moveCommand[8]){
            return 0;
        }
    } else if(moveCommand[2] == '-' && moveCommand[3] == '>'){
        if(moveCommand[4] == 'C'){
            if(!(moveCommand[5] > 48 && moveCommand < 56)){
                return 0;
            }
        } else if( moveCommand[4] == 'F'){
            if(!(moveCommand[5] > 48 && moveCommand[5] < 53)){
                return 0;
            }
        }
    } else if(moveCommand[0] == 'P'){
        return 2;
    } else if(moveCommand[0] == '*'){
        return 3;
    }
    return 1;
}

int winnerFound(gameBoard* thisGame){
    int winner = 0;
    for (int i = 7; i < 11; ++i){
        if(thisGame->board[i].size == 13){
            winner++;
        }
    }
    if(winner == 4){
        return 1;
    }
    else{
        return 0;
    }
}
