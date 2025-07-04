#include <vector>

#ifndef HEAP_H
#define HEAP_H

using namespace std;

class Heap {
private:
    vector<int> arr;
    int arr_size;
    int heap_length;

public:
    Heap(vector<int> arr, int size);
    ~Heap();

    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void maxHeapify(int i);
    void minHeapify(int i);
    void buildMaxHeap();
    void buildMinHeap();
    int getNode(int i);
    void exchangeNode(int i, int j);
    void printHeap();
    void decrementHeap();
};

#endif