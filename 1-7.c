#include <stdio.h>

main()
{
    int c, prev_c;

    prev_c = -1;

    while ((c = getchar()) != EOF)
    {
        if (c != ' ' || (c == ' ' && prev_c != ' '))
        {
            putchar(c);
        }

        prev_c = c;
    }

    if (prev_c != -1)
    {
        putchar('\n');
    }

    printf("hi\n");
}