/*
 * Tests.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: cln
 */

#include "Tests.h"

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests(){
	return true;
	bool ok1 = testInitBoard();
	bool ok2 = testPrintBoard();
	bool ok3 = testInitPlayers();
	bool ok4 = testPrintFullBoard();
	bool ok5 = testChance();
	bool ok6 = testStay();
	bool ok7 = testRail();
	bool ok8 = testMove();
	bool ok9 = testMoveGo();
	bool ok10 = testUpgrade();
	bool ok11 = testBuy();
	bool ok12 = testSell();
	bool ok13 = testBankrupt();
	bool ok14 = testPrintHist();
	bool ok15 = testAddEntry();
	return ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7&&ok8&&ok9&&ok10&&ok11&&ok12&&ok13&&ok14&&ok15;
}

bool Tests::testInitBoard(){
	fflush(stdin);
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	for (int i = 0; i < 32; i++){
		ok = testBoard->spaces[i]->number == i;
		if (i % 8 == 0){
			ok = testBoard->spaces[i]->symbol == 'f';
		}
		else if ((i-2) % 8 == 0){
			ok = testBoard->spaces[i]->symbol == 'c';
		}
		else if ((i-5) % 8 == 0){
			ok = testBoard->spaces[i]->symbol == 'r';
			ok = testBoard->spaces[i]->own == false;
		}
		else {
			ok = testBoard->spaces[i]->houses == 0;
			ok = testBoard->spaces[i]->own == false;
			ok = testBoard->spaces[i]->symbol == 's';
		}
	}
	if (ok){
		std::cout<<"testInitBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testInitBoard failed"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintBoard(){
	fflush(stdin);
	int ans;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->printBoard(false);
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testPrintBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testPrintBoard failed"<<std::endl;
	}
	return ok;
}

bool Tests::testInitPlayers(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	std::cout<<testBoard->playerCount<<std::endl;
	for (int i = 0; i < 3; i++){
		std::cout<<testBoard->players[i]->pos<<std::endl;
		std::cout<<testBoard->players[i]->money<<std::endl;
		std::cout<<testBoard->players[i]->numProps<<std::endl;
		for (int j = 0; j < 32; j++){
			if (testBoard->players[i]->property[j]){
				std::cout<<j<<std::endl;
				std::cout<<testBoard->spaces[j]->houses<<std::endl;
			}
		}
	}
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testInitPlayers passed"<<std::endl;
	}
	else {
		std::cout<<"testInitPlayers failed"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintFullBoard(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	testBoard->printBoard(true);
	fclose(f);
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testPrintFullBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testPrintFullBoard failed"<<std::endl;
	}
	return ok;
}

bool Tests::testChance(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<testBoard->players[1]->money<<std::endl;
	testBoard->chance(1);
	std::cout<<testBoard->players[1]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testChance passed"<<std::endl;
	}
	else {
		std::cout<<"testChance failed"<<std::endl;
	}
	return ok;
}

bool Tests::testStay(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	testBoard->stay(1, 3);
	testBoard->stay(2, 3);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testStay passed"<<std::endl;
	}
	else {
		std::cout<<"testStay failed"<<std::endl;
	}
	return ok;
}

bool Tests::testRail(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<testBoard->players[2]->rNum<<std::endl;
	testBoard->rail(1, 5);
	testBoard->rail(2, 5);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testRail passed"<<std::endl;
	}
	else {
		std::cout<<"testRail failed"<<std::endl;
	}
	return ok;
}

bool Tests::testMove(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	testBoard->printBoard(true);
	testBoard->move(1);
	testBoard->printBoard(true);
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testMove passed"<<std::endl;
	}
	else {
		std::cout<<"testMove failed"<<std::endl;
	}
	return ok;
}

bool Tests::testMoveGo(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	testBoard->printBoard(true);
	std::cout<<"Player 1 has "<<testBoard->players[1]->money<<std::endl;
	int last = 0;
	while (testBoard->players[1]->pos >= last){
		last = testBoard->players[1]->pos;
		testBoard->move(1);
	}
	testBoard->printBoard(true);
	std::cout<<"Player 1 has "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testMoveGo passed"<<std::endl;
	}
	else {
		std::cout<<"testMoveGo failed"<<std::endl;
	}
	return ok;
}

