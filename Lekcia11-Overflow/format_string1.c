/*
* Program skompilujeme s pomocou gcc -g -o format_string1 format_string1.c
* Hlavny problem tohoto programu je ten, ze uzivatel priamo kontroluje vstup
* fukncie printf. Ked je text iba obycajny text, vsetko je v poriadku a 
* program funguje ako ma.
* Problem nastane ak ako druhy parameter dame formatovaci retazec. Kedze
* tento moze obsahovat instrukcie na vypisanie obsahu pamate alebo dokonca
* jej zmenu. 
* V pripade vypisanie obsahu pamate mozeme pouzit retazec %#x niekolko krat
* za sebou. Vypisuje sa nam obsah stacku, ktory moze napr. obsahovat citlive
* data:
*   ./format_string1 1 '%#x %#x %#x %#x'
*   0 0xa 0xaf5df8f8 0x1
* S pomocou argumentu %n mozeme zapisovat do pamate co sposobi v nasom pripade
* crash programu. Predstavte si takyto kod v spracovani poziadavie web servera.
*   ./format_string1 1 '%n'
*   Segmentation fault (core dumped)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// vypise arg2 podla poctu v arg1
int main(int argc, char * argv[]) {
	if (argc<=2) {
		perror("Aspon 2 argumenty");
		exit(1);
	}
	int pocet = atoi(argv[1]);
	for (int i=0; i<pocet; i++) {
		printf(argv[2]);
		printf("\n");
	}
}
