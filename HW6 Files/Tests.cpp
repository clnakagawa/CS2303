/*
 * Tests.cpp
 *
 *  Created on: Mar 13, 2021
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
	bool ok1 = testWelcomeScreen();
	bool ok2 = testPrintBoard();
	bool ok3 = testInitBoard();
	bool ok4 = testPutShip();
	bool ok5 = testGetInput();
	bool ok6 = testManual();
	bool ok7 = testValid();
	bool ok8 = testGetTarget();
	bool ok9 = testGenerate();
	bool ok10 = testRandom();
	bool ok11 = testUpdate();
	bool ok12 = testCheckWin();
	bool ok13 = testCheckShot();
	bool ok14 = testCardinals();
	bool ok15 = testCheckSunk();
	bool ok16 = testSysMessage();
	return ok1&&ok2&&ok3&&ok4&&ok5&&ok6&&ok7&&ok8&&ok9&&ok10&&ok11&&ok12&&ok13&&ok14&&ok15&&ok16;
}

bool Tests::testWelcomeScreen(){
	bool ok = false;
	int ans;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->welcomeScreen();
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testWelcomeScreen passed"<<std::endl;
	}
	else {
		std::cout<<"testWelcomeScreen failed"<<std::endl;
	}
	return ok;
}

bool Tests::testPrintBoard(){
	bool ok = false;
	int ans;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			testBoard->grid[i][j] = (Cell*)malloc(sizeof(Cell));
		}
	}
	testBoard->printBoard(false);
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testPrintBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testPrintBoard failed"<<std::endl;
	}
	return ok;
}

bool Tests::testInitBoard(){
	bool ok = false;
	int ans;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	testBoard->printBoard(true);
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testInitBoard passed"<<std::endl;
	}
	else {
		std::cout<<"testInitBoard failed"<<std::endl;
	}
	return ok;
}

bool Tests::testPutShip(){
	bool ok = false;
	int ans;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	Carrier* c = (Carrier*)malloc(sizeof(Carrier));
	c->setSymbol('c');
	c->setLength(5);
	Battleship* b = (Battleship*)malloc(sizeof(Battleship));
	b->setSymbol('b');
	b->setLength(4);
	Cruiser* r = (Cruiser*)malloc(sizeof(Cruiser));
	r->setSymbol('r');
	r->setLength(3);
	Submarine* s = (Submarine*)malloc(sizeof(Submarine));
	s->setSymbol('s');
	s->setLength(3);
	Destroyer* d = (Destroyer*)malloc(sizeof(Destroyer));
	d->setSymbol('d');
	d->setLength(2);
	Coordinate* coords[5];
	for (int i = 0; i < 5; i++){
		coords[i] = (Coordinate*)malloc(sizeof(Coordinate));
		coords[i]->setRow(i);
		coords[i]->setCol(0);
	}
	std::cout<<c->getSymbol()<<std::endl;
	testBoard->putShip(c, coords[0], HORIZONTAL);
	testBoard->putShip(b, coords[1], HORIZONTAL);
	testBoard->putShip(r, coords[2], HORIZONTAL);
	testBoard->putShip(s, coords[3], HORIZONTAL);
	testBoard->putShip(d, coords[4], HORIZONTAL);
	testBoard->printBoard(true);
	testBoard->initializeBoard();
	for (int i = 0; i < 5; i++){
		coords[i]->setCol(i);
		coords[i]->setRow(0);
	}
	testBoard->putShip(c, coords[0], VERTICAL);
	testBoard->putShip(b, coords[1], VERTICAL);
	testBoard->putShip(r, coords[2], VERTICAL);
	testBoard->putShip(s, coords[3], VERTICAL);
	testBoard->putShip(d, coords[4], VERTICAL);
	testBoard->printBoard(true);
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testPutShip passed"<<std::endl;
	}
	else {
		std::cout<<"testPutShip failed"<<std::endl;
	}
	return ok;
}

bool Tests::testGetInput(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	char inputOne[11] = "1020304050";
	Coordinate posOne[5];
	for (int i = 0; i < 5; i++){
		std::cout<<posOne[i].getRow()<<posOne[i].getCol()<<std::endl;
	}
	ok = testBoard->inputPositions(posOne, inputOne, 5);
	for (int i = 0; i < 5; i++){
		std::cout<<posOne[i].getRow()<<posOne[i].getCol()<<std::endl;
	}
	if (ok){
		std::cout<<"testGetInput passed"<<std::endl;
	}
	else {
		std::cout<<"testGetInput failed"<<std::endl;
	}
	return ok;
}

bool Tests::testManual(){
	bool ok = false;
	int ans;
	Ship* c = new Carrier();
	Ship* b = new Battleship();
	Ship* r = new Cruiser();
	Ship* s = new Submarine();
	Ship* d = new Destroyer();
	Ship ships[NUM_OF_SHIPS];
	ships[0] = *c;
	ships[1] = *b;
	ships[2] = *r;
	ships[3] = *s;
	ships[4] = *d;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	testBoard->manualPlace(ships);
	testBoard->printBoard(true);
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testManual passed"<<std::endl;
	}
	else {
		std::cout<<"testManual failed"<<std::endl;
	}
	return ok;
}

bool Tests::testValid(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	Coordinate* testCoord = (Coordinate*)malloc(sizeof(Coordinate));
	testCoord->setCol(0);
	testCoord->setRow(2);
	Coordinate* shipCoord = (Coordinate*)malloc(sizeof(Coordinate));
	shipCoord->setCol(3);
	shipCoord->setRow(1);
	Destroyer* d = (Destroyer*)malloc(sizeof(Destroyer));
	d->setSymbol('d');
	d->setLength(2);
	testBoard->putShip(d, shipCoord, VERTICAL);
	testBoard->printBoard(true);
	ok = testBoard->validLoc(testCoord, 0, 2)
			&&(!(testBoard->validLoc(testCoord, 0, 5)))
			&&(!(testBoard->validLoc(testCoord, 1, 10)));
	if (ok){
		std::cout<<"testValid passed"<<std::endl;
	}
	else {
		std::cout<<"testValid failed"<<std::endl;
	}
	return ok;
}

bool Tests::testGetTarget(){
	bool ok = false;
	Coordinate testCoord(4, 2);
	ok = (testCoord.getRow() == 2)&&(testCoord.getCol() == 4);
	if (ok){
		std::cout<<"testGetTarget passed"<<std::endl;
	}
	else {
		std::cout<<"testGetTarget failed"<<std::endl;
	}
	return ok;
}

bool Tests::testGenerate(){
	bool ok = false;
	int dir = 0;
	int length = 5;
	Coordinate coord(6, 11);
	Coordinate* testCoord = &coord;
	for (int i = 0; i < 20; i++){
		testCoord->generate(dir, length);
		ok = (testCoord->getCol() < 5) &&
				(testCoord->getCol() >= 0) &&
				(testCoord->getRow() < 10) &&
				(testCoord->getRow() >= 0);
	}
	if (ok){
		std::cout<<"testGenerate passed"<<std::endl;
	}
	else {
		std::cout<<"testGenerate failed"<<std::endl;
	}
	return ok;
}

bool Tests::testRandom(){
	bool ok = false;
	int ans;
	Ship* c = new Carrier();
	Ship* b = new Battleship();
	Ship* r = new Cruiser();
	Ship* s = new Submarine();
	Ship* d = new Destroyer();
	Ship ships[NUM_OF_SHIPS];
	ships[0] = *c;
	ships[1] = *b;
	ships[2] = *r;
	ships[3] = *s;
	ships[4] = *d;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	testBoard->randomPlace(ships);
	testBoard->printBoard(true);
	std::cout<<"Looks good?"<<std::endl;
	std::cin>>ans;
	ok = ans == 1;
	if (ok){
		std::cout<<"testRandom passed"<<std::endl;
	}
	else {
		std::cout<<"testRandom failed"<<std::endl;
	}
	return ok;
}

bool Tests::testUpdate(){
	bool ok = false;
	Ship* d = new Destroyer();
	d->setSymbol('d');
	d->setLength(2);
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	Coordinate shipLoc(2, 2);
	Coordinate targetLoc(2, 3);
	testBoard->putShip(d, &shipLoc, 0);
	testBoard->updateBoard(&shipLoc);
	testBoard->updateBoard(&targetLoc);
	ok = (testBoard->grid[2][2]->symbol == '*')
			&&(testBoard->grid[3][2]->symbol == 'm');
	if (ok){
		std::cout<<"testUpdate passed"<<std::endl;
	}
	else {
		std::cout<<"testUpdate failed"<<std::endl;
	}
	return ok;
}

bool Tests::testCheckWin(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	testBoard->pStats[0]->numHits = 15;
	testBoard->pStats[1]->numHits = 17;
	ok = (testBoard->isWinner(1))&&
			(!(testBoard->isWinner(0)));
	if (ok){
		std::cout<<"testCheckWin passed"<<std::endl;
	}
	else {
		std::cout<<"testCheckWin failed"<<std::endl;
	}
	return ok;
}

bool Tests::testCheckShot(){
	bool ok = false;
	Ship* d = new Destroyer();
	d->setSymbol('d');
	d->setLength(2);
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	Coordinate shipLoc(2, 2);
	Coordinate targetLoc(2, 3);
	Coordinate coordOne(3, 2);
	Coordinate coordTwo(4, 4);
	testBoard->putShip(d, &shipLoc, 0);
	testBoard->updateBoard(&shipLoc);
	testBoard->updateBoard(&targetLoc);
	ok = (testBoard->checkShot(&shipLoc) == -1)&&
			(testBoard->checkShot(&targetLoc) == -1)&&
			(testBoard->checkShot(&coordOne) == 1)&&
			(testBoard->checkShot(&coordTwo) == 0);
	if (ok){
		std::cout<<"testCheckShot passed"<<std::endl;
	}
	else {
		std::cout<<"testCheckShot failed"<<std::endl;
	}
	return ok;
}

bool Tests::testCardinals(){
	bool ok = false;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->initializeBoard();
	testBoard->checkBounds(5, NORTH);
	testBoard->checkBounds(10, SOUTH);
	testBoard->checkBounds(-1, WEST);
	testBoard->checkBounds(4, EAST);
	ok = (testBoard->cardinals[0])&&
			(!(testBoard->cardinals[1]))&&
			(!(testBoard->cardinals[2]))&&
			(testBoard->cardinals[3]);
	if (ok){
		std::cout<<"testCardinals passed"<<std::endl;
	}
	else {
		std::cout<<"testCardinals failed"<<std::endl;
	}
	return ok;
}

bool Tests::testCheckSunk(){
	bool ok = false;
	int ans;
	FILE* testOutStream = NULL;
	testOutStream = fopen("testLog.txt", "w");
	short testShips[2][NUM_OF_SHIPS];
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testShips[0][0] = 5;
	testShips[0][1] = 4;
	testShips[0][2] = 3;
	testShips[0][3] = 3;
	testShips[0][4] = 2;
	testShips[1][0] = 5;
	testShips[1][1] = 4;
	testShips[1][2] = 3;
	testShips[1][3] = 3;
	testShips[1][4] = 2;
	ok = (!(testBoard->checkSunkShip(testShips, 0, 'd', testOutStream)))
			&&(testBoard->checkSunkShip(testShips, 0, 'd', testOutStream));
	fclose(testOutStream);
	std::cout<<"file looks good?"<<std::endl;
	std::cin>>ans;
	ok = ok&&(ans == 1);
	if (ok){
		std::cout<<"testCheckSunk passed"<<std::endl;
	}
	else {
		std::cout<<"testCheckSunk failed"<<std::endl;
	}
	return ok;
}

bool Tests::testSysMessage(){
	bool ok = true;
	Board* testBoard = (Board*)malloc(sizeof(Board));
	testBoard->systemMessage("Test Message");
	std::cout<<"testSysMessage passed"<<std::endl;
	return ok;
}