bool Tests::testUpgrade(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	testBoard->players[1]->money = 0;
	testBoard->upgrade(1, 31);
	testBoard->upgrade(1, 3);
	for (int i = 0; i < 4; i++){
		testBoard->upgrade(2, 14);
	}
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testUpgrade passed"<<std::endl;
	}
	else {
		std::cout<<"testUpgrade failed"<<std::endl;
	}
	return ok;
}

bool Tests::testBuy(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	testBoard->players[1]->money = 0;
	testBoard->buy(1, 4);
	testBoard->buy(1, 5);
	testBoard->buy(2, 29);
	testBoard->buy(2, 30);
	testBoard->buy(2, 6);
	testBoard->printBoard(true);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testBuy passed"<<std::endl;
	}
	else {
		std::cout<<"testBuy failed"<<std::endl;
	}
	return ok;
}

bool Tests::testSell(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	testBoard->players[1]->money = 0;
	testBoard->sell(1, 3);
	testBoard->sell(1, 4);
	testBoard->sell(2, 5);
	testBoard->sell(2, 14);
	testBoard->printBoard(true);
	std::cout<<"Player 1 money: "<<testBoard->players[1]->money<<std::endl;
	std::cout<<"Player 2 money: "<<testBoard->players[2]->money<<std::endl;
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = ans == 1;
	if (ok){
		std::cout<<"testSell passed"<<std::endl;
	}
	else {
		std::cout<<"testSell failed"<<std::endl;
	}
	return ok;
}

bool Tests::testBankrupt(){
	fflush(stdin);
	int ans;
	FILE* f = fopen("monopolyInput.txt", "r");
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initBoard();
	testBoard->initPlayers(f);
	fclose(f);
	testBoard->players[1]->money = -300;
	testBoard->players[2]->money = -10;
	bool bOne = testBoard->isBankrupt(1);
	bool bTwo = testBoard->isBankrupt(2);
	std::cout<<"looks good?"<<std::endl;
	std::cin>>ans;
	bool ok = (ans == 1)&&(bOne)&&(!bTwo);
	if (ok){
		std::cout<<"testBankrupt passed"<<std::endl;
	}
	else {
		std::cout<<"testBankrupt failed"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintHist(){
	fflush(stdin);
	int ans = 0;
	Record* testRecord = (Record*)malloc(sizeof(Record));
	testRecord->next = (Record*)malloc(sizeof(Record));
	testRecord->next->next = (Record*)malloc(sizeof(Record));
	RecordData dataOne = { 1, 0, 5, 0, 5, 0, -1, false, 0 };
	RecordData dataTwo = { 2, 1, 7, 0, 7, 0, -1, false, 30 };
	RecordData dataThree = { 3, 2, 6, 2, 6, 0, 6, false, 30 };
	testRecord->data = &dataOne;
	testRecord->next->data = &dataTwo;
	testRecord->next->next->data = &dataThree;
	printHistory(&testRecord);
	std::cout<<"looks good?"<<std::endl;
		std::cin>>ans;
		bool ok = (ans == 1);
		if (ok){
			std::cout<<"testPrintHist passed"<<std::endl;
		}
		else {
			std::cout<<"testPrintHist failed"<<std::endl;
		}
	return ok;
}

bool Tests::testAddEntry(){
	fflush(stdin);
	int ans = 0;
	Record* testRecord = (Record*)malloc(sizeof(Record));
	testRecord->next = (Record*)malloc(sizeof(Record));
	testRecord->next->next = (Record*)malloc(sizeof(Record));
	RecordData dataOne = { 1, 0, 5, 0, 5, 0, -1, false, 0 };
	RecordData dataTwo = { 2, 1, 7, 0, 7, 0, -1, false, 30 };
	RecordData dataThree = { 3, 2, 6, 2, 6, 0, 6, false, 30 };
	testRecord->data = &dataOne;
	testRecord->next->data = &dataTwo;
	testRecord->next->next->data = &dataThree;
	printHistory(&testRecord);
	addEntry(&testRecord, 1, 3, 3, 1, 8, 0, -1, false, 10);
	printHistory(&testRecord);
	std::cout<<"looks good?"<<std::endl;
		std::cin>>ans;
		bool ok = (ans == 1);
		if (ok){
			std::cout<<"testAddEntry passed"<<std::endl;
		}
		else {
			std::cout<<"testAddEntry failed"<<std::endl;
		}
	return ok;
}
