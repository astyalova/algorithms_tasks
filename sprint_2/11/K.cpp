#include <iostream>

int count_commits(int x) {
    if(x == 1 || x == 0) {
        return 1;
    }
    return count_commits(x-1)+count_commits(x-2);
}


int main() {
    int x = 0;
    std::cin>>x;
    std::cout << count_commits(x);
}