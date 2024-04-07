#include <stdio.h>

int strindex(char input[], char s2[])
{
    int i, j, k;
    int index = -1;
    for(i=0;input[i] != '\0'; i++)
    {
        for(j = i, k=0; s2[k]!='\0'&& input[j] == s2[k]; j++, k++);
        if(k>0 && s2[k]=='\0')
        {
            index =  i;
        }
    }
    return index;
}

int main(void)
{
    char line[]= "mnbvjhgkabc";
    char pattern[] = "abc";
    int found = 0;
   
    found = strindex(line, pattern);   
    printf("%d\n", found);

}