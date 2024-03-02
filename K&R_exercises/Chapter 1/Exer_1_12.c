#include<stdio.h>

int main()
{
    int cinput, isnewword;
    isnewword = 0;
    while((cinput = getchar()) != EOF)
    {
        if((cinput == ' ') || (cinput == '\t'))
        {
            isnewword = 1;
        }
        if((isnewword == 1) && (cinput  != '\t') && (cinput != ' '))
        {
            printf("\n%c", cinput);
            isnewword = 0;
        }
        else
        {
           printf("%c", cinput); 
        }
    }
}