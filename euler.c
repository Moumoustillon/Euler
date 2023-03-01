#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void convert_grid(int grid[][20],char chaine[])
{
    int i, j, ch=-1;
    for (i=0;i<20;i++)
    {
        for(j=0;j<20;j++)
        {
            ch++;
            grid[i][j] = (int)(chaine[ch])-48;
            grid[i][j] = grid[i][j]*10;
            ch++;
            grid[i][j] += (int)(chaine[ch])-48;
            printf("%d|",grid[i][j]);
        }
        printf("\n");
    }
}

int max11(int a, int b)
{
    if(a>b) return a;
    return b;
}

long long euler11(int grid[][20], int tab[])
{   
    int i, j, max_v=0, max_h=0, max_dd=0, max_dg=0, product=1;
    
    /* horizontal */
    for (i=0;i<20;i++)
    {
        for(j=0;j<=16;j++)
        {
            product = grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3];
            max_h = max11(max_h, product);
        }
    }
    printf("Max horizontal : %d\n", max_h);

    /* vertical */
    for (i=0;i<20;i++)
    {
        for (j=0;j<16;j++)
        {
            product = grid[j][i]*grid[j+1][i]*grid[j+2][i]*grid[j+3][i];
            max_v = max11(max_v, product);
        }
    }
    printf("Max vertical : %d\n", max_v);

    /* diagonale droite */
    for (i=0;i<=16;i++)
    {
        for (j=0;j<=16;j++)
        {
            product = grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3];
            max_dd = max11(max_dd, product);
        }
    }
    printf("Max diagonale droite : %d\n", max_dd);

    /* diagonale gauche */
    for (i=0;i<=16;i++)
    {
        for(j=3;j<20;j++)
        {
            product = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
            max_dg = max11(max_dg, product);
        }
    }
    printf("Max diagonale gauche : %d\n", max_dg);

    product = max11(max11(max_v, max_h), max11(max_dd, max_dg));

    return product;
}

void convert_str_mat13(char str[], long long matrice[][50])
{
    int i, j, c=0;
    for(i=0;i<100;i++)
    {
        for(j=0;j<50;j++)
        {
            matrice[i][j] = (long long)(str[c])-48;
            printf("%d|", matrice[i][j]);
            c++;
        }
        printf("\n");
    }
}

void affichetab(int tab[], int debut)
{
    int i;
    printf("tab %d :", debut);
    for(i=debut;i<50;i++)
    {
        printf("%d", tab[i]);
    }
    printf("\n");
}

void euler13(long long nb[][50])
{   
    int result[50];
    int i, j, somme=0;
    for(j=49;j>=0;j--)
    {   
        somme = 0;
        for(i=0;i<100;i++)
        {
            somme = somme+nb[i][j];
        }
        printf("somme %d : %d\n", j, somme);

        result[j] = result[j]+somme;
        if(j>0)
        {
            result[j-1] = result[j]/10;
            affichetab(result, j);
            result[j] = result[j]%10;
        }
    }
    affichetab(result,0);
}

int nb_div(long long n)
{
    long long i, nbdiv=0;

    for (i=1;i<sqrt(n)+1;i++)
    {
        if(n%i==0) nbdiv = nbdiv+1;
    }

    return nbdiv*2;
}

long long euler12()
{
    long long n, tn, tnp=0, div=0;

    /* Nb triangulaires */
    for(n=1;div<500;n++)
    {
        tn = tnp+n;
        tnp = tn;

        /* Test nb diviseurs */
        div = nb_div(tn);
    }
    printf("nb : %d, div : %d\n", tn, div);
    return tn;
}

long long euler14()
{
    long long i, j, nbt, nbtmax=0, startingmax=0;
    for(i=1;i<1000000;i++)
    {   
        nbt = 0;
        j = i;
        while(j>1)
        {
            if(j<=0)
            {
                printf("erreur j négatif %d\n", j);
                return -1;
            }

            if(j%2==0) j = j/2;
            else j = 3*j+1;
            nbt = nbt+1;
        }
        printf("nbt %d : %d\n", i, nbt);
        nbtmax = max11(nbtmax, nbt);
        if(nbtmax==nbt) startingmax=i;
        printf("nb termes max : %d\n", nbtmax);
    }
    return startingmax;
}

