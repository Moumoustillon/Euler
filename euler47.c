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

int nb_prime_factors(int primes[], int size, int num)
{
    int i = 0, nb_f = 0, n = num, distinct = 0;

    printf("%d = ", n);
    while (n != 1)
    {
        if (n % primes[i] == 0)
        {
            printf("%d*", primes[i]);
            n = n/primes[i];
            nb_f = nb_f+1;
            
        }
        else
        {
            i++;
        }
    }
    printf("\n");
    return nb_f;
}

void euler47()
{
    int size = 200, i, four = 0, nb;
    int primes[size];

    fill_primes_array(primes, size);

    //printf("test\n");
    for (i=2;four<4;i++)
    {   
        nb = nb_prime_factors(primes, size, i);
        //printf("test2\n");
        printf("%d : %d\n", i, nb);
        
        if (nb==4)
        {
            four++;
        }
        else
        {
            four = 0;
        }
    }
    printf("%d\n", i-4);
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