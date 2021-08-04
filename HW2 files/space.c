/*
 * space.c
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */
#include "space.h"

void setMatch(Space* cell){
	if (!cell->match){
		cell->match = true;
	}
}
