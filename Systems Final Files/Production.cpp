/*
 * Production.cpp
 *
 *  Created on: Mar 16, 2021
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
	int currentP;
	char *endptr;
	bool ok = true;
	if (argc < 4){
		std::cout<<"not enough arguments (enter at least infile name, outfile name, number of dice rolls)\n"<<std::endl
		return false;
	}
	else if (argc < 5){
		currentP = 0;
	}
	else {
		currentP = currentP = strtol(argv[4], &endptr, 10);
	}
	char* ifname = argv[1];
	char* ofname = argv[2];
	int input;
	int upCount;
	int endLoc;
	int tempNum;
	int dice;
	int bought;
	int sold;
	int changeM;
	bool b;
	int numTurns = strtol(argv[3], &endptr, 10);
	int turnNum = 0;
	FILE* f = fopen(ifname, "r");
	Board* board = (Board*)malloc(sizeof(Board));
	Record* record = NULL;
	board->initBoard();
	board->initPlayers(f);
	fclose(f);
	int numP = board->playerCount;
	while (numP > 1 && numTurns - turnNum > 0){
		b = false;
		endLoc = 0;
		upCount = 0;
		changeM = board->players[currentP]->money;
		sold = board->players[currentP]->numProps;
		dice = board->players[currentP]->pos;
		board->printBoard(true);
		for (int i = 0; i < board->playerCount; i ++){
			if (board->players[i]->money >= 0){
				std::cout<<"player "<<i<<" has "<<board->players[i]->money<<std::endl;
				std::cout<<"properties on spaces"<<std::endl;
				for (int j = 0; j < 32; j++){
					if (board->players[i]->property[j]){
						printf("%d ", j);
					}
				}
				printf("\n");
			}
		}
		std::cout<<"player "<<currentP<<"'s turn"<<std::endl;
		tempNum = 0;
		input = 0;
		std::cout<<"upgrade (Y = 1)?)\n"<<std::endl;
		std::cin>>input;
		while (input == 1){
			upCount++;
			std::cout<<"which street (input space number)?"<<std::endl;
			std::cin>>tempNum;
			board->upgrade(currentP, tempNum);
			board->printBoard(true);
			std::cout<<"upgrade again (Y == 1)?\n"<<std::endl;
			std::cin>>input;
		}

		board->move(currentP);
		board->printBoard(true);
		endLoc = board->players[currentP]->pos;
		dice < endLoc ? dice = endLoc - dice : dice = endLoc - dice + 31;
		switch(board->spaces[endLoc]->symbol){
		case 's':
			if (!(board->spaces[endLoc]->own)){
				std::cout<<"buy property?"<<std::endl;
				std::cin>>input;
				if (input == 1){
					board->buy(currentP, endLoc);
					bought = endLoc;
				}
				else {
					printf("chose not to buy\n");
					bought = -1;
				}
			}
			else {
				board->stay(currentP, endLoc);
			}
			break;
		case 'r':
			if (!(board->spaces[endLoc]->own)){
				std::cout<<"buy property?"<<std::endl;
				std::cin>>input;
				if (input == 1){
					board->buy(currentP, endLoc);
					bought = endLoc;
				}
				else {
					printf("chose not to buy\n");
					bought = -1;
				}
			}
			else {
				board->rail(currentP, endLoc);
			}
			break;
		case 'c':
			board->chance(currentP);
			break;
		case 'f': default:
			break;
		}
		b = board->isBankrupt(currentP);
		if (b){
			numP--;
		}
		board->printBoard(true);
		std::cout<<"end of turn "<<turnNum<<std::endl;
		sold = board->players[currentP]->numProps - sold;
		changeM = board->players[currentP]->money - changeM;
		addEntry(&record, turnNum, currentP, dice, upCount, endLoc, sold, bought, b, changeM);
		currentP = currentP + 1 % board->playerCount;
		while (board->players[currentP]->money < 0){
			currentP = currentP + 1 % board->playerCount;
		}
		std::cout<<"continue?"<<std::endl;
		std::cin>>input;
		if (input == 807){
			turnNum = numTurns-1;
		}
		turnNum++;
	}
	std::cout<<"History:"<<std::endl;
	printHistory(&record);
	FILE* of = fopen(ofname, "w");
	while (record != NULL){
		std::cout<<record->data->turn<<std::endl;
		fprintf(of, "Turn %d\n", record->data->turn);
		fprintf(of, "player number %d\n", record->data->player);
		fprintf(of, "player upgraded %d streets\n", record->data->upgrades);
		fprintf(of, "Dice roll was %d\n", record->data->dice);
		fprintf(of, "End location was space %d\n", record->data->endLoc);
		record->data->bought == -1 ? fprintf(of, "Player didn't buy property\n") : fprintf(of, "Player bought property %c\n", record->data->bought);
		fprintf(of, "Player sold %d properties\n", record->data->sold);
		fprintf(of, "Player total money changed by %d\n", record->data->changeMoney);
		fprintf(of, record->data->bankruptcy ? "Player went bankrupt\n" : "Player remains in the game\n");
		record = record->next;
	}
	fprintf(of, "End of Record\n");
	fclose(of);
	return ok;
}
