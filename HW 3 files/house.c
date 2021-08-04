/*
 * house.c
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */
#include "house.h"
Room* getRoom(Room* rooms[], int roomNum){
	Room* temp;
	for (int i = 0; i < 10; i++){
		if (rooms[i]->roomNum == roomNum){
			temp = rooms[i];
		}
	}
	return temp;
}

int* getNeighborsMultiple(int* roomNums, AdjMat* graph){
	int ind = 0;
	bool repeatCheck = false;
	static int neighbors[10];
	int temp = 0;
	while (*(roomNums+temp) != -1){
		temp++;
	}
	int arrLen =  graph->n;
	int tempArray[10];
	for (int i = 0; i < temp; i++){
		tempArray[i] = *(roomNums+i);
	}
	tempArray[temp] = -1;
	for (int i = 0; i < temp; i++){
		for (int j = 0; j < arrLen; j++){
			if (graph->edges[tempArray[i]][j] == 1){

				for (int k = 0; k < ind; k++){
					if (neighbors[k] == j){
						repeatCheck = true;
					}
				}
				if (repeatCheck == false){
					neighbors[ind] = j;
					ind++;
				}
				repeatCheck = false;
			}
		}
	}
	neighbors[ind] = -1;
	return neighbors;

}

int collectRooms(Room* rooms[], int* roomNums, int roomLim, int treasureLim, int current){
	int temp = 0;
	while (*(roomNums+temp) != -1){
		temp++;
	}
	int foundAmt = 0;
	for (int i = 0; i < temp; i++){
		if (roomLim == 0 || current >= treasureLim){
			i = temp-1;
		}
		else {
			if (!getRoom(rooms, *(roomNums+i))->searched){
				foundAmt = searchRoom(getRoom(rooms, *(roomNums+i)));
				current += foundAmt;
				printf("%d found in room %d, total is now %d\n", foundAmt, *(roomNums+i), current);
				roomLim--;
			}
		}

	}
	return current;
}

void navigateHouse(House* house, int roomLim, int treasureLim){
	int treasure = 0;
	int temp = 0;
	int* roomsToSearch = (int*)malloc(sizeof(int)*house->layout->n);
	*roomsToSearch = 0;
	*(roomsToSearch+1) = -1;
	while (*roomsToSearch != -1 && roomLim  >  0 && treasure < treasureLim){
		for (int i = 0; *(roomsToSearch+i) != -1; i++){
			if (!getRoom(house->rooms, i)->searched){
				temp++;
			}
		}
		treasure = collectRooms(house->rooms, roomsToSearch, roomLim, treasureLim, treasure);
		roomLim -= temp;
		temp = 0;
		roomsToSearch = getNeighborsMultiple(roomsToSearch, house->layout);
	}
	if (roomLim <= 0){
		printf("Room limit reached, ending search\n"); fflush(stdout);
	}
	else {
		printf("Treasure limit reached, ending search\n"); fflush(stdout);
	}
}























