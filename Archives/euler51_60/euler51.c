#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"



void euler51()
{
    int i, j, horizon = 999999999;
    int number[10];

    for (i=100000;i<horizon;i++)
    {
        j = 2;
        while(is_a_permutation_of_b(i, i*j)==1)
        {
            if (j==6)
            {
                printf("%d\n", i);
                exit(EXIT_SUCCESS);
            }
            j++;
        }
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    euler51();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}