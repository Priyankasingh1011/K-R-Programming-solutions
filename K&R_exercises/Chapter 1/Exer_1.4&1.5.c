/*This is a program to convert fahreheit tempertaure to celsius*/
#include<stdio.h>
/* MACROS definition*/
#define  LOWER_D     0
#define  STEP_D      20
#define  UPPER_D     300

/*function prototype*/
void Convert_Fahrenheit_to_celsius(void);

/*main function*/
int main()
{
  
   printf("print fahrenheit-celsius table\n\t");
   printf("for fahr = 0, 20, ...,300; floating point version\n\n");
   Convert_Fahrenheit_to_celsius();
   
}

void Convert_Fahrenheit_to_celsius(void)
{
    float f_fahr, f_celsius;
    for(f_fahr = UPPER_D; f_fahr>=LOWER_D; f_fahr-=STEP_D)
    {
        f_celsius = (5.0/9.0)*(f_fahr-32.0);
        printf("%3.0f %6.1f\n", f_fahr, f_celsius);      
    }
}