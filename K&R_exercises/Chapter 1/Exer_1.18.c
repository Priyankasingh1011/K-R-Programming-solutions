#include<stdio.h>

#define MAXLEN    1000

int my_getline(char line[], int limit)
{
	int i, j, c;
	for(i=0; i< limit-1 && (c=getchar())!=EOF && c!= '\n' ; i++)
	{
		line[i] = c;
	}
	
	if(c == '\n')
	{
		line[i++] = c;
	}
	
	line[i] = '\0';
	return i;
}

int remv_blanktab(char sinput[])
{
	int i;
	for(i=0; sinput[i]!='\n'; ++i);
	--i;
	printf("%d\n", i);
	
	for(i > 0; ((sinput[i] == '\t' ) || (sinput[i] == ' ')); --i)
	{
			printf("%d\n", i);
	}
	

	
	if(i>=0)
	{
		++i;
		sinput[i] = '\n';
		++i;
		sinput[i] = '\0';
	}
	printf("%s\n", sinput);
	return i;
	
}


int main(void)
{
	char sinput[MAXLEN];
	int len = 0;
	while(my_getline(sinput, MAXLEN) > 0)
	{
		if(len = remove_trail(sinput)>0)
	    {
	        printf("%s\n", sinput);	
	    }
	}	
}
