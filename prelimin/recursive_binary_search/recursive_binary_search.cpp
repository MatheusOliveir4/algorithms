#include <bits/stdc++.h>
using namespace std;

int recursive_binary_search(int* A, int p, int r, int k) {
    if (p <= r) {
        int q = (p + r) / 2;

        if (A[q] == k) {
            return q;
        } else if (A[q] < k ) {
            return recursive_binary_search(A, q + 1, r, k);
        } else {
            return recursive_binary_search(A, p, q - 1, k);
        }
    }

    return -1;
}

int main() {
    int size, i, k;
    cin >> size;

    int* A = new int[size];

    for (i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    
    cin >> k;

    int result = recursive_binary_search(A, 0, size - 1, k);

    cout << result << endl;

    delete[] A;

    return 0;
}