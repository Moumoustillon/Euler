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
void euler32()
{
    int i, product_max = 987654321, check_d, result_sum = 0, fact1 = 111, fact2 = 11, prod = 1221;
    int *digits, *number;

    digits = (int*)malloc(sizeof(int)*9);
    number = (int*)calloc(9,sizeof(int));

    if (digits==NULL) exit(EXIT_FAILURE);
    if (number == NULL) exit(EXIT_FAILURE);


    free(digits);
    free(number);
}

int main()
{
    clock_t start, end;
    start = clock();
    int coins[] = {1,2,5,10,20,50,100,200};

    euler31(coins,8,200);

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}