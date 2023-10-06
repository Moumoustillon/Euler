#ifndef TOOLBOX_H
    #define TOOLBOX_H

// data structures ...

typedef struct vector vector;
void display_vector(vector *t);
vector *create_vector(int taille);
void init_vector(vector *t);
int read_vector(vector *t,int indice);
int write_vector(vector *t,int indice, int valeur);



// int, numbers and calculations ...

int max(int a, int b);
unsigned long long max_llu(unsigned long long a, unsigned long long b);

int min(int a, int b);
unsigned long long min_llu(unsigned long long a, unsigned long long b);

int count_digits(int n);
int factorial(int n);
int power(int x, int n); // returns x^n

// float

float power_f(float x, int n);

// number analysis functions ...

int is_n_palindromic(int n); // 1 if n is palindromic, 0 otherwise
int is_a_permutation_of_b(int a, int b); // 1 if a and b are permutations of each other
int is_a_coprime_of_b(int a, int b); // 1 if a and b are coprime
int prime(int n); // 1 if n is prime

// arrays, analysis, sort ...

void display_array(int array[], int size);
void display_array_as_number(int array[], int size);
int dichotomy(int array[], int a, int b, int target);


// SEQUENCES FUNCTIONS
    // triangular numbers :
    int generate_nth_triangular(int n);
    int is_triangular(int num);
    // pentagonal numbers :
    int generate_nth_pentagonal(int n);
    int is_pentagonal(int num);
    // hexagonal numbers :
    int generate_nth_hexagonal(int n);
    int is_hexagonal(int num);
#endif // TOOLBOX_H