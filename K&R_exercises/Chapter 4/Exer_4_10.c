#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXOP     100
#define NUMBER    '0'
#define MAXVAL    100
#define MAXLINE   100

int sp = 0;
int indx =0;
double val[MAXVAL];
char line[MAXLINE];

void push(double f)
{
    if(sp < MAXVAL)
    {
        val[sp++] = f;
    }
        
    else
        printf("error: stack full\n");
}

double pop(void)
{
    if(sp > 0)
       return val[--sp];

    else
       printf("error: stack empty\n");
}
int mgetline(char s[], int lim)
{
    int i, c;
    for(i=0;i<lim-1 && (c= getchar())!=EOF && c!='\n';i++)
    {
        s[i] = c;
    }

    if(c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';

    return i;
}

int getop(char s[])
{
    int c,i;
    if(line[indx] == '\0')
    {
        if(mgetline(line, MAXLINE) == 0)
            return EOF;

        else
            indx = 0;
    }

    while((s[0] = c= line[indx++]) == ' ' || c == '\t');

    s[1] = '\0';

    if(!isdigit(c) && c!='.')
        return c;

    i=0;

    if(isdigit(c))
        while(isdigit(s[++i] = c= line[indx++]));

    if(c=='.')
        while(isdigit(s[++i] = c = line[indx++]));

    s[i] = '\0';

    indx--;

    return NUMBER;
}

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while((type = getop(s))!=EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            
            case '+':
               push(pop() + pop());
               break;

            case '*':
               push(pop() * pop());
               break;

            case '-':
               op2 = pop();
               push(pop() - op2);
               break;

            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                break;

            case '\n':
                printf("\t%.9g\n", pop());
                break;

            default:
               printf("error: Unknown command\n");
               break;
        }
    }
}

