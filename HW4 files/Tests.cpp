/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <iostream>
#include <fstream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testGetNeighbors();
	bool ok4 = testSearchRoom();
	bool ok5 = testSearchHistory();
	bool ok6 = testPrintHistory();
	bool ok7 = testWriteHistory();
	bool ok8 = testSetN();
	bool ok9 = testGetEdge();
	answer = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	AdjMat* adjMP = (AdjMat*) malloc(sizeof(AdjMat));
	Room* theRoomPs[10];//addresses for 10 rooms

	Production* pP = new Production();
	const char* fname = "houseGraph.txt";
	ok = pP->readFile(fname, &answer, adjMP, theRoomPs); //read the file
	if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of rooms");
		}

	}
	puts("The adjacency matrix");
	for(int i = 0; i<answer; i++)
	{
		for(int j = 0; j<answer; j++)
		{
			printf("%d",adjMP->getEdge(i, j));

		}
		printf("\n");
	}
	puts("The treasure values");
	for(int i = 0; i<answer; i++)
	{
		printf("%f\n", theRoomPs[i]->treasure);
	}


	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ok = true;
	AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
	graph->setN(5);
	graph->init();
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if (graph->getEdge(i, j) != 0){
				ok = false;
			}
		}
	}
	if (ok == true){
		std::cout<<"testGotAdjancencyMatrix passed"<<std::endl;
	}
	else {
		std::cout<<"testGotAdjancencyMatrix did not pass"<<std::endl;
	}
	return ok;
}
bool Tests::testGetNeighbors(){
	bool ok = false;
	AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
	graph->setN(5);
	graph->init();
	graph->setEdge(2, 3);
	graph->setEdge(2, 4);
	graph->setEdge(2, 1);
	Room* testRooms[10];
	for (int i = 0; i < 10; i++){
		testRooms[i] = (Room*)malloc(sizeof(Room));
		testRooms[i]->searched = false;
		testRooms[i]->roomNumber = i;
		testRooms[i]->treasure = 10*i;
	}
	int* roomNumbers = (int*)malloc(sizeof(int)*10);
	*roomNumbers = 2;
	*(roomNumbers+1) = -1;
	int* neighbors = (int*)malloc(sizeof(int)*10);
	neighbors = graph->getNeighbors(roomNumbers, testRooms);
	if (*neighbors == 1){
		if (*(neighbors+1) == 3){

			if (*(neighbors+2) == 4){
				ok = true;
			}
		}
	}
	if (ok == true){
		std::cout<<"testGetNeighbors passed"<<std::endl;
	}
	else {
		std::cout<<"testGetNeighbors did not pass"<<std::endl;
	}
	return ok;
}
bool Tests::testSearchRoom(){
	bool ok = false;
	Room* testRoom = (Room*)malloc(sizeof(Room));
	testRoom->searched = false;
	testRoom->treasure = 20;
	int total = 0;
	total += searchRoom(testRoom);
	if (total == 20 && testRoom->searched){
		ok = true;
	}
	if (ok == true){
		std::cout<<"testSearchRoom passed"<<std::endl;
	}
	else {
		std::cout<<"testSearchRoom did not pass"<<std::endl;
	}
	return ok;
}
bool Tests::testSearchHistory(){
	bool ok = true;
	searchHistory* testHist = (searchHistory*)malloc(sizeof(searchHistory));
	AdjMat* testGraph = (AdjMat*)malloc(sizeof(AdjMat));
	testGraph->setN(5);
	testGraph->init();
	testGraph->setEdge(0, 1);
	testGraph->setEdge(0, 2);
	testGraph->setEdge(1, 3);
	testGraph->setEdge(2, 4);
	Room* testRooms[10];
	for (int i = 0; i < 10; i++){
		testRooms[i] = (Room*)malloc(sizeof(Room));
		testRooms[i]->searched = false;
		testRooms[i]->roomNumber = i;
		testRooms[i]->treasure = 10*i;
	}
	testHist->init(testRooms, testGraph);
	if (testHist->roomNums == NULL){
		std::cout<<"testSearchHistory did not pass"<<std::endl;
		return false;
	}
	for (int i = 0; *(testHist->roomNums+i) != -1; i++){
		std::cout<<"here"<<std::endl;
		std::cout<<*(testHist->roomNums+i)<<" "<<*(testHist->subtotals+i)<<"\n"<<std::endl;
		if (*(testHist->roomNums+i) != i || *(testHist->subtotals+i) != (i+1)*10*((float)i)/2){
			ok = false;
		}
	}
	if (ok == true){
		std::cout<<"testSearchHistory passed"<<std::endl;
	}
	else {
		std::cout<<"testSearchHistory did not pass"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintHistory(){
	bool answer = false;
	searchHistory* testHist = (searchHistory*)malloc(sizeof(searchHistory));
	AdjMat* testGraph = (AdjMat*)malloc(sizeof(AdjMat));
	testGraph->setN(5);
	testGraph->init();
	testGraph->setEdge(0, 1);
	testGraph->setEdge(0, 2);
	testGraph->setEdge(1, 3);
	testGraph->setEdge(2, 4);
	Room* testRooms[10];
	for (int i = 0; i < 10; i++){
		testRooms[i] = (Room*)malloc(sizeof(Room));
		testRooms[i]->searched = false;
		testRooms[i]->roomNumber = i;
		testRooms[i]->treasure = 10*i;
	}
	testHist->init(testRooms, testGraph);
	std::cout<<"limited by number of rooms"<<std::endl;
	testHist->printHistory(3, 120);
	std::cout<<"limited by treasure"<<std::endl;
	testHist->printHistory(5, 50);
	std::cout<<"looks correct?"<<std::endl;
	int response;
	std::cin>>response;
	if (response == 1){
		answer = true;
	}
	if (answer == true){
		std::cout<<"testPrintHistory passed"<<std::endl;
	}
	else {
		std::cout<<"testPrintHistory did not pass"<<std::endl;
	}
	return answer;
}
bool Tests::testWriteHistory(){
	bool ok = false;
	searchHistory* testHist = (searchHistory*)malloc(sizeof(searchHistory));
	AdjMat* testGraph = (AdjMat*)malloc(sizeof(AdjMat));
	testGraph->setN(5);
	testGraph->init();
	testGraph->setEdge(0, 1);
	testGraph->setEdge(0, 2);
	testGraph->setEdge(1, 3);
	testGraph->setEdge(2, 4);
	Room* testRooms[10];
	for (int i = 0; i < 10; i++){
		testRooms[i] = (Room*)malloc(sizeof(Room));
		testRooms[i]->searched = false;
		testRooms[i]->roomNumber = i;
		testRooms[i]->treasure = 10*i;
	}
	testHist->init(testRooms, testGraph);
	char text[100];
	std::cout<<"limited by number of rooms"<<std::endl;
	testHist->writeHistory(3, 120, "testOut1.txt");
	std::cout<<"limited by treasure"<<std::endl;
	testHist->writeHistory(5, 50, "testOut2.txt");
	std::cout<<"Files look correct?"<<std::endl;
	int response;
	std::cin>>response;
	if (response == 1){
		ok = true;
	}
	if (ok == true){
		std::cout<<"testWriteHistory passed"<<std::endl;
	}
	else {
		std::cout<<"testWriteHistory did not pass"<<std::endl;
	}
	return ok;
}
bool Tests::testSetN(){
	bool ok = false;
	AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
	graph->setN(5);
	if(graph->n == 5){
		ok = true;
	}
	if (ok == true){
		std::cout<<"testSetN passed"<<std::endl;
	}
	else {
		std::cout<<"testSetN did not pass"<<std::endl;
	}
	return ok;
}
bool Tests::testGetEdge(){
	bool ok = false;
	AdjMat* graph = (AdjMat*)malloc(sizeof(AdjMat));
	graph->setN(5);
	graph->init();
	graph->setEdge(2, 3);
	if (graph->getEdge(2, 3) == 1 && graph->getEdge(3, 2) == 1){
		ok = true;
	}
	if (ok == true){
		std::cout<<"testGetEdge passed"<<std::endl;
	}
	else {
		std::cout<<"testGetEdge did not pass"<<std::endl;
	}
	return ok;
}
