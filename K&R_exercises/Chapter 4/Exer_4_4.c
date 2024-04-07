#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP          100
#define BUFSIZE        100
#define NUMBER         '0'
#define MAXVAL         100

int sp=0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

void push(double f)
{
    if(sp<MAXVAL)
    {
       val[sp++] = f;
       printf("pushed\n");
    }
    else
       printf("error:stcak full\n");
}

double pop(void)
{
    if(sp>0)
       return val[--sp];
    else{
        printf("error stack empty\n");
        return 0.0;
    }
}

int getch(void)
{
    return (bufp>0)?buf[--bufp]:getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFSIZE)
       printf("ungetch: too many character\n");
    else
       buf[bufp++] = c;
}

int getop(char s[])
{
    int i, c;
    while((s[0]=c=getch()) == ' '|| c=='\t')
    ;
    s[1]='\0';

    if(!isdigit(c) && c!='.'&& c!='-')
       return c;

    i=0;

    if(c == '-')
    {
        if(isdigit(c=getch()) || c =='.')
        {
            s[++i] = c;
        }
        else
        {
            if(c!=EOF)
                ungetch(c);
            return '-';
        }
    }
    if(isdigit(c))
    {
        while(isdigit(s[++i]=c=getch()));
    }

    if (c=='.') 
    {
        while(isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if(c!=EOF)
       ungetch(c);
    return NUMBER;
}

void clearcommand(void)
{
    sp=0;
    printf("stack cleared\n");
}

int main(void)
{
    int type;
    double op2, op1;
    char s[MAXOP];

    while((type=getop(s))!=EOF)
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
                push(pop() - pop());
                break;
            case '/':
                op2 = pop();
                if(op2!=0.0)
                {
                    push(pop()/op2);
                }
                else 
                    printf("divide by zero error\n");
                break;
            case 'c':
                clearcommand();
                break;
            case 's':
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case 'd':
                op1 = pop();
                push(op1);
                push(op1);
                break;   
            case '?':
                op1 = pop();
                printf("\t%.8g\n", op1);   
                push (op1);  
                break;      
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command\n");
                break;
        }
    }
}
