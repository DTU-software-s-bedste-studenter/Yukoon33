//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#ifndef YUKOON33_STRUCTS_H
#define YUKOON33_STRUCTS_H
typedef enum suit{
    C = 'C',
    S = 'S',
    D = 'D',
    H = 'H'
} suit;

typedef struct card{
    suit suit;
    char number;
    int visible;
} card;

typedef struct deck{
    card deck[52];
} deck;

typedef struct messages{
    char* lastCmd;
    char* message;
} messages;

typedef struct gameState{
    deck currentDeck;
    char* message;
    char* lastCommand;
} gameState;

#endif //YUKOON33_STRUCTS_H
