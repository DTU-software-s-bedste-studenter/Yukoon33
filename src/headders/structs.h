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

typedef struct node{
    struct node* next;
    struct node* prev;
    card data;
} node;

typedef struct cmdNode{
    struct cmdNode* next;
    struct cmdNode* prev;
    char* cmd;
    int pastVisible;
} cmdNode;

typedef struct cmdList{
    cmdNode* head;
    cmdNode* tail;
    cmdNode* current;
    int size;
} cmdList;

typedef struct list{
    char name[2];
    node* head;
    node* tail;
    int size;
}list;

typedef enum phase{
    I = 'I', //Inital phase
    G = 'G'  //Game phase
} phase;

typedef struct gameBoard{
    list board[11];
} gameBoard;

typedef struct gameState{
    phase currentPhase;
    deck currentDeck;
    char* message;
    char* lastCommand;
} gameState;



#endif //YUKOON33_STRUCTS_H
