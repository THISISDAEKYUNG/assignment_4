#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void CountingSort(int arr[]);
void MergeSort(int arr[], int start, int end);
void Merge(int arr[], int start, int end);
void print_array(int array[], int size);
int array1[16], array2[16], array3[16], array4[16];

int main() {
  int type;
  cin >> type;

  int array_c[16] = {0,};
  int array_m[16] = {0,};

  switch (type) {
  case 1:
    for(int i=0; i<16; i++){
      cin>>array_c[i];
    }
    CountingSort(array_c);
    break;
  case 2:
    for(int i=0; i<16; i++){
      cin>>array_m[i];
    }
    print_array(array_m, 16);
    MergeSort(array_m, 0, 15);
    print_array(array1, 16);
    print_array(array2, 16);
    print_array(array3, 16);
    print_array(array_m, 16);
    break;
  }
}

// your code starts here (function definition : CountingSort, MergeSort)
void print_array(int array[], int size) {
  for (int k = 0; k < size; k++) {
    if (k != size - 1) {
      cout << array[k] << " ";
    } else {
      cout << array[k] << endl;
    }
  }
}

void CountingSort(int array[]) {
  // step1 : find maximum value. we assume maximum value=5
  int max = 5;
  int size = 16;
  // step2 : make counting array and initialize it with 0
  int count_array[6] = {
      0,
  };
  int result_array[16] = {
      0,
  };

  // step3 : calculate counts of each element and store it in count array
  for (int i = 0; i < size; i++) {
    count_array[array[i]] += 1;
  }

  // step4 : calculate cumulative sum
  for (int i = 0; i < max; i++) {
    count_array[i + 1] += count_array[i];
  }

  // step5 : starts with last element of original array.
  for (int i = size - 1; i >= 0; i--) {
    // You can use the code below
    // fill the blanks
    /*blank1*/ count_array[array[i]] -= 1;               
    int target_index = /*blank2(same as blank1)*/ count_array[array[i]];
    result_array[target_index] = /*blank3*/ array[i];
  }
  print_array(result_array, 16);
}

void MergeSort(int array[], int start, int end){
  if(start<end){
    int mid= (start+end)/2;
    MergeSort(array, start, mid);
    MergeSort(array, mid+1, end);
    Merge(array, start, end);
  }
}

void Merge(int array[], int start, int end){
  int* tmp;
  int level = (end + 1 - start);
  if (level == 2) tmp = array1;
  if (level == 4) tmp = array2;
  if (level == 8) tmp = array3;
  if (level == 16) tmp = array4;
  // you should save intermediate results in the "tmp" array as well as in "result" array.
  /*Implement Merge function*/
  int mid = (start + end) / 2;
  int i = start;
  int j = mid + 1;
  int k = start;
  while (i <= mid && j <= end) {
      if (array[i] <= array[j]) {
          tmp[k++] = array[i++];
      }
      else {
          tmp[k++] = array[j++];
      }
  }
  while (i <= mid) {
      tmp[k++] = array[i++];
  }
  while (j <= end) {
      tmp[k++] = array[j++];
  }
  for (int l = start; l <= end; l++) {
      array[l] = tmp[l];
  }
}