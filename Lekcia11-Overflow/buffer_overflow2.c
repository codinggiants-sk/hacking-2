/* 
* Program skompilujeme s pomocou gcc -g -o buffer_overflow1 buffer_overflow2.c 
* Ak program spustime ako ./buffer_overflow1 "student" tak vypise vystup podla
* ocakavania:
*  Ukazka buffer oveflow #1
*  adresa buf1: 0xffffdacf1dc0
*  adresa buf2: 0xffffdacf1dc8
*  Hello there: student
* Program nespadne nech dame do vstupu cokolvek.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(char str[]) {
    char buf1[8];
    char buf2[13] = "Hello there:";
    // vypiseme si koli pre nasu informaciu adresy buf1 a buf2
    printf("adresa buf1: %p\nadresa buf2: %p\n", &buf1, &buf2);
    strncpy(buf1, str, sizeof(buf1)-1);
    printf("%s %s\n", buf2, buf1);
    return;
}


int main(int argc, char * argv[]) {
    printf("Ukazka buffer oveflow #2\n");
    if (argc<2) {
        perror("Program musi mat aspon jeden parameter");
        return(1);
    }
    fn(argv[1]);
    return(0);
}
