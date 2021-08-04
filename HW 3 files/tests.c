/*
 * tests.c
 *
 *  Created on: Feb 22, 2021
 *      Author: cln
 */
#include "tests.h"

bool tests(){
	bool ans = false;
	bool getRoomTest = testGetRoom();
	bool searchRoomTest = testSearchRoom();
	bool getNeighborsMultipleTest = testGetNeighborsMultiple();
	bool collectRoomsRoomLimitTest = testCollectRoomsRoomLimit();
	bool collectRoomsTreasureLimitTest = testCollectRoomsTreasureLimit();
	bool navigateHouseTest = testNavigateHouse();
	ans = getRoomTest
			&&searchRoomTest
			&&getNeighborsMultipleTest
			&&collectRoomsRoomLimitTest
			&&collectRoomsTreasureLimitTest
			&&navigateHouseTest;
	return ans;
}

bool testGetRoom(){
	bool ans = false;
	Room* rooms[10];
	for (int i = 0; i < 10; i++){
		rooms[i] = (Room*)malloc(sizeof(Room));
		rooms[i]->roomNum = i;
		rooms[i]->searched = false;
		rooms[i]->treasure = 10*(i);
	}
	if (getRoom(rooms, 2)->treasure == 20){
		printf("checked"); fflush(stdout);
		ans = true;
	}

	if (ans == true){
		printf("testGetRoom passed\n"); fflush(stdout);
	}
	else {
		printf("testGetRoom did not pass\n"); fflush(stdout);
	}
	return ans;
}

bool testSearchRoom(){
	bool ans = false;
	Room* room1 = (Room*)malloc(sizeof(Room));
	room1->roomNum = 1;
	room1->treasure = 20;
	room1->searched = false;
	int testTreasure = searchRoom(room1);
	if (testTreasure == 20){
		if (room1->searched == true){
			ans = true;
		}
	}
	if (ans == true){
		printf("testSearchRoom passed\n"); fflush(stdout);
	}
	else {
		printf("testSearchRoom did not pass\n"); fflush(stdout);
	}
	return ans;
}

bool testGetNeighborsMultiple(){
	bool ans = false;
	int* roomNums = (int*)malloc(sizeof(int)*3);
	*roomNums = 2;
	*(roomNums+1) = 3;
	*(roomNums+2) = -1;
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
	int* numbers = getNeighborsMultiple(roomNums, graph);
	if (*numbers == 1){
		if (*(numbers+1) == 2){
			if (*(numbers+2) == 3){
				if (*(numbers+3) == 4){
					if (*(numbers+4) == -1){
						ans = true;
					}
				}
			}
		}
	}
	if (ans == true){
		printf("testGetNeighborMultiple passed\n"); fflush(stdout);
	}
	else {
		printf("testGetNeighborMultiple did not pass\n"); fflush(stdout);
	}
	return ans;
}

bool testCollectRoomsRoomLimit(){
	bool ans = false;
	Room* rooms[10];
	for (int i = 0; i < 10; i++){
		rooms[i] = (Room*)malloc(sizeof(Room));
		rooms[i]->roomNum = i;
		rooms[i]->searched = false;
		rooms[i]->treasure = 10*(i);
	}

	int roomNums[4];
	for (int i = 0; i < 3; i++){
		roomNums[i] = 1+2*i;
	}
	roomNums[3] = -1;
	int* roomList = roomNums;
	int treasure = 0;
	treasure = collectRooms(rooms, roomList, 2, 500, 0);
	if (treasure == 40){
		ans = true;
	}
	if (ans == true){
		printf("testCollectRoomsRoomLimit passed\n"); fflush(stdout);
	}
	else {
		printf("testCollectRoomsRoomLimit did not pass\n"); fflush(stdout);
	}
	return ans;
}

bool testCollectRoomsTreasureLimit(){
	bool ans = false;
	Room* rooms[10];
	for (int i = 0; i < 10; i++){
		rooms[i] = (Room*)malloc(sizeof(Room));
		rooms[i]->roomNum = i;
		rooms[i]->searched = false;
		rooms[i]->treasure = 10*(i);
	}

	int roomNums[4];
	for (int i = 0; i < 3; i++){
		roomNums[i] = 1+2*i;
	}
	roomNums[3] = -1;
	int* roomList = roomNums;
	int treasure = 0;
	treasure = collectRooms(rooms, roomList, 4, 30, 0);
	if (treasure == 40){
		ans = true;
	}
	if (ans == true){
		printf("testCollectRoomsTreasureLimit passed\n"); fflush(stdout);
	}
	else {
		printf("testCollectRoomsTreasureLimit did not pass\n"); fflush(stdout);
	}
	return ans;
}

bool testNavigateHouse(){
	bool ans = false;
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
	navigateHouse(testHouse, 5, 200);
	int response = 0;
	puts("passed test (1 = true)?"); fflush(stdout);
	scanf("%d", &response);
	if (response == 1){
		ans = true;
	}
	if (ans == true){
		printf("testNavigateHouse passed\n"); fflush(stdout);
	}
	else {
		printf("testNavigateHouse did not pass\n"); fflush(stdout);
	}
	return ans;
}
