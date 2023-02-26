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

long long max8(long long a, long long b)
{
    if (a>b) return a;
    else return b;
}

long long produit8(int tab[])
{
    int i;
    long long prod = 1;
    for(i=0;i<13;i++)
    {
        prod = prod*tab[i];
        if(prod==0) return prod;
    }
    return prod;
}

long long euler8(char serie[], int facteurs[], int facmax[])
{
    long long i=0, j, res=0, p=1;

    while (i<1000-13)
    {
        for(j=0;j<13;j++)
        {
            facteurs[j]=(long long)(serie[j+i])-48;
        }

        printf("\n\nfacteurs : ");

        for(j=0;j<13;j++)
        {   
            printf("%d*", facteurs[j]);
        }

        p = produit8(facteurs);
        printf("\nproduit = %d, ", p);
        
        if (p==0)
        {
            for(j=0;j<13;j++)
            {   
                if (facteurs[j]==0) i=i+j;
            }
        }

        printf("res = %d\n", res);
        res = max8(p,res);

        if (res == p)
        {
            for(j=0;j<13;j++)
            {   
                facmax[j]=facteurs[j];
            }
        }

        printf("max : %d\n", res);
        i++;
    }

    printf("i = %d\nfacteurs max : ", i);
    for(j=0;j<13;j++)
        {   
            printf("%d*", facmax[j]);
        }
    printf("resultat incorrect, multiplier à la main facmax\n");
    return res;
}

int somme9(int triplet[])
{
    return triplet[0]+triplet[1]+triplet[2];
}

int verif_triplet9(int triplet[])
{
    if (triplet[0]*triplet[0]+triplet[1]*triplet[1]!=triplet[2]*triplet[2])
    {
        printf("(%d,%d,%d) n'est pas un triplet pythagoricien\n", triplet[0], triplet[1], triplet[2]);
        return 0;
    }
    printf("(%d,%d,%d) est un triplet pythagoricien\n", triplet[0], triplet[1], triplet[2]);
    return 1;
}

int carre(int n)
{
    return n*n;
}

int euler9()
{
    int triplet[3], u, v,i;
    for (u=1;u<1000;u++)
    {
        for (v=u;v<1000;v++)
        {
            triplet[0]=2*u*v;
            triplet[1]=carre(u)-carre(v);
            if (triplet[1]<0) triplet[1] = triplet[1]*(-1);
            triplet[2]=carre(u)+carre(v);
            
            printf("triplet : (%d,%d,%d)\n", triplet[0], triplet[1], triplet[2]);

            if ((somme9(triplet)==1000)&&(verif_triplet9(triplet)==1))
            {
                printf("réponse : (%d,%d,%d)\n", triplet[0], triplet[1], triplet[2]);
                return 1;
            }
        }
    }
    printf("sortie de boucle\n");
    return 0;

}

int prime10(long long n)
{
    long long i;
    if (n<=1) return 0;
    if(n==2) return 1;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return 0;
    }
    printf("%ld est premier\n", n);
    return 1;
}

long long euler10()
{
    long long i, s=0;
    for(i=1;i<2000000;i++)
    {
        if (prime10(i)==1)
        {
            printf("s = %ld, i = %ld, s+i = %ld\n", s, i, s+i);
            s+=i;
        }
    }
    return s;
}

int main()
{   
    printf("réponse : %ld\n", euler10()); 

    return EXIT_SUCCESS;
}