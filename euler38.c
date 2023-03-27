#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int pandigital(int n)
{
    int digits[]={0,0,0,0,0,0,0,0,0};
    if (n<123456789) return 0;
    if (n>987654321) return 0;
    while(n!=0)
    {
        if (digits[(n%10)-1]!=0) return 0;
        digits[(n%10)-1] = 1;
        n/=10;
    }
    return 1;
}

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
    int reverse[], i, j=0;
    for(i=size-1;i>=0;i--)
    {
        reverse[j]=num[i];
        j++;
    }
    for(i=0;i<size;i++)
    {
        if (num[i]!=reverse[i]) return 0;
    }
    return 1;
}

int euler38()
{
    int number, mult, product, digits = 0, largest_concat = 123456789, n_concat = 0, i;
    int concat[]={0,0,0,0,0,0,0,0,0}

    // 2 digit numbers
    for (number=10;number<=99;number++)
    {   
        printf("number = %d\n", number);
        digits = 0;
        // concatenating the products
        for (mult = 1; digits<9;mult++)
        {
            printf("    %d*%d=%d", number, mult,number*mult);
            product = reverse_num(number*mult);
            while(product!=0)
            {
                concat[digits]=product%10;
                product/=10;
                digits++;
                if (digits>=9)
                {
                    printf("too much digits (%d*%d=%d)\n", number, mult, product);
                    concat[0]=0;
                    break;
                }
            }
        }
        if(pandigital(concat, 9)==1)
        {
            n_concat = conv_tab_num(concat, 9);
        }

        
    }
    // 3 digit numbers
    for (number=100;number<=999;number++)
    {
        
    }
    // 4 digit numbers
    for (number=1000;number<=9999;number++)
    {
        
    }

}

int main()
{
    clock_t start, end;
    start = clock();

    euler808();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}