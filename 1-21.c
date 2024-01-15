#include <stdio.h>
#define MAXLINE 1000
#define TABCOLUMNS 3

int getline(char s[], int limit);
void entab(char s[], char t[]);

int main(void)
{
    char s[MAXLINE];
    char t[MAXLINE];

    while (getline(s, MAXLINE) > 0)
    {
        entab(s, t);
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

void entab(char s[], char t[])
{
    int i, j, k;
    int spaces;

    i = j = k = spaces = 0;

    for (; i < MAXLINE - 1 && s[i] != '\n'; ++i)
    {
        if (s[i] == ' ')
        {
            ++spaces;
        }
        else if (spaces > 0 && spaces < TABCOLUMNS)
        {
            for (k = 0; k < spaces; ++k)
            {
                t[j++] = ' ';
            }
            spaces = 0;
        }

        if (s[i] != ' ')
        {
            t[j++] = s[i];
        }

        if (spaces == TABCOLUMNS)
        {
            t[j++] = '*';
            spaces = 0;
        }
    }

    if (s[i] == '\n' || j == MAXLINE - 1)
    {
        t[j++] = '\n';
    }

    t[j] = '\0';
}