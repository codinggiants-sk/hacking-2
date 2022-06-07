/* 
* Program skompilujeme s pomocou gcc -g -o stack_overflow2 stack_overflow2.c 
* Opravime situaciu kde uzivatel moze nezadat ziaden argument. Chyba s 
* pretecenim zasobnika pri volani strcpy stale zostava.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void fn(char str[]) {
    char buf[16];
    strcpy(buf, str);
    printf("%s\n", buf);
    return;
}


int main(int argc, char * argv[]) {
    printf("Ukazka stack oveflow #2\n");
    if (argc<2) {
        perror("Program musi mat aspon jeden parameter");
        return(1);
    }
    fn(argv[1]);
    return(0);
}
