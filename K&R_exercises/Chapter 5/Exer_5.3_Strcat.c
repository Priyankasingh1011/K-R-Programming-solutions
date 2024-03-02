#include<stdio.h>

#define MAXINPUT    1000

void my_strcat(char *s, char *t) {
    while (*s != '\0')
        s++;
    s--;             /* goes back to \0 char */
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void my_strncat(char *s, char *t, int n) {
    while (*s != '\0')
        s++;
    s--;             /* goes back to \0 char */
    while (n!=0) {
        *s++ = *t++;
         n--;
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
	putchar('s');
	putchar(':');
	my_getline(sinput, MAXINPUT);
	
	putchar('d');
	putchar(':');
	my_getline(dinput, MAXINPUT);
	
	my_strcat(sinput, dinput);
	printf("%s\n", sinput);
	my_strncat(sinput, dinput, 3);
	printf("%s\n", sinput);
}

