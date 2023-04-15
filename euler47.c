#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

int fill_primes_array(int primes[], int size)
{
    int i, t=0;
    for (i=0;t<size;i++)
    {
        if (prime(i)==1)
        {
            primes[t] = i;
            t++;
        }
    }
}

void euler47()
{
    int size = 200, i, j, four = 0, nb_fac = 0, index_p = 0;
    int primes[size];

    fill_primes_array(primes, size);

    for (i = 10 ; four <4 ; i++)
    {
        j = i;
        index_p = 0;
        while (j!=0)
        {

        }
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    euler47();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}