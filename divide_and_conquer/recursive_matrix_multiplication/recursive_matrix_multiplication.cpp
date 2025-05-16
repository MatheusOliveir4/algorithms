#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_sum(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int n
) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    return C;
}

//O(n^3)
vector<vector<int>> recursive_matrix_multiplication(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int n, 
    int sr_A, int sc_A, int sr_B, int sc_B
) {

    if (n == 1) {
        return {{A[sr_A][sc_A] * B[sr_B][sc_B]}};
    }

    int mid = n / 2;

    vector<vector<int>> C11 = matrix_sum(recursive_matrix_multiplication(A, B, mid, sr_A, sc_A, sr_B, sc_B), recursive_matrix_multiplication(A, B, mid, sr_A, sc_A + mid, sr_B + mid, sc_B), mid);
    vector<vector<int>> C12 = matrix_sum(recursive_matrix_multiplication(A, B, mid, sr_A, sc_A, sr_B, sc_B + mid), recursive_matrix_multiplication(A, B, mid, sr_A, sc_A + mid, sr_B + mid, sc_B + mid), mid);
    vector<vector<int>> C21 = matrix_sum(recursive_matrix_multiplication(A, B, mid, sr_A + mid, sc_A, sr_B, sc_B), recursive_matrix_multiplication(A, B, mid, sr_A + mid, sc_A + mid, sr_B + mid, sc_B), mid);
    vector<vector<int>> C22 = matrix_sum(recursive_matrix_multiplication(A, B, mid, sr_A + mid, sc_A, sr_B, sc_B + mid), recursive_matrix_multiplication(A, B, mid, sr_A + mid, sc_A + mid, sr_B + mid, sc_B + mid), mid);

    vector<vector<int>> C(n, vector<int>(n, 0));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + mid] = C12[i][j];
            C[i + mid][j] = C21[i][j];
            C[i + mid][j + mid] = C22[i][j];
        }
    }
    
    return C;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> A(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = recursive_matrix_multiplication(A, B, n, 0, 0, 0, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}