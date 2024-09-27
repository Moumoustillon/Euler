#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include"toolbox.h"

int recherche_tab(int* tab, int taille, long long n)
{
    for(int i = 0; i<taille ; ++i)
    {
        if(tab[i] == n) return 1;
    }
    return 0;
}


long long euler808()
{   
    long long sum = 0;
    long long count = 0;
    long long p = 1;
    long long n1 = 0;
    long long n2 = 0;


    printf("début \n");

    while (count<50)
    {
        if (prime(p))
        {
            n1 = p*p;
            printf("p = %d || n1 = %d  ", p, n1);
            if(!is_n_palindromic(n1))
            {
                n2 = inverse(n1);
                if (prime(sqrt(n2)) && sqrt(n2)*sqrt(n2)==n2)
                {
                    printf(", n2 = %d : is prime || ", n2);

                    sum += n2;
                    count++;
                    printf("count = %d, sum = %d\n", count, sum);
                }   
                else printf(" : is not prime ... \n");
            }
            else printf(" : palindromic ... \n");
        }
        ++p;
    }
    return sum;


}

int main()
{
    clock_t start, end;
    start = clock();

    int a = euler808();
    printf("result = %d\n", a);

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}