#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int is_pentagonal(int num)
{
    int n = 1+(int)sqrt(1+24*num)/6;
    if (num == (n*(3*n-1))/2) 
    {
        return 1;
    }
    return 0;
}

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

void euler50()
{   
    int i, j, k, size = 78498, sum = 0, nbterms = 0, nbmax = 0, primemax;
    int primes[size];
    
    init_primes(primes, size);
    display_array(primes, size);
    
    for (i=2;i<size;i++)
    {
        for (j=0;j<=i;j++)
        {
            printf("%d = ", primes[i]);
            k = j;
            sum = 0;
            nbterms = 0;
            while (sum<primes[i])
            {
                printf("%d + ", primes[k]);
                sum += primes[k];
                nbterms++;
                k++;
            }
            printf(" = %d\n", sum);
            if (sum == primes[i])
            {
                if (nbmax<nbterms)
                {
                    nbmax = nbterms;
                    primemax = primes[i];
                }
            }
        }
        
    }
    printf("%d, %d\n", primemax, nbmax);
}

int main()
{
    clock_t start, end;
    start = clock();
    
    int sum = 0, i;
    for (i=0;i<=1000000;i++)
    {
        if (prime(i)==1)
        {
            sum++;
            printf("%d, %d\n", i, sum);
        }
    }
    


    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}
