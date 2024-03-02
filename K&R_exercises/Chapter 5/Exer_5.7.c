#include<stdio.h>
#include<string.h>

#define MAXLINES     5000
#define MAXLEN       1000
#define ALLOCSIZE    1000
#define MAXSTORAGE   200

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
int getline(char*, int);
char *alloc(int);
char *lineptr[MAXLINES];

char linestorage[MAXSTORAGE];

int readlines(char *lineptr[], char *linestorage, int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

void swap (char *v[], int i, int j);

/*sort input lines*/
int main()
{
	int nlines;
	
	if((nlines = readlines(lineptr,linestorage, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("input too big to sort\n");
		return 1;
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

/*char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp +=n;
		return allocp-n;
	}
	else
	    return 0;
}

void afree(char *p)
{
	if(p>=allocbuf && p< allocbuf + ALLOCSIZE)
	    allocp = p;
}*/

/*readlines: read input lines*/
int readlines(char *lineptr[], char *linestorage, int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = linestorage;
	char *linestop = linestorage + MAXSTORAGE;
	
	nlines = 0;
	printf("enter the line:\n");
	while((len = my_getline(line, MAXLEN))>0)
	{
		if ((nlines >= maxlines) || p +len > linestop)
		{
			return -1;
		}
		else
		{
			line[len-1] = '\0';
			strcpy(p,line);
			lineptr[nlines++] = p;
			p+=len;
		}
	}	
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for(i = 0; i<nlines;i++)
	{
		printf("%s\n", lineptr[i]);
	}
}

void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	
	
	if(left >= right)
	  return;
	
	swap(v, left, (left+right)/2);
	
	last = left;
	
	for(i = left+1; i<= right; i++)
	{
		if(strcmp(v[i], v[left]) < 0)
		{
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}
