#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int prime(int n)
{
    if (n<=1) return 0;
    if (n==2) return 1;
    for (int i = 2;i<sqrt(n)+1;i++)
    {
        if (n%i == 0) return 0;
    }
    return 1;
}

void display_array(int array[], int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        printf(" %d |", array[i]);
    }
    printf("\n");
}

void init_primes(int primes[], int size)
{
    int i, j=0;
    for (i=2;j<size;i++)
    {
        if (prime(i)==1)
        {
            primes[j] = i; 
            j++;
        }
    }
}

void euler50()
{   
    int i, j, k, size = 78498, sum = 0, nbterms = 0, nbmax = 0, primemax;
    int primes[size];
    
    init_primes(primes, size);
    display_array(primes, size);
    
    for (i=0;i<size;i++)
    {
        k = i;
        sum = 0;
        while (sum<1000000)
        {
            sum += primes[k];
            if (prime(sum)==1)
            {
                nbterms = k-i;
                if (nbterms>nbmax)
                {
                    nbmax = nbterms;
                    primemax = sum;
                }
            }
            k++;
        }
    }

    printf("%d, %d\n", primemax, nbmax);
}

int main()
{
    clock_t start, end;
    start = clock();

    euler50();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}