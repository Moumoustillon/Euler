#ifndef TOOLBOX_H
    #define TOOLBOX_H

void display_array(int array[], int size);
void display_array_as_number(int array[], int size);

int permutation_ab(int a, int b); // 1 if a and b are permutations of each other
int power(int n); // returns n^2
int prime(int n); // 1 if n is primex

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