/*
 * searchHistory.h
 *
 *  Created on: Mar 1, 2021
 *      Author: cln
 */

#ifndef SEARCHHISTORY_H_
#define SEARCHHISTORY_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "AdjMat.h"
#include "Room.h"

class searchHistory{
public:

	void init(Room* rooms[], AdjMat* graph);
	void printHistory(int roomLim, float treasLim);
	void writeHistory(int roomLim, float treasLim, const char* fname);
	int* roomNums;
	float* subtotals;
};

#endif /* SEARCHHISTORY_H_ */
