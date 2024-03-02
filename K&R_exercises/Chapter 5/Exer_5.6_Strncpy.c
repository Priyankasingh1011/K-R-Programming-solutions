#include<stdio.h>

#define MAXINPUT    1000

void my_strncpy(char *s, char *t, int n) {
        
		while (n!=0) {
		*s++ = *t++;
        n--;
    }
}

void my_strcpy(char *s, char *t) {
	   
	while ((*s = *t) != '\0') 
	{
		s++;
		t++;
    }
}


int my_getline(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

int main()
{
	char sinput[MAXINPUT], dinput[MAXINPUT];
	
	putchar('d');
	putchar(':');
	my_getline(dinput, MAXINPUT);
	
	my_strcpy(dinput, sinput);
	printf("%s", dinput);
	my_strncpy(sinput, dinput, 3);
	printf("%s", sinput);
}
