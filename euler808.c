#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define SIZE_ARRAY 20
#define STOP 50

void display_array(int *array, int size) // display array, ignoring value -1
{
    int i;
    for(i=0;i<size;i++)
    {
        if (array[i]==-1) break;
        printf("%d", array[i]);
    }
}

int *init_array(int *array, int size) // return initialised array to -1
{
    array = (int*)malloc(sizeof(int)*size);
    printf("hey\n");
    if (array == NULL)
    {
        printf("malloc failed\n"); 
        exit(EXIT_FAILURE);
    }
    printf("hoy\n");
    for (int i=0;i<size;i++) array[i] = -1;
    return array;
}

int *set_array_null(int *array, int size)
{
    for(int i=0;i<size;i++) array[i] = -1;
    return array;
}

long long convert_array_to_int(int *array, int size) // return long long number
{
    long long number = 0, i;
    for(i=size-1;i>=0;i--)
    {
        if (array[i]!=-1)
        {
            number *= 10;
            number += array[i];
        }
    }
    return number;
}

int *convert_int_to_array(int *array, int size, long long n)
{
    int i = 0;
    while(n!=0)
    {
        array[i] = n%10;
        n /= 10;
        i++;
    }
    return array;
}

int palindromic_array(int *array, int size)  // 1 : is palindromic, 0 : is not palindromic
{
    int *palindrome, i, j = 0;
    palindrome = init_array(palindrome, size);
    for(i=size-1; i>=0 ;i--)
    {
        if (array[i]!=-1) palindrome[j] = array[i]; j++;
    }
    for(i=0;i<size;i++)
    {
        if (array[i]!=palindrome[i]) return 0;
    }
    return 1;
}

int prime(long long n) // 1 : is prime, 0 : is not prime
{
    int i;
    if (n>=1) return 0;
    if (n==2) return 1;
    for (i=3;i<=sqrt(n);i++)
    {
        if (n%i==0) return 0;
    }
    return 1;
}

int get_size_number(long long number)
{
    int digits=0;
    while(number!=0) number/=10; digits++;
    return digits;
}

long long get_reverse(long long n) // return n reversed
{
    long long copy = n, reverse = 0;
    while(copy!=0)
    {
        reverse = (reverse*10) + (copy%10);
        copy = copy/10;
    }
    return reverse;
}

void euler808()
{
    int maxi = 0 , p_number, p_reverse, check;
    int *numberA, *reverseA; 
    long long sqrtNumber, sqrtReverse, size_number, number, reverse, sum = 0 ;
    printf("start\n");
    numberA = init_array(numberA, 18);
    reverseA = init_array(reverseA,18);
    printf("2\n");
    for (number = 13; maxi<STOP ; number+=2)
    {
        check = 0;
        size_number = get_size_number(number);
        numberA = convert_int_to_array(numberA, size_number, number);

        // Number must start or end with 1, 3 or 9
        if ( (numberA[size_number-1]!=1)&&(numberA[size_number-1]!=3)&&(numberA[size_number-1]!=9) )
        {
            if (numberA[size_number-1]<3) numberA[size_number-1]=3;
            if ( (numberA[size_number-1]<9)&&(numberA[size_number-1]>3) ) numberA[size_number-1]=9;
            number = convert_array_to_int(numberA, size_number);
            check = 1;
        }
        if ( (numberA[0]!=1)&&(numberA[0]!=3)&&(numberA[0]!=9) )
        {
            if (numberA[0]==0) numberA[0]=1;
            if ((numberA[0]<3)&&(numberA[0]!=0)) numberA[0]=3;
            if ( (numberA[0]<9)&&(numberA[0]>3) ) numberA[0]=9;
            number = convert_array_to_int(numberA, size_number);
            check = 1;
        }
        // checking if number is the square of a prime
        printf("test number 2 = %lli\n", number);
        sqrtNumber = sqrt(number);
        p_number = prime(sqrtNumber);
        if ( (sqrtNumber*sqrtNumber==number)&&(p_number==1) )
        {
            printf("test number = %lli\n", number);
            reverse = get_reverse(number);
            sqrtReverse = sqrt(reverse);
            p_reverse = prime(sqrtReverse);
            if ( (sqrtReverse*sqrtReverse==reverse)&&(p_reverse==1) )
            {
                sum = sum+number;
                maxi = maxi+1;
            }

        }
        printf("number : %lli | sqrt : %lli | prime : %d\n", number, sqrtNumber,p_number);
        display_array(numberA, SIZE_ARRAY); printf("\n");
        printf("reverse: %lli | sqrt : %lli | prime : %d\n", reverse, sqrtReverse, p_reverse);
        printf("sum : %lli | maxi : %d\n\n", sum, maxi);
    }

    printf("answer : %lli\n", sum);
    free(numberA);
    free(reverseA);
}

int main()
{
    clock_t start, end;
    start = clock();

    printf("before\n");
    euler808();
    printf("after\n");

    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}