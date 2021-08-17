/*
 * Record.h
 *
 *  Created on: Mar 17, 2021
 *      Author: cln
 */

#ifndef RECORD_H_
#define RECORD_H_
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <stdbool.h>

typedef struct {
	int player;
	int turn;
	int dice;
	int upgrades;
	int endLoc;
	int sold;
	int bought;
	bool bankruptcy;
	int changeMoney;
} RecordData;

class Record {
public:
	Record();
	virtual ~Record();
	Record* next;
	RecordData* data;
};

void addEntry(Record** start, int turn,
								int givenPlayer,
								int givenDice,
								int givenUp,
								int givenLoc,
								int givenSold,
								int givenBought,
								bool bankruptcy,
								int givenMoney);
void printHistory(Record** start);

#endif /* RECORD_H_ */
