/*
 * Ship.h
 *
 *  Created on: Mar 13, 2021
 *      Author: cln
 */

#ifndef SHIP_H_
#define SHIP_H_

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

class Ship {
public:
	Ship();
	virtual ~Ship();
	char getSymbol();
	short getLength();
	const char* getName();
	void setSymbol(char sym);
	void setLength(short l);
	void setName(const char* n);
private:
	char symbol;
	short length;
	const char* name;
};

#endif /* SHIP_H_ */
