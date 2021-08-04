/*
 ============================================================================
 Name        : HW3.c
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
		puts("Tests passed.");
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
