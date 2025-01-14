#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& v) {
    bool is_change = false;
    bool is_sorted = true;

    for (size_t i = 0; i < v.size() - 1; ++i) {
        is_change = false;  
        for (size_t j = 0; j < v.size() - 1 - i; ++j) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                is_change = true; 
                is_sorted = false;
            }
        }

        if (is_change) {
            for (size_t k = 0; k < v.size(); ++k) {
                std::cout << v[k] << " ";
            }
            std::cout << std::endl;
        }
    }
    if (is_sorted) {
            for (size_t k = 0; k < v.size(); ++k) {
                std::cout << v[k] << " ";
            }
            std::cout << std::endl;
        }
}

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<int> sort;

    for (int i = 0; i < n; ++i) {
        int num;
        std::cin >> num;
        sort.push_back(num);
    }

    bubble_sort(sort);  

    return 0;
}
