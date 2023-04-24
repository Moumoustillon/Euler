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
#include"toolbox.h"

void init_matrix(int matrix[][163], int size)
{
    int i, j;
    for (i=0;i<size;i++)
    {
        for (j=0;j<163;j++)
        {
            matrix[i][j]=-1;
        }
    }
}

void copy_array(int n[][163], int size, int f)
{
    int i=0;
    while(n[f-1][i]!=-1)
    {
        n[f][i]=n[f-1][i];
        i++;
    }
}

void invert_array(int n[], int size)
{
    int i, j = size-1, change;
    for (i = 0;i<=size/2;i++)
    {
        change = n[i];
        n[i] = n[j];
        n[j] = change;
        j--;
    }
}

int factorial2(int n[][163], int size, int f)
{
    int j, r;
    copy_array(n, size, f);

    j = 0;
    r = 0;

    while(n[f][j]!=-1)
    {
        n[f][j] = (n[f][j]*f)+r;
        r = n[f][j]/10;
        n[f][j] = n[f][j]%10;
        //printf("%d", n[f][j]);
        j++;
    }
    while (r!=0)
    {
        n[f][j] = r%10;
        r/=10;
        //printf("%d", n[f][j]);
        j++; 
    }

    return j;
}


void display_matrix_llu(int matrix[][163], int size)
{
    int i, j;
    for (i=0;i<size;i++)
    {
        j = 0;
        while(matrix[i][j]!=-1)
        {
            printf("%d", matrix[i][j]);
            j++;
        }
        printf("\n");
    }
    
}

void add_array(int r[], int s[], int size, int rank)
{
    int i;
    while ()
}

void multiply_array(int n[], int sizen, int sizer, int r[], int result[])
{
    int i, j, rank = 0, rest = 0, s[200];
    for (i = 0;i<sizer;i++)
    {
        for (j=0;j<sizen;j++)
        {
            s[j] = n[j]*r[i] + rest;
            rest = s[j]/10;
            s[j] = s[j]%10;
        }

    }

}

void euler53()
{
    int n, r, sum = 0, value = 0;
    int fact[101][163];
    int digits[101];
    int fraction[2][163];
    
    init_matrix(fact, 101);

    fact[0][0] = 1;
    
    for (n = 1;n<=100;n++)
    {
        printf("%d\n", n);
        digits[n] = factorial2(fact, 101, n);
        printf("\n");
    }

    for (n=23;n<=100;n++)
    {
        for (r=1;r<=n;r++)
        {

        }
    }


    printf("answer : %d\n", sum);
}

int main()
{
    clock_t start, end;
    start = clock();

    euler53();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}
