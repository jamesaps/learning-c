#include <stdio.h>
#define MAXLINE 1000

int getline(char s[], int limit);
void reverse(char s[], int len);

int main()
{
    int len;
    char str[MAXLINE];

    while ((len = getline(str, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            reverse(str, len);
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
void reverse(char s[], int len)
{
    int start, end;
    char tmp;
    start = 0;
    end = len - 2;

    while (start < end)
    {
        tmp = s[start];

        s[start] = s[end];
        s[end] = tmp;

        ++start;
        --end;
    }
}