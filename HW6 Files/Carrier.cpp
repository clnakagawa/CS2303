/*
 * Carrier.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Carrier.h"

Carrier::Carrier() {
	Ship::setLength(5);
	Ship::setName("Carrier");
	Ship::setSymbol(CARRIER);
}

Carrier::~Carrier() {
	// TODO Auto-generated destructor stub
}

