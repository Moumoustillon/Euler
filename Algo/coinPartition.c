#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display_array(int array[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i]>=-1) printf("%d|", array[i]);
    }
    printf("\n");
}



int result_matrix(int num[], int NUMBERS, int TARGET)
{
    int result[NUMBERS][TARGET+1];

    int i, j, withNB, withoutNB;

    for(i=0;i<NUMBERS;i++)
    {
        result[i][0] = 1;
    }

    // Les autres valeurs
    for (i=0;i<NUMBERS;i++)
    {
        for (j=1;j<TARGET+1;j++)
        {
            if (j - num[i] >= 0) withNB = result[i][j-num[i]];
            else withNB = 0;

            if (i >= 1) withoutNB = result[i-1][j];
            else withoutNB = 0;

            result[i][j] = withoutNB+withNB;            
        }
        
    }

    printf("result : %d\n", result[NUMBERS-1][TARGET]);
    return result[NUMBERS-1][TARGET];
}