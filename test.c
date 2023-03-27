#include <stdio.h>

int is_pandigital(int n) {
    // Returns 1 if n is pandigital, i.e., if it contains all the digits from 1 to 9 exactly once.
    int digits[10] = {0};
    while (n > 0) {
        int digit = n % 10;
        if (digit == 0 || digits[digit] == 1) {
            return 0;
        }
        digits[digit] = 1;
        n /= 10;
    }
    return 1;
}

int main() {
    int largest_pandigital = 0;

    // 3-digit integers
    for (int i = 912; i < 988; i++) {
        int concatenated_product = i * 100002;  // product of i and (1,2)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 100020;  // product of i and (1,2,3)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 100200;  // product of i and (1,2,3,4)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 102003;  // product of i and (1,2,3,4,5)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 120003;  // product of i and (1,2,3,4,5,6)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 120300;  // product of i and (1,2,3,4,5,6,7)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
        concatenated_product = i * 123000;  // product of i and (1,2,3,4,5,6,7,8)
        if (is_pandigital(concatenated_product)) {
            largest_pandigital = (concatenated_product > largest_pandigital) ? concatenated_product : largest_pandigital;
        }
    }
}


