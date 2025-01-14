#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StackMax{
private:
    std::vector <int> stack;
public:

    void push(int x) {
        stack.push_back(x);
    }

    void pop() {
        if(isEmpty()) {
            std::cout << "error" << '\n';
        } else {
        stack.pop_back();
        }
    }

    bool isEmpty() {
        if(stack.empty()) {
            return true;
        }
        return false;
    }

    void get_max() {
        if(isEmpty()) {
            std::cout << "None" << '\n';
        } else {
            int max = *std::max_element(stack.begin(), stack.end());
            std::cout << max << '\n';
        }
    }
};
 int main() {
    StackMax stack;
    int n = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
        if(command == "push") {
            int x = 0;
            std::cin >> x;
            stack.push(x);
        } else if( command == "pop") {
            stack.pop();
        } else if(command == "get_max") {
            stack.get_max();
        }
    }
 }

