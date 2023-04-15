#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

int fill_primes_array(int primes[], int size)
{
    int i, t=0;
    for (i=2;t<size;i++)
    {
        if (prime(i)==1)
        {
            primes[t] = i;
            t++;
        }
    }
    display_array(primes, size);
}



int main()
{
    clock_t start, end;
    start = clock();
    int primes[200];
    fill_primes_array(primes, 200);

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}