/*
 * Board.h
 *
 *  Created on: Mar 16, 2021
 *      Author: cln
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

typedef struct {
	int pNum;
	int pos;
	int money;
	int rNum;
	int numProps;
	bool property[32];
} Player;

typedef struct {
	int number;
	char symbol;
	bool own;
	int player;
	int houses;
	int val;
	bool occupied[4];
} Space;


class Board {
public:
	Board();
	virtual ~Board();
	Space* spaces[32];
	Player* players[4];
	int playerCount;
	//visuals
	void printBoard(bool showPlayers); //TESTED
	void initBoard(); //TESTED
	void initPlayers(FILE* file); //TESTED

	//events
	void chance(int pNum); //TESTED
	void stay(int pNum, int sNum);
	void rail(int pNum, int sNum);

	//player turn actions
	void move(int pNum);

	//player space actions
	void upgrade(int pNum, int sNum);
	void buy(int pNum, int sNum);
	void sell(int pNum, int sNum);

	//loss condition
	bool isBankrupt(int pNum);
};

#endif /* BOARD_H_ */
