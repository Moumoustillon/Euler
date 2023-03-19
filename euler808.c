#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



int main()
{
    clock_t start, end;
    start = clock();

    euler808();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}