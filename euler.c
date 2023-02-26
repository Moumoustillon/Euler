#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int euler1()
{
    int i, s=0;

    for (i=1;i<1000;i++)
    {
        if((i%3==0)||(i%5==0))
        {
            s+=i;
        }
    }
    return s;
}

int euler2()
{
    int u1=1, u2=2, u, s=2;
    u=u1+u2;

    while(u<=4000000)
    {
        if( u%2 == 0 ) s+=u;

        u = u1+u2;
        u1 = u2;
        u2 = u;
    }
    return s;
}

long long primeeuler3(long long nb)
{
    long long i;

    for (i=3;i<sqrt(nb);i++)
    {
        if (nb%i == 0) return 0;
    }
    printf("prime %ld\n", nb);
    return 1;
}

long long euler3()
{
    long long n = 600851475143, i;
    for (i = n/71; i>71; i = i-2)
    {
        if (n%i==0) 
        {
            printf("euler %ld\n", i);
        
            if(primeeuler3(i)==1) return i;
        }
    }
    return 2;
}

int palindromic(int n)
{
    int i, r = 0, copy;
    copy = n;

    while(copy!=0)
    {
        r = r*10;
        r = r+(copy%10);
        copy = copy/10;
    }
    if(r == n) 
    {
        printf("pal %d\n", n);
        return 1;
    }
    return 0;
}

int euler4()
{
    int i, j, res = 0;
    i=999;
    j=i;
    for (i=999;i>=100;i=i-1)
    {   
        if (palindromic(i*i)==1) 
        {
            printf("euler %d\n", i);
            if (i*i>res) res=i*i;
        }
        for (j=i+1;j>=100;j=j-1)
        {   
            if (palindromic(i*j)==1) 
            {
                
                if (i*j>res)
                {
                    printf("euler j %d %d\n", i, j);
                    res = i*j;
                }
            }
        }
    }
    
    return res;
}

int euler5()
{
    int i, j, v=1, t=1;

    for (i=2520;v==1;i=i+20)
    {
        for (j=3;j<20;j++)
        {
            if (i%j!=0) t=0;
        }
        if (t==1)
        {
            printf("ok %d\n", i);
            return i;
        }
        t=1;
    }
    return -1;
}

int prime7(long long int n)
{
    long long int i;
    for(i=2;i<sqrt(n)+1;i++)
    {
        if (n%i == 0) return 0;
    }
    printf("\n%d est premier.\n", n);
    return 1;
}

long long euler7()
{
    long long i, j=3, resultat=3;

    for (i=2;i<10001;i++)
    {
        j=resultat+2;
        while(prime7(j)!=1)
        {
            j=j+2;
        }
        resultat = j;
        printf("res = %d\ni = %d\n", resultat, i);
    } 
    return resultat;
}

long long max(long long a, long long b)
{
    if (a>b) return a;
    return b;
}

long long produit(int tab[], int taille)
{
    int i, res=1;
    for (i=0;i<taille;i++)
    {
        res = res*tab[i];
    }
    return res;
}

long long euler8(char serie[], long long tab[])
{
    int i,j=0, k;

    while(serie[j]!="\0")
    {
        k=j;
        for(i=0;i<13;i++)
        {
            if (serie[k]==0)
        }
    }
}

int main()
{   
    char serie[1001] = {"73167176531330624919225119674426574742355349194934\
                        96983520312774506326239578318016984801869478851843\
                        85861560789112949495459501737958331952853208805511\
                        12540698747158523863050715693290963295227443043557\
                        66896648950445244523161731856403098711121722383113\
                        62229893423380308135336276614282806444486645238749\
                        30358907296290491560440772390713810515859307960866\
                        70172427121883998797908792274921901699720888093776\
                        65727333001053367881220235421809751254540594752243\
                        52584907711670556013604839586446706324415722155397\
                        53697817977846174064955149290862569321978468622482\
                        83972241375657056057490261407972968652414535100474\
                        82166370484403199890008895243450658541227588666881\
                        16427171479924442928230863465674813919123162824586\
                        17866458359124566529476545682848912883142607690042\
                        24219022671055626321111109370544217506941658960408\
                        07198403850962455444362981230987879927244284909188\
                        84580156166097919133875499200524063689912560717606\
                        05886116467109405077541002256983155200055935729725\
                        71636269561882670428252483600823257530420752963450\0"};
    long long largest, tab[13];



    largest = produit(tab, 13);

    for (i=0;i<nb;i++)
    {

    }

    

    return EXIT_SUCCESS;
}