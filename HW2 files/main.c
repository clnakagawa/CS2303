/*
 ============================================================================
 Name        : SystemsHW2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
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
