//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#ifndef YUKOON33_CMDS_H
#define YUKOON33_CMDS_H

#include <stdio.h>
#include "structs.h"
#include "utils.h"
int evaluateCmd(char*, deck*, messages*);
void cmdLD(char*, deck*,  messages*);
void cmdSW(deck*);
void cmdSI(deck*, int);
int cmdQQ();
void cmdSR(deck*, deck*);
#endif //YUKOON33_CMDS_H
