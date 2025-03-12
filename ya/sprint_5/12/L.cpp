#include <vector>
#include <cassert>
#ifdef REMOTE_JUDGE
#include "solution.h"
#endif


int siftDown(std::vector<int>& heap, int idx) {
    int l = 2 * idx;
    int r = 2 * idx + 1;

    if(l >= heap.size()) {
        return idx;
    }
    int larg_idx = l;

    if(r < heap.size() && heap[r] > heap[l]) {
        larg_idx = r;
    }

    if(heap[larg_idx] > heap[idx]) {
        std::swap(heap[larg_idx], heap[idx]);
        return siftDown(heap, larg_idx);
    }

    return idx;
}

#ifndef REMOTE_JUDGE
void test() {
    std::vector<int> sample = {-1, 12, 1, 8, 3, 4, 7};
    assert(siftDown(sample, 2) == 5);
}


int main() {
    test();
}
#endif