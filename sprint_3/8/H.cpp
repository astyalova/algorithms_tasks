#include <iostream>
#include <vector>

bool compare(std::string a, std::string b) {
    return a+b > b+a;
}

void biggest(std::vector <std::string>& v, bool (*more)(std::string, std::string)) {
    for(int i = 1; i <v.size(); ++i) {
        std::string item_insert = v[i];
        int j = i;
        while(j > 0 && more(item_insert, v[j-1])) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = item_insert;
    }
}

int main() {
	int n = 0;
	std::cin >> n;
	std::vector <std::string> numbers(n);

	for(int i = 0; i < n; ++i) {
    std::cin >> numbers[i];
	}

    biggest(numbers, compare);
    for(int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
    }
    return 0;
}