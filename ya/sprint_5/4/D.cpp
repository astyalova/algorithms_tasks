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
	return r1->value == r2->value && dfs(r1->left, r2->left) && dfs(r1->right, r2->right);
}

bool Solution(const Node* root1, const Node* root2) {
	if(root1 == nullptr && root2 == nullptr) {
		return true;
	} 
	return dfs(root1, root2);
} 

#ifndef REMOTE_JUDGE
void test() {

    Node node1({1, nullptr, nullptr});
    Node node2({2, nullptr, nullptr});
    Node node3({3, &node1, &node2});

    Node node4({1, nullptr, nullptr});
    Node node5({2, nullptr, nullptr});
    Node node6({3, &node4, &node5});
    assert(Solution(&node3, &node6));
}

int main() {
  test();
}
#endif