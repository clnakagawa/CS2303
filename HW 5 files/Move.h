/*
 * Move.h
 *
 *  Created on: Mar 7, 2021
 *      Author: cln
 */

#ifndef MOVE_H_
#define MOVE_H_
#include "Board.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

class Move {
public:
	virtual ~Move();
	void setVal();
	void jumping(Board* board, Piece* piece, int startx, int starty);
	Board* execute(Board* board);
	int ix;
	int iy;
	int fx;
	int fy;
	int numJumps;
	int* jumpLocs;
	bool king;
	int val;
};

bool checkJump(Board* board, Piece* piece, int startx, int starty, int xdir, int ydir);
Move* moveInit(Board* board, Piece* piece, int dir);
Board* compTurn(Board* board);

#endif /* MOVE_H_ */
