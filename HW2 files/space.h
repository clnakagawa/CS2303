/*
 * space.h
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */

#ifndef SPACE_H_
#define SPACE_H_
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int number;
	char letter;
	bool match;
} Space;

void setMatch(Space*);
char* displaySpace(Space*);

#endif /* SPACE_H_ */
