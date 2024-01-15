#include <stdio.h>
#define MAXLINE 1000

int main()
{
    int len;
    char str[MAXLINE];

    while ((len = getline(str, MAXLINE)) > 0)
    {
        if (len > 80)
        {
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