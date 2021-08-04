/*
 * AdjMat.h
 *
 */

#ifndef ADJMAT_H_
#define ADJMAT_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "Room.h"

class AdjMat{
public:

	void setEdge(int row, int col);
	int getEdge(int row, int col); //Returns binary value on adjMatrix given a row and a col
	void init();
	void setN(int set);
	int* getNeighbors(int* roomNums, Room* rooms[]);
	int n;
	int* edgesP;
};



#endif /* ADJMAT_H_ */
