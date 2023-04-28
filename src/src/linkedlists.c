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
            return &currentNode;
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

void moveCard(card* fromCard, list* fromCardPile, list* toCard){
    char numbers[14] = {'A','2','3','4','5','6','7','8','9' ,'T','J','Q','K', 'NULL'};
    if(!findCard(*fromCard, fromCardPile)){
        return; //error message
    } // &??
    card* tempFromCard = fromCard;
    if(toCard->size == 0){
        if(fromCard->number == 'A' && toCard->name[0] == 'F') {
            if(fromCardPile->tail->prev->data != fromCard){
                return; // error message
            }
            addNode(*fromCard, toCard);
        } else if(toCard->name[0] == 'F'){
            return; //error message
        }
        else{
            while(tempFromCard->number != '#')
            addNode(*tempFromCard, toCard);
            *tempFromCard = findNode(*tempFromCard, fromCardPile)->next->data;
        }
    }
    if(fromCard->suit != toCard->tail->prev->data.suit && toCard->name[0] == 'F'){
        return; //print error statement
    }
    if(fromCard->suit == toCard->tail->prev->data.suit && toCard->name[0] == 'C'){
        return; //print error statement
    }
    int firstNumber = (int) NULL;
    int secondNumber = (int) NULL;
    for (int i = 0; i < numbers; ++i) {
        if(numbers[i] == fromCard->number){
            firstNumber = i;
        }
        if(numbers[i] == toCard->tail->prev->data.number){
            secondNumber = i;
        }
    }
    if(numbers[firstNumber+1] != numbers[secondNumber]){
        return; //print error statement
    }



}