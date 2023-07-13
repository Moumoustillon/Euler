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

int permutation(int ab, int bb)
{
    int digits[] = {0,0,0,0,0,0,0,0,0,0};
    int i, a, b;
    a = ab;
    b = bb;
    while(a != 0)
    {
        digits[a%10]++;
        a/=10;
    }
    while(b != 0)
    {
        digits[b%10]--;
        b/=10;
    }
    for (i=0;i<10;i++)
    {
        if (digits[i]!=0) return 0;
    }
    return 1;
}

void euler49()
{
    int i, a, b, c;

    for (i=1001;i<=3339;i+=2)
    {
        a = i;
        b = a+3330;
        c = b+3330;
        
        if ((prime(a)==1)&&(prime(b)==1)&&(prime(c)==1))
        {
            if ((permutation(a, b)==1)&&(permutation(b,c)==1))
            {
                printf("%d %d %d\n", a, b, c);
            }
        }
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    euler49();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}