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


int Solution(const Node* root) {
  if(root == nullptr) {
    return 0;
  }
  int res = root->value;
  int left_max = Solution(root->left);
  int right_max = Solution(root->right);

  if(res < left_max) {
    res = left_max;
  }

  if(res < right_max) {
    res = right_max;
  }
    return res;
}

#ifndef REMOTE_JUDGE
void test() {
    Node node1({1, nullptr, nullptr});
    Node node2({-5, nullptr, nullptr});
    Node node3({3, &node1, &node2});
    Node node4({2, &node3, nullptr});
    assert(Solution(&node4) == 3);
}

int main() {
  test();
}
#endif