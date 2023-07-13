#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

void euler53()
{
    unsigned long long K = 1000000;
    unsigned long long answer = 0, n = 101, r, i ,j;

    unsigned long long *ligne1, *ligne2;
    ligne1 = malloc(sizeof(unsigned long long));
    ligne2 = malloc(sizeof(unsigned long long)*2);
    ligne2[0] = 1;
    ligne2[1] = 1;
    
    for (i = 3; i <= n; i++)
    {
        ligne1 = realloc(ligne1, sizeof(unsigned long long)*i);
        ligne1[0] = 1;
        printf("%5d | ", ligne1[0]);
        for (j = 1; j < i-1; j++)
        {
            ligne1[j] = ligne2[j-1]+ligne2[j];
            printf("%5d | ", ligne1[j]);
            if (ligne1[j] >= K) answer ++;
        }
        ligne1[j] = 1;
        printf("%5d \n", ligne1[j]);

        ligne2 = realloc(ligne2, sizeof(unsigned long long)*i);
        for (j = 0; j < i; j++) ligne2[j] = ligne1[j];
    }
    
    printf("answer = %d\n", answer);

    free(ligne1);
    free(ligne2);
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