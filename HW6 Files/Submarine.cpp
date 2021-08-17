/*
 * Submarine.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Submarine.h"

Submarine::Submarine() {
	Ship::setLength(3);
	Ship::setName("Submarine");
	Ship::setSymbol(SUBMARINE);
}

Submarine::~Submarine() {
	// TODO Auto-generated destructor stub
}

