#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

<<<<<<< Updated upstream
<<<<<<< Updated upstream
void prime_array(int *array, int size)
=======
int* reverse(int n)
>>>>>>> Stashed changes
{
    int rev = 0;
    while (n>0)
    {
        rev = rev*10 + n%10;
        n = n/10;
    }
    return rev;
}

void euler55()
{
<<<<<<< Updated upstream
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
=======
    int answer = 0, n, m, i, rev, pal;
    for (n = 1; n<10000;n++)
    {   
        printf("%d\n", n);
        m = n;
        for (i = 1;i<=50;i++)
        {
            rev = rev(m);
            pal = rev+m;
            if (is_n_palindromic(pal)==1) answer++;
            m = pal;
            printf("____%d + %d = %d\n", m, rev, pal);
        }
    }
    printf("%d\n", answer);
>>>>>>> Stashed changes
}

int main()
{
    clock_t start, end;
    start = clock();

<<<<<<< Updated upstream
<<<<<<< Updated upstream
    euler();
=======
    euler55();
>>>>>>> Stashed changes
=======
    euler55();
>>>>>>> Stashed changes

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}