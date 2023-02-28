#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int i, div=0;

    for (i=1;i<=367567200;i++)
    {
        if(367567200%i==0) div++;
    }

    printf("%d", div);
    return EXIT_SUCCESS;
}