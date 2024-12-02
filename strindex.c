/* 
   program structure:
   while (line exist?){
       if (line contain pattern)
           print this line
   }
*/
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getlin(char line[], int max); 
int strindex(char source[], char searchfor[]);


int main(int argc, char *argv[])
{
   char line[MAXLINE];
   int found = 0;
   while (getlin(line, MAXLINE) > 0)
       if (strstr(line, argv[1]) > 0) {
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

