#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void display_array(int a[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]>=-1) printf("%d|", a[i]);
    }
    printf("\n");
}

// Coin sums
int euler31(int num[], int NUMBERS, int TARGET)
{
    //Matrice des résultats -> chaque ligne = usage d'une pièce plus grande en plus
    // -> chaque colonne = somme visée, la dernière colonne étant la cible £2 ou 100 selon le problème
    int result[NUMBERS][TARGET+1];

    // Variables du nombre de possibilités de former la valeur cible avec les pièces inférieures
    // et la pièce actuelle
    int i, j, withNB, withoutNB;

    // une seule façon de former la valeur 1 peu importe les pièces qu'on a
    for(i=0;i<NUMBERS;i++)
    {
        result[i][0] = 1;
    }

    // Les autres valeurs
    for (i=0;i<NUMBERS;i++)
    {
        for (j=1;j<TARGET+1;j++)
        {
            // si on peut utiliser le nb actuel dans la valeur -> withNB = nb de façons de faire - (valeur-nb actuel)
            if (j - num[i] >= 0) withNB = result[i][j-num[i]];
            else withNB = 0;

            // si on peut pas utiliser la valeur, nb de façons de faire pareil que la valeur précédente;
            if (i >= 1) withoutNB = result[i-1][j];
            else withoutNB = 0;

            result[i][j] = withoutNB+withNB;            
        }
        
    }

    // resultat dans la dernière case
    printf("result : %d\n", result[NUMBERS-1][TARGET]);
    return result[NUMBERS-1][TARGET];

}

// Pandigital products
/*int *product_decomposition(int n, int **products)
{
    int a, b, size = 2;
    int *result;
    result=(int*)malloc(sizeof(int)*size);
    if (result==NULL) exit(EXIT_FAILURE);

    for (a = 12; a<n/2 ; a++)
    {
        if (n%a==0) 
    }
}*/
void euler32()
{
    int **products, *actual_p;
    int i;

    products = (int**)malloc(sizeof(int*)*3024);
    if (products==NULL) exit(EXIT_FAILURE);
    for(i=0;i<3024;i++) products[i]=(int*)calloc(3,sizeof(int));
    actual_p=(int*)calloc(3,sizeof(int));


    for(i=0;i<3024;i++) free(products[i]);
    free(products);
}


long long palindromic(long long n)
{
    long long i, r = 0, copy;
    copy = n;

    while(copy!=0)
    {
        r = r*10;
        r = r+(copy%10);
        copy = copy/10;
    }
    if(r == n) 
    {
        return 1;
    }
    return 0;
}
long long reverse(long long n)
{
    long long i, r = 0, copy;
    copy = n;

    while(copy!=0)
    {
        r = r*10;
        r = r+(copy%10);
        copy = copy/10;
    }
    return r;
}

long long prime(long long n)
{
    long long i;

    if(n<=1) return 0;
    if(n==2) return 1;

    for (i=3;i<sqrt(n)+1;i++)
    {
        if (n%i == 0)return 0;
    }
    printf("%d is prime\n", n);
    return 1;
}

long long get_first_digit(long long n)
{
    long long n2;
    n2 = n;
    while(n2>10)
    {
        n2 = n2/10;
    }
    return n2;
}

void euler808()
{
    long long sum = 0, i, max=0, reverse_i, sqrt_i, sqrt_rev, j;

    for(i=10;max<50;i++)
    {
        j = get_first_digit(i);
        if ((j==1)||(j==3)||(j==9))
        {
            if ((i%10==1)||(i%10==3)||(i%10==9))
            {
                if(palindromic(i)==0)
                {
                    reverse_i = reverse(i);
                    sqrt_i = sqrt(i);
                    sqrt_rev = sqrt(reverse_i);
                    printf("i=%lli, reverse=%lli\n", i, reverse_i);
                    printf("sqrt i : %lli, sqrt rev : %lli\n", sqrt_i, sqrt_rev);

                    if ((sqrt_i*sqrt_i == i)&&(sqrt_rev*sqrt_rev == reverse_i))
                    {
                        if( (prime(sqrt_i)==1) && (prime(sqrt_rev)==1) )
                        {
                            sum += i;
                            max++;
                        }
                        
                    }
                    printf("sum = %lli, max = %lli\n", sum, max);
                }
            }
        }
        
    }
    printf("reponse : %lli\n", sum);
}



int main()
{
    clock_t start, end;
    start = clock();
    

    euler808();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}