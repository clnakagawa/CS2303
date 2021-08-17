/*
 * Board.h
 *
 *  Created on: Mar 7, 2021
 *      Author: cln
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include "Piece.h"

typedef struct {
	Piece* grid[8][8];
	int pCount; //number of pieces left for player
	int cCount; //number of pieces left for computer
} Board;

void loadBoard(Board* board, const char* fname);
void printBoard(Board* board);
void movePiece(Piece* piece, Board* board, int x, int y);
int checkWin(Board* board);
void promote(Board* board, Piece* piece);

#endif /* BOARD_H_ */
