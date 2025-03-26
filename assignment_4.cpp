#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const int MAX_SIZE = 100;

void read_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size);

void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size);

void matrix_mul(int mat_A[MAX_SIZE][MAX_SIZE], int mat_A_row_size,
                int mat_A_col_size, int mat_B[MAX_SIZE][MAX_SIZE],
                int mat_B_row_size, int mat_B_col_size,
                int scores[MAX_SIZE][MAX_SIZE]);
int isWin(int A, int B);

int main() {
    int mat_A_row_size, mat_A_col_size;
    int mat_B_row_size, mat_B_col_size;

    int mat_A[MAX_SIZE][MAX_SIZE];
    int mat_B[MAX_SIZE][MAX_SIZE];
    int scores[MAX_SIZE][MAX_SIZE] = {
        0,
    };

    cin >> mat_A_row_size >> mat_A_col_size;
    cin >> mat_B_row_size >> mat_B_col_size;

    read_matrix(mat_A, mat_A_row_size, mat_A_col_size);

    read_matrix(mat_B, mat_B_row_size, mat_B_col_size);

    cout << "[A matrix]" << endl;
    print_matrix(mat_A, mat_A_row_size, mat_A_col_size);
    cout << "[B matrix]" << endl;
    print_matrix(mat_B, mat_B_row_size, mat_B_col_size);

    matrix_mul(mat_A, mat_A_row_size, mat_B_row_size, mat_B, mat_B_row_size,
               mat_B_col_size, scores);
    cout << "[Score matrix]" << endl;
    print_matrix(scores, mat_A_row_size, mat_B_col_size);

    return 0;
}

// your code starts here!

void read_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size) {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            cin >> mat[i][j];
        }
        // cout << endl;
    }
}

void print_matrix(int mat[MAX_SIZE][MAX_SIZE], int row_size, int col_size) {
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            cout << mat[i][j] << " ";
            /*
            if (!(j == col_size - 1)) {
                cout << " ";
            }
            */
        }
        cout << endl;
    }
}

void matrix_mul(int mat_A[MAX_SIZE][MAX_SIZE], int mat_A_row_size,
                int mat_A_col_size, int mat_B[MAX_SIZE][MAX_SIZE],
                int mat_B_row_size, int mat_B_col_size,
                int scores[MAX_SIZE][MAX_SIZE]) {
                    // mat_A_col_size = mat_B_row_size
                    int result = 0;
                    for (int i = 0; i < mat_A_row_size; i++) {
                        for (int j = 0; j < mat_B_col_size; j++) {
                            for (int k = 0; k < mat_A_col_size; k++) {
                                result += isWin(mat_A[i][k], mat_B[k][j]);
                            }
                            scores[i][j] = result;
                            result = 0;
                        }
                    }
                }

int isWin(int A, int B) {
    if (A == B) {
        return 0;
    }
    else if (A - B == 1 || (A == 1 && B == 3)) {
        return 1;
    }
    else {
        return -1;
    }
}

// your code ends here!