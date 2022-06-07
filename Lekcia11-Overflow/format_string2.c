/*
* Program skompilujeme s pomocou gcc -g -o format_string2 format_string2.c
* Hlavny problem tohoto programu je ten, ze uzivatel priamo kontroluje vstup
* fukncie printf. Ked je text iba obycajny text, vsetko je v poriadku a 
* program funguje ako ma. Kedze v tomto pripade kontrolujeme formatovaci
* retazec, vstup sa jednoducho interpretuje ako text.
*   ./format_string2 1 '%#x %#x %#x %n'
*     %#x %#x %#x %n
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
		printf("%s\n", argv[2]);
	}
}
