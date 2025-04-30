#include <iostream>
using namespace std;

// O(n^2)
int* insertion_sort(int* A, int size) {
    int i, j, key;
    
    for (i = 1; i < size; i++)
    {
        j = i - 1;
        key = A[i];

        while (j > -1 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        
        A[j + 1] = key;
    }   

    return A;
}
 
int main() {
    int size, i;
    cin >> size;

    int* A = new int[size];

    for (i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    int* B = insertion_sort(A, size);
    
    for (i = 0; i < size; i++)
    {
        cout << B[i] << " ";
    }

    return 0;
    
}