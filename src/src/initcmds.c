//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#include "../headders/initcmds.h"
/**
 * A function meant to evaluating commands.
 * @param command the command string.
 * @param deck pointer for the deck currently in use.
 * @param display pointer for the messages that will be shown.
 * @return
 */
int evaluateCmd(char* command, deck* deck, messages* display, gameBoard* newGame, phase* currentPhase) {
    if(*currentPhase == I) {
        if (command[0] == 'L' && command[1] == 'D') {
            char filetxt[20];
            for (int i = 0; i < 20; i++) {
                filetxt[i] = command[i + 3];
                if (command[i + 3] == '\n' || command[2] == '\n') {
                    filetxt[i] = '\0';
                    break;
                }
            }
            display->lastCmd = command;
            display->message = "OK";

            cmdLD(filetxt, deck, display);
            return 1;
        } else if (command[0] == 'S' && command[1] == 'W') {
            cmdSW(deck);
            display->lastCmd = command;
            display->message = "OK";
            return 1;
        } else if (command[0] == 'S' && command[1] == 'I') {
            char numbers[3];
            for (int i = 0; i < 3; i++) {
                if (command[i + 3] == '\n') {
                    numbers[i] = '\0';
                    break;
                } else {
                    numbers[i] = command[i + 3];
                }
            }
            int number;
            if (command[4] == '\n') {
                number = (numbers[0] - 48);
            } else {
                number = (10 * (numbers[0] - 48)) + (numbers[1] - 48);
            }
            if (command[2] != ' ') {
                number = rand()%52;
            }
            if (number > 52 || 0 > number || command[5] != '\n') {
                display->lastCmd = command;
                display->message = "Number too large OR too small, for split";
                return 1;
            }
            cmdSI(deck, number);

            display->lastCmd = command;
            display->message = "OK";
            return 1;
        } else if (command[0] == 'S' && command[1] == 'R'&& command[2] == '\n') {
            cmdSR(deck);
            display->lastCmd = command;
            display->message = "OK";
            return 1;
        } else if (command[0] == 'S' && command[1] == 'D' ) {
            char filetxt[20];
            for (int i = 0; i < 20; i++) {
                filetxt[i] = command[i + 3];
                if (command[i + 3] == '\n' || command[2] == '\n') {
                    filetxt[i] = '\0';
                    break;
                }
            }
            cmdSD(deck, filetxt);
            display->lastCmd = command;
            display->message = "OK";
            return 1;
        } else if (command[0] == 'Q' && command[1] == 'Q' && command[2] == '\n') {
            display->lastCmd = command;
            display->message = "OK - BYE";
            return cmdQQ();
        } else if (command[0] == 'P' && command[1] == '\n') {
            cmdP(deck, newGame, currentPhase);
            display->lastCmd = command;
            display->message = "OK";
        } else{
            display->lastCmd = command;
            display->message = "Invalid command";
        }
    } else{
        if(command[0] == 'Q' && command[1] == '\n'){
            cmdQ(currentPhase, deck);
            display->lastCmd = command;
            display->message = "OK, entered STARTUP";
        }
        if(command[0] == 'P'){
            command[0] = '*';
        }
    }
}

void cmdLD(char* filetxt, deck* deck, messages* display){
    FILE *file = fopen(filetxt, "r");
    if(file != NULL) {
        for (int i = 0; i < 52; i++) {
            char card[5];
            fgets(card, sizeof(card), file);
            deck->deck[i].number = card[0];
            deck->deck[i].suit = (suit) card[1];
            deck->deck[i].visible = card[2] - 48;
        }
    }else if(filetxt[0] == '\0') {
        file = fopen("factoryDeck.txt", "r");
        for (int i = 0; i < 52; i++) {
            char card[5];
            fgets(card, sizeof(card), file);
            deck->deck[i].number = card[0];
            deck->deck[i].suit = (suit) card[1];
            deck->deck[i].visible = card[2] - 48;
        }
    } else{
        display->lastCmd = "LD\n";
        display->message = "File doesn't exist";
    }
}

void cmdSW(deck* deck1){
    for(int i = 0; i < 52;i++) {
        deck1->deck[i].visible = 1;
    }
}

void cmdHD(deck* deck1){
    for(int i = 0; i < 52;i++) {
        deck1->deck[i].visible = 0;
    }
}

void cmdSI(deck* deck, int split){
    card cards1[split];
    card cards2[52 - split];
    int j = 0;
    int k = 0;
    //splitting the card array into two temp. card arrays.
    for(int i = 0; i < 52; i++){
        if(i < split){
            cards1[j] = deck->deck[i];
            j++;
        } else{
            cards2[k] = deck->deck[i];
            k++;
        }
    }
    int smallest;
    int deckChoice;
    if(k > j){
        smallest = j * 2;
        deckChoice = 0;
    } else{
        smallest = k * 2;
        deckChoice = 1;
    }
    k = 0;
    j = 0;
    for(int i = 0; i < smallest; i++){
        if(i % 2){
            deck->deck[i] = cards1[k];
            k++;
        } else{
            deck->deck[i] = cards2[j];
            j++;
        }
    }
    k = smallest / 2;
    for(int i = smallest;i < 52; i++){
        if(deckChoice){
            deck->deck[i] = cards1[k];
            k++;
        } else{
            deck->deck[i] = cards2[k];
            k++;
        }
    }

}

void cmdSR(deck* input){
    for (int i = 0; i < 52; i++){
        srand(time(0));
        int random = rand() % 52;
        card tempCard = input->deck[i];
        input->deck[i] = input->deck[random];
        input->deck[random] = tempCard;
    }
}

void cmdSD(deck* currentdeck, char* filename){
    FILE* file;
    if (filename[0] == '\0'){
        file = fopen("cards.txt", "w");
    } else {
        file = fopen(filename, "w");
    }
    for(int i = 0; i < 52; i++) {
        fprintf(file, "%c%c%d\n", currentdeck->deck[i].number, currentdeck->deck[i].suit, currentdeck->deck[i].visible);
    }
    fclose(file);
}

int cmdQQ(){
    return 0;
}

int cmdQ(phase* currentPhase, deck* currentdeck){
    *currentPhase = I;
    cmdHD(currentdeck);
}

int cmdP(deck* currentDeck, gameBoard* board, phase* currentPhase){
    *currentPhase = G;
    for(int i = 0; i<11; i++){
        board->board[i].size = 0;
    }
    initializeGame(currentDeck, board);
}

