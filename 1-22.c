#include <stdio.h>

#define MAXLINELENGTH 20

/* This solution does not account for input that it receives in multiple lines. */

int main(void)
{
    int c, i, j;
    int maxblankindex;
    char buffer[MAXLINELENGTH];

    i = j = 0;
    maxblankindex = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            maxblankindex = i;
        }

        buffer[i++] = c;

        if (i == MAXLINELENGTH || c == '\n')
        {
            for (j = 0; j < maxblankindex; ++j)
            {
                putchar(buffer[j]);
            }

            putchar('\n');

            i = 0;
            j = maxblankindex;

            while (j < MAXLINELENGTH)
            {
                if (buffer[j] != ' ' && buffer[j] != '\t')
                {
                    buffer[i++] = buffer[j];
                }

                j++;
            }

            if (i < MAXLINELENGTH)
            {
                buffer[i] = '\n';
            }

            maxblankindex = 0;
        }
    }

    return 0;
}