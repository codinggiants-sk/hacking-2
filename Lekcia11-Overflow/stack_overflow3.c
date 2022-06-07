/* 
* Program skompilujeme s pomocou gcc -g -o stack_overflow3 stack_overflow3.c 
* Namiesto nebezpecneho strcpy() pouzijeme bezpecnejsie strncpy(). Posledny
* argument definuje maximalny pocet znakov v cielovom bufferi be zarataneho 
* ukoncovacieho znaku \0. Do volania jednoducho dame velkost nasho buffera -1.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(char str[]) {
    char buf[16];
    strncpy(buf, str, sizeof(buf)-1);
    printf("%s\n", buf);
    return;
}


int main(int argc, char * argv[]) {
    printf("Ukazka stack oveflow #3\n");
    if (argc<2) {
        perror("Program musi mat aspon jeden parameter");
        return(1);
    }
    fn(argv[1]);
    return(0);
}
