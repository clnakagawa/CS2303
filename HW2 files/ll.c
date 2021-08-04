/*
 * ll.c
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */
#include "ll.h"

void addNode(Node* ll, Record* givenData){
	Record* tempRecord = (Record*)malloc(sizeof(Record));
	tempRecord->letter = givenData->letter;
	tempRecord->number = givenData->number;
	tempRecord->match = givenData->match;
	tempRecord->xloc = givenData->xloc;
	tempRecord->yloc = givenData->yloc;
	if (ll->data == NULL){
		ll->data = tempRecord;
	}
	else{
		Node* last = ll;
		int i = 0;
		while (last->next != NULL){
			last = last->next;
			i++;
		}
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = tempRecord;
		newNode->next = NULL;
		last->next = newNode;
	}
}

void printHistory(Node* ll){
	while (ll != NULL){
		if (ll->data->match){
			printf("Called %c%d, found a match at row %d column %d\n",
					ll->data->letter,
					ll->data->number,
					ll->data->yloc,
					ll->data->xloc);
			ll = ll->next;
		}
		else {
			printf("Called %c%d, no match\n",
					ll->data->letter,
					ll->data->number);
			ll = ll->next;
		}
	}

}

