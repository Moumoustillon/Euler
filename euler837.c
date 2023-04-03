#include <stdio.h>

#define MOD 1234567891

int main() {
    int m, n;
    long long dp[4][1000005] = {0}; // use a smaller 2D array
    
    dp[0][0] = 1;
    for (m = 0; m <= 3; m++) {
        for (n = 0; n <= 987654321; n++) { // only compute up to n = 987654321
            if (m > 0) {
                dp[m%4][n] = dp[(m-1)%4][n];
                if (n > 0) {
                    dp[m%4][n] += dp[(m-1)%4][n-1];
                    dp[m%4][n] %= MOD;
                    dp[m%4][n] += dp[m%4][n-1] * 2;
                    dp[m%4][n] %= MOD;
                }
            } else if (n > 0) {
                dp[m%4][n] = dp[m%4][n-1];
            }
        }
    }
    printf("%lld\n", dp[3][987654321]); // print the result
    return 0;
}
