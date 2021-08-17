/*
 * Piece.cpp
 *
 *  Created on: Mar 6, 2021
 *      Author: cln
 */

#include "Piece.h"

Piece::Piece(bool king, bool givenSide, int givenXPos, int givenYPos) {
	isKing = king;
	side = givenSide;
	xPos = givenXPos;
	yPos = givenYPos;

}

Piece::~Piece() {
	// TODO Auto-generated destructor stub
}

