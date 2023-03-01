#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int a,b,c;
    int *p2;
    int *p1; 

    a=1,b=2,c=3;
    p1=&a,p2=&c;
    printf("a|b|c|  p1           |*p1|   p2            |*p2\n");
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    *p1=(*p2)++;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    p1=p2;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    p2=&b;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    *p1 -= *p2;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    ++*p2;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    *p1 *= *p2;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    a = ++*p2 * *p1;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    p1=&a;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);
    *p2 = *p1 /= *p2;
    printf(" %d|%d|%d|%p| %d|%p|%d\n",a,b,c,p1,*p1,p2,*p2);

    return EXIT_SUCCESS;
}