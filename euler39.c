#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void display_array(int n[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf(" p:%d s:%d |",i+1,n[i]);
    }
    printf("\n");
}

int coprime(int a, int b)
{
    int max = a, i;
    if (b<max) max = b;
    for(i=2;i<=max;i++)
    {
        if ((a%i==0)&&(b%i==0)) return 0;
    }
    return 1;

}

int carre(int n)
{
    return n*n;
}
int maxtab(int *tab, int size)
{
    int max = 0, i;
    for(i=0;i<size;i++)
    {
        if (tab[i]>tab[max-1]) max = i+1;
    }
    printf("tabmax : %d\n", tab[119]);
    return max;
}
int verif_triplet(int a, int b, int c)
{
    if (carre(a)+carre(b)==carre(c))
    {
        return 1;
    }
    return 0;
}

int euler39()
{
    int *p, m, n, soluce_max = 0, pmax = 0, sol = 0, a,b,c,k;
    p = (int*)calloc(1000, sizeof(int));
    if (p==NULL) exit(EXIT_FAILURE);
    for (a=0;a<500;a++)
    display_array(p,1000);
    soluce_max = maxtab(p, 1000);
    printf("solution : %d\n", soluce_max);
    free(p);
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