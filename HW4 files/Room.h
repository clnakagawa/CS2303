/*
 * Room.h
 *
 *  Created on: May 22, 2020
 *      Author: Owen Aguirre
 */

#ifndef ROOM_H_
#define ROOM_H_
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int roomNumber;
	float treasure;
	bool searched;
}Room;

float searchRoom(Room* room);

#endif /* ROOM_H_ */
