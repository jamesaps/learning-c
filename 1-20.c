#include <stdio.h>
#define MAXLINE 1000
#define TABCOLUMNS 3

int getline(char s[], int limit);
void detab(char s[], char t[]);

int main(void)
{
    char s[MAXLINE];
    char t[MAXLINE];

    while (getline(s, MAXLINE) > 0)
    {
        detab(s, t);
        printf("%s", t);
    }
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

void detab(char s[], char t[])
{
    int i, j, k;

    i = j = k = 0;

    for (; i < MAXLINE - 1 && j < MAXLINE - 1 && s[i] != '\n'; ++i)
    {
        if (s[i] == '\t')
        {
            for (k = 0; k < TABCOLUMNS; ++k)
            {
                t[j++] = ' ';
            }
        }
        else
        {
            t[j++] = s[i];
        }
    }

    if (s[i] == '\n' || j == MAXLINE - 1)
    {
        t[j++] = '\n';
    }

    t[j] = '\0';
}