/*
 * Production.h
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include "Board.h"
#include "Coordinate.h"

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
};

#endif /* PRODUCTION_H_ */
