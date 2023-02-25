#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int euler1()
{
    int i, s=0;

    for (i=1;i<1000;i++)
    {
        if((i%3==0)||(i%5==0))
        {
            s+=i;
        }
    }
    return s;
}

int euler2()
{
    int u1=1, u2=2, u, s=2;
    u=u1+u2;

    while(u<=4000000)
    {
        if( u%2 == 0 ) s+=u;

        u = u1+u2;
        u1 = u2;
        u2 = u;
    }
    return s;
}

long long primeeuler3(long long nb)
{
    long long i;

    for (i=3;i<sqrt(nb);i++)
    {
        if (nb%i == 0) return 0;
    }
    printf("prime %ld\n", nb);
    return 1;
}

long long euler3()
{
    long long n = 600851475143, i;
    for (i = n/71; i>71; i = i-2)
    {
        if (n%i==0) 
        {
            printf("euler %ld\n", i);
        
            if(primeeuler3(i)==1) return i;
        }
    }
    return 2;
}

int main()
{   
    printf("%d\n",euler3());
    return 0;
}