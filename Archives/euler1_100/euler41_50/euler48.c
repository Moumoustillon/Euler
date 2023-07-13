#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

long long power_modulo(long long x)
{
    long long i, result = 1;
    for (i = 1; i <= x; i++) {
        result = (result * x) % 10000000000;
    }
    printf("%d^%d = %lli\n", x, x, result);
    return result;
}

void euler48()
{
    long long fin = 1000, i, answer = 0;
    long long suite[fin];

    for (i=1;i<=fin;i++)
    {
        answer += power_modulo(i);
    }
    printf("answer : %lli\n", answer);
}

int main()
{
    clock_t start, end;
    start = clock();

    euler48();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}