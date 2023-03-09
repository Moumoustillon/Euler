#include<stdio.h>
#include<stdlib.h>
#include<math.h>


// Amicable Numbers (21)
void euler21()
{
    long long a, b, da=0, db=0, i, sum=0;
   
    
    // d(a)
    for(a=2;a<10000;a++)
    {
        da = 0;
        printf("a = %d ->", a);
        for(i=1;i<a;i++)
        {
            if(a%i==0)
            {
                da = da+i;
                printf("%d, ", i);
            }
        }
        printf("\nd(a)=%d\n", da);
        
        b = da;
        db = 0;
        printf("b = %d ->", b);
        for(i=1;i<b;i++)
        {
            if(b%i==0)
            {
                db = db+i;
                printf("%d, ", i);
            }
        }
        printf("\nd(b)=%d\n\n", db);

        if (db == a)
        {
            if (a!=b)
            {
                if (b<10000)
                {
                    sum = sum+a+b;
                    printf("%d and %d are amicable numbers\n\n", a, b);
                }
            }
        }



    }
    
    printf("amicable numbers sum : %d\n", sum);
    printf("amicable numbers sum/2 : %d\n", sum/2);
}

// Name scores
    // 5 163 names
void display_matrix(char matrix[][50], int d1, int d2)
{
    int i, j;
    for(i=0;i<5163;i++)
    {
        j=0;
        while(matrix[i][j] != '\0')
        {
            printf("%c", matrix[i][j]);
            j++;
        }
        printf("\n");
        
    }
}
void euler22(char names[][50])
{
    int t_score=0, score, pos, letter;
    for (pos=0; pos<5163;pos++)
    {
        score = 0;
        letter = 0;
        while (names[pos][letter] != '\0')
        {
            score = score+(int)(names[pos][letter])-64;
            letter++;
        }
        score = score*(pos+1);
        t_score = t_score+score;
        printf("%d\n",t_score);
    }
    printf("answer : %d\n", t_score);
}

// non-abundant sum
int is_abundant(int n)
{
    int i, sum = 0;
    for(i=1;i<=n/2;i++)
    {
        if(n%i==0)
        {
            sum = sum+i;
        }
    }
    if(sum>n)
    {
        return 1;
    }
    return 0;
}
void euler23()
{
    int n, result=0, i, check=0;

    for(n=1;n<=28123;n++)
    {
        check=0;
        for(i=1;i<n;i++)
        {
            if (is_abundant(i)==1)
            {
                if(is_abundant(n-i)==1)
                {
                    check=1;
                    printf("%d+%d=%d -> abundant sum\n", i, n-i, n);
                    break;
                }
            }
        }
        if (check==0)
        { 
            result = result + n;
            printf("result=%d, n=%d\n", result, n);
        }
    }
    printf("result : %d\n", result);
}

// Lexicographic permutations
    // 2783915460

// 1000-digit Fibonacci number
void display_array(int a[], int size)
{
    int i;
    for(i=size-1;i>=0;i--)
    {
        if(a[i]>=0) printf("%d|", a[i]);
    }
    printf("\n");
}
void init_tab(int tab[], int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        tab[i] = -1;
    }
}
void euler25()
{
    int fibo[1000], fibo1[1000], fibo2[1000];
    int i=0, index = 2, r = 0, stop=0,size=0, j;
    int t, t1, t2;

    init_tab(fibo,1000);
    init_tab(fibo1,1000);
    init_tab(fibo2,1000);

    fibo[0] = 1;
    fibo1[0] = 1;
    fibo2[0] = 1;

    while(stop==0)
    {
        i = 0;
        index++;
        r = 0;
        while(fibo[i] != -1)
        {
            if(fibo2[i] != -1)
            {
                fibo[i] = fibo1[i]+fibo2[i]+r;
                r = fibo[i]/10;
                fibo[i] = fibo[i]%10;
                
                if (i>size) size = i;
                i++;
            }
            else 
            {
                fibo[i] = fibo1[i]+r;
                r = fibo[i]/10;
                fibo[i] = fibo[i]%10;
                
                if (i>size) size = i;
                i++;
            }
        }
        
        if (r>=1)
        {
            fibo[i] = r;
            if (i>size) size = i;
        }

        for(j=0;j<1000;j++)
        {
            fibo2[j] = fibo1[j];
            fibo1[j] = fibo[j];
        }
        if (size>=999) stop = 1;
        display_array(fibo,size+1);
        printf(" | index=%d, size=%d\n", index, size+1);
    }

}

