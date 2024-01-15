#include <stdio.h>

#define YES 1
#define NO 0
#define MAXWORDLENGTH 12

main()
{
    int c, i, j, inword, wlen, maxlengthcount;
    int wordcount[MAXWORDLENGTH + 1];

    inword = NO;
    wlen = maxlengthcount = 0;

    for (i = 0; i <= MAXWORDLENGTH; ++i)
    {
        wordcount[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        if (inword == NO)
        {
            if (c != ' ' && c != '\t' && c != '\n')
            {
                inword = YES;
                wlen = 1;
            }
        }
        else
        {
            if (c == ' ' || c == '\t' || c == '\n')
            {
                if (wlen <= MAXWORDLENGTH)
                {
                    if (++wordcount[wlen] > maxlengthcount)
                    {
                        maxlengthcount = wordcount[wlen];
                    }
                }

                inword = NO;
            }
            else
            {
                ++wlen;
            }
        }
    }

    printf("LEN\n");

    for (i = 1; i <= MAXWORDLENGTH; ++i)
    {
        printf("%3d |", i);

        for (j = 1; j <= wordcount[i]; ++j)
        {
            printf("*");
        }

        printf("\n");
    }
}