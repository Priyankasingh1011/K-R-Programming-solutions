/*Program to convert hexadecimal to integers*/

#include<stdio.h>
#include<string.h>
/* prototype of the function*/
int htoi(const char *s);

/*main function*/
int main()
{
   char *string = "0x0F";
   printf("the converted integer value for %s is %d\n", string, htoi(string));
}

int htoi(const char *s)
{
    int i;
    static int Result = 0;  
    if ((s[0] == '0') && ((s[1] == 'x') ||(s[1] == 'X')))
    {
        i=2;
    }
    for(;i<strlen(s);i++)
    {
        Result = Result * 16;
        if((s[i] >= '0') && (s[i] <= '9'))
        {
            Result = Result + s[i] - '0';
        }
        else if((s[i] >= 'a') && (s[i] <= 'f'))
        {
            Result = Result +  s[i] - 'a' + 10;
        }
        else if((s[i] >= 'A') && (s[i] <= 'F'))
        {
            Result = Result +  s[i] - 'A' + 10;
        }
    }   
    return Result;
}
