/*
 * Piece.h
 *
 *  Created on: Mar 6, 2021
 *      Author: cln
 */

#ifndef PIECE_H_
#define PIECE_H_

class Piece {
public:
	Piece(bool king, bool givenSide, int givenXPos, int givenYPos);
	virtual ~Piece();
	bool isKing;
	bool side;
	int xPos;
	int yPos;
};

#endif /* PIECE_H_ */
