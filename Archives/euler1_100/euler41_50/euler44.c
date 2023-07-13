#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int penta(int n)
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

void euler44()
{
    int k = 1, j, pk, pj, fin = 0;
    while (fin == 0)
    {
        k += 1;
        pk = penta(k);
        for (j=1;j<k;j++)
        {
            pj = penta(j);
            printf("pk = %d | pj = %d\n", pk, pj);
            printf("k = %d | j = %d\n\n", k, j);

            if (is_pentagonal(pk+pj)==1)
            {
                if (is_pentagonal(pk-pj)==1)
                {
                    printf("pk-pj = %d, pj+pk = %d\n", pk-pj, pj+pk);
                    printf("diff = %d\n", pk-pj);
                    fin = 1;
                    break;
                }
            }
        }
    }
}




int main()
{
    clock_t start, end;
    start = clock();

    euler44();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}