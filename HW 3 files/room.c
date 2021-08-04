/*
 * room.c
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */
#include "room.h"

int searchRoom(Room* room){
	room->searched = true;
	return room->treasure;
}

