#include <stdio.h>
#include <stdbool.h>
#define MAX_INPUT 30

enum suit{
    C = 'C',
    S = 'S',
    D = 'D',
    H = 'H'
};
typedef enum suit suit;

struct card{
    suit suit;
    char number;
    bool visible;
};
typedef struct card card;

struct deck{
    card deck[52];
};
typedef struct deck deck;

struct gameState{
    deck currentDeck;
    char* message;
    char* lastCommand;

};

void printInitialView();
void deckInit(deck);
void shuffel(deck);
void takeInput(char*);
void evaluateCmd(char*, deck* deck);
void cmdLD(char*, deck*);

int main(void) {
    printInitialView();
    deck firstDeck = {};
    deck *deckptr = &firstDeck;
    //deckInit(firstDeck);
    char command[MAX_INPUT];
    takeInput(command);
    evaluateCmd(command, deckptr);
    return 0;
}

void printInitialView(){
    for(int i = 1; i < 8; i++){
        printf("C%d\t", i);
    }
    printf("\n");
    for(int j = 1; j<5; j++) {
        for (int i = 1; i < 8; i++) {
            printf("\t");
        }
        printf("[]\tF%d\n\n", j);
    }
    printf("LAST Command:");
    printf("\nMessage:");
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
            fprintf(file, "%c%c\n", newCard.number, newCard.suit);

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

void evaluateCmd(char* command, deck* deck){
    if(command[0] == 'L' && command[1] == 'D'){
        char filetxt[20];
        for(int i = 0; i < 20; i++){
            filetxt[i] = command[i + 3];
            if(command[i + 3] == '\n'){
                filetxt[i] = '\0';
                break;
            }
        }

        cmdLD(filetxt, deck);
    }
}

void cmdLD(char* filetxt, deck* deck){
    FILE *file = fopen(filetxt, "r");
    if(file != NULL) {
        for (int i = 0; i < 52; i++) {
            char card[4];
            fgets(card, sizeof(card), file);
            deck->deck[i].number = card[0];
            deck->deck[i].suit = (suit) card[1];
        }
    } else{
        printf("File doesn't exist");
    }
}