// Reciprocal cycles
int max(int a, int b)
{
    if (a>b) return a;
    return b;
}
int generate_digits(int b)
{
    int a=1, digits = 0;
    printf("\n%d/%d = ", a, b);
    do{
        printf("%d", a*10/b);
        a = a*10%b;
        digits++;
    } while(a!=1);
    return digits;
}
void euler26(int primes[])
{
    int i, digits, maxi=0, result;
    for(i=0;i<165;i++)
    {
        digits = generate_digits(primes[i]);
        maxi = max(maxi, digits);
        if (maxi == digits) result = primes[i];
    }
    printf("\nmax cycle = %d\n", maxi);
    printf("d = %d\n", result);
}

// Quadratic Primes
int prime(int n)
{
    int i;

    if(n<=1) return 0;
    if(n==2) return 1;

    for (i=3;i<sqrt(n);i++)
    {
        if (n%i == 0)return 0;
    }
    return 1;
}

void euler27()
{
    int a, b, n, max_p_sequence = 0, sequence = 0, res, max_n=-1;
    int results[3];

    for(a=-999;a<1000;a++)
    {
        for(b=-1000;b<=1000;b++)
        {
            for(n=0;n<=4000000;n++)
            {
                res = (n*n)+(n*a)+b;
                if (prime(res)==1)
                {
                    sequence = sequence+1;
                }
                else break;
            }
            max_p_sequence = max(max_p_sequence, sequence);
            printf("max = %d\n", max_p_sequence);
            if (max_p_sequence == sequence)
            {
                results[0]=n;
                results[1]=a;
                results[2]=b;
            }
            sequence = 0;
        }
    }
    printf("longest sequence : n=%d, a=%d, b=%d\n", results[0], results[1], results[2]);
    printf("a*b = %d\n", results[1]*results[2]);
}

// Number spiral diagonals
void euler28()
{
    int i, j, n = 1, res = 1;
    for(i=2;i<=1001;i = i+2)
    {
        for(j=1;j<=4;j++)
        {
            n = n+i;
            res = res+n;
        }
    }
    printf("result : %d\n", res);
}

// Distinct powers
int **init_matrix(int width, int height)
{
    int i, j;
    int **matrix;

    matrix=(int**)malloc(sizeof(int*)*width);
    if(matrix==NULL)
    {
        exit(EXIT_FAILURE);
    }

    for(i=0;i<width;i++)
    {
        matrix[i]=(int*)malloc(sizeof(int)*height);
        if(matrix==NULL)
        {
            exit(EXIT_FAILURE);
        }
    }
    return matrix;
}

int *init_array(int size)
{
    int *array;

    array=(int*)malloc(sizeof(int)*size);
    if (array==NULL)
    {
        exit(EXIT_FAILURE);
    }
    return array;
}

void set_array(int *array, int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        array[i]=-1;
    }
}

int nb_digits(int a)
{
    int nb = 0;
    while(a!=0)
    {
        nb = nb+1;
        a = a/10;
    }
    return nb;
}
void power(int *array, int a, int b, int size)
{
    int i, remain, d, j, cm = a;

    // count digits in a
    d = nb_digits(a);

    // set array with -1
    set_array(array, size);

    // set array to first number
    i = 0;
    while(cm!=0)
    {
        array[i] = cm%10;
        cm = cm/10;
        i++;
    }

    // multiplicating
    for (i=2;i<=b;i++)
    {
        j = 0;
        remain = 0;

        while(array[j]!=-1)
        {
            array[j] = array[j]*a+remain;
            remain = array[j]/10;
            array[j] = array[j]%10;
            j++;
        }
        while(remain>0)
        {
            array[j] = remain%10;
            remain = remain/10;
            j++;
        }
    }
    display_array(array, size);
}

int unique(int **matrix, int size_array, int index)
{
    int i, j, unique = 0;

    for(i=0;i<index;i++)
    {
        for(j=0;j<size_array;j++)
        {
            if (matrix[i][j]!=matrix[index][j])
            {
                unique = unique+1;
                break;
            }
        }
    }
    if(unique==index) return 1;
    return 0;
}

void euler29()
{
    int **matrix;
    int a, b, distinct = 0, i = 0;

    matrix = init_matrix(9801, 205);

    for (a=2;a<=100;a++)
    {
        for(b=2;b<=100;b++)
        {
            power(matrix[i], a, b, 205);
            distinct = distinct + unique(matrix, 205, i);
            i++;
        }
    }

    printf("result : %d\n", distinct);
    free(matrix);
}



int main()
{
    euler29();
    return 0;
}