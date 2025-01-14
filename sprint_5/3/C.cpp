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

bool dfs(const Node* r1, const Node* r2) {
	if(r1 == nullptr && r2 == nullptr) {
		return true;
	}

	if(r1 == nullptr || r2 == nullptr) {
		return false;
	}

	return r1->value == r2->value && dfs(r1->left, r2->right) && dfs(r2->left, r1->right);
}

bool Solution(const Node* root) {
	if(root == nullptr) {
		return true;
	}
	return dfs(root->left, root->right);
} 

#ifndef REMOTE_JUDGE
void test() {
    Node node1({3, nullptr, nullptr});
    Node node2({4, nullptr, nullptr});
    Node node3({4, nullptr, nullptr});
    Node node4({3, nullptr, nullptr});
    Node node5({2, &node1, &node2});
    Node node6({2, &node3, &node4});
    Node node7({1, &node5, &node6});
    assert(Solution(&node7));
}


int main() {
  test();
}
#endif