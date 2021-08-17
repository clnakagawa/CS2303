/*
 * Board.h
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#include "Battleship.h"
#include "Carrier.h"
#include "Cruiser.h"
#include "Destroyer.h"
#include "Submarine.h"
#include "Coordinate.h"

#define LOG_FILE_NAME "battleship.log"

#define NUM_OF_SHIPS  5

#define HORIZONTAL    0
#define VERTICAL      1

#define PLAYER_ONE    0
#define PLAYER_TWO    1


#define WATER         '~'
#define HIT           '*'
#define MISS          'm'

#define NORTH 0
#define SOUTH 1
#define WEST  2
#define EAST  3


typedef struct {
	char symbol;
	Coordinate* pos;
} Cell;

typedef struct {
	int numHits;
	int numMisses;
	int totalShots;
	double hitMissRatio;
} Stats;

class Board {
public:
	Board();
	virtual ~Board();
	void welcomeScreen();
	void initializeBoard();
	void printBoard(bool showPegs);
	void putShip(Ship* ship, Coordinate* pos, int dir);
	bool inputPositions(Coordinate pos[], char strPos[], int length);
	void manualPlace(Ship ships[]);
	bool isWinner(int pNum);
	bool validLoc(Coordinate* pos, int dir, int length);
	void randomPlace(Ship ships[]);
	void updateBoard(Coordinate* target);
	void checkBounds(int bound, int dir);
	void systemMessage(const char*);
	bool checkSunkShip(short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream);
	short checkShot(Coordinate* target);
	bool cardinals[4];
	Cell* grid[10][10];
	Stats* pStats[2];
};

#endif /* BOARD_H_ */
