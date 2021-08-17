/*
 * Cruiser.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Cruiser.h"

Cruiser::Cruiser() {
	Ship::setLength(3);
	Ship::setName("Cruiser");
	Ship::setSymbol(CRUISER);
}

Cruiser::~Cruiser() {
	// TODO Auto-generated destructor stub
}

