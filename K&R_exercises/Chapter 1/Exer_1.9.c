#include<stdio.h>
#define  NONBLANK      '-'

int main()
{
    int cinput, lastinput;
    lastinput = NONBLANK;
    while((cinput = getchar())!= EOF)
    {
        if(cinput == ' ')
        {
            if(lastinput != ' ')
            {
                putchar(cinput);
            }
        }
        else
        {
            putchar(cinput);
        }
        lastinput = cinput;
    }
}