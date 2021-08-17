/*
 * Board.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Board.h"

Board::Board() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::welcomeScreen(){
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n");
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. Player 1 is you and Player 2 is the computer.\n");
	printf ("3. Player 1 will be prompted if user wants to manually input coordinates\n");
	printf ("   for the game board or have the computer randomly generate a game board\n");
	printf ("4. There are five types of ships to be placed by longest length to the\n");
	printf ("   shortest; [c] Carrier has 5 cells, [b] Battleship has 4 cells, [r] Cruiser\n");
	printf ("   has 3 cells, [s] Submarine has 3 cells, [d] Destroyer has 2 cells\n");
	printf ("5. The computer randomly selects which player goes first\n");
	printf ("6. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [*] hit and [m] miss\n");
	printf ("7. First player to guess the location of all ships wins\n\n");
}

void Board::initializeBoard(){
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			grid[i][j] = (Cell*)malloc(sizeof(Cell));
			grid[i][j]->symbol = WATER;
			grid[i][j]->pos = (Coordinate*)malloc(sizeof(Coordinate));
			grid[i][j]->pos->setCol(j);
			grid[i][j]->pos->setRow(i);
		}
	}

	for (int i = 0; i < 4; i++){
		cardinals[i] = true;
	}
	pStats[0] = (Stats*)malloc(sizeof(Stats));
	pStats[1] = (Stats*)malloc(sizeof(Stats));
	pStats[0]->numHits = 0;
	pStats[0]->numMisses = 0;
	pStats[0]->totalShots = 0;
	pStats[0]->hitMissRatio = 0.0;
	pStats[1]->numHits = 0;
	pStats[1]->numMisses = 0;
	pStats[1]->totalShots = 0;
	pStats[1]->hitMissRatio = 0.0;
}

void Board::printBoard(bool showPegs){
	printf ("  0 1 2 3 4 5 6 7 8 9\n");
	for (int i = 0; i < 10; i++){
		printf("%d ", i);
		for (int j = 0; j < 10; j++){
			if (showPegs){
				printf("%c ", (grid[i][j]->symbol));
			}
			else {
				switch(grid[i][j]->symbol){
				case HIT:
					printf("%c ", HIT);
					break;
				case MISS:
					printf("%c ", MISS);
					break;
				case WATER:
				default:
					printf("%c ", WATER);
					break;
				}
			}
		}
		printf("\n");
	}
}

void Board::putShip(Ship* ship, Coordinate* pos, int dir){
	short shipLength = ship->getLength();
	int ir = pos->getRow();
	int ic = pos->getCol();
	for (short i = 0; i < shipLength; i++){
		if (dir == HORIZONTAL){
			grid[ir][ic+i]->symbol = ship->getSymbol();
		}
		else {
			grid[ir+i][ic]->symbol = ship->getSymbol();
		}
	}
}

bool Board::inputPositions(Coordinate pos[], char strPos[], int length){
	bool ok = true;
	int tempC, tempR;
	for (int i = 0; i < length && ok; i++){
		tempR = strPos[2*i]-'0';
		tempC = strPos[2*i+1]-'0';
		if (tempR < 0 || tempR > 9 || tempC < 0 || tempC > 9){
			ok = false;
		}
		else {
			pos[i].setRow(tempR);
			pos[i].setCol(tempC);
		}
	}
	return ok;
}

void Board::manualPlace(Ship ships[]){
	char       stringPosition[11] = "";
	int        i = 0, j = 0;

	Coordinate position[5];
	bool    isValid = false;

	fflush (stdin);

	for (i = 0; i < NUM_OF_SHIPS; i++) {

		while (true) {
			for (int n = 0; n < 20; n++){
				printf("\n");
			}
			printBoard(true);
			printf ("> Please enter the %d cells to place the %s across (no spaces):\n", ships[i].getLength(), ships[i].getName());
			printf ("> ");
			scanf ("%s", stringPosition);

			/* convertStringtoPosition returns false if unsuccessful */
			if (inputPositions(position, stringPosition, ships[i].getLength())) {

				isValid = true;

				for (j = 0; j < ships[i].getLength(); j++) {

					if (grid[position[j].getRow()][position[j].getCol()]->symbol == WATER) {
						grid[position[j].getRow()][position[j].getCol()]->symbol = ships[i].getSymbol();
					} else {
						isValid = false;
						printf ("> Invalid input!\n");

						if (j != 0)
							while (j >= 0) {
								grid[position[j].getRow()][position[j].getCol()]->symbol = WATER;
								j--;
							}

						break;
					}
				}
			} else {
				isValid = false;
				printf ("> Invalid input!\n");
			}

			if (isValid == true) break;
		}

	}
}

