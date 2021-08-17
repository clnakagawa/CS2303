/*
 * Coordinate.cpp
 *
 *  Created on: Mar 14, 2021
 *      Author: cln
 */

#include "Coordinate.h"

Coordinate::Coordinate() { // @suppress("Class members should be properly initialized")
}

Coordinate::Coordinate(int c, int r){
	column = c;
	row = r;
}

void Coordinate::generate(int direction, int length){
	srand(time(NULL));
	if (direction == 0){
		row = rand() % 10;
		column = rand() % (10 - length);
	}
	else {
		row = rand() % (10 - length);
		column = rand() % 10;
	}
}

Coordinate::~Coordinate() {
	// TODO Auto-generated destructor stub
}

void Coordinate::setCol(int c){
	column = c;
}

void Coordinate::setRow(int r){
	row = r;
}

int Coordinate::getCol(){
	return column;
}

int Coordinate::getRow(){
	return row;
}

void Coordinate::setInput() { // @suppress("Class members should be properly initialized")
	printf ("> Enter Target (ex. > 3 4):\n");
	printf ("> ");
	std::cin>>row>>column;
}
