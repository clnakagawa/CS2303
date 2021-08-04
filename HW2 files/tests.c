/*
 * tests.c
 *
 *  Created on: Feb 14, 2021
 *      Author: cln
 */
#include "tests.h"

bool tests(){
	bool passed = false;
	bool firstSpace = firstSpaceTest();
	bool secondSpace = secondSpaceTest();
	bool firstBoard = firstBoardTest();
	bool secondBoard = secondBoardTest();
	bool thirdBoard = thirdBoardTest();
	bool boardPrint = boardPrintTest();
	bool firstLL = firstLLTest();
	bool secondLL = secondLLTest();
	bool printHistory = printHistoryTest();
	passed = firstSpace&&secondSpace&&firstBoard&&secondBoard&&thirdBoard&&firstLL&&secondLL;

	return passed;
}

bool firstSpaceTest(){
	bool passed = false;
	Space* testSpace = (Space*)malloc(sizeof(Space));
	testSpace->match = false;
	setMatch(testSpace);
	if (testSpace->match){
		passed = true;
	}
	if (passed){
		printf("first test of function setMatch passed\n");
	}
	else {
		printf("first test of function setMatch failed\n");
	}
	return passed;
}

bool secondSpaceTest(){
	bool passed = false;
	Space* testSpace  = (Space*)malloc(sizeof(Space));
	testSpace->match = true;
	setMatch(testSpace);
	if (testSpace->match){
		passed = true;
	}
	if (passed){
		printf("second test of function setMatch passed\n");
	}
	else {
		printf("second test of function setMatch failed\n");
	}
	return passed;
}

bool firstBoardTest(){
	bool passed = true;
	Space* testBoard = initBoard();
	int charVal;
	for (int i = 0; i < 25; i++){
		charVal = (int)((testBoard+i)->letter);
		if (charVal < 65 || charVal > 90){
			passed = false;
		}
	}
	if (passed){
		printf("first test of function initBoard passed\n");
	}
	else {
		printf("first test of function initBoard failed\n");
	}
	return passed;
}

bool secondBoardTest(){
	bool passed = true;
	Space* testBoard = initBoard();
	int numVal;
	for (int i = 0; i < 25; i++){
		numVal = (testBoard+i)->number;
		if (numVal < 0 || numVal > 9){
			passed = false;
		}
	}
	if (passed){
		printf("second test of function initBoard passed\n");
	}
	else {
		printf("second test of function initBoard failed\n");
	}
	return passed;
}

bool thirdBoardTest(){
	bool passed = true;
	Space* testBoard = initBoard();
	for (int i = 0; i < 25; i++){
		if ((testBoard+i)->match){
			passed = false;
		}
	}
	if (passed){
		printf("third test of function initBoard passed\n");
	}
	else {
		printf("third test of function initBoard failed\n");
	}
	return passed;
}

bool boardPrintTest(){
	bool passed = false;
	int temp = 0;
	Space* testBoard = initBoard();
	displayBoard(testBoard);
	puts("Looks correct (1 = true)?"); fflush(stdout);
	scanf("%d", &temp);
	if (temp == 1){
		passed = true;
	}
	if (passed){
		printf("test of function printBoard passed\n");
	}
	else {
		printf("test of function printBoard failed\n");
	}
	return passed;
}

bool firstLLTest(){
	bool passed = true;
	Node* testList = (Node*)malloc(sizeof(Node));
	Record* testRecord = (Record*)malloc(sizeof(Record));
	testRecord->letter = 'A';
	testRecord->number = 2;
	testRecord->match = false;
	testRecord->xloc = 2;
	testRecord->yloc = 3;
	addNode(testList, testRecord);
	if (testList->data == NULL){
		passed = false;
	}
	else if (testList->data->letter != 'A'){
		passed = false;
	}
	else if (testList->data->number != 2){
		passed = false;
	}
	else  if (testList->data->match){
		passed = false;
	}
	else if (testList->data->xloc != 2){
		passed = false;
	}
	else if (testList->data->yloc != 3){
		passed = false;
	}
	if (passed){
		printf("first test of function addNode passed\n");
	}
	else {
		printf("first test of function addNode failed\n");
	}
	return passed;
}

bool secondLLTest(){
	bool passed = true;
	Node* testList = (Node*)malloc(sizeof(Node));
	Record* testRecord = (Record*)malloc(sizeof(Record));
	testRecord->letter = 'A';
	testRecord->number = 2;
	testRecord->match = false;
	testRecord->xloc = 2;
	testRecord->yloc = 3;
	addNode(testList, testRecord);
	addNode(testList, testRecord);
	if (testList->next == NULL){
		passed = false;
	}
	else if (testList->next->data->letter != 'A'){
		passed = false;
	}
	else if (testList->next->data->number != 2){
		passed = false;
	}
	else  if (testList->next->data->match){
		passed = false;
	}
	else if (testList->next->data->xloc != 2){
		passed = false;
	}
	else if (testList->next->data->yloc != 3){
		passed = false;
	}
	if (passed){
		printf("second test of function addNode passed\n");
	}
	else {
		printf("second test of function addNode failed\n");
	}
	return passed;
}

bool printHistoryTest(){
	bool passed = false;
	int temp = 0;
	Node* testList = (Node*)malloc(sizeof(Node));
	Record* testRecord = (Record*)malloc(sizeof(Record));
	testRecord->letter = 'A';
	testRecord->number = 2;
	testRecord->match = false;
	testRecord->xloc = 2;
	Record* otherTestRecord = (Record*)malloc(sizeof(Record));
	otherTestRecord->letter = 'B';
	otherTestRecord->number = 3;
	otherTestRecord->match = false;
	otherTestRecord->xloc = 3;
	addNode(testList, testRecord);
	addNode(testList, otherTestRecord);
	printHistory(testList);
	puts("Looks correct (1 = true)?"); fflush(stdout);
	scanf("%d", &temp);
	if (temp == 1){
		passed = true;
	}
	if (passed){
		printf("test of function printHistory passed\n");
	}
	else {
		printf("test of function printHistory failed\n");
	}
	return passed;
}
