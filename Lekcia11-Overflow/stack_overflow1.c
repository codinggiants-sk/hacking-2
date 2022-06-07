/* 
* Program skompilujeme s pomocou gcc -g -o stack_overflow1 stack_overflow1.c 
* Program obsahuje dva problemy
* a) v pripade, ze nezadame prvy argument 
*   `./stack_overflow`
*   Program spadne so segmentation fault. Je to preto, ze argv[1] ma hodnotu NULL
*   a pri pristupe na 0x0 (NULL) strcpy vyvola Segmentation Fault.
* 
* b) v pripade, ze ako prvy argument dame retazec vacsi ako 20 znakov
*   `./stack_overflow1 123456789012345678901`
*   Program spadne s hlaskou:
*   123456789012345678901
*   *** stack smashing detected ***: terminated
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
    printf("Ukazka stack oveflow #1\n");
    fn(argv[1]);
    return(0);
}
