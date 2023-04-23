#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// 785

long long gcd(long long a, long long b, long long c)
{
    int i, mini = min(a, min(b,c));
    if ((a<=0)||(b<=0)||(c<=0)) return 0;
    for (i=2;i<=mini;i++)
    {
        if ( (a%i==0)&&(b%i==0)&&(c%i==0))
        {
            return 0;
        }
    }
    return 1;
}


void solve_equation(long long N)
{
    long long x, y, z, S = 0;
    for (z = 1; z <= N; z++)
    {
        for (y = 1; y <= z; y++)
        {
            
            for (x = 1; x <= y; x++)
            {
                
                if (15*(x*x+y*y+z*z) == 34*(x*y+y*z+z*x))
                {
                    printf("(%lli,%lli,%lli)\n", x, y, z);
                    S += x + y + z;
                }
            }
        }
    }
    printf("answer: %lli\n", S);
}

int main()
{
    clock_t start, end;
    start = clock();

    solve_equation(100);

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds: %f\n", duration);
    return EXIT_SUCCESS;
}
