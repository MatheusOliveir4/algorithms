#include "Heap.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

Heap::Heap(vector<int> arr, int size) {
    this->arr = arr;
    this->arr_size = size;
    this->heap_length = size;
}

Heap::~Heap() {
}

int Heap::parent(int i) {
    return floor((i - 1) / 2);
}

int Heap::leftChild(int i) {
    return 2 * i + 1;
}

int Heap::rightChild(int i) {
    return 2 * i + 2;
}

void Heap::decrementHeap() {
    this->heap_length = this->heap_length - 1;
}

int Heap::getNode(int i) {
    return this->arr[i];
}

void Heap::exchangeNode(int i, int j) {
    int aux = this->arr[i];
    this->arr[i] = this->arr[j];
    this->arr[j] = aux;
}

void Heap::printHeap() {
    for (int i = 0; i < heap_length; i++)
    {
        cout << this->arr[i] << " ";
    }
}

void Heap::maxHeapify(int i) {
    int max = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < this->heap_length && this->arr[max] < this->arr[left]) {
        max = left;
    }

    if (right < this->heap_length && this->arr[max] < this->arr[right]) {
        max = right;
    }

    if (max != i) {
        exchangeNode(i, max);
        maxHeapify(max);
    }
}

void Heap::minHeapify(int i) {
    int min = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < this->heap_length && this->arr[min] > this->arr[left]) {
        min = left;
    }

    if (right < this->heap_length && this->arr[min] > this->arr[right]) {
        min = right;
    }

    if (min != i) {
        exchangeNode(i, min);
        minHeapify(min);
    }
}

void Heap::buildMaxHeap() {
    int n = this->heap_length;
    int i = floor((double) n/2) - 1; 

    for (i; i >= 0; i--)
    {
        maxHeapify(i);
    }
}

void Heap::buildMinHeap() {
    int n = this->heap_length;
    int i = floor((double) n/2) - 1; 

    for (i; i >= 0; i--)
    {
        minHeapify(i);
    }
}
