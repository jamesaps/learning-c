#include <stdio.h>
#define MAXLINE 30 /* maximum input line length */
#define YES 1
#define NO 0

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */

int main()
{
    int len;               /* current line length */
    int max;               /* maximum length seen so far */
    int c;                 /* current character */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')
        {
            while ((c = getchar()) != EOF && c != '\n')
            {
                ++len;
            }
        }

        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* there was a line */
        printf("%d: %s", max, longest);
    return 0;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}