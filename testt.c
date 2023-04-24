#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

void power_array(int p[], int size, int a, int b) 
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
        display_array(p, 9);
        j = 0;
        r = 0;
        while(p[j]!=-1)
        {
            p[j] = (p[j]*a)+r;
            r = p[j]/10;
            p[j] = p[j]%10;
            
            j++;
            
        }

        while (r!=0)
        {

            p[j] = r%10;
            r/=10;
            j++; 
            p[i] = acopy%10;
            acopy /= 10;
        }  
    }
}

int main()
{
    clock_t start, end;
    start = clock();

    int p[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1};

    power_array(p, 9, 5, 7);

    display_array(p, 9);

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}