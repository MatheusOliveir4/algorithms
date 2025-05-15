#include <bits/stdc++.h>
using namespace std;

struct Subarray {
    int low;
    int high;
    int sum;
};

Subarray* find_max_crossing_subarray(int* A, int low, int mid, int high) {
    int left_sum = A[mid];
    int sum = A[mid];
    int max_left = mid;

    for (int i = mid - 1; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = A[mid + 1];
    sum = A[mid + 1];
    int max_right = mid + 1;

    for (int i = mid + 2; i <= high; i++) {
        sum += A[i];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }

    Subarray* cross_subarray = new Subarray();
    cross_subarray->low = max_left;
    cross_subarray->high = max_right;
    cross_subarray->sum = left_sum + right_sum;

    return cross_subarray;
}

Subarray* find_max_subarray(int* A, int low, int high) {
    if (low == high) {
        Subarray* min_subarray = new Subarray();
        min_subarray->low = low;
        min_subarray->high = high;
        min_subarray->sum = A[low];
        return min_subarray;
    }

    int mid = (low + high) / 2;
    Subarray* L = find_max_subarray(A, low, mid);
    Subarray* R = find_max_subarray(A, mid + 1, high);
    Subarray* C = find_max_crossing_subarray(A, low, mid, high);

    if (L->sum >= R->sum && L->sum >= C->sum) {
        delete R;
        delete C;
        return L;
    } else if (R->sum >= L->sum && R->sum >= C->sum) {
        delete L;
        delete C;
        return R;
    } else {
        delete L;
        delete R;
        return C;
    }
}

int main() {
    int size;
    cin >> size;

    int* A = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> A[i];
    }

    Subarray* subarray = find_max_subarray(A, 0, size - 1);
    cout << subarray->low << " " << subarray->high << " " << subarray->sum << endl;

    delete[] A;
    delete subarray;

    return 0;
}
