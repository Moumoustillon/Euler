#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display_array(int a[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]>=0) printf("%d|", a[i]);
    }
    printf("\n");
}
void set_null(int a[], int start, int size)
{
    int i;
    for(i=start;i<size;i++)
    {
        a[i]=0;
    }
}

// Coin sums
int glouton(int v[], int n[], int m[], int i, int result, int skip)
{
    int j, p=0;

    for(j=0;j<i;j++)
    {   
        if(n[j]!=-1) p = p+(v[j]*n[j]);
    }

    printf("p = %d\n",p);

    if(p==100)
    {
        printf("result+1 = %d\n", result+1);
        return 1;
    }
    if(p<100)
    {
        while(n[i]<=m[i])
        {
            printf("while i=%d\n",i);
            n[i] = n[i]+skip;
            set_null(n,i+1,8);
            display_array(n, 8);
            result += glouton(v,n,m,i+1,result,200/v[i+1]);
        }
    }
    else
    {
        printf("end 0\n");
        return 0;
    }
}

void euler31()
{
    int v[] = {200,100,50,20,10,5,2,1};
    int n[] = {0,0,0,0,0,0,0,0};
    int m[] = {1,2,4,10,20,40,100,200};
    int result = 0, i=0;

    result = glouton(v,n,m,i,result, 1);
    printf("reponse : %d\n", result);

}


int main()
{
    euler31();
    return EXIT_SUCCESS;
}