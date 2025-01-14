#ifndef REMOTE_JUDGE
struct Node {  
  int value;  
  const Node* left = nullptr;  
  const Node* right = nullptr;
  Node(int value, Node* left, Node* right) : value(value), left(left), right(right) {}
};  
#endif

#ifdef REMOTE_JUDGE
#include "solution_tree.h"
#endif
#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

int max_path;

int dfs(const Node* root) {

	if(root == nullptr) {
  		return 0;
    }

	int l_s = std::max(0, dfs(root->left));
    int r_s = std::max(0, dfs(root->right));

    max_path = std::max(max_path, l_s + r_s + root->value);
    
    return std::max(l_s, r_s) + root->value;
}

int Solution(const Node* root) {
	max_path = INT_MIN;
	dfs(root);
	return max_path;
} 

#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({8, nullptr, nullptr});
    Node node5({5, &node3, &node4});
    assert(Solution(&node5) == 20);
}


int main() {
  test();
}
#endif