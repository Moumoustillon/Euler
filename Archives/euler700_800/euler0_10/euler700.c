#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

#define MOD 4503599627370517
#define EULERCOIN 1504170715041707
#define REVERSEEULERCOIN 3451657199285664

void euler700()
{
    unsigned long long n, coin = EULERCOIN, sum = EULERCOIN, min_coin = EULERCOIN, count;
    for (n = 2, count = 1; n <99999999 ; n++)
    {
        coin = (coin+EULERCOIN)%MOD;
        if (coin<min_coin)
        {
            count++;
            sum+=coin;
            min_coin=coin;
            printf("n=%llu, coin=%llu\n", count, coin);
        }
    }

    unsigned long long previous = REVERSEEULERCOIN;
    coin = REVERSEEULERCOIN;
    sum+=1;
    for (n=2; n<15806432 ; n++)
    {
        coin = (REVERSEEULERCOIN*n)%MOD;
        if (coin<previous)
        {
            count++;
            sum+=n;
            previous=coin;
            printf("n=%llu, coin=%llu\n", count, n);
        }
    }
    printf("\nsum = %llu\n", sum);
}

int main()
{
    clock_t start, end;
    start = clock();
    
    euler700();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}