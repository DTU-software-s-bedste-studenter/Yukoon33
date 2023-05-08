//
// Created by Anthon Hertz Bie on 24/04/2023.
//

#include "../headders/linkedlists.h"
#include <stdlib.h>
void initList(list* list, char* name){
    list->size = 0;
    list->name[0] = name[0];
    list->name[1] = name[1];
}

void addNode(card data, list* plist){
    node *newNode;
    newNode = (node *) malloc(sizeof(node));
    newNode->data = data;
    if(plist->size == 0){
        node *dummy;
        card dummyCard = DUMMY_VALUE;
        dummy = (node *) malloc(sizeof(node));
        dummy->data = dummyCard;
        plist->head = newNode;
        plist->tail = dummy;
        newNode->prev = dummy;
        newNode->next = dummy;
        dummy->prev = plist->head;
        dummy->next = plist->head;
    } else{
        node *secondLast = plist->tail->prev;
        secondLast->next = newNode;
        newNode->prev = secondLast;
        newNode->next = plist->tail;
        plist->tail->prev = newNode;
    }
    plist->size++;
}

node* findNode(card card, list* list){
    node* currentNode;
    currentNode = list->head;
    while(currentNode->data.number != '#'){
        if(currentNode->data.number == card.number && currentNode->data.suit == card.suit && currentNode->data.visible == 1){
            list->head = list->tail->next;
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

card* getByIndex(int index, list* list){
    node* currentNode;
    currentNode = list->head;
    int i = 0;
    while(i < list->size){
        if(i == index){
            return &currentNode->data;
        }
        currentNode = currentNode->next;
        i++;
    }
    return 0;
}

node* getCardByName(char suit, char number, list* fromlist){
    node* tempnode = fromlist->head;
    while(tempnode->data.number != '#'){
        if(tempnode->data.suit == suit && tempnode->data.number ==  number && tempnode->data.visible == 1){
            return tempnode;
        }
        tempnode = tempnode->next;
    }
    return 0;
}

list* getListByName(char column, char number, gameBoard* gameBoard1){
    for(int i = 0; i < 11; ++i){
        if(gameBoard1->board[i].name[0] == column && gameBoard1->board[i].name[1] == number){
            return &gameBoard1->board[i];
        }
    }
}


/**
 * first we check if the card is in the pile, if not: error. if it is
 * then we check if the to-pile to is empty, if it is
 * then we check if the to-card pile is an F pile, if it is
 * then we check if the card(s) is an A, if it is
 * then we check if it is only one card is to be moved, if not: error. if it is
 * then we move the card.
 *
 * If it wasn't empty, then we check if the cards are valid to be put on top of eachother.
 *
 * Missing error statements, and haven't been implemented yet
 *
 * @param fromCard
 * @param fromPile
 * @param toPile
 */


int moveCard(node* fromCard, list* fromPile, list* toPile, messages* display) {
    char numbers[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'NULL'};
    size_t numbersSize = sizeof(numbers)/sizeof(numbers[0]);

    node* tempFromCard = fromCard;
    if(tempFromCard->data.visible == 0){
        display->message = "Invalid move, card not visible";
        return 0;
    }
    node* prevCard = findNode(fromCard->data, fromPile)->prev;

    if (toPile->size == 0) {
        if (fromCard->data.number == 'A' && toPile->name[0] == 'F') {
            if (fromPile->tail->prev->data.number != fromCard->data.number ||
                fromPile->tail->prev->data.suit != fromCard->data.suit) {
                display->message = "Invalid move, only one card at a time to F-piles";
                return 0;
            }
            addNode(fromCard->data, toPile);
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            fromPile->size = fromPile->size - 1;
            display->message = "OK";
            if(prevCard->data.visible == 0){
                prevCard->data.visible = 1;
                return 2;
            }
            return 1;
        } else if (toPile->name[0] == 'F') {
            display->message = "Invalid move, needs to be Ace";
            return 0;
        } else if(toPile->name[0] == 'C' && fromCard->data.number != 'K') {
            display->message = "Invalid move, you can only move a king to an empty C-pile";
            return 0;
        } else{
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            display->message = "OK";
            if(prevCard->data.visible == 0){
                prevCard->data.visible = 1;
                return 2;
            }
            return 1;
        }
    }


    if (fromCard->data.suit != toPile->tail->prev->data.suit && toPile->name[0] == 'F') {
        display->message = "Invalid move, can't move a card of different suit to this pile";
        return 0;
    }
    if (fromCard->data.suit == toPile->tail->prev->data.suit && toPile->name[0] == 'C') {
        display->message = "Invalid move, can't move a card of same suit to this pile";
        return 0;
    }
    int firstNumber = 0;
    int secondNumber = 0;
    for (int i = 0; i < numbersSize; ++i) {
        if (numbers[i] == fromCard->data.number) {
            firstNumber = i;
        }
        if (numbers[i] == toPile->tail->prev->data.number) {
            secondNumber = i;
        }
    }
    if (toPile->name[0] == 'F') {
        if (numbers[firstNumber] != numbers[secondNumber + 1]) {
            display->message = "Invalid move";
            return 0;
        } else {
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            toPile->tail->prev->prev->data.visible = 0;
            display->message = "OK";
            if(prevCard->data.visible == 0){
                prevCard->data.visible = 1;
                return 2;
            }
            return 1;
        }
    } else if (toPile->name[0] == 'C') {
        if (numbers[firstNumber + 1] != numbers[secondNumber]) {
            display->message = "Invalid move";
            return 0;
        } else {
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            display->message = "OK";
            if(prevCard->data.visible == 0){
                prevCard->data.visible = 1;
                return 2;
            }
            return 1;
        }
    }
    display->message = "Invalid move";
    return 0;

}

void reverseMove(char* command, cmdList* gameCmds, gameBoard* gameBoard1, int prevVisible, messages* messages1){
    if(gameCmds->current != gameCmds->tail) {
        char firstColoum[2];
        firstColoum[0] = command[0];
        firstColoum[1] = command[1];
        char secondColoum[2];
        char cardZ[2];
        if (command[2] == ':') {
            secondColoum[0] = command[7];
            secondColoum[1] = command[8];
            cardZ[0] = command[3];
            cardZ[1] = command[4];
        } else {
            secondColoum[0] = command[4];
            secondColoum[1] = command[5];
        }
        list *coloumTo = getListByName(firstColoum[0], firstColoum[1], gameBoard1);
        list *coloumFrom = getListByName(secondColoum[0], secondColoum[1], gameBoard1);
        node *thisCard;
        if (command[2] == ':') {
            card actual = getCardByName(cardZ[1], cardZ[0], coloumFrom)->data;
            thisCard = findNode(actual, coloumFrom);
        } else {
            thisCard = coloumFrom->tail->prev;
        }
        node *prevCard;
        if (coloumFrom->size > 1) {
            prevCard = findNode(thisCard->data, coloumFrom)->prev;
        } else {
            prevCard = coloumFrom->tail;
        }
        if (!prevVisible && coloumTo->size != 0) {
            if (coloumTo->name[0] == 'C') {
                coloumTo->tail->prev->data.visible = 0;
            }
        }
        while (thisCard->data.number != '#') {
            addNode(thisCard->data, coloumTo);
            coloumFrom->size = coloumFrom->size - 1;
            thisCard = thisCard->next;
        }

        prevCard->next = coloumFrom->tail;
        coloumFrom->tail->prev = prevCard;
        gameCmds->current = gameCmds->current->prev;



    //012345678
    //c1:2h->c2
    //c1->c2


}

void addCmdNode(char* data, cmdList* plist, int pastVisible){
    cmdNode *newNode;
    newNode = (cmdNode *) malloc(sizeof(cmdNode));
    char *newData = (char*) malloc(sizeof(data));
    strcpy(newData ,data);
    newNode->cmd = newData;
    if(plist->size == 0){
        cmdNode *dummy;
        char* dummyCMD = DUMMY_CMD;
        dummy = (cmdNode *) malloc(sizeof(cmdNode));
        dummy->cmd = dummyCMD;
        plist->head = newNode;
        plist->tail = dummy;
        newNode->prev = dummy;
        newNode->next = dummy;
        dummy->prev = plist->head;
        dummy->next = plist->head;
    } else{
        cmdNode *secondLast = plist->tail->prev;
        secondLast->next = newNode;
        newNode->prev = secondLast;
        newNode->next = plist->tail;
        plist->tail->prev = newNode;
    }
    if(pastVisible == 2){
        newNode->pastVisible = 0;
    } else{
        newNode->pastVisible = 1;
    }
    plist->current = plist->tail->prev;
    plist->size++;
}
