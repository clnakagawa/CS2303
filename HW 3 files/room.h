/*
 * room.h
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */

#ifndef ROOM_H_
#define ROOM_H_
#include "AdjMat.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int roomNum;
	int treasure;
	bool searched;
} Room;

int searchRoom(Room*);

#endif /* ROOM_H_ */
