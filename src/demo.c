/*
 ============================================================================
 Name        : demo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include "tests.h"
#include "agent.h"
#include "xMotor.h"
#include "yMotor.h"
#include "zMotor.h"

// names: Carter Nakagawa

int main(int argc, char* argv[]) {
	puts("Let's get started with HW1"); /* prints !!!Hello World!!! */
	if(tests())
	{
		if(production(argc, argv))
		{
			puts("Hurray, it worked");

		}
		else
		{
			puts("Sorry");
		}
	}
	return EXIT_SUCCESS;
}
