#include <stdio.h>

float fahrtocelsius(float fahr);

int main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("f   |c\n");
    printf("----+------\n");

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = fahrtocelsius(fahr);
        printf("%3.0f |%6.1f\n", fahr, celsius);

        fahr += step;
    }
    return 0;
}

float fahrtocelsius(float fahr)
{
    return 5.0 * (fahr - 32.0) / 9.0;
}