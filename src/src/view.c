//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#include "../headders/view.h"
void printInitialView(){
    for (int n = 0; n < 10; n++) {
        printf("\n\n\n\n\n\n\n\n\n\n");
    }
    printTitle();
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
    printf("\nLAST Command:");
    printf("\nMessage:");
    printf("\nINPUT > ");
}

void printCurrentView(deck* deck1, messages* display){
    for (int n = 0; n < 10; n++) {
        printf("\n\n\n\n\n\n\n\n\n\n");
    }
    printTitle();
    if(deck1->deck[0].number != 0) {
        for (int i = 1; i < 8; i++) {
            printf("C%d\t", i);
        }
        printf("\n\n");
        int k = 0;
        for (int j = 0; j < 8; j++) {
            for (int i = 1; i < 8; i++) {
                if (k > 51) {
                    printf("\t");
                    continue;
                } else if (deck1->deck[k].visible) {
                    printf("%c%c\t", deck1->deck[k].number, deck1->deck[k].suit);
                } else {
                    printf("[]\t");
                }
                k++;
            }
            if (j % 2 == 0) {
                printf("[] : F%d\n", j);
            } else {
                printf("\n");
            }
        }
    }else{
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
    }
        printf("\nLAST Command: ");
        printf("%s", display->lastCmd);
        printf("Message: ");
        printf("%s", display->message);
        printf("\nINPUT > ");
}

void printCurrentGame(gameBoard* currentGame, messages* display){
    for (int n = 0; n < 10; n++) {
        printf("\n\n\n\n\n\n\n\n\n\n");
    }
    printTitle();
    for(int i = 1; i < 8; i++){
        printf("C%d\t", i);
    }
    printf("\n\n");
    int row = 0;
    int column = 0;
    int fTiles = 7;
    int finishedColoums[7] = {0,0,0,0,0,0,0};
    while(1){
        card* thisCard = getByIndex(row, &currentGame->board[column % 7]);
        if(thisCard != 0) {
            if (thisCard->visible) {
                printf("%c%c\t", thisCard->number, thisCard->suit);
            } else {
                printf("[]\t");
            }

        } else{
            printf("\t");
            finishedColoums[column % 7] = 1;
        }
        column++;
        int sum = 0;
        if(column % 7 == 0){
            if(row % 2 == 0 && row < 8) {
                if(currentGame->board[fTiles].size == 0) {
                    printf("[] : F%d\n", 1 + row / 2);
                }else{
                    card* otherCard = &currentGame->board[fTiles].tail->prev->data;
                    printf( "%c%c : F%d\n", otherCard->number, otherCard->suit, 1 + row / 2);
                }
                fTiles++;
            } else{
                printf("\n");
                for(int i = 0; i<7; i++){
                    sum += finishedColoums[i];
                }
            }
            row++;
        }



        if(sum == 7 && row > 8){
            break;
        }
    }
    printf("\nLAST Command: ");
    printf("%s", display->lastCmd);
    printf("Message: ");
    printf("%s", display->message);
    printf("\nINPUT > ");
}

void printTitle(){
    printf("---------------------------------------------------------------------\n");
    printf("    \\\\   // ||  || ||  //  ||‾‾|| ||‾‾|| ||  ||    3333    3333 \n");
    printf("     \\\\ //  ||  || || //   ||  || ||  || ||\\ ||       333     333\n");
    printf("      \\//   ||  || ||||    ||  || ||  || ||\\\\||     333     333  \n");
    printf("     ///    ||  || || \\\\   ||  || ||  || || \\||       333     333\n");
    printf("    ///     ||__|| ||  \\\\  ||__|| ||__|| ||  ||    3333    3333 \n");
    printf("---------------------------------------------------------------------\n");
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