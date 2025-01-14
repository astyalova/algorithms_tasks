#include <vector>
#include <cassert>
#include <algorithm>
#include <iostream>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftUp(std::vector<int>& heap, int idx) {
    if(idx == 1) {
        return idx;
    }

    int parent_idx = idx/2;
    if(heap[parent_idx] < heap[idx]) {
        std::swap(heap[parent_idx], heap[idx]);
        return siftUp(heap, parent_idx);
    }
    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 6, 8, 3, 15, 7};
    assert(siftUp(sample, 5) == 1);
}


int main() {
    test();
}
#endif