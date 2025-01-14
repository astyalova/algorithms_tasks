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

int check_balance(const Node* root) {
		if(root == nullptr) {
		return 0;
	}
	int l = 0, r = 0;

	l = check_balance(root->left);
	if(l == -1) {return -1;}

	r = check_balance(root->right);
	if(r == -1) {return -1;}

	if(abs(l-r) > 1) {
		return -1;
	}
	return std::max(l, r) + 1;
}


bool Solution(const Node* root) {
	return check_balance(root) != -1;
} 


#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({10, nullptr, nullptr});
    Node node5({2, &node3, &node4});
    assert(Solution(&node5));
}

int main() {
  test();
}
#endif