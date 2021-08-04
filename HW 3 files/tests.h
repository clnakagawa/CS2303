/*
 * tests.h
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "house.h"

bool tests();
bool testGetRoom();
bool testSearchRoom();
bool testGetNeighborsMultiple();
bool testCollectRoomsRoomLimit();
bool testCollectRoomsTreasureLimit();
bool testCollectRoomsTreasureLimit();
bool testNavigateHouse();

#endif /* TESTS_H_ */
