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
    for(i=size-1;i>=0;i--)
    {
        printf("%d", a[i]);
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

//Digit factorials
int *digits_list(int n, int *list)
{
    int i=0;
    while(n!=0)
    {
        list[i]=n%10;
        n=n/10;
        i++;
    }
    return list;
}
long factorial(int n)
{
    long result=1;
    if (n==-1) return 0;
    for(int i = 2;i<=n;i++)
    {
        result = result*i;
    }
    return result;
}

long sum_fact_digits(int n)
{
    int size_list = 7;
    int *list;
    int i, sum=0;

    list=(int*)malloc(sizeof(int)*7);
    if (list==NULL) exit(EXIT_FAILURE);
    for(i=0;i<7;i++)
    {
        list[i]=-1;
    }
    list = digits_list(n, list);
    for (i=0;i<size_list;i++)
    {
        sum = sum+factorial(list[i]);
    }
    free(list);
    printf("sum(%d)=%d\n", n, sum);
    return sum;
}
void euler34()
{
    int i;
    long long result=0;
    for(i=3;i<=40585;i++)
    {
        if (i==sum_fact_digits(i))
        {
            result+=i;
        }
    }
    printf("result : %lli\n", result);
}



int main()
{
    clock_t start, end;
    start = clock();
    

    euler34();

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}