#include <stdio.h>
#include <stdlib.h>
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
    int visible;
};
typedef struct card card;

struct deck{
    card deck[52];
};
typedef struct deck deck;

struct messages{
    char* lastCmd;
    char* message;
};
typedef struct messages messages;

struct gameState{
    deck currentDeck;
    char* message;
    char* lastCommand;
};
typedef struct gameState gameState;


void printInitialView();
void printCurrentView(deck*, messages*);
void deckInit(deck);
void shuffle(deck);
void takeInput(char*);

int evaluateCmd(char*, deck*, messages*);
void cmdLD(char*, deck*,  messages*);
void cmdSW(deck*);
void cmdSI(deck*, int);
int cmdQQ();
void cmdSR(deck*, deck*);

int randomNum();

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printInitialView();
    deck firstDeck = {};
    deck *deckptr = &firstDeck;
    messages gameMessages;
    messages *messagesptr = &gameMessages;
    //deckInit(firstDeck);

    char command[MAX_INPUT];
    while(1) {
        takeInput(command);
        if(!evaluateCmd(command, deckptr, messagesptr)){
            break;
        }
        printCurrentView(deckptr, messagesptr);
    }
    printf("%s", gameMessages.message);
    return 0;
}

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
            if (command[i + 3] == '\n' || command[i + 2] == '\n') {
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
    }else if(filetxt[0] = '\0') {
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

// Utility functions here:

int randomNum(){
    return (rand() % 52);
}

//LD factoryDeck.txt