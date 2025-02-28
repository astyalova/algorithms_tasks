/*
https://contest.yandex.ru/contest/24810/run-report/132496581/
-- ПРИНЦИП РАБОТЫ --
 Осуществляется удаление элемента из дерева. Когда удаляется узел, который имеет два потомка, его 
 значение заменяется на минимальное значение в правом поддереве, а затем это минимальное значение 
 удаляется рекурсивно. Если удаляемый узел не имеет потомков, он просто удаляется. Если потомок один, то
 она заменяет узел собой.
-- ДОКАЗАТЕЛЬСТВО КОРРЕКТНОСТИ --
 В функции remove осуществляется рекурсивный поиск узла по ключу. Если ключ найден, то:
 Если у узла нет потомков, он просто удаляется.
 Если у узла есть только один потомок, то он заменяет собой узел.
 Если у узла есть два потомка, его значение заменяется на минимальное значение в правом поддереве, и 
 затем это минимальное значение удаляется.
 В функции `findMinim` происходит поиск минимального значения в правом поддереве.
-- ВРЕМЕННАЯ СЛОЖНОСТЬ --
 В худшем случае, когда дерево сбалансировано временная сложность поиска и удаления элемента составляет
 O(log n), где n количество элементов в дереве. В случае несбалансированного дерева, сложность может
 быть O(n), где n количество элементов.

-- ПРОСТРАНСТВЕННАЯ СЛОЖНОСТЬ --
Пространственная сложность O(h), где h высота дерева.
*/
#ifndef REMOTE_JUDGE
struct Node {  
  int value;  
  Node* left = nullptr;  
  Node* right = nullptr;
  Node(Node* left, Node* right, int value) : value(value), left(left), right(right) {}
};  
#endif
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif
#include <cassert>

Node* removeNode(Node* root);

Node* findMinim(Node* root) {
    while(root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    
    if (key > root->value) {
        root->right = remove(root->right, key);
    } else if (key < root->value) {
        root->left = remove(root->left, key);
    } else {
        root = removeNode(root);
    }
    
    return root;
}

Node* removeNode(Node* root) {
    if (root->right == nullptr) {
        return root->left;
    }
    if (root->left == nullptr) {
        return root->right;
    }
    
    Node* tmp = findMinim(root->right);
    root->value = tmp->value;
    root->right = remove(root->right, tmp->value);
    
    return root;
}


#ifndef REMOTE_JUDGE
void test() {
    Node node1({nullptr, nullptr, 2});
    Node node2({&node1, nullptr, 3});
    Node node3({nullptr, &node2, 1});
    Node node4({nullptr, nullptr, 6});
    Node node5({&node4, nullptr, 8});
    Node node6({&node5, nullptr, 10});
    Node node7({&node3, &node6, 5});
    Node* newHead = remove(&node7, 10);
    assert(newHead->value == 5);
    assert(newHead->right == &node5);
    assert(newHead->right->value == 8);
}

int main() {
  test();
}
#endif