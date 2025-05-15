#include <bits/stdc++.h>
using namespace std;

struct Subarray {
    int low;
    int high;
    int sum;
};

// O(n^2)
Subarray* find_max_subarray_bruteforce(int* A, int low, int high) {
    int max_sum = A[low];
    int max_low = 0;
    int max_high = 0;

    int i, j, sum = A[low];

    for (i = 0; i < high; i++)
    {
        for (j = i + 1; j < high; j++)
        {
            sum += A[j];
            if (sum > max_sum) {
                max_sum = sum;
                max_low = i;
                max_high = j;
            }
        }

        sum = A[i + 1];
    }

    Subarray* max_subarray = new Subarray();
    max_subarray->low = max_low;
    max_subarray->high = max_high;
    max_subarray->sum = max_sum;

    return max_subarray;
}

int main() {
    int size;
    cin >> size;

    int* A = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }

    Subarray* subarray = find_max_subarray_bruteforce(A, 0, size - 1);
    cout << subarray->low << " " << subarray->high << " " << subarray->sum << endl;

    delete[] A;
    delete subarray;

    return 0;
}