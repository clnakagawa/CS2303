/*
 * Move.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: cln
 */

#include "Move.h"

Move::~Move() {
	// TODO Auto-generated destructor stub
}

Move* moveInit(Board* board, Piece* piece, int dir){
	Move* move = (Move*)malloc(sizeof(Move));
	int tempx, tempy;
	move->ix = piece->xPos;
	move->iy = piece->yPos;
	int xdir;
	int ydir;
	switch(dir){
	case 1:
		xdir = 1;
		ydir = 1;
		break;
	case 2:
		xdir = 1;
		ydir = -1;
		break;
	case 3:
		xdir = -1;
		ydir = 1;
		break;
	case 4:
		xdir = -1;
		ydir = -1;
		break;
	}
	if (piece->xPos+xdir > 7 || piece->xPos+xdir < 0 || piece->yPos+ydir > 7 || piece->yPos+ydir < 0){

		move->val = 0;
	}
	else if (board->grid[piece->xPos+xdir][piece->yPos+ydir] == NULL){
		move->fx = piece->xPos+xdir;
		move->fy = piece->yPos+ydir;
		move->numJumps = 0;
		if (move->fx == 7 && !piece->isKing){
			move->king = true;
		}
		move->setVal();
	}
	else if (checkJump(board, piece, piece->xPos, piece->yPos, xdir, ydir)){
		tempx = piece->xPos+2*xdir;
		tempy = piece->yPos+2*ydir;
		move->jumpLocs = (int*)malloc(sizeof(int));
		*(move->jumpLocs) = 8*(tempx-xdir)+tempy-ydir;
		move->numJumps = 0;
		move->numJumps++;
		move->jumping(board, piece, tempx, tempy);
		if (move->fy == 7 && !piece->isKing){
			move->king = true;
		}
		move->setVal();
	}
	else {
		move->val = 0;
	}
	return move;
}

void Move::setVal(){
	val = 1000*((int)king)+100*numJumps+10*fx+fy;
}

void Move::jumping(Board* board, Piece* piece, int startx, int starty){
	bool can = true;
	int jumpVal;
	int tempx = startx;
	int tempy = starty;
	int ind = 1;
	bool repeatCheck;
	if (piece->isKing){
		while(can){
			repeatCheck = false;
			can = false;
			if (checkJump(board, piece, tempx, tempy, 1, 1)){
				jumpVal = 8*(tempx+1)+tempy+1;
				for (int i = 0; i < ind; i++){
					if (jumpVal == *(jumpLocs+i)){
						repeatCheck = true;
					}
				}
				if (!repeatCheck){
					can = true;
					*(jumpLocs+ind) = jumpVal;
					ind++;
					numJumps++;
					tempx += 2;
					tempy += 2;
				}
			}
			else if (checkJump(board, piece, tempx, tempy, -1, 1)){
				jumpVal = 8*(tempx-1)+tempy+1;
				for (int i = 0; i < ind; i++){
					if (jumpVal == *(jumpLocs+i)){
						repeatCheck = true;
					}
				}
				if (!repeatCheck){
					can = true;
					*(jumpLocs+ind) = jumpVal;
					ind++;
					numJumps++;
					tempx -= 2;
					tempy += 2;
				}
			}
			else if (checkJump(board, piece, tempx, tempy, 1, -1)){
				jumpVal = 8*(tempx+1)+tempy-1;
				for (int i = 0; i < ind; i++){
					if (jumpVal == *(jumpLocs+i)){
						repeatCheck = true;
					}
				}
				if (!repeatCheck){
					can = true;
					*(jumpLocs+ind) = jumpVal;
					ind++;
					numJumps++;
					tempx += 2;
					tempy -= 2;
				}
			}
			else if (checkJump(board, piece, tempx, tempy, -1, -1)){
				jumpVal = 8*(tempx-1)+tempy-1;
				for (int i = 0; i < ind; i++){
					if (jumpVal == *(jumpLocs+i)){
						repeatCheck = true;
					}
				}
				if (!repeatCheck){
					can = true;
					*(jumpLocs+ind) = jumpVal;
					ind++;
					numJumps++;
					tempx -= 2;
					tempy -= 2;
				}
			}
		}
		fx = tempx;
		fy = tempy;
		*(jumpLocs+ind) = -1;
	}
	else {
		while(can){
			can = false;
			if (checkJump(board, piece, tempx, tempy, 1, 1)){
				*(jumpLocs+ind) = 8*(tempx+1)+tempy+1;
				can = true;
				ind++;
				numJumps++;
				tempx += 2;
				tempy += 2;
			}
			else if (checkJump(board, piece, tempx, tempy, 1, -1)){
				*(jumpLocs+ind) = 8*(tempx+1)+tempy-1;
				can = true;
				ind++;
				numJumps++;
				tempx += 2;
				tempy -= 2;
			}
		}
		fx = tempx;
		fy = tempy;
		*(jumpLocs+ind) = -1;
	}
}

Board* Move::execute(Board* givenBoard){
	Board* board = givenBoard;
	board->pCount -= numJumps;
	int tempx, tempy;
	movePiece(board->grid[ix][iy], board, fx, fy);
	if (king){
		promote(board, board->grid[fx][fy]);
	}
	if (jumpLocs != NULL){
		for (int i = 0; *(jumpLocs+i) != -1; i++){
			tempx = *(jumpLocs+i) / 8;
			tempy = *(jumpLocs+i) % 8;
			board->grid[tempx][tempy] = NULL;
		}
	}
	return board;
}

bool checkJump(Board* board, Piece* piece, int startx, int starty, int xdir, int ydir){
	bool answer = false;
	if (xdir == 1 && ydir == 1){
		answer = (startx + 1 <  7 && starty + 1 < 7);
	}
	else if (xdir == -1 && ydir == 1){
		answer = (startx - 1 > 0 && starty + 1 < 7);
	}
	else if (xdir == 1  && ydir == -1){
		answer = (startx + 1 < 7 && starty - 1 > 0);
	}
	else if (xdir == -1 && ydir == -1){
		answer = (startx - 1 > 0 && starty - 1 > 0);
	}
	return answer
			&& board->grid[startx+xdir][starty+ydir] != NULL
			&& board->grid[startx+xdir][starty+ydir]->side != piece->side
			&& board->grid[startx+2*xdir][starty+2*ydir] == NULL;
}

Board* compTurn(Board* board){
	Move* posMoves[50];
		int ind = 0;
		for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++){
				if (board->grid[i][j] != NULL && board->grid[i][j]->side){
					if (board->grid[i][j]->isKing){
						for (int k = 1; k < 5; k++){
							*(posMoves + ind) = (Move*)malloc(sizeof(Move));
							*(posMoves + ind) = moveInit(board, board->grid[i][j], k);
							ind++;
						}
					}
					else {
						for (int k = 1; k < 3; k++){
							*(posMoves + ind) = (Move*)malloc(sizeof(Move));
							*(posMoves + ind) = moveInit(board, board->grid[i][j], k);
							ind++;
						}
					}
				}
				else {
				}
			}
		}
		int maxVal = 0;
		int maxInd = -1;
		for (int i = 0; i < ind; i++){
			if ((*(posMoves + i))->val > maxVal){
				maxVal = (*(posMoves + i))->val;
				maxInd = i;
			}
		}
		if (maxInd == -1){
			std::cout<<"no valid moves"<<std::endl;
			return NULL;
		}
		else {
			std::cout<<"executing move "<<maxVal<<std::endl;
			return (*(posMoves + maxInd))->execute(board);
		}
}

