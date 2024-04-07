#include<stdio.h>

#define MAXSIZE   1000

int buf[MAXSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp>0) ? buf[--bufp]:getchar();
}

void ungetch(int c)
{
    if (bufp>= MAXSIZE)
    {
        printf("ungetch: error too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int main(void)
{
    int c;

    c = 'k';

    ungetch(c);

    while((c=getch())!=EOF)
       putchar(c);

}