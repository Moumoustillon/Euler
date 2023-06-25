#ifndef TOOLBOX_H
    #define TOOLBOX_H

int max(int a, int b);
int min(int a, int b);

int count_digits(int n);

void display_array(int array[], int size);
void display_array_as_number(int array[], int size);

int dichotomy(int array[], int a, int b, int target);

int is_a_permutation_of_b(int a, int b); // 1 if a and b are permutations of each other
int factorial(int n);

int permutation_ab(int a, int b); // 1 if a and b are permutations of each other
int power(int x, int n); // returns x^n
float power_f(float x, int n);
int prime(int n); // 1 if n is prime
int is_coprime(int a, int b); // 1 if a and b are coprime

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