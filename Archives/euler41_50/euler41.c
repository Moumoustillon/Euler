#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int prime(int n)
{
    if (n<=1) return 0;
    if (n==2) return 2;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}

int nb_digits(int n)
{
    int size = 0;
    while(n!=0)
    {
        size++;
        n/=10;
    }
    return size;
}

int pandigital(int n)
{
    int size = nb_digits(n), copy = n;
    int tab[size+1];
    for (int i=0;i<=size;i++)
    {
        tab[i] = 0;
    }
    
    while(n!=0)
    {
        if (tab[(n%10)]!=0) 
        {
            return 0;
        }
        tab[(n%10)] = 1;
        n=n/10;
    }
    return 1;
}

void euler41()
{
    int i;
    for (i = 7654321;i>=1234;i--)
    {
        if (pandigital(i)==1)
        {
            printf("i : %d\n", i);
            if (prime(i)==1)
            {
                printf("answer = %d\n", i);
                break;
            }
        }
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    euler41();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}