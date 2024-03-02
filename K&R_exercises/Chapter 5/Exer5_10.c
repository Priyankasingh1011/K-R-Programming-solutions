#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXSTACK    100
#define NUMBER       'n'

static double stack[MAXSTACK];
static double *pstack = stack;

void push(double value)
{
    if(pstack-stack > MAXSTACK)
    {
        printf("Stack out of space\n");
    }
    else{
        *(pstack++) = value;
    }
}

double pop(void)
{
    if(pstack-stack > 0)
    {
        return *--pstack;
    }
    else{
        printf("stack is empty\n");
    }
}


static char isNumber(const char *s)
{
    if(*s == '-' || *s == '+')
    {
        s++;
    }
    if(*s == '\0')
    {
        return 0;
    }
    while(isdigit(*s))
    {
        s++;
    }
    if(*s == '.')
    {
        s++;
        while(isdigit(*s)) 
        {
            s++;
        }
    }

    return *s == '\0';
}

char getop(const char *op)
{
    return isNumber(op) ? NUMBER : *op;
}
 int main(int argc, char *argv[])
 {
    char c;
    double tempOp;

    if(argc<=1)
    {
        printf("invalid expression\n");
        return -1;
    }

    while(--argc)
    {
        c = getop(*++argv);
        switch(c)
        {
            case NUMBER:
                push(atof(*argv));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                push(pop() - pop());
                break;

            case '*':
                push(pop() * pop());
                break;
            
            case '/':
                tempOp = pop();

                if(!tempOp)
                {
                    printf("division by zero error");
                }
                else
                {
                    push(pop()/pop());
                }
                break;

            default:
                printf("unknown expression %s\n", *argv);
                break;
        }
    }
    printf("the output of the expression is: %g\n", pop());
}