#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void BubbleSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void SelectionSort(int arr[], int size);
void print(int arr[], int size);


int main() {
    int type, size;

    cin >> type >> size;

    int array[size];

    for (int i=0; i<size; i++){
        cin >> array[i];
    }

    switch (type){
        case 1:
            BubbleSort(array, size);
            break;
        case 2:
            InsertionSort(array, size);
            break;
        case 3:
            SelectionSort(array, size);
            break;
  }
}

//your code starts here (function definition : BubbleSort, InsertionSort, SelectionSort)
void BubbleSort(int array[], int size) {
    int num1, num2;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] < array[j + 1]) {
                num1 = array[j];
                num2 = array[j + 1];
                array[j + 1] = num1;
                array[j] = num2;
                print(array, size);
            }
        }
    }
}


void InsertionSort(int array[], int size) {
    int key, num;
    for (int i = 1; i < size; i++) {
        key = array[i];
        for (int j = i - 1; j >= 0; j--) {
            if (key > array[j]) {
                num = array[j];
                array[j] = key;
                array[j + 1] = num;
            }
        }
        if (array[i] != key) {
            print(array, size);
        }
    }
}

void SelectionSort(int array[], int size) {
    int max, max_index, num1, num2;
    for (int i = 0; i < size - 1; i++) {
        max = array[i];
        max_index = i;
        for (int j = i + 1; j < size; j++) {
            if (max < array[j]) {
                max = array[j];
                max_index = j;
            }
        }
        if (array[i] != array[max_index]){
            num1 = array[i];
            num2 = array[max_index];
            array[max_index] = num1;
            array[i] = num2;
            print(array, size);
        }
    }
}

void print(int array[], int size) {
    for (int k = 0; k < size; k++) {
        if (k == size - 1) {
            cout << array[k] << endl;
        }
        else {
            cout << array[k] << " ";
        }
    }
}