/*
 * production.c
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */
#include "production.h"
#include "board.h"
#include "space.h"
#include "ll.h"

bool production(int argc, char* argv[]){
	srand(time(0));
	bool ans = true;
	if (argc < 2){
		printf("insufficient arguments\n"); fflush(stdout);
		ans = false;
	}
	else if (argc > 2){
		printf("too many arguments\n"); fflush(stdout);
		ans = false;
	}
	else {
		char* ptr;
		int calls = strtol(argv[1], &ptr, 10);
		char letterCall;
		int numberCall;
		Space* board = initBoard();
		Node* ll = (Node*)malloc(sizeof(Node));
		Record* tempRecord = (Record*)malloc(sizeof(Record));
		for (int i = 0; i < calls; i++){
			letterCall = (char)(65+rand()%26);
			numberCall = rand()%10;

			tempRecord->letter = letterCall;
			tempRecord->number = numberCall;
			tempRecord->match = false;
			for (int i = 0; i < 25; i++){
				if ((board+i)->letter == letterCall && (board+i)->number == numberCall){
					tempRecord->match = true;
					tempRecord->xloc = (i%5)+1;
					tempRecord->yloc = (i/5)+1;
					setMatch((board+i));
				}
			}
			addNode(ll, tempRecord);
			displayBoard(board);
		}
		printHistory(ll);
	}

	return ans;
}

