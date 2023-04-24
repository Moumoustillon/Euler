#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

void display_array_as_number_ccc(int array[], int size)
{
    int i;
    for (i=0; array[i]!=-1; i++)
    {
        printf("%d", array[i]);
    }
    printf("\n");
}

int* init_array_p(int *p, int size)
{
    p = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        p[i] = -1;
    }
    return p;
}

void power_array(int *p, int size, int a, int b) 
{
    int acopy = a, j, r;
    // init array a
    for (int i = 0; acopy != 0; i++)
    {
        p[i] = acopy%10;
        acopy /= 10;
    }
    
    
    // multiply array by a b times
    for (int i = 2; i <= b; i++)
    {
        j = 0;
        r = 0;
        while(p[j]!=-1)
        {
            p[j] = (p[j]*a)+r;
            r = p[j]/10;
            p[j] %= 10;

            j++;
        }
        while (r!=0)
        {
            p[j] = r%10;
            r/=10;
            j++; 
        }   
    }
}

int sum_digits(int *p, int size)
{
    int sum = 0, i = 0;
    while(p[i] != -1)
    {
        sum += p[i];
        i++;
    }
    return sum;
}

void euler56()
{
    int a, b, sum = 0, size = 300, sum_d;
    int *num;

    for (a = 1 ; a < 100 ; a++)
    {
        
        for (b = 1 ; b < 100 ; b++)
        {

            num = init_array_p(num, size);
            power_array(num, size, a, b);

            sum_d = sum_digits(num, size);

            sum = max(sum, sum_d);
        }
    }
    printf("answer %d\n", sum);
    free(num);
}


int main()
{
    clock_t start, end;
    start = clock();

    euler56();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}


