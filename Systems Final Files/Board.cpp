/*
 * Board.cpp
 *
 *  Created on: Mar 16, 2021
 *      Author: cln
 */

#include "Board.h"

Board::Board() { // @suppress("Class members should be properly initialized")
	// TODO Auto-generated constructor stub

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

void Board::initBoard(){
	fflush(stdin);
	for (int i = 0; i < 32; i++){
		spaces[i] = (Space*)malloc(sizeof(Space));
		spaces[i]->number = i;
		if (i % 8 == 0){
			spaces[i]->own = false;
			spaces[i]->symbol = 'f';
		}
		else if ((i-2) % 8 == 0){
			spaces[i]->own = false;
			spaces[i]->symbol = 'c';
		}
		else if ((i-5) % 8 == 0){
			spaces[i]->symbol = 'r';
			spaces[i]->own = false;
		}
		else {
			spaces[i]->houses = 0;
			spaces[i]->own = false;
			spaces[i]->symbol = 's';
			spaces[i]->val = 20;
		}
	}
}

void Board::printBoard(bool showPlayers){
	fflush(stdin);
	if (showPlayers){
		printf("______________________________________________________\n");
		printf("|");
		for (int i = 0; i < 9; i++){
			printf("%c", spaces[16+i]->symbol);
			spaces[16+i]->own ? printf("%d", spaces[16+i]->player) : printf(" ");
			printf("  ");
			spaces[16+i]->symbol == 's' ? printf("%d", spaces[16+i]->houses) : printf(" ");
			printf("|");
		}
		printf("\n");
		printf("|");
		for (int i = 0; i < 9; i++){
			printf(" ");
			for (int j = 0; j < 4-playerCount; j++){
				printf(" ");
			}
			for (int j = 0; j < playerCount; j++){
				spaces[16+i]->occupied[j] ? printf("%d", j) : printf(" ");
			}
			printf("|");
		}
		printf("\n");
		for (int i = 0; i < 7; i++){
			printf("______________________________________________________\n");
			printf("|%c", spaces[15-i]->symbol);
			spaces[15-i]->own ? printf("%d", spaces[15-i]->player) : printf(" ");
			printf("  ");
			spaces[15-i]->symbol == 's' ? printf("%d", spaces[15-i]->houses) : printf(" ");
			printf("|                                         |");
			printf("%c", spaces[25+i]->symbol);
			spaces[25+i]->own ? printf("%d", spaces[25+i]->player) : printf(" ");
			printf("  ");
			spaces[25+i]->symbol == 's' ? printf("%d", spaces[15-i]->houses) : printf(" ");
			printf("|\n| ");
			for (int j = 0; j < 4-playerCount; j++){
				printf(" ");
			}
			for (int j = 0; j < playerCount; j++){
				spaces[15-i]->occupied[j] ? printf("%d", i) : printf(" ");
			}
			printf("|                                         | ");
			for (int j = 0; j < 4-playerCount; j++){
				printf(" ");
			}
			for (int j = 0; j < playerCount; j++){
				spaces[25+i]->occupied[j] ? printf("%d", i) : printf(" ");
			}
			printf("|\n");
		}
		printf("______________________________________________________\n");
		printf("|");
		for (int i = 8; i > -1; i--){
			printf("%c", spaces[i]->symbol);
			spaces[i]->own ? printf("%d", spaces[i]->player) : printf(" ");
			printf("  ");
			spaces[i]->symbol == 's' ? printf("%d", spaces[i]->houses) : printf(" ");
			printf("|");
		}
		printf("\n");
		printf("|");
		for (int i = 8; i > -1; i--){
			printf(" ");
			for (int j = 0; j < 4-playerCount; j++){
				printf(" ");
			}
			for (int j = 0; j < playerCount; j++){
				spaces[i]->occupied[j] ? printf("%d", j) : printf(" ");
			}
			printf("|");
		}
		printf("\n");
		printf("______________________________________________________\n");
	}
	else {
		printf("______________________________________________________\n");
		printf("|");
		for (int i = 0; i < 9; i++){
			printf("%c    |", (spaces[16+i]->symbol));
		}
		printf("\n");
		printf("|");
		for (int i = 0; i < 9; i++){
			printf("     |");
		}
		printf("\n");
		for (int i = 0; i < 7; i++){
			printf("______________________________________________________\n");
			printf("|%c    |                                         |%c    |\n", spaces[15-i]->symbol, spaces[25+i]->symbol);
			printf("|     |                                         |     |\n");
		}
		printf("______________________________________________________\n");
		printf("|");
		for (int i = 8; i > -1; i--){
			printf("%c    |", spaces[i]->symbol);
		}
		printf("\n");
		printf("|");
		for (int i = 0; i < 9; i++){
			printf("     |");
		}
		printf("\n");
		printf("______________________________________________________\n");
	}
}

void Board::initPlayers(FILE* file){
	fflush(stdin);
	int numP = 0;
	int propNum = 0;
	int tempNum = 0;
	fscanf(file, "%d", &numP);
	playerCount = numP;
	for (int i = 0; i < numP; i++){
		players[i] = (Player*)malloc(sizeof(Player));
		players[i]->rNum = 0;
		fscanf(file, "%d", &(players[i]->pos));
		spaces[players[i]->pos]->occupied[i] = true;
		fscanf(file, "%d", &(players[i]->money));
		fscanf(file, "%d", &propNum);
		players[i]->numProps = propNum;
		for (int j = 0; j < propNum; j++){
			fscanf(file, "%d", &tempNum);
			players[i]->property[tempNum] = true;
			fscanf(file, "%d", &(spaces[tempNum]->houses));
			spaces[tempNum]->val = 10+(spaces[tempNum]->houses)*10;
			spaces[tempNum]->own = true;
			spaces[tempNum]->player = i;
			if ((tempNum-5) % 8 == 0){
				players[i]->rNum++;
			}
		}
	}
}

void Board::chance(int pNum){
	fflush(stdin);
	srand(time(NULL));
	int sign = (rand() % 2 == 1) ? -1 : 1;
	std::cout<<"first die: "<<sign<<std::endl;
	int amt = (rand() % 6 + 1);
	std::cout<<"second die: "<<amt<<std::endl;
	players[pNum]->money += sign*amt*10;
}

void Board::stay(int pNum, int sNum){
	fflush(stdin);
	if (!spaces[sNum]->own){
		std::cout<<"no one owns this street, no rent"<<std::endl;
	}
	else if (spaces[sNum]->player == pNum){
		std::cout<<"player owns this street, no rent"<<std::endl;
	}
	else {
		players[pNum]->money -= spaces[sNum]->val;
		players[spaces[sNum]->player]->money += spaces[sNum]->val;
		std::cout<<"player "<<pNum<<" paid "<<spaces[sNum]->val<<" to player "<<spaces[sNum]->player<<std::endl;
	}
}

void Board::rail(int pNum, int sNum){
	fflush(stdin);
	if (!spaces[sNum]->own){
		std::cout<<"no one owns this railroad, no rent"<<std::endl;
	}
	else if (spaces[sNum]->player == pNum){
		std::cout<<"player owns this railroad, no rent"<<std::endl;
	}
	else {
		int rails = players[spaces[sNum]->player]->rNum;
		players[pNum]->money -= 25*rails;
		players[spaces[sNum]->player]->money += 25*rails;
		std::cout<<"player "<<pNum<<" paid "<<25*rails<<" to player "<<spaces[sNum]->player<<std::endl;
	}
}

void Board::move(int pNum){
	fflush(stdin);
	srand(time(NULL));
	int die = 1 + (rand() % 8);
	std::cout<<"die roll: "<<die<<std::endl;
	spaces[players[pNum]->pos]->occupied[pNum] = false;
	players[pNum]->pos += die;
	if (players[pNum]->pos > 31){
		std::cout<<"passed go, gained 200 dollars"<<std::endl;
		players[pNum]->pos = players[pNum]->pos % 31;
		players[pNum]->money += 200;
	}
	spaces[players[pNum]->pos]->occupied[pNum] = true;
	std::cout<<"player "<<pNum<<" moved to space "<<players[pNum]->pos<<std::endl;
}

void Board::upgrade(int pNum, int sNum){
	fflush(stdin);
	if (spaces[sNum]->own == false || spaces[sNum]->player != pNum){
		std::cout<<"player does not own house";
	}
	else if (players[pNum]->money >= 30){
		if (spaces[sNum]->houses == 4){
			std::cout<<"already have 4 houses"<<std::endl;
		}
		else {
			std::cout<<"player "<<pNum<<" paid 30 to add a house to street "<<sNum<<std::endl;
			players[pNum]->money -= 30;
			++(spaces[sNum]->houses) == 4 ? spaces[sNum]->val += 20 : spaces[sNum]->val += 10;
			std::cout<<"Street on space "<<sNum<<" now has "<<spaces[sNum]->houses<<" houses";
			std::cout<<"Property rent is now "<<spaces[sNum]->val<<std::endl;
		}
	}
	else {
		std::cout<<"not enough money"<<std::endl;
	}
}

void Board::buy(int pNum, int sNum){
	fflush(stdin);
	int value;
	if (spaces[sNum]->symbol == 'r'){
		value = 100;
	}
	else if (spaces[sNum]->number >= 24){
		value = 70;
	}
	else if (spaces[sNum]->number >= 16){
		value = 50;
	}
	else if (spaces[sNum]->number >= 8){
		value = 40;
	}
	else {
		value = 20;
	}
	if (spaces[sNum]->own){
		std::cout<<"property not for sale\n";
	}
	else if (players[pNum]->money >= value){
		players[pNum]->money -= value;
		players[pNum]->numProps++;
		players[pNum]->property[sNum] = true;
		if ((sNum-5)%8){
			(players[pNum]->rNum)++;
		}
		spaces[sNum]->own = true;
		spaces[sNum]->player = pNum;
		std::cout<<"player "<<pNum<<" has bought property on space "<<sNum<<std::endl;
	}
	else {
		std::cout<<"cannot afford property"<<std::endl;
	}
}

void Board::sell(int pNum, int sNum){
	fflush(stdin);
	int value;
	if (spaces[sNum]->symbol == 'r'){
		value = 50;
	}
	else if (spaces[sNum]->number >= 24){
		value = 35;
	}
	else if (spaces[sNum]->number >= 16){
		value = 25;
	}
	else if (spaces[sNum]->number >= 8){
		value = 20;
	}
	else {
		value = 10;
	}
	if (players[pNum]->property[sNum]){
		players[pNum]->money += value;
		players[pNum]->numProps--;
		players[pNum]->property[sNum] = false;
		if ((sNum-5)%8 == 0){
			players[pNum]->rNum--;
		}
		spaces[sNum]->own = false;
		spaces[sNum]->player = -1;
		spaces[sNum]->houses = 0;
		std::cout<<"player "<<pNum<<" has sold property on space "<<sNum<<std::endl;
	}
	else {
		std::cout<<"player does not own the property, can't sell"<<std::endl;
	}
}

bool Board::isBankrupt(int pNum){
	fflush(stdin);
	bool b = false;
	int tempS;
	if (players[pNum]->money < 0) {
		std::cout<<"player "<<pNum<<" is bankrupt"<<std::endl;
		while (players[pNum]->numProps > 0 && players[pNum]->money < 0){
			std::cout<<"choose property to sell (enter space number)"<<std::endl;
			printf("can sell properties on ");
			for (int i = 0; i < 32; i++){
				if (players[pNum]->property[i]){
					std::cout<<i<<" "<<std::flush;
				}
			}
			printf("\n");
			std::cin>>tempS;
			sell(pNum, tempS);
			printBoard(true);
		}
		if (players[pNum]->money < 0){
			b = true;
		}
	}
	if (b){
		spaces[players[pNum]->pos]->occupied[pNum] = false;
		for (int i = 0; i < 32; i++){
			if (players[pNum]->property[i]){
				spaces[i]->own = false;
				spaces[i]->houses = 0;
				spaces[i]->player = -1;
			}
		}
		printBoard(true);
		std::cout<<"player "<<pNum<<" has lost"<<std::endl;
	}
	else {
		std::cout<<"player "<<pNum<<" is still in the game"<<std::endl;
	}
	return b;
}

