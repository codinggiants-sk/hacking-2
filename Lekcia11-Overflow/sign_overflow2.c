/*
* Program skompilujeme s pomocou gcc -g -o sign_overflow2 sign_overflow2.c
* Ak program spustime ako ./sign_overflow1 5 ahoj tak vypise vystup podla
* ocakavania 5x ahoj.
*  sign_overflow1 vypise ahoj 5 krat
*  ahoj (0)
*  ahoj (1)
*  ahoj (2)
*  ahoj (3)
*  ahoj (4)
* Ak vsak program spustime s parametrom ./sign_overflow1 -1 ahoj
*  tak program po spravnosti nevypise vystup ani raz, kedze spravne
*  narabame so znamienkovou premennou pocet a i. 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// vypise argument2 podla poctu v arg1
int main(int argc, char * argv[]) {
	if (argc<=2) {
		perror("Aspon 2 argumenty");
		exit(1);
	}
    printf("sign_overflow2 vypise %s %s krat\n", argv[2], argv[1]);
	int pocet = atoi(argv[1]);
	for (int i=0; i<pocet; i++){
        printf("%s (%d)\n", argv[2], i);
	}
}
