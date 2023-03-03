#include<stdio.h>
#include<stdlib.h>

// maximum of two integers
int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

// palindromic integer
int palindromic(int n)
{
    int i, r = 0, copy;
    copy = n;

    while(copy!=0)
    {
        r = r*10;
        r = r+(copy%10);
        copy = copy/10;
    }
    if(r == n) 
    {
        printf("pal %d\n", n);
        return 1;
    }
    return 0;
}

// prime number
int prime(int n)
{
    int i;

    for (i=3;i<sqrt(n);i++)
    {
        if (n%i == 0) printf("%d is not prime\n", n); return 0;
    }
    printf("%d is prime\n", n);
    return 1;
}

// factorial 
int factorial(int n)
{
    int i, res=1;
    for(i=2;i<=n;i++)
    {
        res = res*i;
    }
    printf("factorial %d = %d\n", n, res);
    return res;
}

