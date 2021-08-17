/*
 * Ship.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Ship.h"

Ship::Ship() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

Ship::~Ship() {
	// TODO Auto-generated destructor stub
}

char Ship::getSymbol() {
	return symbol;
}

short Ship::getLength() {
	return length;
}

const char* Ship::getName() {
	return name;
}

void Ship::setSymbol(char sym){
	symbol = sym;
}

void Ship::setLength(short l){
	length = l;
}

void Ship::setName(const char* n){
	name = n;
}

