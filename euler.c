#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

void prime_array(int *array, int size)
{
    int i, count = 0;
    for(i=0;count<size; i++)
    {
        if(prime(i) == 1)
        {
            array[i] = i;
        }
    }
}


void euler51()
{
    int i_candidates = 0 ;
    int *primes;
    int size = 1000000;
    primes = (int*)malloc(size*sizeof(int));



    free(primes);
}

int main()
{
    clock_t start, end;
    start = clock();

    euler();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}