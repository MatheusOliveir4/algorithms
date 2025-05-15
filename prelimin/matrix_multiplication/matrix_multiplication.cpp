#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_multiplication(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    int rows_A, int columns_A, int columns_B
) {
    vector<vector<int>> C(rows_A, vector<int>(columns_B, 0));

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < columns_B; ++j) {
            for (int k = 0; k < columns_A; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

int main() {
    int rows_A, columns_A, rows_B, columns_B;
    cin >> rows_A >> columns_A >> rows_B >> columns_B;

    vector<vector<int>> A(rows_A, vector<int>(columns_A));
    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < columns_A; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(rows_B, vector<int>(columns_B));
    for (int i = 0; i < rows_B; ++i) {
        for (int j = 0; j < columns_B; ++j) {
            cin >> B[i][j];
        }
    }

    vector<vector<int>> C = matrix_multiplication(A, B, rows_A, columns_A, columns_B);

    for (int i = 0; i < rows_A; ++i) {
        for (int j = 0; j < columns_B; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
