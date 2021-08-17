/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <iostream>
#include <fstream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;
	bool ok1 = testMovePiece();
	bool ok2 = testPrintBoard();
	bool ok3 = testLoadBoard();
	bool ok4 = testPromote();
	bool ok5 = testCheckJump();
	bool ok6 = testJumping();
	bool ok7 = testMoveInit();
	bool ok8 = testExecute();
	bool ok9 = testSetVal();
	bool ok10 = testCheckWin();
	bool ok11 = testCompTurn();
	answer = ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7&&ok8&&ok9&&ok10&&ok11;
	return answer;
}

bool Tests::testMovePiece(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[2][2] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[2][2]->isKing = true;
	testBoard->grid[2][2]->xPos = 2;
	testBoard->grid[2][2]->yPos = 2;
	movePiece(testBoard->grid[2][2], testBoard, 3, 3);
	ok = testBoard->grid[2][2] == NULL && testBoard->grid[3][3]->isKing;
	if (ok){
		std::cout<<"testMovePiece passed\n"<<std::endl;
	}
	else {
		std::cout<<"testMovePiece did not pass\n"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintBoard(){
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	printBoard(testBoard);
	int answer;
	std::cout<<"looks correct?"<<std::endl;
	std::cin>>answer;
	if (answer != 1){
		ok = false;
	}
	if (ok){
		std::cout<<"testPrintBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testPrintBoard did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testLoadBoard(){
	bool ok = true;
	const char* filename = "checkersConfig.txt";
	Board* testBoard = (Board*)malloc(sizeof(Board));
	loadBoard(testBoard, filename);
	std::cout<<std::endl;
	printBoard(testBoard);
	int answer;
	std::cout<<"looks correct?"<<std::endl;
	std::cin>>answer;
	if (answer != 1){
		ok = false;
	}
	if (ok){
		std::cout<<"testLoadBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testLoadBoard did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testCompTurn(){
	bool ok = true;
	const char* filename = "checkersConfig.txt";
	Board* testBoard = (Board*)malloc(sizeof(Board));
	loadBoard(testBoard, filename);
	movePiece(testBoard->grid[5][2], testBoard, 3, 2);
	std::cout<<std::endl;
	printBoard(testBoard);
	testBoard = compTurn(testBoard);
	printBoard(testBoard);
	std::cout<<"Looks correct?"<<std::endl;
	int answer;
	std::cin>>answer;
	if (answer != 1){
		ok = false;
	}
	if (ok){
		std::cout<<"testCompTurn passed"<<std::endl;
	}
	else {
		std::cout<<"testCompTurn did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testCheckWin(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3]->isKing = false;
	testBoard->grid[3][3]->side = true;
	testBoard->grid[3][3]->xPos = 3;
	testBoard->grid[3][3]->yPos = 3;
	testBoard->grid[4][4] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[4][4]->isKing = false;
	testBoard->grid[4][4]->side = false;
	testBoard->grid[4][4]->xPos = 4;
	testBoard->grid[4][4]->yPos = 4;
	testBoard->cCount = 1;
	testBoard->pCount = 1;
	printBoard(testBoard);
	compTurn(testBoard);
	printBoard(testBoard);
	if (checkWin(testBoard) == 2){
		ok = true;
	}
	if (ok){
		std::cout<<"testCheckWin passed"<<std::endl;
	}
	else {
		std::cout<<"testCheckWin did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testCheckJump(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3]->isKing = false;
	testBoard->grid[3][3]->side = true;
	testBoard->grid[3][3]->xPos = 3;
	testBoard->grid[3][3]->yPos = 3;
	testBoard->grid[4][4] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[4][4]->isKing = false;
	testBoard->grid[4][4]->side = false;
	testBoard->grid[4][4]->xPos = 4;
	testBoard->grid[4][4]->yPos = 4;
	testBoard->cCount = 1;
	testBoard->pCount = 1;
	printBoard(testBoard);
	ok = checkJump(testBoard, testBoard->grid[3][3], 3, 3, 1, 1);
	if (ok){
		std::cout<<"testCheckJump passed"<<std::endl;
	}
	else {
		std::cout<<"testCheckJump did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testJumping(){
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3]->isKing = false;
	testBoard->grid[3][3]->side = true;
	testBoard->grid[3][3]->xPos = 3;
	testBoard->grid[3][3]->yPos = 3;
	testBoard->grid[4][4] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[4][4]->isKing = false;
	testBoard->grid[4][4]->side = false;
	testBoard->grid[4][4]->xPos = 4;
	testBoard->grid[4][4]->yPos = 4;
	testBoard->grid[6][6] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[6][6]->isKing = false;
	testBoard->grid[6][6]->side = false;
	testBoard->grid[6][6]->xPos = 6;
	testBoard->grid[6][6]->yPos = 6;
	printBoard(testBoard);
	compTurn(testBoard);
	printBoard(testBoard);
	std::cout<<"Looks correct?"<<std::endl;
	int answer;
	std::cin>>answer;
	if (answer != 1){
		ok = false;
	}
	if (ok){
		std::cout<<"testJumping passed"<<std::endl;
	}
	else {
		std::cout<<"testJumping did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testSetVal(){
	bool ok = true;
	Move* testMove = (Move*)malloc(sizeof(Move));
	testMove->fx = 4;
	testMove->fy = 3;
	testMove->king = false;
	testMove->numJumps = 1;
	testMove->setVal();
	ok = testMove->val == 143;
	if (ok){
		std::cout<<"testSetVal passed"<<std::endl;
	}
	else {
		std::cout<<"testSetVal did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testMoveInit(){
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3]->isKing = false;
	testBoard->grid[3][3]->side = true;
	testBoard->grid[3][3]->xPos = 3;
	testBoard->grid[3][3]->yPos = 3;
	testBoard->grid[4][4] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[4][4]->isKing = false;
	testBoard->grid[4][4]->side = false;
	testBoard->grid[4][4]->xPos = 4;
	testBoard->grid[4][4]->yPos = 4;
	Move* testMove = (Move*)malloc(sizeof(Move));
	testMove = moveInit(testBoard, testBoard->grid[3][3], 1);
	printBoard(testBoard);
	testMove->execute(testBoard);
	std::cout<<" "<<std::endl;
	printBoard(testBoard);
	if (testMove->val != 155){
		ok = false;
	}
	if (ok){
		std::cout<<"testMoveInit passed"<<std::endl;
	}
	else {
		std::cout<<"testMoveInit did not pass"<<std::endl;
	}
	return ok;
}


bool Tests::testExecute(){
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[3][3] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[3][3]->isKing = false;
	testBoard->grid[3][3]->side = true;
	testBoard->grid[3][3]->xPos = 3;
	testBoard->grid[3][3]->yPos = 3;
	testBoard->grid[4][4] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[4][4]->isKing = false;
	testBoard->grid[4][4]->side = false;
	testBoard->grid[4][4]->xPos = 4;
	testBoard->grid[4][4]->yPos = 4;
	Move* testMove = moveInit(testBoard, testBoard->grid[3][3], 1);
	printBoard(testBoard);
	testMove->execute(testBoard);
	std::cout<<" "<<std::endl;
	printBoard(testBoard);
	std::cout<<"Looks correct?"<<std::endl;
	int answer;
	std::cin>>answer;
	if (answer != 1){
		ok = false;
	}
	if (ok){
		std::cout<<"testExecute passed"<<std::endl;
	}
	else {
		std::cout<<"testExecute did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testPromote(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->grid[7][7] = (Piece*)malloc(sizeof(Piece));
	testBoard->grid[7][7]->isKing = false;
	testBoard->grid[7][7]->side = true;
	testBoard->grid[7][7]->xPos = 7;
	testBoard->grid[7][7]->yPos = 7;
	printBoard(testBoard);
	promote(testBoard, testBoard->grid[7][7]);
	printBoard(testBoard);
	ok = testBoard->grid[7][7]->isKing;
	if (ok){
		std::cout<<"testPromote passed"<<std::endl;
	}
	else {
		std::cout<<"testPromote did not pass"<<std::endl;
	}
	return ok;
}
