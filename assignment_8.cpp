#include <iostream>
#include <limits.h>

using std::cout;
using std::endl;
using std::cin;


void getMaxMinRow(int** matrix, int row, int col, int** maxRowPtrPtr, int** minRowPtrPtr);
void displayMatrix(int** matrix, int row, int col);
void swapRow(int* a, int* b, int col);

int main(){
    int** matrix;
    int row, col;
    int num;

    std::cin >> row >> col;

    //TODO
    /*Allocate memory to matrix*/
    matrix = new int *[row];

    for (int i = 0; i < row; i++) {
        matrix[i] = new int [col];
    }
    //TODO
    /*Fill matrix with given input*/
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> num;
            matrix[i][j] = num;
        }
    }
    /*
    for (int i = 0; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
    */

    int *maxRowPtr, *minRowPtr;
    std::cout << "---Before Swap Max Min---" << std::endl;
    displayMatrix(matrix, row, col);
    getMaxMinRow(matrix, row, col, &maxRowPtr, &minRowPtr);

    swapRow(maxRowPtr, minRowPtr, col);
    std::cout << "---After Swap Max Min---"<< std::endl;
    displayMatrix(matrix, row, col);

    return 0;

}

void getMaxMinRow(int** matrix, int row, int col, int** maxRowPtrPtr, int** minRowPtrPtr){
    int sum_max = INT_MIN, sum_min = INT_MAX;
    //TODO
    for (int i = 0; i < row; i++) {
        int sum = 0;
        for (int j = 0; j < col; j++) {
            sum += matrix[i][j];
        }
        if (sum_max < sum) {
            sum_max = sum;
            *maxRowPtrPtr = matrix[i];
        }
        if (sum_min > sum) {
            sum_min = sum;
            *minRowPtrPtr = matrix[i];
        }
    }
    
}

void displayMatrix(int** matrix, int row, int col){
    //TODO
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j == col - 1) {
                cout << matrix[i][j];
            }
            else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
};

void swapRow(int* a, int* b, int col){
    //TODO
    for (int i = 0; i < col; i++) {
        int temp;
        temp = b[i];
        b[i] = a[i];
        a[i] = temp;
    }
    
}