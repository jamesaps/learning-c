#include <stdio.h>

main()
{
    int lower, upper, step;
    float celsius, fahr;

    lower = 0;
    upper = 150;
    step = 10;

    celsius = lower;

    printf("celsius fahr\n");
    printf("-------+----\n");

    while (celsius <= upper)
    {
        fahr = celsius * (9.0 / 5.0) + 32;
        printf("%4.0f  %4.0f\n", celsius, fahr);

        celsius = celsius + step;
    }
}