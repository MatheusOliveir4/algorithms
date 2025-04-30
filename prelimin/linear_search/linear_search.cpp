#include <iostream>
using namespace std;

int linear_search(int* A, int size, int k) {
    int i;

    for (i = 0; i < size; i++)
    {
        if (A[i] == k) {
            return i;
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

    res = linear_search(A, size, k);

    cout << res << endl;

}