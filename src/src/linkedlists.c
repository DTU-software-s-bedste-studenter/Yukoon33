//
// Created by Anthon Hertz Bie on 24/04/2023.
//

#include "../headders/linkedlists.h"
#include <stdlib.h>
void initList(list* list){
    list->size = 0;
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

card* findNode(card card, list* list){
    node* currentNode;
    currentNode = list->head;
    while(currentNode->data.number != '#'){
        if(currentNode->data.number == card.number){
            return &currentNode->data;
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

void moveCard(card* fromCard, list* toCard){
    //TODO make this command
}