bool Board::isWinner(int pNum){
	return pStats[pNum]->numHits == 17;
}

bool Board::validLoc(Coordinate* pos, int dir, int length) {
	bool isValid = true;

	for (int i = 0; isValid && i < length; i++) {
		if (dir == HORIZONTAL) {
			if (grid[pos->getRow()][pos->getCol() + i]->symbol != WATER ||
				(pos->getCol() + i) > 9)
				isValid = false;
		} else {
			if (grid[pos->getRow() + i][pos->getCol()]->symbol != WATER ||
				(pos->getRow() + i) > 9)
				isValid = false;
		}
	}

	return isValid;
}

void Board::randomPlace(Ship ships[]) {
	std::cout<<"Starting"<<std::endl;
	srand(time(NULL));
	Coordinate* position = (Coordinate*)malloc(sizeof(Coordinate));
	int direction = -1;
	bool isValid = false;
	int i = 0;
	for (i = 0; i < NUM_OF_SHIPS; i++) {
		isValid = false;
		while (!isValid) {
			direction = rand() % 2; /* 0 -> horizontal, 1 -> vertical */
			position->generate(direction, ships[i].getLength());
			isValid = validLoc(position, direction, ships[i].getLength());
		}
		putShip(&ships[i], position, direction);
	}
}

void Board::updateBoard (Coordinate* target) {
	switch (grid[target->getRow()][target->getCol()]->symbol) {
		/* miss */
		case WATER:
			grid[target->getRow()][target->getCol()]->symbol = MISS;
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			grid[target->getRow()][target->getCol()]->symbol = HIT;
			break;

		case HIT:
		case MISS:
		default:
			break;
	}
}

void Board::checkBounds(int bound, int dir) {
	switch (dir) {
		case NORTH:
			if (bound < 0)
				cardinals[0] = false;
			else
				cardinals[0] = true;
			break;

		case SOUTH:
			if (bound > 9)
				cardinals[1] = false;
			else
				cardinals[1] = true;
			break;

		case WEST:
			if (bound < 0)
				cardinals[2] = false;
			else
				cardinals[2] = true;
			break;

		case EAST:
			if (bound > 9)
				cardinals[3] = false;
			else
				cardinals[3] = true;
			break;
	}
}

void Board::systemMessage (const char* message) {
	do {
		std::cout<<message<<std::endl;
	} while (std::cin.get() != '\n');
}

bool Board::checkSunkShip(short sunkShip[][NUM_OF_SHIPS], short player, char shipSymbol, FILE *stream) {
	bool sunked = false;
	switch (shipSymbol) {
		case CARRIER:
			if (--sunkShip[player][0] == 0) {
				printf ("> Player %d's Carrier sunked!\n", player + 1);
				fprintf (stream, "Player %d's Carrier sunked!\n", player + 1);
				sunked = true;
			}
			break;
		case BATTLESHIP:
			if (--sunkShip[player][1] == 0) {
				printf ("> Player %d's Battleship sunked!\n", player + 1);
				fprintf (stream, "Player %d's Battleship sunked!\n", player + 1);
				sunked = true;
			}
			break;
		case CRUISER:
			if (--sunkShip[player][2] == 0) {
				printf ("> Player %d's Cruiser sunked!\n", player + 1);
				fprintf (stream, "Player %d's Cruiser sunked!\n", player + 1);
				sunked = true;
			}
			break;
		case SUBMARINE:
			if (--sunkShip[player][3] == 0) {
				printf ("> Player %d's Submarine sunked!\n", player + 1);
				fprintf (stream, "Player %d's Submarine sunked!\n", player + 1);
				sunked = true;
			}
			break;
		case DESTROYER:
			if (--sunkShip[player][4] == 0) {
				printf ("> Player %d's Destroyer sunked!\n", player + 1);
				fprintf (stream, "Player %d's Destroyer sunked!\n", player + 1);
				sunked = true;
			}
			break;
	}
	return sunked;
}

short Board::checkShot(Coordinate* target) {
	int hit = -2;
	switch (grid[target->getRow()][target->getCol()]->symbol) {
		case WATER:
			hit = 0;
			break;
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			hit = 1;
			break;
		case HIT:
		case MISS:
		default:
			hit = -1;
			break;
	}
	return hit;
}
