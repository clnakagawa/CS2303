/*
 * ll.h
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */

#ifndef LL_H_
#define LL_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int number;
	char letter;
	int xloc;
	int yloc;
	bool match;
} Record;

typedef struct Node{
	struct Node* next;
	Record* data;
} Node;

void addNode(Node*, Record*);
void printHistory(Node*);

#endif /* LL_H_ */
