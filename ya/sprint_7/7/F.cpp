
#include <iostream>
#include <vector>

int max_nominal_value(int x, std::vector<int>& nominal_value) {
    std::vector<int> dp(x + 1, 0);  
    dp[0] = 1;  

    for (int coin : nominal_value) {  
        for (int i = coin; i <= x; ++i) {  
            dp[i] += dp[i - coin];  
        }
    }

    return dp[x];
}

int main() {

    int x = 0;
    int k = 0;

    std::cin >> x >> k;

    std::vector<int> nominal_value(k, 0);

    for(int i = 0; i < k; ++i) {
        std::cin >> nominal_value[i];
    }

    std::cout <<  max_nominal_value(x, nominal_value) << std::endl;

}

