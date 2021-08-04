///*
// * AdjMat.cpp
// *
// *  Created on: May 30, 2020
// *      Author: Owen Aguirre
// */
/*
 * AdjMat.c
 *
 *  Created on: Oct 24, 2019
 *      Author: Therese
 */

#include "AdjMat.h"

void AdjMat::init()
{
	int ncols = n;
	edgesP = (int*)malloc(sizeof(int)*n*n);
	for(int row = 0; row<ncols; row++)
	{
		for(int col = 0; col<ncols; col++)
		{
			*((edgesP)+(row*ncols)+col)= 0;
		}
	}
}

void AdjMat::setEdge(int row, int col)
{

	int ncols = n;
	int* arrayBeginning = edgesP;
	*(arrayBeginning + (ncols*row) +col) = 1;
	*(arrayBeginning + (ncols*col) + row) = 1;
}

int AdjMat::getEdge(int row, int col)
{
	int ncols = n;
	int* arrayBeginning = edgesP;
	return *(arrayBeginning + (ncols*row) + col);
}

void AdjMat::setN(int set)
{
	n = set;
}

int* AdjMat::getNeighbors(int* roomNums, Room* rooms[]){
	int* neighbors = (int*)malloc(sizeof(int)*n);
	bool repeatCheck;
	int ind = 0;
	for (int i = 0; *(roomNums+i) != -1; i++){
		for (int j = 0; j < n; j++){
			if ((bool) getEdge(*(roomNums+i), j) && !rooms[j]->searched){
				repeatCheck = false;
				for (int k = 0; k < ind; k++){
					if (j == *(neighbors+k)){
						repeatCheck = true;
					}
				}
				if (!repeatCheck){

					*(neighbors+ind) = j;
					ind++;
				}
			}
		}
	}
	*(neighbors+ind) = -1;
	return neighbors;
}









//bool repeatCheck;
//int ind = 0;
//for (int i = 0; *(roomNums+i) != -1; i++){
//	for (int j = 0; j < n; j++){
//		if ((bool) getEdge(*(roomNums+i), j) && !rooms[j]->searched){
//			repeatCheck = false;
//			for (int k = 0; k < ind; k++){
//				if (j == *(neighbors+k)){
//					repeatCheck = true;
//				}
//			}
//			if (!repeatCheck){
//
//				*(neighbors+ind) = j;
//				ind++;
//			}
//		}
//	}
//}
//*(neighbors+ind) = -1;
