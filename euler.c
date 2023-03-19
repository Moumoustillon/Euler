#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct identity
{
    int multiplicand;
    int multiplier;
    int product;
} identity;

typedef struct frac
{
    int num;
    int den;
} frac;

void display_array(int a[], int size)
{
    int i;
    for(i=size-1;i>=7;i--)
    {
        if(a[i]>=-1) printf("%d", a[i]);
    }
    printf("*");
    for(i=6;i>=4;i--)
    {
        if(a[i]>=-1) printf("%d", a[i]);
    }
    printf(" = ");
    for(i=3;i>=0;i--)
    {
        if(a[i]>=-1) printf("%d", a[i]);
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
int *init_malloc(int *array, int size)
{
    array=(int*)malloc(sizeof(int)*size);
    if (array==NULL) exit(EXIT_SUCCESS);
    return array;
}
int *init_calloc(int *array, int size)
{
    array = (int*)calloc(size, sizeof(int));
    if (array==NULL) exit(EXIT_FAILURE);
    return array;
}

int *set_zero(int *array, int size)
{
    for(int i=0;i<size;i++)
    {
        array[i]=0;
    }
    return array;
}

int *put_digits(int *tab, int i, int j, int k)
{
    int l = 0;
    while(i!=0)
    {
        tab[l] = i%10;
        i = i/10;
        l++;
    }

    while(j!=0)
    {
        tab[l] = j%10;
        j = j/10;
        l++;
    }
    while(k!=0)
    {
        tab[l] = k%10;
        k = k/10;
        l++;
    }
    //display_array(tab, 9);
    return tab;
}

int pandigital(int *tab, int *verif)
{
    int i, j;
    for(i=0;i<9;i++)
    {
        j = tab[i]-1;
        if(verif[j]!=0)
        {
            verif = set_zero(verif, 9);
            
            return 0;
        }
        verif[j]=1;
    }
    verif = set_zero(verif, 9);
    printf("is pandigital\n");
    return 1;
}
int digits(int j)
{
    int count=0;
    while(j!=0)
    {
        count++;
        j/=10;
    }
    return count;
}
void euler32()
{
    int *result, *verif;
    int i, j, k, sum = 0;
    verif = init_calloc(verif, 9);
    result = init_malloc(result,9);

    for (i=1000;i<=9999;i++)
    {
        for(j=2;j<=999;j++)
        {
            if (i%j==0)
            {
                k = i/j;
                if (digits(k)==5-digits(j)) 
                {
                    result=put_digits(result, i, j ,k);
                    if (i==7852)
                    {
                        display_array(result, 9); 
                        printf("sum : %d+%d \n", sum, i);
                    }
                    if (pandigital(result, verif)==1)
                    {   
                        display_array(result, 9);
                        printf("sum : %d+%d --> ", sum, i);
                        sum = sum+i; 
                        printf("%d\n", sum);
                        break;
                    }
                }
                result = set_zero(result,9);
            }
        }
    }
    printf("answer : %d\n", sum);
}

//Digit cancelling fractions
frac cancel_common_digit(frac f, int digit)
{   
    
}
frac common_digit(frac f)
{
    frac reduced = f;
    int common = 0, num=reduced.num, den=reduced.den;

    if (num%10==den%10)
    {
        common = num%10;
        return common;
    }
    if ((num/10)%10==den%10)
    {
        common = den%10;
        return common;
    }
    if (num%10==(den/10)%10)
    {
        common = num%10;
        return common;
    }
    if ((num/10)%10==(den/10)%10)
    {
        common = num%10;
        return common;
    }
    return -1;
}
void euler33()
{
    frac f, result;
    int common_digit;
    result.num = 1;
    result.den = 2;

    for(f.den = 11;den<100;den++)
    {
        for(f.num=10;num<den;num++)
        {
            common_digit=common_digit(f.num, f.den);
            if (common_digit==-1) break;

        }
    }

}

int main()
{
    clock_t start, end;
    start = clock();
    

    euler32();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}