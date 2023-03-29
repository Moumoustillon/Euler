#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int prime(int n)
{
    if (n<=1) return 0;
    if (n==2) return 1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    printf("%d is prime\n", n);
    return 1;
}

int reverse(int n)
{
    int ncopy = n, reverse = 0;
    while(ncopy!=0)
    {
        reverse = reverse*10 + ncopy%10;
        ncopy /= 10;
    }
    return reverse;
}

int trunc_lr(int n)
{
    n = reverse(n);
    n = n/10;
    n = reverse(n);
    return n;
}

int trunc_rl(int n)
{
    return n/10;
}

int truncatable_prime(int n)
{
    int ncopy=n;
    while(ncopy!=0)
    {
        ncopy=trunc_lr(ncopy);
        if ((prime(ncopy)!=1)&&(ncopy!=0)) return 0;
    }
    ncopy = n;
    while(ncopy!=0)
    {
        ncopy=trunc_rl(ncopy);
        if((prime(ncopy)!=1)&&(ncopy!=0)) return 0;
    }
    return 1;
}
void euler37()
{
    int sum = 0, limit = 0, i;
    int primes[] = {1,2,3,5,7,9};
    for (i=11;limit<11;i+=2)
    {
        if (prime(i)==1)
        {
            if(truncatable_prime(i)==1)
            {
                sum = sum+i;
                limit++;
            }
        }
    }
    printf("answer : %d\n", sum);
}   

int main()
{
    clock_t start, end;
    start = clock();

    euler37();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}