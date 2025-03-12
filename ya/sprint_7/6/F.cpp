
#include <iostream>
#include <vector>

const int MOD = 1000000007;

int jumps_count(int n, int k) {
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;

    int sum = dp[1];

    for(int i = 2; i <=n; ++i) {
        dp[i] = sum;

        sum = (sum  + dp[i]) % MOD;

        if(i - k >= 1) {
            sum = (sum - dp[i - k] + MOD) % MOD;
        }
    }

    return dp[n];
}

int main() {

    int n = 0, k;

    std::cin >> n >> k;
    
    std::cout << jumps_count(n, k);

}