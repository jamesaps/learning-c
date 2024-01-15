#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int limit);
void removetrailing(char s[], int limit);

int main()
{
    int len;
    char str[MAXLINE];

    while ((len = getline(str, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            removetrailing(str, MAXLINE);
            printf("%s", str);
        }
    }

    return 0;
}

/* read a line into s and return length */
int getline(char s[], int limit)
{
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/* remove trailing blanks and tabs from s */
void removetrailing(char s[], int limit)
{
    int i, lastnonblank;

    for (i = 0; i < limit - 1 && s[i] != '\n'; ++i)
    {
        if (s[i] != '\t' && s[i] != ' ')
        {
            lastnonblank = i;
        }
    }

    if (lastnonblank == limit - 2)
    {
        /* string stays the same */
    }
    else
    {
        s[lastnonblank + 1] = '\n';
        s[lastnonblank + 2] = '\0';
    }
}