void syracuse(long long j)
{
    while(j!=1)
    {
        if(j%2==0) j = j/2;
        else j = 3*j+1;
        printf("%lli|",j);
    }
    printf("\n");
}

long long factorielle15()
{
    long long i, result=1, n=20;
    for(i=2;i<=n;i++)
    {

        result = result*i;
        printf("%lli, %lli\n", result, i);
    }
    return result;
}

void affiche_matrice(long long matrice[][21])
{
    int i, j;
    for(i=0;i<21;i++)
    {
        for(j=0;j<21;j++)
        {
            if(matrice[i][j]<10) printf("0%lli|",matrice[i][j]); 
            else printf("%lli|",matrice[i][j]);
        }
        printf("\n");
    }
}

void euler15(long long matrice[][21])
{
    long long i, j;
        for(i=0;i<21;i++)
        {
            matrice[0][i] = 1;
            matrice[i][0] = 1;
        }

        for(i=1;i<21;i++)
        {
            for(j=1;j<21;j++)
            {
                matrice[i][j] = matrice[i][j-1]+matrice[i-1][j];
            }
        }

        affiche_matrice(matrice);
        printf("rep : %lli\n", matrice[20][20]);
}

void init_tab(int tab[], int taille)
{
    int i;
    tab[0] = 1;
    for(i=1;i<taille;i++)
    {
        tab[i] = -1;
    }
}

void affiche_tab(int tab[], int taille)
{
    int i;
    for(i=0;i<taille;i++)
    {
        printf("%d|", tab[i]);
    }
    printf("\n\n\n okk \n");
}

int euler16(int tab[], int taille)
{
    int i, sum=0, r=0, nb_cases=0, j=0;

    /* puissance i */
    for(i=1;i<=1000;i++)
    {   
        r = 0;
        while(tab[j] != -1)
        {
            tab[j] = (tab[j]*2)+r;
            r = tab[j]/10;
            tab[j] = tab[j]%10;
            printf("%d|", tab[j]);
            if (j>nb_cases) nb_cases=j;
            j++;
        }
        if (r>0)
        {
            tab[j] = r;
            printf("%d|", tab[j]);
            if (j>nb_cases) nb_cases=j;
        }
        printf(" puissance %d\n___\n", i);
        j = 0;
    }
    
    nb_cases++;

    printf("\nnbcases : %d\n", nb_cases);

    for(i=nb_cases-1;i>=0;i--)
    {
        printf("%d",tab[i]);
        sum = sum+tab[i];
    }
    printf("\nsum : %d\n", sum);
    return sum;
}

long long euler17(int lettres[])
{
    int dizaines=1, centaines=0, i, unites=0;
    long long result;

    /* and */
    result += 3*793;

    /* hundred */
    result += 8*100;
    

    /* dizaines */
    for(i=2;i<10;i++)
    {
        result += lettres[i+18]*8;
        /* unités */
        for(i=1;i<10;i++)
        {
            result += lettres[i]*8;
        }
    }

    /* unités */
    for(i=1;i<10;i++)
    {
        result += lettres[i];
    }

    /* 1-20 */
    for(i=1;i<20;i++)
    {
        result+=lettres[i]*9;
    }

    result+=11;

    printf("result : %d\n", result);
    return result;
}

void euler18(int triangle[][t], int t)
{
    int i, j;
    for(i=t-1;i>0;i--)
    {   
        for(j=1;j<=i;j++)
        {
            triangle[i-1][j-1] = max11(triangle[i][j-1]+triangle[i-1][j-1], triangle[i][j]+triangle[i-1][j-1]);
            
        }
    }

    printf("reponse : %d\n", triangle[0][0]);
}

int main()
{      
    


    return EXIT_SUCCESS;
}