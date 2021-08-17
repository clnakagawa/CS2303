/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "Piece.h"
#include "Board.h"
#include "Move.h"


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testMovePiece();
	bool testLoadBoard();
	bool testPrintBoard();
	bool testCompTurn();
	bool testCheckWin();
	bool testCheckJump();
	bool testJumping();
	bool testSetVal();
	bool testExecute();
	bool testMoveInit();
	bool testPromote();
};

#endif /* TESTS_H_ */
