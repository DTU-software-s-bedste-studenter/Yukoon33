//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#include "../headders/view.h"
void printInitialView(){
    for(int i = 1; i < 8; i++){
        printf("C%d\t", i);
    }
    printf("\n\n");
    for(int j = 1; j<5; j++) {
        for (int i = 1; i < 8; i++) {
            printf("\t");
        }
        printf("[] : F%d\n\n", j);
    }
    printf("LAST Command:");
    printf("\nMessage:");
    printf("\nINPUT > ");
}

void printCurrentView(deck* deck1, messages* display){
    for(int i = 1; i < 8; i++){
        printf("C%d\t", i);
    }
    printf("\n\n");
    int k = 0;
    for(int j = 0; j<8; j++) {
        for (int i = 1; i < 8; i++) {
            if(k > 51){
                printf("\t");
                continue;
            } else if(deck1->deck[k].visible) {
                printf("%c%c\t", deck1->deck[k].number, deck1->deck[k].suit);
            } else{
                printf("[]\t");
            }
            k++;
        }
        if(j%2 == 0) {
            printf("[] : F%d\n", j);
        } else{
            printf("\n");
        }
    }
    printf("LAST Command: ");
    printf("%s", display->lastCmd);
    printf("\nMessage: ");
    printf("%s", display->message);
    printf("\nINPUT > ");
}

void deckInit(deck firstDeck) {
    int cardCount = 0;
    suit localSuit = C;
    FILE *file;
    file = fopen("factoryDeck.txt", "w");
    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 14; i++) {
            card newCard;
            newCard.visible = 0;
            if (i == 1) {
                newCard.number = 'A';
            } else if (i == 10) {
                newCard.number = 'T';
            } else if(i == 11) {
                newCard.number = 'J';
            } else if(i == 12) {
                newCard.number = 'Q';
            }else if(i == 13){
                newCard.number = 'K';
            } else{
                char charNumber = i + '0';
                newCard.number = charNumber;
            }
            newCard.suit = localSuit;
            firstDeck.deck[cardCount] = newCard;
            cardCount++;
            fprintf(file, "%c%c%d\n", newCard.number, newCard.suit, newCard.visible);

        }
        switch(localSuit){
            case C:
                localSuit = H;
                break;
            case H:
                localSuit = S;
                break;
            case S:
                localSuit = D;
                break;
            case D:
                localSuit = C;
        }
    }
    fclose(file);
}

void takeInput(char* command){
    fgets(command, MAX_INPUT, stdin);
}