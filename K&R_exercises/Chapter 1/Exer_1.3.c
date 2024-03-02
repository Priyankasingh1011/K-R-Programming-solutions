#include<stdio.h>
int main()
{
   float fahr, upper, lower, celsius,step;
   lower = 0;
   step = 20;
   upper = 300;

   fahr = lower;
   printf("print fahrenheit-celsius table\n\t");
   printf("for fahr = 0, 20, ...,300; floating point version\n\n");
   while(fahr<=upper)
   {
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr+=step;
   }
}
