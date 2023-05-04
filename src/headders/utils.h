//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#ifndef YUKOON33_UTILS_H
#define YUKOON33_UTILS_H
#include <stdlib.h>
#include "structs.h"
#include "linkedlists.h"
int randomNum();
void initializeGame(deck*, gameBoard*);
int evalMoveInput(char*);
int wrongPhaseErr(messages*);

#endif //YUKOON33_UTILS_H
