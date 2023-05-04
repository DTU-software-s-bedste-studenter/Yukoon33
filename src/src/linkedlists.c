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

card* findCard(card card, list* list){
    node* currentNode;
    currentNode = list->head;
    while(currentNode->data.number != '#'){
        if(currentNode->data.number == card.number && currentNode->data.suit == card.suit && currentNode->data.visible == 1){
            return &currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return 0;
}

node* findNode(card card, list* list){
    node* currentNode;
    currentNode = list->head;
    while(currentNode->data.number != '#'){
        if(currentNode->data.number == card.number && currentNode->data.suit == card.suit && currentNode->data.visible == 1){
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

card* getCardByName(char suit, char number, list* fromlist){
    node* tempnode = fromlist->head;
    card* tempcard = &tempnode->data;
    while(tempcard->number != '#'){
        tempcard = &tempnode->data;
        tempnode = tempnode->next;
        if(tempcard->suit == suit && tempcard->number ==  number && tempcard->visible == 1){
            return tempcard;
        }
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
 * @param fromCardPile
 * @param toCard
 */
// C1H2:C8
// C6:H2->C4
void moveCard(card* fromCard, list* fromCardPile, list* toCard) {
    char numbers[14] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'NULL'};
    size_t numbersSize = sizeof(numbers)/sizeof(numbers[0]);
    card* tempFromCard = fromCard;
    node* prevCard = findNode(*fromCard, fromCardPile)->prev;
    if (toCard->size == 0) {
        if (fromCard->number == 'A' && toCard->name[0] == 'F') {
            if (fromCardPile->tail->prev->data.number != fromCard->number &&
                fromCardPile->tail->prev->data.suit != fromCard->suit) {
                return; // error message
            }
            addNode(*fromCard, toCard);
            fromCardPile->size = fromCardPile->size-1;
            prevCard->next = fromCardPile->tail;
            fromCardPile->tail->prev = prevCard;
            return;
        } else if (toCard->name[0] == 'F') {
            return; //error message
        } else {
            while (tempFromCard->number != '#') {
                addNode(*tempFromCard, toCard);
                fromCardPile->size = fromCardPile->size-1;
                *tempFromCard = findNode(*tempFromCard, fromCardPile)->next->data;
            }
            prevCard->next = fromCardPile->tail;
            fromCardPile->tail->prev = prevCard;
            return;
        }
    }
    if (fromCard->suit != toCard->tail->prev->data.suit && toCard->name[0] == 'F') {
        return; //print error statement
    }
    if (fromCard->suit == toCard->tail->prev->data.suit && toCard->name[0] == 'C') {
        return; //print error statement
    }
    int firstNumber = (int) NULL;
    int secondNumber = (int) NULL;
    for (int i = 0; i < numbersSize; ++i) {
        if (numbers[i] == fromCard->number) {
            firstNumber = i;
        }
        if (numbers[i] == toCard->tail->prev->data.number) {
            secondNumber = i;
        }
    }
    if (toCard->name[0] == 'F') {
        if (numbers[firstNumber] != numbers[secondNumber + 1]) {
            return; //print error statement
        } else {
            while (tempFromCard->number != '#') {
                addNode(*tempFromCard, toCard);
                fromCardPile->size = fromCardPile->size-1;
                *tempFromCard = findNode(*tempFromCard, fromCardPile)->next->data;
            }
            prevCard->next = fromCardPile->tail;
            fromCardPile->tail->prev = prevCard;
            return;
        }
    } else if (toCard->name[0] == 'C') {
        if (numbers[firstNumber + 1] != numbers[secondNumber]) {
            return; //print error statement
        } else {
            prevCard->next = fromCardPile->tail;
            fromCardPile->tail->prev = prevCard;
            while (tempFromCard->number != '#') {
                addNode(*tempFromCard, toCard);
                fromCardPile->size = fromCardPile->size-1;
                tempFromCard = &findNode(*tempFromCard, fromCardPile)->next->data; //error happens here
            }
            prevCard->next = fromCardPile->tail;
            fromCardPile->tail->prev = prevCard;
            return;
        }
    }
    return; //print error statement
}
