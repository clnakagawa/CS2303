/*
 * searchHistory.cpp
 *
 *  Created on: Mar 1, 2021
 *      Author: cln
 */
#include "searchHistory.h"

void searchHistory::init(Room* rooms[], AdjMat* graph){
	subtotals = (float*)malloc(sizeof(float)*graph->n);
	roomNums = (int*)malloc(sizeof(int)*graph->n);
	int* toSearch = (int*)malloc(sizeof(int)*10);
	int indSearch = 0;
	int indHist = 0;
	float total = 0;
	*toSearch = 0;
	*(toSearch+1) = -1;
	while (*(toSearch+indSearch) != -1){
		total += searchRoom(rooms[toSearch[indSearch]]);
		*(subtotals+indHist) = total;
		*(roomNums+indHist) = *(toSearch+indSearch);
		indHist++;
		indSearch++;
		if (*(toSearch+indSearch) == -1){
			toSearch = graph->getNeighbors(toSearch, rooms);
			indSearch = 0;
		}
	}
	*(roomNums+indHist) = -1;
}

void searchHistory::printHistory(int roomLim, float treasLim){
	for (int i = 0; *(roomNums+i) != -1 && i < roomLim; i++){
		std::cout<<"Searched room "<<*(roomNums+i)<<", total is now "<<*(subtotals+i)<<std::endl;
		if (*(subtotals+i) >= treasLim){
			i = roomLim;
		}
	}
	std::cout<<"Limit reached, search ended"<<std::endl;
}

void searchHistory::writeHistory(int roomLim, float treasLim, const char* fname){
	std::ofstream output;
	output.open(fname);
	for (int i = 0; roomNums[i] != -1 && i < roomLim; i++){
		output<<roomNums[i]<<" "<<subtotals[i]<<"\n";
		if (*(subtotals+i) >= treasLim){
			i = roomLim;
		}
	}
	output.close();
}














