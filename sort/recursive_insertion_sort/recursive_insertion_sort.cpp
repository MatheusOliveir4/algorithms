#include <bits/stdc++.h>
using namespace std;

// O(n)
void insertion(int* A, int n) {
    int key = A[n];
    int i = n - 1;

    while(i >= 0 && A[i] > key) {
        A[i + 1] = A[i];
        i--;
    }

    A[i + 1] = key;
}   

void recursive_insertion_sort(int* A, int n) {
    if (n > 0) {
        recursive_insertion_sort(A, n - 1);
        insertion(A, n);
    }

}

int main() {
    int size, i;
    cin >> size;

    int* A = new int[size];

    for (i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    
    recursive_insertion_sort(A, size - 1);

    for (i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;

    return 0;
}