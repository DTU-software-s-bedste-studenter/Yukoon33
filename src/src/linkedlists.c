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
    card* tempcard = &tempnode->data;
    while(tempcard->number != '#'){
        tempcard = &tempnode->data;
        if(tempcard->suit == suit && tempcard->number ==  number && tempcard->visible == 1){
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

node* getLastCardFromList(list* thisList){
    return thisList->tail->prev;
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
// C1H2:C8
// C6:H2->C4
void moveCard(node* fromCard, list* fromPile, list* toPile, messages* display) {
    char numbers[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'NULL'};
    size_t numbersSize = sizeof(numbers)/sizeof(numbers[0]);

    node* tempFromCard = fromCard;
    if(tempFromCard->data.visible == 0){
        display->message = "Invalid move, card not visible";
        return;
    }
    node* prevCard = findNode(fromCard->data, fromPile)->prev;

    if (toPile->size == 0) {
        if (fromCard->data.number == 'A' && toPile->name[0] == 'F') {
            if (fromPile->tail->prev->data.number != fromCard->data.number ||
                fromPile->tail->prev->data.suit != fromCard->data.suit) {
                display->message = "Invalid move, only one card at a time to F-piles";
                return;
            }
            addNode(fromCard->data, toPile);
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            fromPile->size = fromPile->size - 1;
            display->message = "OK";
            return;
        } else if (toPile->name[0] == 'F') {
            display->message = "Invalid move, needs to be Ace";
            return;
        } else if(toPile->name[0] == 'C' && fromCard->data.number != 'K') {
            display->message = "Invalid move, you can only move a king to an empty C-pile";
            return;
        } else{
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            prevCard->data.visible = 1;
            return;
        }
    }


    if (fromCard->data.suit != toPile->tail->prev->data.suit && toPile->name[0] == 'F') {
        display->message = "Invalid move, can't a card of the different suit to this pile";
        return;
    }
    if (fromCard->data.suit == toPile->tail->prev->data.suit && toPile->name[0] == 'C') {
        display->message = "Invalid move, wrong suit";
        return;
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
            return; //print error statement
        } else {
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            prevCard->data.visible = 1;
            toPile->tail->prev->prev->data.visible = 0;
            display->message = "OK";
            return;
        }
    } else if (toPile->name[0] == 'C') {
        if (numbers[firstNumber + 1] != numbers[secondNumber]) {
            return; //print error statement
        } else {
            while (tempFromCard->data.number != '#') {
                addNode(tempFromCard->data, toPile);
                fromPile->size = fromPile->size - 1;
                tempFromCard = tempFromCard->next;
            }
            prevCard->next = fromPile->tail;
            fromPile->tail->prev = prevCard;
            prevCard->data.visible = 1;
            return;
        }
    }
    return; //print error statement
}
