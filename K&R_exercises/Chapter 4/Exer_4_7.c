#include <stdio.h>
#include <string.h>

#define MAXBUF   100
#define MAXLINE  100

int bufp = 0;
int buf[MAXBUF];

int getch(void)
{
     return bufp > 0? buf[--bufp]:getchar();
}

void ungetch(int c)
{
    if(bufp >= MAXBUF)
       printf("ungetch: too many charcater\n");

    else
       buf[bufp++] = c;
}

void ungets(char s[])
{
    int i;
    i = strlen(s);

    while (i>0)
    {
        ungetch(s[--i]);
    }
}

void mgetline(char s[], int lim)
{
    int i, c;
    for(i=0;i<lim-1 && (c=getch())!= EOF && c!='\n'; i++)
    {
        s[i] = c;
    }

    if(s[i] == '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';
}

int main(void)
{
    char line[MAXLINE];
    int c;

    mgetline(line, MAXLINE);

    ungets(line);

    while((c= getch()) != EOF)
       putchar(c);
}

