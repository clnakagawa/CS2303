/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include "AdjMat.h"
#include "Room.h"
#include  "searchHistory.h"
//#include "AdjMat.h"
//#include "Room.h"
//#include "LinkedList.h"


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testReadFile();
	bool testGotAdjacencyMatrix();
	bool testGetNeighbors();
	bool testSearchRoom();
	bool testSearchHistory();
	bool testPrintHistory();
	bool testWriteHistory();
	bool testSetN();
	bool testGetEdge();
};

#endif /* TESTS_H_ */
