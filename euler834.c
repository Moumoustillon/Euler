#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void display_sequence(unsigned long long *array, long size, long N)
{
    long i;
    printf("Sequence(%d) = {", N);
    for (i=0;i<size-1;i++)
    {
        printf("%lu, ", array[i]);
    }
    printf("%lu", array[i]);
    printf("}\n");
}


// Add and Divide
unsigned long long *find_sequence_N(long N, unsigned long long *N_sequence, long size)
{
    long i=0;
    N_sequence[i] = N;
    for (i=1;i<size;i++)
    {
        N_sequence[i] = N_sequence[i-1]+(N+i);
    }
    display_sequence(N_sequence,N*N,N);
    return N_sequence;
}

unsigned long long *find_sequence_S(long N, unsigned long long *S_sequence, long *sizeP)
{
    unsigned long long *N_sequence;
    long sizeN = N*N, i, i_S=0,sizeS = 1;

    // init sequence array
    N_sequence = (unsigned long long*)malloc(sizeof(unsigned long long)*sizeN); // Size N*N 
    if (N_sequence==NULL) exit(EXIT_FAILURE);
    
    N_sequence = find_sequence_N(N, N_sequence, sizeN);
    for (i=1;i<sizeN;i++)
    {
        if(N_sequence[i]%(N+i)==0)
        {
            if(i_S<sizeS)
            {
                S_sequence[i_S] = i;
                i_S++;
            }
            else 
            {
                sizeS += 1;

                S_sequence = (unsigned long long*)realloc(S_sequence,sizeS*sizeof(unsigned long long));
                if (S_sequence==NULL) exit(EXIT_FAILURE);

                S_sequence[i_S] = i;
                i_S++;
            }
        }
    }
    //display_sequence(S_sequence, sizeS, N);
    *sizeP = sizeS;

    free(N_sequence);
    return S_sequence;
}

unsigned long long find_sum_T(long N)
{
    unsigned long long T = 0, *S_sequence;
    long sizeS = 0, i;
    long *sizeP=&sizeS;
    sizeP = &sizeS;

    S_sequence = (unsigned long long*)malloc(sizeof(unsigned long long)*1); // Size 1, realloc later
    if (S_sequence==NULL) exit(EXIT_FAILURE);

    S_sequence=find_sequence_S(N, S_sequence, sizeP);
    for(i=0;i<sizeS;i++)
    {
        T = T+S_sequence[i];
    }

    free(S_sequence);
    return T;
}

unsigned long long find_sum_U(long N)
{
    long n;
    unsigned long long U=0;

    for(n=3;n<=N;n++)
    {
        U += find_sum_T(n);
        printf("U(%li) = %llu\n",n, U);
    }
    
    return U;
}

int main()
{
    clock_t start, end;
    unsigned long long U;
   
    U = find_sum_U(1234567);

    printf("answer : %llu\n", U);


    end = clock();
    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("\nTime taken to execute in seconds : %f\n", duration);
    return EXIT_SUCCESS;
}