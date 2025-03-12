#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
	int n = prices.size();
	int profit = 0;

	for(int i = 1; i < n; ++i) {
    	if(prices[i] > prices[i - 1]) {
           profit += prices[i] - prices[i - 1];
        }
    }
	return profit;
}

int main() {
	int n = 0;

	std::cin >> n;

	std::vector<int> prices(n);

	for(int i = 0; i < n; ++i) {
    	std::cin >> prices[i];
    }

	std::cout << maxProfit(prices);
} 

