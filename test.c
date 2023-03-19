#include<stdio.h>
#include<stdlib.h>


int main()
{
    int j=2;
    while(j<1000)
    {
        if (7852%j==0)
        {
            printf("%d * %d = 7852\n", j, 7852/j);
        }
        j++;
    }
    return EXIT_SUCCESS;
}