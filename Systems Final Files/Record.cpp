/*
 * Record.cpp
 *
 *  Created on: Mar 17, 2021
 *      Author: cln
 */

#include "Record.h"

Record::Record() { // @suppress("Class members should be properly initialized")

}

Record::~Record() {
	// TODO Auto-generated destructor stub
}

void addEntry(Record** start, int givenPlayer,
								int givenTurn,
								int givenDice,
								int givenUp,
								int givenLoc,
								int givenSold,
								int givenBought,
								bool givenBankruptcy,
								int givenMoney){
	fflush(stdin);

	RecordData* newData = (RecordData*)malloc(sizeof(RecordData));
	newData->player = givenPlayer;
	newData->turn = givenTurn;
	newData->dice = givenDice;
	newData->upgrades = givenUp;
	newData->endLoc = givenLoc;
	newData->sold = givenSold;
	newData->bought = givenBought;
	newData->bankruptcy = givenBankruptcy;
	newData->changeMoney = givenMoney;
	Record* last = *start;
	Record* newRec = new Record();
	newRec->data = newData;
	newRec->next = NULL;
	int ind = 0;
	if (*start == NULL){
		*start = newRec;
	}
	else {
		while (last->next != NULL){
			ind++;
			last = last->next;
		}
		last->next = newRec;
	}
}

void printHistory(Record** start){
	Record* current = *start;
	while (current != NULL){
		printf("Turn %d\n", current->data->turn);
		printf("player number %d\n", current->data->player);
		printf("player upgraded %d streets\n", current->data->upgrades);
		printf("Dice roll was %d\n", current->data->dice);
		printf("End location was space %d\n", current->data->endLoc);
		current->data->bought == -1 ? printf("Player didn't buy property\n") : printf("Player bought property %c\n", current->data->bought);
		printf("Player sold %d properties\n", current->data->sold);
		printf("Player total money changed by %d\n", current->data->changeMoney);
		printf(current->data->bankruptcy ? "Player went bankrupt\n" : "Player remains in the game\n");
		current = current->next;
	}
	printf("End of Record\n");
}

