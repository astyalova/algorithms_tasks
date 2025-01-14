#include <iostream>
#include <vector>

int buy_bicycle(std::vector <int> v, int cost, int left, int right) {
    if(left >= right) {
        return (v[left] >= cost) ? left + 1 : -1;
    } 
    int mid = left + (right-left)/2;
    if(v[mid] >= cost) {
        return buy_bicycle(v, cost, left, mid);
    } else {
        return buy_bicycle(v, cost, mid + 1, right);
    }
}

int main() {
    int n =  0;
    std::cin >> n;

    std::vector <int> money;
    for(int i = 0; i < n; ++i) {
        int num = 0;
        std::cin >> num;
        money.push_back(num);
    }
    int cost = 0;
    std::cin >> cost;

    int first = buy_bicycle(money, cost, 0, n-1);
    int second = buy_bicycle(money, cost*2, 0, n-1);

    std::cout << first << " " << second << '\n';
    return 0;
}