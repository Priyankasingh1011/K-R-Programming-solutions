/*This program verifies whether EOF is 0 or 1*/
#include<stdio.h>

int main()
{
    int c;
    while(c=getchar() !=EOF)
    {
        printf("%d\n", c);
    }
    printf("EOF is %d", EOF);
}

