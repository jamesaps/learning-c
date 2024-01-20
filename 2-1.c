#include <stdio.h>

int main()
{
    char c, c_max, c_min;
    short s, s_max, s_min;
    int i, i_max, i_min, flag;

    c = c_max = c_min = 0;
    s = s_max = s_min = 0;
    i = i_max = i_min = 0;

    flag = 1;

    while (flag == 1)
    {
        flag = 0;

        if (c + 1 > c_max)
        {
            c_max = c++;
            flag = 1;
        }

        if (s + 1 > s_max)
        {
            s_max = s++;
            flag = 1;
        }

        if (i + 1 > i_max)
        {
            i_max = i++;
            flag = 1;
        }
    }

    c = s = i = 0;
    flag = 1;

    while (flag == 1)
    {
        flag = 0;

        if (c - 1 < c_min)
        {
            c_min = c--;
            flag = 1;
        }

        if (s - 1 < s_min)
        {
            s_min = s--;
            flag = 1;
        }

        if (i - 1 < i_min)
        {
            i_min = i--;
            flag = 1;
        }
    }

    printf("char: %d to %d\n", c_min, c_max);
    printf("short: %d to %d\n", s_min, s_max);
    printf("int: %d to %d\n", i_min, i_max);

    return 0;
}