//
// Created by Anthon Hertz Bie on 24/04/2023.
//

#ifndef YUKOON33_LINKEDLISTS_H
#define YUKOON33_LINKEDLISTS_H
#include "structs.h"
#define DUMMY_VALUE {H, '#'};

void initList(list*, char*);

void addNode(card, list*);

card* findCard(card card, list *list);

node* findNode(card card, list* list);

card* getByIndex(int index, list* list);

void moveCard(card* fromCard, list* fromCardPile, list* toCard);

#endif //YUKOON33_LINKEDLISTS_H