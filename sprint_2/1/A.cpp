#include <iostream>

int main() {
    int n = 0, m = 0;
    std::cin >> n >> m;
    int matrix[n][m];
    for(int i = 0; i < n; ++i) {
	    for(int j = 0; j < m; ++j) {
    	    std::cin>> matrix[i][j];
        }
    }
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cout << matrix[j][i] << ' ';
        }
        std::cout << '\n';
    }
} 