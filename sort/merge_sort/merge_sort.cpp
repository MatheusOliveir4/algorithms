#include <bits/stdc++.h>
using namespace std;

// O(n)
void merge(int* A, int p, int q, int r) {
    int i, j, k;
    
    int n1 = q - p + 1;
    int n2 = r - q;
    
    int* B = new int[n1];
    int* C = new int[n2];

    for (i = 0; i < n1; i++)
    {
        B[i] = A[p + i];
    }

    for (i = 0; i < n2; i++)
    {
        C[i] = A[q + 1 + i];
    }

    j = 0;
    k = 0;
    i = p;

    while (j < n1 && k < n2) {
        if (B[j] <= C[k]) {
            A[i++] = B[j++];
        } else {
            A[i++] = C[k++];
        }
    }

    while (j < n1) {
        A[i++] = B[j++];
    }

    while (k < n2) {
        A[i++] = C[k++];
    }

    delete[] B;
    delete[] C;
}

//O(n lg n)
void merge_sort(int* A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
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
    
    merge_sort(A, 0, size - 1);

    for (i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    delete[] A;

    return 0;
}