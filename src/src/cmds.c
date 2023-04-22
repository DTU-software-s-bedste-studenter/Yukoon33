//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#include "../headders/cmds.h"
/**
 * A function meant to evaluating commands.
 * @param command the command string.
 * @param deck pointer for the deck currently in use.
 * @param display pointer for the messages that will be shown.
 * @return
 */
int evaluateCmd(char* command, deck* deck, messages* display) {
    if (command[0] == 'L' && command[1] == 'D') {
        char filetxt[20];
        for (int i = 0; i < 20; i++) {
            filetxt[i] = command[i + 3];
            if (command[i + 3] == '\n' || command[2] == '\n') {
                filetxt[i] = '\0';
                break;
            }
        }
        display->lastCmd = "LD";
        display->message = "OK";

        cmdLD(filetxt, deck, display);
        return 1;
    }

    if(command[0] == 'S' && command[1] == 'W'){
        cmdSW(deck);
        display->lastCmd = "SW";
        display->message = "OK";
        return 1;
    } else if(command[1] == 'I') {
        char numbers[3];
        for (int i = 0; i < 3; i++) {
            if (command[i + 3] == '\n') {
                numbers[i] = '\0';
                break;
            } else{
                numbers[i] = command[i + 3];
            }
        }
        int number;
        if (command[4] == '\n') {
            number = (numbers[0] - 48);
        } else {
            number = (10 * (numbers[0] - 48)) + (numbers[1] - 48);
        }
        if(command[2] != ' '){
            number = randomNum();
        }
        if(number > 52 || 0 > number){
            display->lastCmd = "SI";
            display->message = "Number to large, for split";
            return 1;
        }
        cmdSI(deck, number);

        display->lastCmd = "SI";
        display->message = "OK";
    }
    else if(command[1] == 'R'){

        cmdSR(deck, deck);
        display->lastCmd = "SR";
        display->message = "OK";
    }

    if (command[0] == 'Q' && command[1] == 'Q') {
        display->message = "OK - BYE";
        return cmdQQ();
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
        display->lastCmd = "LD";
        display->message = "File doesn't exist";
    }
}

void cmdSW(deck* deck1){
    for(int i = 0; i < 52;i++) {
        deck1->deck[i].visible = 1;
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



int cmdQQ(){
    return 0;
}

void cmdSR(deck* input, deck* ref){
    card newDeck[52];
    for (int i = 0; i < 52; i++){
        newDeck[randomNum()] = input->deck[i];
    }
    ref = &newDeck;
}