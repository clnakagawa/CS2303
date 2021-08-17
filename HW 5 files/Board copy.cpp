/*
 * Board.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: cln
 */
#include "Board.h"

void movePiece(Piece* piece, Board* board, int x, int y){
	int startX = piece->xPos;
	int startY = piece->yPos;
	piece->xPos = x;
	piece->yPos = y;
	board->grid[x][y] = board->grid[startX][startY];
	board->grid[startX][startY] = NULL;
}

int checkWin(Board* board){
	int win;
		if (board->cCount == 0){
			win = 1;
		}
		else if (board->pCount == 0){
			win = 2;
		}
		else{
			win = 3;
		}
		return win;
}

void printBoard(Board* board){
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++){
			if (board->grid[i][j] == NULL){
				std::cout<<"."<<std::flush;
			}
			else if (board->grid[i][j]->isKing){
				if (board->grid[i][j]->side){
					std::cout<<"k"<<std::flush;
				}
				else {
					std::cout<<"K"<<std::flush;
				}
			}
			else {
				if (board->grid[i][j]->side){
					std::cout<<"p"<<std::flush;
				}
				else {
					std::cout<<"P"<<std::flush;
				}
			}
			std::cout<<" "<<std::flush;
		}
		std::cout<<std::endl;
	}
}




void loadBoard(Board* board, const char* fname){
	char c;
	FILE* inputFile;
	int ind = 0;
	board->cCount = 0;
	board->pCount = 0;
	inputFile = fopen(fname, "r");
	for (int i = 0; i < 8; i++){
		ind = 0;
		for (int j = 0; j < 17; j++){
			fscanf(inputFile, "%c", &c);
			if (c == 'p'){
				board->grid[i][ind] = (Piece*)malloc(sizeof(Piece));
				board->grid[i][ind]->isKing = false;
				board->grid[i][ind]->side = true;
				board->grid[i][ind]->xPos = i;
				board->grid[i][ind]->yPos = ind;
				board->cCount++;
			}
			else if (c == 'P'){
				board->grid[i][ind] = (Piece*)malloc(sizeof(Piece));
				board->grid[i][ind]->isKing = false;
				board->grid[i][ind]->side = false;
				board->grid[i][ind]->xPos = i;
				board->grid[i][ind]->yPos = ind;
				board->pCount++;
			}
			if (c != ' '){
				ind++;
			}
		}
	}
}

void promote(Board* board, Piece* piece){
	int x = piece->xPos;
	int y = piece->yPos;
	bool side = piece->side;
	free(board->grid[x][y]);
	board->grid[x][y] = (Piece*)malloc(sizeof(Piece));
	board->grid[x][y]->xPos = x;
	board->grid[x][y]->yPos = y;
	board->grid[x][y]->isKing = true;
	board->grid[x][y]->side= side;
}








