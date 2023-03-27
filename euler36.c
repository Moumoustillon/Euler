#include <stdio.h>
#include <stdlib.h>

int is_palindrome(int n) {
    int reverse = 0, ncopy = n;
    while (ncopy != 0) {
        reverse = reverse * 10 + ncopy % 10;
        ncopy /= 10;
    }
    return (n == reverse);
}

void reverse_array(int arr[], int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int is_palindrome_base2(int n) {
    int binary[32] = {0};
    int size = 0;
    while (n > 0) {
        binary[size++] = n % 2;
        n /= 2;
    }
    reverse_array(binary, size);
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        if (binary[i] != binary[j]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if (is_palindrome(i) && is_palindrome_base2(i)) {
            sum += i;
        }
    }
    printf("Sum of palindromic numbers in both base 10 and base 2: %d\n", sum);
    return EXIT_SUCCESS;
}
