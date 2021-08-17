/*
 * production.h
 *
 *  Created on: Mar 6, 2021
 *      Author: cln
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Board.h"
#include "Move.h"
#include "Piece.h"

class production {
public:
	production();
	virtual ~production();
	bool prod(int argc, char* argv[]);
};

#endif /* PRODUCTION_H_ */
