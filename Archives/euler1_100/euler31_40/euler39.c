#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void display_array(int n[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("%d\n",n[i]);
    }
    printf("\n");
}

int carre(int a)
{
    return a*a;
}

void euler39()
{
    int a, p, c, pmax =0, max = 0;
    for (p=2;p<=1000;p+=2)
    {
        c = 0;
        for (a=2; a<p/3;a++)
        {
            if ( p*(p-2*a)%(2*(p-a)) == 0 ) c++;
        }
        if (c>max)
        {
            max = c;
            pmax = p;
        }
    }
    printf("pmax = %d, max = %d\n", pmax, max);
}


int main()
{
    clock_t start, end;
    start = clock();

    euler39();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}