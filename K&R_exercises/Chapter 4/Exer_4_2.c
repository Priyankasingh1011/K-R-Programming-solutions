#include <ctype.h>
#include <stdio.h> 
#define MAXLINE   100

int power(int base, int expo)
{
    int power = 1;
    while(expo-- > 0)
    {
        power*=base;
    }
    return power;
}

double atof(char s[])
{
    double value, pow, results;
    int i, sign, esign,expo;

    for(i=0;isspace(s[i]);i++);

    sign = (s[i] == '-') ? -1: 1;

    if(s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for(value = 0.0; isdigit(s[i]);i++)
    {
        value = 10.0*value + (s[i] - '0');
    }
    if(s[i] == '.')
    {
        i++;
    }

    for(pow = 1.0;isdigit(s[i]);i++)
    {
        value = 10.0*value + (s[i] - '0');
        pow*=10;
    }

    if(s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }

    if(s[i] == '-' || s[i] == '+')
    {
        esign = s[i];
        i++;
    }

    for(expo = 0.0; isdigit(s[i]);i++)
    {
        expo = 10.0*expo + (s[i] - '0');
    }

    if(esign == '-')
    {
        results = sign*(value/pow) / power(10, expo); 
    }
    else
    {
        results = sign*(value/pow) * power(10, expo); 
    }

    return results;
}
int my_getline(char s[], int lim)
{
    int i, c;
    for(i=0;i< lim-1 && (c=getchar())!=EOF && c!='\n';i++)
    {
        s[i] = c;
    }
    if(s[i] =='\n')
    {
        s[i++] = c;
    }

    s[i]= '\0';
    return i;
}



int main()
{
    char line[MAXLINE];

    my_getline(line, MAXLINE);

    printf("\t%g\n", atof(line));

}