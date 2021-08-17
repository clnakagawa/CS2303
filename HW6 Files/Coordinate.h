/*
 * Coordinate.h
 *
 *  Created on: Mar 14, 2021
 *      Author: cln
 */

#ifndef COORDINATE_H_
#define COORDINATE_H_
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class Coordinate {
public:
	Coordinate();
	Coordinate(int c, int r);
	void generate(int direction, int length);
	virtual ~Coordinate();
	void setCol(int c);
	void setRow(int r);
	int getCol();
	int getRow();
	void setInput();
private:
	int column;
	int row;
};

#endif /* COORDINATE_H_ */
