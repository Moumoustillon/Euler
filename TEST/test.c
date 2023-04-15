#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int isPentagonal(long long int num) {
    // A number is part of the pentagonal sequence if and only if
    // it can be expressed as n(3n-1)/2 for some positive integer n
    // We can rearrange this formula to check if num is a pentagonal number
    // using the inverse formula: n = (sqrt(24*num + 1) + 1) / 6
    long long int root = (long long int)sqrt(24 * num + 1);
    if ((root * root == 24 * num + 1) && ((root + 1) % 6 == 0))
    {
        return 1;
    }
    return 0;
}
int isHexagonal(long long num) {
    // A number is part of the hexagonal sequence if and only if
    // it can be expressed as n(2n-1) for some positive integer n
    // We can rearrange this formula to check if (sqrt(8*num + 1) + 1) / 4 is an integer
    long long root = sqrt(8 * num + 1);
    if (((int)root == root) && ((int)root % 4 == 3))
    {
        return 1;
    }
    return 0;
}



int main()
{
    clock_t start, end;
    start = clock();
    int n = 1532447841;
    printf("%d\n", isPentagonal(n));
    printf("%d\n", isHexagonal(n));

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}