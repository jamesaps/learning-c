#include <stdio.h>

#define YES 1
#define NO 0

main()
{
    int c, nl, nw, nc, letter_char, inword;

    nl = nw = nc = 0;
    inword = NO;

    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
        }

        if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        {
            letter_char = YES;
        }
        else
        {
            letter_char = NO;
        }

        if (inword == NO && letter_char == YES)
        {
            ++nw;
            inword = YES;
        }

        if (c == ' ' || c == '\t' || c == '\n')
        {
            inword = NO;
        }
    }

    printf("characters: %d, words: %d, new lines: %d", nc, nw, nl);
}