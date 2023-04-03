#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Sub-string divisibility

void reverse(int n[], int start, int finish)
{
    int i, j=finish-1, swap;
    for (i=start;i<(start+finish)/2;i++)
    {
        swap = n[i];
        n[i] = n[j];
        n[j] = swap;
        j--;
    }
}

int lexi_permutation(int n[], int size)
{
    int i, k, l, swap;
    for (i=0;i<size;i++)
    {
        k = -1;
        if ((i<size-1)&&(n[i]<n[k+1])) k = i;
    }
    if (k==-1)
    {
        printf("last permutation : %d\n", array_value(n, size));
        return -1;
    }
    for (i=0;i<size;i++)
    {
        if (n[i]>n[k]) l = i;
    }

    swap = n[k];
    n[k] = n[l];
    n[l] = swap;
    
    reverse(n, k+1, size);

    return 0; 
}

void euler43()
{
    int n[]={0,1,2,3,4,5,6,7,8,9}
}

int main()
{
    clock_t start, end;
    start = clock();

    euler43();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}