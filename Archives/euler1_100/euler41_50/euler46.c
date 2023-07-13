#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int prime(int n)
{
    if (n<=1) return 0;
    if (n==2) return 1;
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}

int power(int n)
{
    return n*n;
}

void euler46()
{
    int i, j, k, stop = 0, sum, square, verif;

    for(i=33;stop==0;i=i+2)
    {
        printf("num : %d", i);
        verif = 0;
        for (j=3;j<=i;j=j+2)
        {
            if (prime(j)==1)
            {
                square = i-j;
                square = square/2;
                square = sqrt(square);
                sum = j+ 2*power(square);
                if (sum==i)
                {
                    printf(" = %d+2*%d^2\n", j, square);
                    verif = 1;
                    break;
                }
            }
        }
        if (verif == 0)
        {
            printf(" = none\nanswer %d\n", i);
            break;
        }
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    euler46();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}