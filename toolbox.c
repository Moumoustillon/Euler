
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"toolbox.h"

int max(int a, int b)
{
    if (a>b) return a;
    return b;
}

int min(int a, int b)
{
    if (a<b) return a;
    return b;
}

int count_digits(int n)
{
    int digits = 0;
    while(n!=0)
    {
        digits++;
        n/=10;
    }
    return digits;
}

void display_array(int array[], int size)
{
    int i;
    printf("{");
    for (i=0;i<size;i++)
    {
        printf("%d,", array[i]);
    }
    printf("}\n");
}

void display_array_as_number(int array[], int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

int is_a_permutation_of_b(int a, int b)
{
    
}
int factorial(int n)
{
    int i, fact = 1;
    for (i=2;i<=n;i++)
    {
        fact *= i;
    }
    return fact;
}

int permutation_ab(int a, int b)
{
    int digits[] = {0,0,0,0,0,0,0,0,0,0};
    int i;

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

int power(int x, int n)
{
    if (n<0) return n;
    if (n==0) return 1;
    if (n%2 == 0) return power(x*x, n/2);
    return x*power(x*x,(n-1)/2);
}

float power_f(float x, int n)
{
    if (n<0)
    {
        if (x == 0) return x; 
        x = 1/x;
        return power_f(x, -n);
    }
    if (n==0) return 1;
    if (n%2 == 0) return power_f(x*x, n/2);
    return x*power_f(x*x,(n-1)/2);
}



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

int is_coprime(int a, int b)
{
    int max, min, div;
    if ((a<=1)||(b<=1)) return 0;
    if (a>b)
    {
        max = a;
        min = b;
    }
    else 
    {
        max = b;
        min = a;
    }
    for (div = 2;div<=min;div++)
    {
        if ((min%div==0)&&(max%div==0))
        {
            return 0;
        }
    }
    return 1;
}




// SEQUENCES FUNCTIONS

    // Triangular numbers
int generate_nth_triangular(int n)
{
    return (n*(n+1))/2;
}
int is_triangular(int num)
{
    int n = 0;
    int triangularNum = 0;
    while (triangularNum < num) {
        n++;
        triangularNum = n * (n + 1) / 2;
    }
    if (triangularNum == num) return 1;
    return 0;
}
    // Pentagonal numbers
int generate_nth_pentagonal(int n)
{
    return (n*(3*n-1))/2;
}
int is_pentagonal(int num)
{
    int n = 1+(int)sqrt(1+24*num)/6;
    if (num == (n*(3*n-1))/2) 
    {
        return 1;
    }
    return 0;
}
    // Hexagonal numbers
int generate_nth_hexagonal(int n)
{
    return n*(2*n-1);
}
int is_hexagonal(int num)
{
    double root = sqrt(8 * num + 1);
    if (((int)root == root) && ((int)root % 4 == 3)) return 1;
    return 0;
}

