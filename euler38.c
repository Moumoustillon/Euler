#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int size_num(int n)
{
    int size=0;
    while(n!=0)
    {
        size++;
        n/=10;
    }
    return size;
}

int reverse_num(int n)
{
    int r = 0;
    while(n!=0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}

int conv_tab_num(int concat[],int size)
{
    int res=0, i;
    for(i=0;i<size;i++)
    {
        res=res*10+concat[i];
    }
    return res;
}

int pandigital(int num[], int size)
{
    int test[]={0,0,0,0,0,0,0,0,0}, i;
    for (i=0;i<size;i++)
    {
        if (test[num[i]-1]!=0)
        {
            printf("not pandigital\n");
            return 0;
        }
        test[num[i]-1]=1;
    }
    printf("is pandigital\n");
    return 1;
}

void display_array(int n[], int size)
{
    for (int i=0;i<size;i++)
    {
        printf("%d", n[i]);
    }
    printf("\n");
}

int euler38()
{
    int number, mult, product, digits = 0, largest_concat = 123456789, n_concat = 0, i;
    int concat[]={0,0,0,0,0,0,0,0,0};

    for (number=10;number<=9999;number++)
    {   
        printf("\nnumber = %d\n", number);
        digits = 0;
        // concatenating the products
        for (mult = 1; digits<9;mult++)
        {
            printf("    %d*%d=%d", number, mult,number*mult);
            product = reverse_num(number*mult);
            while(product!=0)
            {
                digits++;
                concat[digits-1]=product%10;
                product/=10;
                if (digits>9)
                {
                    printf("\n    too much digits\n");
                    concat[0]=0;
                    break;
                }
            }
        }
        printf("\n");
        display_array(concat, 9);
        if(pandigital(concat, 9)==1)
        {
            n_concat = conv_tab_num(concat, 9);
            if (largest_concat<=n_concat) largest_concat = n_concat; printf("new largest = %d\n", largest_concat);
        }  
    }
    return largest_concat;
}

int main()
{
    clock_t start, end;
    start = clock();

    printf("\n\nanswer : %d\n", euler38());

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}