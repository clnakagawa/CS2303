/*
 * Destroyer.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Destroyer.h"

Destroyer::Destroyer() {
	Ship::setLength(2);
	Ship::setName("Destroyer");
	Ship::setSymbol(DESTROYER);
}

Destroyer::~Destroyer() {
	// TODO Auto-generated destructor stub
}

