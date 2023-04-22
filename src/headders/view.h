//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#ifndef YUKOON33_VIEW_H
#define YUKOON33_VIEW_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#define MAX_INPUT 30

void printInitialView();
void printCurrentView(deck*, messages*);
void deckInit(deck);
void shuffle(deck);
void takeInput(char*);

#endif //YUKOON33_VIEW_H
