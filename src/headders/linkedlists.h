//
// Created by Anthon Hertz Bie on 24/04/2023.
//

#ifndef YUKOON33_LINKEDLISTS_H
#define YUKOON33_LINKEDLISTS_H
#include "structs.h"
#define DUMMY_VALUE {H, '#'};

void initList(list*);

void addNode(card, list*);

card* findNode(card, list*);

void moveCard(card* fromCard, list* toCard);

#endif //YUKOON33_LINKEDLISTS_H