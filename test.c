#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void is_abundant(int n)
{
    int i, sum = 0;
    printf("sum : ");
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum = sum+i;
            printf("%d + ", i);
        }
    }
    printf("= %d\n", sum);
    if(sum>n)
    {
        printf("%d is abundant\n", n);
        
    }
    else printf("%d is not abundant\n", n);
    
    
}

int main()
{
    is_abundant(3527);
    is_abundant(590);
    return EXIT_SUCCESS;
}