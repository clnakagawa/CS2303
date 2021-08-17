/*
 * production.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: cln
 */

#include "production.h"

production::production() {
	// TODO Auto-generated constructor stub

}

production::~production() {
	// TODO Auto-generated destructor stub
}

bool production::prod(int argc, char* argv[]){
	bool answer = false;
	int limit;
	if (argv[1] != NULL){
		limit = std::stoi(argv[1]);
	}
	const char* filename = "checkersConfig.txt";
	Board* testBoard = (Board*)malloc(sizeof(Board));
	loadBoard(testBoard, filename);
	int pOrder;
	int turn = 0;
	bool canJump = false;
	int tempX, tempY;
	std::cout<<"piece x value, piece y value, x to move to/capture, y to move to/capture"<<std::endl;
	std::cout<<"example: 3 5 2 6"<<std::endl;
	std::cout<<"moves up and right on board"<<std::endl;
	printBoard(testBoard);
	std::cout<<"turn order (1 for player 0 for computer)"<<std::endl;
	std::cin>>pOrder;
	if (!(bool)pOrder){
		compTurn(testBoard);
		printBoard(testBoard);
		std::cout<<"turn "<<turn<<std::endl;
		turn++;
	}
	std::cout<<"player inputs as:"<<std::endl;
	int pX, pY, tX, tY;
	while (checkWin(testBoard) == 3 && limit != 0){
		std::cin>>pX>>pY>>tX>>tY;
		std::cout<<"input received"<<std::endl;
		std::cout<<"beginning move"<<std::endl;
		std::cout<<pX<<" "<<pY<<" "<<tX<<" "<<tY<<std::endl;
		if (testBoard->grid[tX][tY] == NULL){
			movePiece(testBoard->grid[pX][pY], testBoard, tX, tY);
		}
		else if (checkJump(testBoard, testBoard->grid[pX][pY], pX, pY, tX-pX, tY-pY)){
			testBoard->grid[tX][tY] = NULL;
			movePiece(testBoard->grid[pX][pY], testBoard, 2*tX-pX, 2*tY-pY);
			testBoard->cCount--;

			tempX = 2*tX-pX;
			tempY = 2*tY-pY;
			if (testBoard->grid[tempX][tempY]->isKing){
				canJump = checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, 1)
						&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, -1)
						&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, 1, 1)
						&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, 1, -1);
			}
			else {
				canJump = checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, 1)
						&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, -1);
			}
			while (canJump){
				printBoard(testBoard);
				std::cout<<"turn "<<turn<<std::endl;
				std::cout<<"jump available, must move again"<<std::endl;
				std::cin>>pX>>pY>>tX>>tY;
				testBoard->grid[tX][tY] = NULL;
				testBoard->cCount--;
				movePiece(testBoard->grid[pX][pY], testBoard, 2*tX-pX, 2*tY-pY);
				tempX = 2*tX-pX;
				tempY = 2*tY-pY;
				if (testBoard->grid[tX+1][tY+1]->isKing){
					canJump = checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, 1)
							&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, -1)
							&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, 1, 1)
							&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, 1, -1);
				}
				else {
					canJump = checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, 1)
							&&checkJump(testBoard, testBoard->grid[tempX][tempY], tempX, tempY, -1, -1);
				}
			}

		}
		for (int j = 0; j < 8; j++){
			if (testBoard->grid[7][j] != NULL){
				if (!testBoard->grid[7][j]->isKing && testBoard->grid[7][j]->side){
					promote(testBoard, testBoard->grid[7][j]);
				}
			}
		}
		printBoard(testBoard);
		std::cout<<"turn "<<turn<<std::endl;
		turn++;
		if (checkWin(testBoard) == 3){
			compTurn(testBoard);
			for (int j = 0; j < 8; j++){
				if (testBoard->grid[0][j] != NULL){
					if (!testBoard->grid[0][j]->isKing && !testBoard->grid[0][j]->side){
						promote(testBoard, testBoard->grid[0][j]);
					}
				}
			}
			printBoard(testBoard);
			std::cout<<"turn "<<turn<<std::endl;
			turn++;
		}
		limit--;
	}
	if (checkWin(testBoard) == 1){
		std::cout<<"Player wins"<<std::endl;
	}
	else {
		std::cout<<"Computer wins"<<std::endl;
	}
	answer = true;
	return answer;
}
