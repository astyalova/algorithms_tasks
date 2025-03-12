
#include <iostream>
#include <vector>

int min_nominal_value(int x, std::vector<int>& nominal_value) {
    int n = nominal_value.size();
    std::vector<int> dp(x + 1, 9999999);
    dp[0] = 0;
    
    for(int i = 1; i < x + 1; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i >= nominal_value[j]) {
                dp[i] = std::min(dp[i], dp[i - nominal_value[j]] + 1);
            }
        }
    }

    return dp[x] != 9999999 ? dp[x] : -1;
}

int main() {

    int x = 0;
    int k = 0;

    std::cin >> x >> k;

    std::vector<int> nominal_value(k, 0);

    for(int i = 0; i < k; ++i) {
        std::cin >> nominal_value[i];
    }

    std::cout <<  min_nominal_value(x, nominal_value) << std::endl;

}

