/*
 * Production.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#include "Production.h"

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[]){
	bool answer = true;

	Board* boardOne = (Board*)malloc(sizeof(Board));       /* Player one game board */
	Board* boardTwo = (Board*)malloc(sizeof(Board));       /* Player two game board */

	Coordinate* target = (Coordinate*)malloc(sizeof(Coordinate));             /* x, y value of a target */
	Coordinate* targetTemp = (Coordinate*)malloc(sizeof(Coordinate));         /* x, y value that holds a temporary value*/
	Coordinate* targetOrigin = (Coordinate*)malloc(sizeof(Coordinate));       /* x, y value of the original target */
	Coordinate* targetAI = (Coordinate*)malloc(sizeof(Coordinate));           /* x, y value of the targets using AI technique */

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

	bool huntMode = true;                     /* mode of randomly selecting a target */
	bool targetMode = false;                    /* mode when there is a hit */
	bool flipper = true;	                  /* flips values of boolean */
	bool sunk = false;                    /* if a ship has sank */
	bool tempBools[4];
	for (int i = 0; i < 4; i++){
		tempBools[i] = false;
	}

	short sunkShip[2][NUM_OF_SHIPS] = {{5, 4, 3, 3, 2},
	                                   {5, 4, 3, 3, 2}};  /* tracks parts of the ship destroyed */

	short player  = 0;	           /* 0 -> player1, 1 -> player2 */
	short shot    = 0;             /* holds temp value if ship has been shot */
	int   option  = 0;             /* option for player to place ship manually or randomly */
	int   north   = 0,             /* holds change of value when going north */
		  south   = 0,             /* holds change of value when going south */
		  east    = 0,             /* holds change of value when going east */
		  west    = 0;             /* holds change of value when going west */
	int i = 0;
	int counter = 1;             /* i and counter are used as counters */

	char  shipSymbol = '\0';       /* temporary value to save character symbol of the ship */

	FILE *outStream = NULL;        /* stream to output file battleship.log */

		/* Start of Program */
	outStream = fopen (LOG_FILE_NAME, "w");

	srand ((unsigned int) time (NULL));

		/**
		 * Print welcome screen
		 */
	boardOne->welcomeScreen();
	boardOne->systemMessage ("                            Hit <ENTER> to continue!\n");
	for (int i = 0; i < 40; i++){
		printf("\n");
	}

		/**
		 * Each Player's game board should be initialized to all '~' indicating
		 * no ships have been placed on either board.
		 */
	boardOne->initializeBoard();
	boardTwo->initializeBoard();

	printf ("> Please select from the following menu:\n");
	printf ("> [1] Manually\n");
	printf ("> [2] Randomly\n");
	printf ("> Enter Option: ");
	scanf ("%d", &option);
	switch(option){
	case 1:
		boardOne->manualPlace(ships);
		break;
	case 2:
		boardOne->randomPlace(ships);
		break;
	default:
		break;
	}
	boardTwo->randomPlace(ships);
	fflush(stdout);
	printf ("> Player 2 (Computer's) board has been generated.\n");

		/**
		 * The program should randomly select Player1 or Player2 to go first.
		 */
	player = rand() % 2;
	printf("> Player %d has been randomly selected to go first.\n", player + 1);
	boardOne->systemMessage("> Hit <ENTER> to continue!\n");
	for (int i = 0; i < 20; i++){
		printf("\n");
	}

	while(true) {

		/* Write to battleship.log */
		fprintf (outStream, "Player %d's turn.\n", player + 1);
			/* switches back and forth between player 1 and player 2 */
		switch (player) {

			case PLAYER_ONE:
					/* Print player 2's game board*/
				printf ("> Player 2's Board:\n");
				boardTwo->printBoard(false);
				printf ("> PLAYER 1'S TURN\n");

					/* Prompts user to enter target */

				do {

					target->setInput();
					std::cout<<target->getRow()<<target->getCol()<<std::endl;
					shot = boardTwo->checkShot(target);

						/* prompts user that input is invalid or either a hit or miss cell */
					if (shot == -1){
						printf ("> Try inputting another target!\n");
					}

				} while (shot == -1);

					/* saves the character of the targeted cell */
				shipSymbol = boardTwo->grid[target->getRow()][target->getCol()]->symbol;
				break;

			case PLAYER_TWO:
				counter = 1;
					/**** IMPLEMENTATION OF ARTIFICIAL INTELLIGENCE ****/

					/* Print player 1's game board */
				printf ("> Player 1's Board:\n");
				boardOne->printBoard(true);
				printf ("> COMPUTER'S TURN\n");

				if (sunk) {
					sunk = false;
					targetMode = false;
					huntMode = true;
				}
				if (targetMode) {

					/* retains value of targetAI */
					target->setCol(targetAI->getCol());
					target->setRow(targetAI->getRow());

					do {
						for (int a = 0; a < 4; a++){
							tempBools[a] = false;
						}
						if (boardOne->cardinals[NORTH]) {        /* NORTH */
							tempBools[0] = true;
							target->setRow(north);
						}
						else if (boardOne->cardinals[SOUTH]) { /* SOUTH */
							tempBools[1] = true;
							target->setRow(south);
						}
						else if (boardOne->cardinals[WEST]) {  /* WEST */
							tempBools[2] = true;
							target->setCol(west);
						}
						else if (boardOne->cardinals[EAST]) {  /* EAST */
							tempBools[3] = true;
							target->setCol(east);
						}
						else if (!boardOne->cardinals[NORTH] && !boardOne->cardinals[SOUTH] &&
						         !boardOne->cardinals[WEST]  && !boardOne->cardinals[EAST]  &&
								 !sunk) {
								/* All cardinals are false but has not sunk a ship */

								/* reinitiliazes target to the original target value */
							target->setRow(targetOrigin->getRow());
							target->setCol(targetOrigin->getCol());
							targetTemp->setCol(target->getCol());
							targetTemp->setRow(target->getRow());
								/**
								 * Counter increments by one, when the loop cycles again and
								 * all cardinals are still false. This ensures that we are checking
								 * one cell over the adjacent cells
								 */
							north = target->getRow() - counter;
							targetTemp->setRow(north);
								/* checks if the value NORTH of the target is a hit or miss */
							if (boardOne->checkShot(targetTemp) != -1 && north >= 0) {
								boardOne->cardinals[NORTH] = true;
							}
							targetTemp->setCol(target->getCol());
							targetTemp->setRow(target->getRow());
							south = target->getRow() + counter;
							targetTemp->setRow(south);

								/* checks if the value SOUTH of the target is a hit or miss */
							if (boardOne->checkShot(targetTemp) != -1 && south <= 9) {
								boardOne->cardinals[SOUTH] = true;
							}

							targetTemp->setCol(target->getCol());
							targetTemp->setRow(target->getRow());
							west = target->getCol() - counter;
							targetTemp->setCol(west);

								/* checks if the value WEST of the target is a hit or miss */
							if (boardOne->checkShot(targetTemp) != -1 && west >= 0) {
								boardOne->cardinals[WEST] = true;
							}
							targetTemp->setCol(target->getCol());
							targetTemp->setRow(target->getRow());
							east = target->getCol() + counter;
							targetTemp->setCol(east);

								/* checks if the value EAST of the target is a hit or miss */
							if (boardOne->checkShot(targetTemp) != -1 && east <= 9) {
								boardOne->cardinals[EAST] = true;
							}
							counter++;
						} else  {
								/* when all conditions are not met, it reverts back to Hunt mode */
							targetMode = false;
							huntMode = true;
							break;
						}
							/* checks if the shot is a hit or miss */
						shot = boardOne->checkShot(target);
						for (int b = 0; b < 4; b++){
							if (tempBools[b]){
								boardOne->cardinals[b] = false;
							}
						}

					} while (shot == -1 && targetMode == true);

					if (shot == 1 && huntMode == false) {
						for (i = 0; i < 4; i++) {
							if (flipper == false)
								boardOne->cardinals[i] = false;

							if (boardOne->cardinals[i] == flipper)
								flipper = false;
						}
					} else {
						for (i = 0; i < 4; i++) {
							if (flipper == true && boardOne->cardinals[i] != false) {
								boardOne->cardinals[i] = false;
								break;
							}
						}
					}

						/* reinitializes the value of flipper */
					flipper = true;


				}
				if (targetMode){
					std::cout<<targetTemp->getRow()<<targetTemp->getCol()<<std::endl;
					std::cout<<target->getRow()<<target->getCol()<<std::endl;
					shot = boardOne->checkShot(target);
					if (boardOne->grid[target->getRow()][target->getCol()]->symbol == '*'){
						huntMode = true;
					}
				}
				for (int b = 0; b < 4; b++){
					if (tempBools[b]){
						boardOne->cardinals[b] = false;
					}
				}
				if (huntMode) {
					std::cout<<"hunt"<<std::endl;

						/* reinitializes important values */
					counter = 1;
					flipper = true;
					for (i = 0; i < 4; i++)
						boardOne->cardinals[i] = true;

						/* loop that gets a random number of a cell as target */
					do {
						target->setRow(rand() % 10);
						target->setCol(rand() % 10);

							/* checks target if it is a miss or hit cell */
						shot = boardOne->checkShot(target);
					} while (shot == -1);

						/* if it is a Hit, this saves the value of the original target */
					if (shot == 1) {
						targetOrigin->setRow(target->getRow());
						targetOrigin->setCol(target->getCol());
					}
				}

					/**
					 * shot values (1 means craft is hit, 0 means missed and -1 means
					 * it is already a hit or miss cell
					 */
				if (shot == 1) {
					huntMode = false;
					targetMode = true;
					targetAI->setRow(target->getRow());
					targetAI->setCol(target->getCol());
					if (boardOne->cardinals[NORTH] == true) {  /* NORTH */
						north = (targetAI->getRow() - 1);
						boardOne->checkBounds(north, NORTH);
						targetTemp->setRow(target->getRow());
						targetTemp->setCol(target->getCol());
						targetTemp->setRow(north);
						if (boardOne->checkShot(targetTemp) == -1){
							boardOne->cardinals[NORTH] = false;
						}
					}

					if (boardOne->cardinals[SOUTH] == true) {  /* SOUTH */
						south = targetAI->getRow() + 1;
						boardOne->checkBounds(south, SOUTH);
						targetTemp->setRow(target->getRow());
						targetTemp->setCol(target->getCol());
						targetTemp->setRow(south);
						if (boardOne->checkShot(targetTemp) == -1){
							boardOne->cardinals[SOUTH] = false;
						}
					}

					if (boardOne->cardinals[WEST] == true) {   /* WEST */
						west  = targetAI->getCol() - 1;
						boardOne->checkBounds(west, WEST);
						targetTemp->setRow(target->getRow());
						targetTemp->setCol(target->getCol());
						targetTemp->setCol(west);
						if (boardOne->checkShot(targetTemp) == -1){
							boardOne->cardinals[WEST] = false;
						}
					}

					if (boardOne->cardinals[EAST] == true) {   /* EAST */
						east  = targetAI->getCol() + 1;
						boardOne->checkBounds(east, EAST);
						targetTemp->setRow(target->getRow());
						targetTemp->setCol(target->getCol());
						if (boardOne->checkShot(targetTemp) == -1){
							boardOne->cardinals[EAST] = false;
						}
					}
				}

					/* saves the character of the targeted cell */
				shipSymbol = boardOne->grid[target->getRow()][target->getCol()]->symbol;
				break;
		}

			/**
			 * Prompts player if it's a hit or miss
			 */
		if (shot == 1) { /* HIT */
			printf ("> %d, %d is a hit!\n", target->getRow(), target->getCol());

				/* Write to battleship.log */
			fprintf (outStream, "%d, %d is a hit!\n", target->getRow(), target->getCol());

				/* Keeps track so number of hits for stats */
			boardOne->pStats[player]->numHits++;

				/* Checks if the ship has sank */
			if (player == 1)
				sunk = boardOne->checkSunkShip(sunkShip, player, shipSymbol, outStream);
			else {
				boardOne->checkSunkShip(sunkShip, !player, shipSymbol, outStream);
			}
		} else {        /* MISS */
			printf ("> %d, %d is a miss!\n", target->getRow(), target->getCol());

				/* Write to battleship.log */
			fprintf (outStream, "%d, %d is a miss!\n", target->getRow(), target->getCol());
			boardOne->pStats[player]->numMisses++;
		}

		if (player == 0){ /* If Player 1 then update player 2's gameboard */
			boardTwo->updateBoard(target);
		}
		else {            /* If Player 2 then update player 1's gameboard */
			boardOne->updateBoard(target);
		}
			/* Determins if there is a winner based on number of hits */
		if (boardOne->isWinner(player)) {
			printf ("\n> Player %d wins!\n", player + 1);

				/* Write to battleship.log */
			fprintf (outStream, "\n>>>>> Player %d wins! <<<<<\n", player + 1);
			break;
		}

		boardOne->systemMessage("> Hit <ENTER> to continue!\n");

			/* switches from player 1 to player 2 */
		player = !player;
		for (int i = 0; i < 20; i++){
			printf("\n");
		}
	}
	boardOne->pStats[0]->totalShots = boardOne->pStats[0]->numHits + boardOne->pStats[0]->numMisses;
	boardOne->pStats[0]->hitMissRatio = ((double) boardOne->pStats[0]->numHits/(double) boardOne->pStats[0]->numMisses) * 100;
	boardOne->pStats[1]->totalShots = boardOne->pStats[1]->numHits + boardOne->pStats[1]->numMisses;
	boardOne->pStats[1]->hitMissRatio = ((double) boardOne->pStats[1]->numHits/(double) boardOne->pStats[1]->numMisses) * 100;
	fprintf (outStream, "+===================================================\n");
	fprintf (outStream, "|                    PLAYER STATS                   \n");
	fprintf (outStream, "+---------------------------------------------------\n");
	fprintf (outStream, "| PLAYER 1 : %d hits                                \n", boardOne->pStats[0]->numHits);
	fprintf (outStream, "|            %d misses                              \n", boardOne->pStats[0]->numMisses);
	fprintf (outStream, "|            %d total shots                         \n", boardOne->pStats[0]->totalShots);
	fprintf (outStream, "|            %.2lf%% hit/miss ratio                 \n", boardOne->pStats[0]->hitMissRatio);
	fprintf (outStream, "| PLAYER 2 : %d hits                                \n", boardOne->pStats[1]->numHits);
	fprintf (outStream, "|            %d misses                              \n", boardOne->pStats[1]->numMisses);
	fprintf (outStream, "|            %d total shots                         \n", boardOne->pStats[1]->totalShots);
	fprintf (outStream, "|            %.2lf%% hit/miss ratio                 \n", boardOne->pStats[1]->hitMissRatio);
	fprintf (outStream, "+===================================================");

	fclose (outStream);
	return answer;
}
