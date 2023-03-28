#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

unsigned long reverse_long(unsigned long n)
{
    unsigned long r=0;
    while(n!=0)
    {
        r = r*10;
        r = r+n%10;
        n /= 10;
    }
    return r;
}

int palindromicu(unsigned long n)
{
    unsigned long r;
    r = reverse_long(n);
    while (n!=0)
    {
        if (n%10 != r%10) return 0;
        n/=10;
        r/=10;
    }
    return 1;
}

int palindromic(int n)
{
    int r;
    r = reverse_long(n);
    while (n!=0)
    {
        if (n%10 != r%10) return 0;
        n/=10;
        r/=10;
    }
    return 1;
}

unsigned long convert_to_binary(int n)
{
    unsigned long bin = 0;
    while(n!=0)
    {
        bin = bin*10 + n%2;
        n = n/2;
    }
    printf("bin : %llu\n", bin);
    return bin;
    
}

void euler36()
{
    int n = 0, i, j, sum = 0, pal;
    unsigned long bin;
    for (i=10;i<1000000;i++)
    {
        
        if (palindromic(i)==1)
        {
            printf("i = %llu\n", i);
            printf("pal : %llu\n", i);
            bin = convert_to_binary(i);
            if (palindromicu(bin)==1)
            {
                sum += i;
            }
        }
    }
    printf("answer : %llu\n", sum);
}

int main()
{
    clock_t start, end;
    start = clock();

    euler36();
    
    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}