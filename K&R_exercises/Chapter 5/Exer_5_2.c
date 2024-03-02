#include<stdio.h>
#include<ctype.h>
#define SIZE      1000
#define BUFSIZE   100
char buf[BUFSIZE];
int bufp=0;
int getfloat(float *pn);
int getch(void)
{
    return (bufp>0) ? buf[--bufp]: getchar();
}
void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
int main()
{
    int n,s;
    float array[SIZE];
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++); 

    for (; n > 0; n--)
        printf("%f\n", array[n]);

  
}
int getfloat(float *pn) {
    int c, sign;
    float power;

    while (isspace(c = getch()));

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); /* it's not a number */
        return -1; /* -1 will end the program directly */
    }

    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
        c = getch();
    
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if(c == '.')
        c= getch();

    for (power = 1.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');
        power *= 10.0;

    *pn *= sign / power;

    if (c != EOF)
        ungetch(c);

    return c;
}
