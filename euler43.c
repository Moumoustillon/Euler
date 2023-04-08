#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// Sub-string divisibility

void display_array(int n[])
{
    for (int i=0;i<10;i++)
    {
        printf("%d", n[i]);
    }
    printf("\n");
}
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
    int i, k = -1, l, swap;
    for (i=0;i<size;i++)
    {
        if ((i<size-1)&&(n[i]<n[i+1])) k = i;
    }
    if (k==-1)
    {
        printf("last permutation : ");
        display_array(n);
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

int construct_nb(int n[], int i)
{
    int res = 0, j=i;
    while(j<i+3)
    {
        res = res*10 + n[j];
        j++;
    }
    return res;
}

unsigned long int convert_tab(int n[], int size)
{
    unsigned long int result = 0, i;
    for (i=0;i<size;i++)
    {
        result = result*10 + n[i];
    }
    return result;
}

void euler43()
{
    int n[]={0,1,2,3,4,5,6,7,8,9};
    int condition[]={2,3,5,7,11,13,17};
    int i, stop = 0, j, ok = 1;
    unsigned long int sum = 0;
    while (stop == 0)
    {
        stop = lexi_permutation(n, 10);
        j=0;
        ok=0;
        for (i=1;i<8;i++)
        {
            if (n[0]==0)
            {
                ok += 1;
                break;
            }
            if (construct_nb(n,i)%condition[j]!=0)
            {
                ok += 1;
                break;
            } 
            j++;
        }
        if (ok == 0)
        {
            display_array(n);
            sum += convert_tab(n, 10);
            printf("sum : %llu\n", sum);
        }
    }
    printf("answer : %llu\n", sum);
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