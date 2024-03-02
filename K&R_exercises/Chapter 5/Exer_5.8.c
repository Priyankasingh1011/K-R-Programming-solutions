#include<stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}	
};

int day_of_year(int year, int month, int day)
{
	int index, isleap;
	
	isleap = year%4==0 && year%100 !=0 || year%400 == 0;
	
	if(month < 1 || month > 12 || year < 1 || day < 1 || day > *(*(daytab + isleap) + month))
	{
		printf("wrong input\n");
		return -1;
	}
	for(index=1;index<month;index++)
	{
		day += *(*(daytab+isleap)+ index);
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int index, isleap;
	
	isleap = year%4==0 && year%100 !=0 || year%400 == 0;
	
	if(year < 1 || yearday < 1 || yearday > (isleap ? 366:365))
	{
		printf("wrong input\n");
		*pmonth = -1;
	    *pday = -1;
	    return;
	}
	
	for(index=0;yearday >daytab[isleap][index];index++)
	{
		yearday -= daytab[isleap][index];
	}
	*pmonth = index;
	*pday = yearday;
}

int main()
{
	int year, yearday, month, day;
	
	yearday = day_of_year(2024, 2, 29);
	printf("%d\n", yearday);
	
	month_day(1999, 365, &month, &day);
	printf("Month: %d, Day: %d\n", month, day);
}
