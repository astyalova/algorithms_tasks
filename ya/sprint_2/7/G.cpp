#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class StackMaxEffective {
private:
    std::vector <int> stack;
    std::vector <int> max_stack;
public:

    void push(int x) {
        if(max_stack.empty() || x >= max_stack.back()) {
            max_stack.push_back(x);
        }
        stack.push_back(x);
    }

    void pop() {
        if(isEmpty()) {
            std::cout << "error" << '\n';
        } else {
            if(stack.back() == max_stack.back())
            max_stack.pop_back();
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
            std::cout << max_stack.back() << '\n';
        }
    }

    void top() {
         if(isEmpty()) {
            std::cout << "error" << '\n';
        } else {
        std::cout << stack.back() << '\n';
        }
    }
};
 int main() {
    StackMaxEffective stack;
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
        } else if(command == "top") {
            stack.top();
        }
    }
 }

