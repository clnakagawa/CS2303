/*
 * production.c
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */
#include "production.h"

bool production(int argc, char* argv[]){
	bool ans = true;
	if (argc < 2){
		printf("insufficient arguments\n"); fflush(stdout);
		ans = false;
	}
	else if (argc == 2){
		char* ptr;
		int roomLim = 10;
		int treasureLim = 450;
		int singleParam = strtol(argv[1], &ptr, 10);
		if (singleParam < 10){
			roomLim = singleParam;
		}
		else if (singleParam <  450){
			treasureLim = singleParam;
		}
		else {
			printf("parameter invalid, using default parameters\n");
		}
		AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
		graph->n = 10;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (i == j){
					setEdge(graph, i, j);
				}
				else if (abs(i-j)==1){
					setEdge(graph, i, j);
				}
			}
		}
		Room* testRooms[10];
		House* testHouse = (House*)malloc(sizeof(House));
		for (int i = 0; i < 10; i++){
			testHouse->rooms[i] = (Room*)malloc(sizeof(Room));
			testHouse->rooms[i]->roomNum = i;
			testHouse->rooms[i]->searched = false;
			testHouse->rooms[i]->treasure = 10*(i);
		}
		testRooms[0]->searched = true;
		testHouse->layout = graph;
		navigateHouse(testHouse, roomLim, treasureLim);
	}
	else if (argc == 3){
		char* ptr1;
		char* ptr2;
		int roomLim = strtol(argv[1], &ptr1, 10);
		int treasureLim = strtol(argv[2], &ptr2, 10);
		AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
		graph->n = 10;
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if (i == j){
					setEdge(graph, i, j);
				}
				else if (abs(i-j)==1){
					setEdge(graph, i, j);
				}
			}
		}
		Room* testRooms[10];
		House* testHouse = (House*)malloc(sizeof(House));
		for (int i = 0; i < 10; i++){
			testHouse->rooms[i] = (Room*)malloc(sizeof(Room));
			testHouse->rooms[i]->roomNum = i;
			testHouse->rooms[i]->searched = false;
			testHouse->rooms[i]->treasure = 10*(i);
		}
		testRooms[0]->searched = true;
		testHouse->layout = graph;
		navigateHouse(testHouse, roomLim, treasureLim);
	}
	return ans;
}

