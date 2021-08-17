/*
 * Battleship.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Battleship.h"

Battleship::Battleship() {
	Ship::setLength(4);
	Ship::setName("Battleship");
	Ship::setSymbol(BATTLESHIP);
}

Battleship::~Battleship() {
	// TODO Auto-generated destructor stub
}

