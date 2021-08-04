/*
 * board.h
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "space.h"
#include <time.h>
#include <stdbool.h>

Space* initBoard();
void displayBoard(Space*);

#endif /* BOARD_H_ */
