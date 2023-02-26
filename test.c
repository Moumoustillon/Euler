#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int prime(long long int n)
{
    long long int i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if (n%i == 0) return 0;
    }
    printf("\n%d est premier.\n", n);
    return 1;
}

int main()
{   
    printf("est premier : %d\n",prime(102983));

    return 0;
}