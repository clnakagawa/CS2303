/*
 * house.h
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */

#ifndef HOUSE_H_
#define HOUSE_H_
#include "room.h"
#include "AdjMat.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	Room* rooms[10];
	AdjMat* layout;
} House;

Room* getRoom(Room* rooms[], int roomNum);
int* getNeighborsMultiple(int* roomNums, AdjMat* graph);
int collectRooms(Room* rooms[], int* roomNums, int roomLim, int treasureLim, int current);
void navigateHouse(House* house, int roomLim, int treasureLim);

#endif /* HOUSE_H_ */
