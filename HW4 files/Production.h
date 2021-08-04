/*
 * Production.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <string>//strncpy
#include <stdlib.h>//strtol
#include "Room.h"
#include "AdjMat.h"

#define FILENAMELENGTHALLOWANCE 50

class Production {
public:
	Production();
	virtual ~Production();
	bool prod(int argc, char* argv[]);
	bool readFile(const char*, int*, AdjMat*, Room**);

private:

};

#endif /* PRODUCTION_H_ */
