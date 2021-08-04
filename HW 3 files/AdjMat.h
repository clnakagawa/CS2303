/*
 * AdjMat.h
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#ifndef ADJMAT_H_
#define ADJMAT_H_


typedef struct
{
	int n;
	int edges[10][10];
}AdjMat;

void setEdge(AdjMat* adjMP, int row, int col);
int getEdge(AdjMat* adjMP, int row, int col);

#endif /* ADJMAT_H_ */
