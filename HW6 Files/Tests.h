/*
 * Tests.h
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#ifndef TESTS_H_
#define TESTS_H_
#include <stdbool.h>
#include "Board.h"
#include "Coordinate.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testWelcomeScreen();
	bool testPrintBoard();
	bool testPrintBoardPegs();
	bool testInitBoard();
	bool testPutShip();
	bool testManual();
	bool testGetInput();
	bool testValid();
	bool testGetTarget();
	bool testGenerate();
	bool testRandom();
	bool testUpdate();
	bool testCheckWin();
	bool testCheckShot();
	bool testCardinals();
	bool testCheckSunk();
	bool testSysMessage();
};

#endif /* TESTS_H_ */
