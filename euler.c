#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

<<<<<<< Updated upstream
void prime_array(int *array, int size)
{
    int i, count = 0;
    for(i=0;count<size; i++)
    {
        if(prime(i) == 1)
        {
            array[i] = i;
        }
    }
}


void euler51()
{
    int i_candidates = 0 ;
    int *primes;
    int size = 1000000;
    primes = (int*)malloc(size*sizeof(int));



    free(primes);
=======
void euler55()
{

    int* list, bool;
    int answer = 0, res;

    list = malloc(sizeof(int)*10001);
    // 0 = lychrel, 1 = not lychrel
    bool = calloc(10001,sizeof(int));

    
    
    
>>>>>>> Stashed changes
}

int main()
{
    clock_t start, end;
    start = clock();

<<<<<<< Updated upstream
    euler();
=======
    euler55();
>>>>>>> Stashed changes

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}