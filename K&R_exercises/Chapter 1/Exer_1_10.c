#include <stdio.h>

int main(void) {
    int cinput;

    while ((cinput = getchar()) != EOF) {
        if (cinput == '\t') {
            putchar('\\');
            putchar('t');
    
        }

        if (cinput == '\b') {
            putchar('\\');
            putchar('b');
           
        }

        if (cinput == '\\') {
            putchar('\\');
            putchar('\\');
        }

        if (cinput != '\t' && cinput != '\b' && cinput != '\\')
            putchar(cinput);
            
    }
    return 0;
}