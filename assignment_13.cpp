#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Matrix {
public:
    Matrix(int **a, int rows, int cols);
    int **getArray() const;
    void displayMatrix() const;
    //TODO
    /*Declare neceessary functions in class definition.*/
    int getrows_() const;
    int getcols_() const;

private:
    int rows_, cols_;
    int **array;
};

Matrix::Matrix(int **array, int rows_, int cols):array(array), rows_(rows_), cols_(cols) {}

int **Matrix::getArray() const {
    return array;
}

int Matrix::getrows_() const {
    return rows_;
}

int Matrix::getcols_() const {
    return cols_;
}

const Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    int **temp;
    temp = new int *[matrix1.getrows_()];
    for (int k = 0; k < matrix1.getrows_(); k++) {
        temp[k] = new int[matrix1.getcols_()];
    }
    for (int i = 0; i < matrix1.getrows_(); i++) {
        for (int j = 0; j < matrix1.getcols_(); j++) {
            temp[i][j] = matrix1.getArray()[i][j] + matrix2.getArray()[i][j];
        }
    }
    return Matrix(temp, matrix1.getrows_(), matrix1.getcols_());
}

const Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    int **temp;
    temp = new int *[matrix1.getrows_()];
    for (int k = 0; k < matrix1.getrows_(); k++) {
        temp[k] = new int[matrix1.getcols_()];
    }
    for (int i = 0; i < matrix1.getrows_(); i++) {
        for (int j = 0; j < matrix1.getcols_(); j++) {
            temp[i][j] = matrix1.getArray()[i][j] - matrix2.getArray()[i][j];
        }
    }
    return Matrix(temp, matrix1.getrows_(), matrix1.getcols_());
}

const Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    int **temp;
    temp = new int *[matrix1.getrows_()];
    for (int k = 0; k < matrix1.getrows_(); k++) {
        temp[k] = new int[matrix1.getcols_()];
    }
    for (int i = 0; i < matrix1.getrows_(); i++) {
        for (int j = 0; j < matrix1.getcols_(); j++) {
            temp[i][j] = matrix1.getArray()[i][j] * matrix2.getArray()[i][j];
        }
    }
    return Matrix(temp, matrix1.getrows_(), matrix1.getcols_());
}

void Matrix::displayMatrix() const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}




// Do not modify this main function.
int main() {

    int **array1;
    int **array2;
    int row, col;

    std::cin >> row >> col;

    array1 = new int *[row];
    for (int k = 0; k < row; k++) {
        array1[k] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        std::cin >> array1[i][j];
        }
    }

    array2 = new int *[row];
    for (int k = 0; k < row; k++) {
        array2[k] = new int[col];
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
        std::cin >> array2[i][j];
        }
    }

    Matrix mat1 = Matrix(array1, row, col);
    Matrix mat2 = Matrix(array2, row, col);

    std::cout << "Addition result" << std::endl;
    (mat1 + mat2).displayMatrix();

    std::cout << "Subtraction result" << std::endl;
    (mat1 - mat2).displayMatrix();

    std::cout << "Multiplication result" << std::endl;
    (mat1 * mat2).displayMatrix();
    return 0;
}

//TODO
// Define a constructor, necessary functions and operator overloading.
