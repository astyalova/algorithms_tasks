#include <iostream>
void Generate_Combination(int n, std::string current, int open_count, int close_count) {
   
    if (current.size() == 2 * n) {
        std::cout << current << '\n';
        return;
    }


    if (open_count < n) {
        Generate_Combination(n, current + "(", open_count + 1, close_count);
    }

    if (close_count < open_count) {
        Generate_Combination(n, current + ")", open_count, close_count + 1);
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    Generate_Combination(n, "", 0, 0);
}