#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>



int *reverse(int n, int *rev)
{
    int i, res = 0, j, a,lim;
    
    for (i=0;i<7;i++)
    {
        rev[i]=-1;
    }
    i = 0;
    while(n!=0)
    {
        rev[i] = n%10;
        i++;
        n /= 10;
    }
    return rev;
}

int*reverse_array(int n[])
{
    int size=0, i, j;
    while(n[size]!=-1)
    {
        size++;
    }
    int a[size];
    j=size-1;
    for(i=0;i<size;i++)
    {
        a[i]=n[j];
        j--;
    }
    for (i=0;i<size;i++)
    {
        n[i]=a[i];
    }
    return n;
}

void display_array(int n[])
{
    int i=0;
    while(n[i]!=-1)
    {
        printf("%d", n[i]);
        i++;
    }
    printf("\n");
}

void euler40()
{
    int number, digit = 0, verif = 1, *rev, i=0, res=1;
    rev = (int*)malloc(sizeof(int)*7);
    if (rev == NULL) exit(EXIT_SUCCESS);
    for (number = 1;digit<=1000000;number++)
    {   
        i=0;
        rev = reverse(number, rev);
        rev = reverse_array(rev);
        while(rev[i]!=-1)
        {
            digit++;
            if (digit == verif)
            {
                verif = verif*10;
                res = res*rev[i];
                printf("digit : %d, number : %d, num : %d, i : %d, array : ", digit, rev[i],number, i);
                display_array(rev);
            }
            i++;
        }
        

    }
    printf("answer : %d\n", res);
    free (rev);
}


int main()
{
    clock_t start, end;
    start = clock();

    euler40();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}