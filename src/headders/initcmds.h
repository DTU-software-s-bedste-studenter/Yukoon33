//
// Created by Anthon Hertz Bie on 23/04/2023.
//

#ifndef YUKOON33_INITCMDS_H
#define YUKOON33_INITCMDS_H

#include <stdio.h>
#include "structs.h"
#include "utils.h"
int evaluateCmd(char*, deck*, messages*, gameBoard*, phase*);
void cmdLD(char*, deck*,  messages*);
void cmdSW(deck*);
void cmdHD(deck*);
void cmdSI(deck*, int);
void cmdSR(deck*);
void cmdSD(deck*, char*);
int cmdQQ();
int cmdP(deck*, gameBoard*,  phase*);
int cmdQ(phase*, deck*);
#endif //YUKOON33_INITCMDS_H
