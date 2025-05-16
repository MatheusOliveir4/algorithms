#include <bits/stdc++.h>
using namespace std;

// O(n^2)
vector<vector<int>> matrix_sum(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int n,
    int sr_A, int sc_A,
    int sr_B, int sc_B
) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    
    int i, j;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = A[sr_A + i][sc_A + j] + B[sr_B + i][sc_B + j];
        }
    }

    return C;
}

// O(n^2)
vector<vector<int>> matrix_sub(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int n,
    int sr_A, int sc_A,
    int sr_B, int sc_B
) {
    vector<vector<int>> C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            C[i][j] = A[sr_A + i][sc_A + j] - B[sr_B + i][sc_B + j];
        }
    }
    
    return C;
}

// O(n^lg7) 
vector<vector<int>> strassen_method(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int n,
    int sr_A, int sc_A, int sr_B, int sc_B
) {

    if (n == 1) {
        return {{A[sr_A][sc_A] * B[sr_B][sc_B]}};
    }

    int mid = n / 2;

    vector<vector<int>> S1 = matrix_sub(B, B, mid, sr_B, sc_B + mid, sr_B + mid, sc_B + mid);
    vector<vector<int>> S2 = matrix_sum(A, A, mid, sr_A, sc_A, sr_A, sc_A + mid);
    vector<vector<int>> S3 = matrix_sum(A, A, mid, sr_A + mid, sc_A, sr_A + mid, sc_A + mid);
    vector<vector<int>> S4 = matrix_sub(B, B, mid, sr_B + mid, sc_B, sr_B, sc_B);
    vector<vector<int>> S5 = matrix_sum(A, A, mid, sr_A, sc_A, sr_A + mid, sc_A + mid);
    vector<vector<int>> S6 = matrix_sum(B, B, mid, sr_B, sc_B, sr_B + mid, sc_B + mid);
    vector<vector<int>> S7 = matrix_sub(A, A, mid, sr_A, sc_A + mid, sr_A + mid, sc_A + mid);
    vector<vector<int>> S8 = matrix_sum(B, B, mid, sr_B + mid, sc_B, sr_B + mid, sc_B + mid);
    vector<vector<int>> S9 = matrix_sub(A, A, mid, sr_A, sc_A, sr_A + mid, sc_A);
    vector<vector<int>> S10 = matrix_sum(B, B, mid, sr_B, sc_B, sr_B, sc_B + mid);

    vector<vector<int>> P1 = strassen_method(A, S1, mid, sr_A, sc_A, 0, 0);
    vector<vector<int>> P2 = strassen_method(S2, B, mid, 0, 0, sr_B + mid, sc_B + mid);
    vector<vector<int>> P3 = strassen_method(S3, B, mid, 0, 0, sr_B, sc_B);
    vector<vector<int>> P4 = strassen_method(A, S4, mid, sr_A + mid, sc_A + mid, 0, 0);
    vector<vector<int>> P5 = strassen_method(S5, S6, mid, 0, 0, 0, 0);
    vector<vector<int>> P6 = strassen_method(S7, S8, mid, 0, 0, 0, 0);
    vector<vector<int>> P7 = strassen_method(S9, S10, mid, 0, 0, 0, 0);

    vector<vector<int>> C11 = matrix_sum(matrix_sub(matrix_sum(P5, P4, mid, 0, 0, 0, 0), P2, mid, 0, 0, 0, 0), P6, mid, 0, 0, 0, 0);
    vector<vector<int>> C12 = matrix_sum(P1, P2, mid, 0, 0, 0, 0);
    vector<vector<int>> C21 = matrix_sum(P3, P4, mid, 0, 0, 0, 0);
    vector<vector<int>> C22 = matrix_sub(matrix_sub(matrix_sum(P5, P1, mid, 0, 0, 0, 0), P3, mid, 0, 0, 0, 0), P7, mid, 0, 0, 0, 0);
    
    vector<vector<int>> C(n, vector<int>(n));
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

    vector<vector<int>> C = strassen_method(A, B, n, 0, 0, 0, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}