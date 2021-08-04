/*
 * board.c
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */
#include "board.h"
#include "space.h"

Space* initBoard(){
	srand(time(0));
	static Space board[25];
	for (int i = 0; i < 25; i++){
		(board+i)->letter = (char)(65+(rand()%26));
		(board+i)->number = rand()%10;
		(board+i)->match = false;
	}
	return board;
}

void displayBoard(Space* board){
	printf("_"); fflush(stdout);
	for (int i = 0; i < 5; i++){
		printf("____"); fflush(stdout);
	}
	printf("\n"); fflush(stdout);
	for (int i = 0; i < 5; i++){
		printf("|"); fflush(stdout);
		for (int j = 0; j < 5; j++){
			printf("%c%d", (board+i*5+j)->letter, (board+i*5+j)->number); fflush(stdout);
			if ((board+i*5+j)->match){
				printf("X"); fflush(stdout);
			}
			else{
				printf(" "); fflush(stdout);
			}
			printf("|"); fflush(stdout);
		}
		printf("\n"); fflush(stdout);
		printf("_"); fflush(stdout);
		for (int j = 0; j < 5; j++){
			printf("____"); fflush(stdout);
		}
		printf("\n"); fflush(stdout);
	}
	printf("\n\n");
}



