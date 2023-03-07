#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int test()
{
    int a=1, b=26, digits = 0, i, r ;

    do{
        printf("%d/%d=%d\n", a, b, a*10/b);
        a = a*10%b;
        digits++;
    } while(digits<15);
    return digits;
}


int main()
{
    printf("%d\n",test());
    printf("%d\n", 10%7);
    return EXIT_SUCCESS;
}