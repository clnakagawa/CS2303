/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"

void setEdge(AdjMat* adjMP, int row, int col)
{
	int ncols = adjMP->n;
	int* arrayBeginning = &(adjMP->edges[0][0]);
	*(arrayBeginning + (ncols*row) +col) = 1;
	*(arrayBeginning + (ncols*col) + row) = 1;
}
int getEdge(AdjMat* adjMP, int row, int col)
{
	int ncols = adjMP->n;
	int* arrayBeginning = &(adjMP->edges[0][0]);
	return *(arrayBeginning + (ncols*row) +col) ;
}

