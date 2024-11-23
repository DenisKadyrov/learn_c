/* 
   program structure:
   while (line exist?){
       if (line contain pattern)
           print this line
   }
*/
#include <stdio.h>

#define MAXLINE 1000

int getlin(char line[], int max); 
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main()
{
   char line[MAXLINE];
   int found = 0;
   while (getlin(line, MAXLINE) > 0)
       if (strindex(line, pattern) >= 0) {
           printf("%s", line);
           found++;
       }
   return found;
}

int getlin(char s[], int lim)
{
    int c, i;
    i = 0;
    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c = '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strindex (char s[], char t[])
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k ++, j ++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
