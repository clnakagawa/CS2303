/*
 * Tests.h
 *
 *  Created on: Mar 16, 2021
 *      Author: cln
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Board.h"
#include "Record.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testInitBoard();
	bool testPrintBoard();
	bool testPrintFullBoard();
	bool testInitPlayers();
	bool testChance();
	bool testStay();
	bool testRail();
	bool testMove();
	bool testMoveGo();
	bool testUpgrade();
	bool testBuy();
	bool testSell();
	bool testBankrupt();
	bool testPrintHist();
	bool testAddEntry();
};

#endif /* TESTS_H_ */
