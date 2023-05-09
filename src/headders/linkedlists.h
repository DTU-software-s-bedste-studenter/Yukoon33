//
// Created by Anthon Hertz Bie on 24/04/2023.
//

#ifndef YUKOON33_LINKEDLISTS_H
#define YUKOON33_LINKEDLISTS_H
#include <string.h>
#include "structs.h"
#define DUMMY_VALUE {H, '#'};
#define DUMMY_CMD "!!!!"

void initList(list*, char*);

void addNode(card, list*);

node* findNode(card card, list* list);

card* getByIndex(int index, list* list);

node* getCardByName(char suit, char number, list* list);

list* getListByName(char, char, gameBoard*);

int moveCard(node* fromCard, list* fromPile, list* toPile, messages* display);

void reverseMove(char*, cmdList*, gameBoard*, messages*);

void addCmdNode(char*, cmdList*, int);

#endif //YUKOON33_LINKEDLISTS_H