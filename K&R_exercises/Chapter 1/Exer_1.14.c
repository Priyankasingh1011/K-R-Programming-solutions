#include<stdio.h>

#define TOTAL_CHARS    128

int main(void)
{
	char arr[TOTAL_CHARS];
	int i, j,c;
	for(i = 0; i< TOTAL_CHARS;i++)
	{
		arr[i] = 0;
	}
	
	while((c=getchar())!= EOF)
	{
		arr[c] = arr[c]+1;
	}
	
	for (i = 0; i < TOTAL_CHARS; ++i) {
        putchar(i);

        for (j = 0; j < arr[i]; ++j)
            putchar('*');

        putchar('\n');
    }
}
