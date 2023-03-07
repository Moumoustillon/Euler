#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int test(int a, int b)
{   
    int digits = 0, r=a;
    do
    {
        printf("%d/%d=%d\n", a, b, a*10/b);
        a = a * 10 % b;
        digits++;
    } while(a!=1);
    return digits;
}


int main()
{
    printf("%d\n",test(1,53));
    
    return EXIT_SUCCESS;
}