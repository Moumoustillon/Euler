
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"toolbox.h"

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

int power(int n)
{
    return n*n;
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

