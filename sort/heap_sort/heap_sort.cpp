#include <iostream> 
#include "../../data_structures/heap/Heap.h"
using namespace std;

vector<int>& heapSort(vector<int>& arr, int n) {
    Heap maxHeap(arr, n);
    maxHeap.buildMaxHeap();

    int size = n - 1;

    for (int i = size; i > 0; i--)
    {
        maxHeap.exchangeNode(0, i);
        arr[i] = maxHeap.getNode(i); 
        maxHeap.decrementHeap();
        maxHeap.maxHeapify(0);
    }

    arr[0] = maxHeap.getNode(0);

    return arr;
} 

int main() {
    vector<int> arr;
    int n, v, i;

    cin >> n;

    for (i = 0; i < n; i++)
    {
        cin >> v;
        arr.push_back(v);
    }

    arr = heapSort(arr, n);
    
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}