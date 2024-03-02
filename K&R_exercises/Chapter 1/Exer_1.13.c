#include<stdio.h>

#define MAXWORD    20
#define MAXLEN     25

void Horz_histogram(int c)
{
	if(c == '\n' || c == '\t' || c== '\0')
	{
		putchar('\n');
	}
	else
	{
		putchar('*');
	}
}

int main(void)
{
	int c;
	int word[MAXLEN];
	int nc, nw, i, j;
	nc=nw=0;
	
	for(i=0;i<MAXLEN;i++)
	    word[i] = 0;
	    
	while((c=getchar())!=EOF)
	{
		Horz_histogram(c);
		nc++;	
	    if(c == '\n' || c == '\t' || c== ' ')
	    {
		    word[nw] = nc-1;
		    ++nw;
		    nc=0;
	    }
	}
	
	for(i= MAXWORD-1;i>=1;--i)
	{
		for(j=0;j<=nw;j++)
		{
			if(i<=word[j])
			{
				putchar('*');
			}
			else
			{
				putchar(' ');
			}			
		}
		putchar('\n');
	}
}
