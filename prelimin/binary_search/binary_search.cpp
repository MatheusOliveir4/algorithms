#include <iostream>
using namespace std;

// O(lg n) -> We are considering that the array it's already sort
int binary_search(int* A, int size, int k) {
    int low, high, mid;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == k) {
            return mid;
        } else if (A[mid] < k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    return -1;
}

int main() {
    int size, k, i, res;
    cin >> size;

    int* A = new int[size];

    for (i = 0; i < size; i++)
    {
        cin >> A[i];
    }
    
    cin >> k;

    res = binary_search(A, size, k);
    cout << res << endl;

    return 0;
}