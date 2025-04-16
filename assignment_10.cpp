#include <iostream>
using namespace std;

// 병합 함수: arr[left..mid], arr[mid+1..right]를 정렬하여 병합
void merge(int* arr, int* temp, int left, int mid, int right) {
    int i = left;      // 왼쪽 부분 배열 시작 인덱스
    int j = mid + 1;   // 오른쪽 부분 배열 시작 인덱스
    int k = left;      // 임시 배열에 값을 채워 넣을 위치

    // 왼쪽과 오른쪽 배열을 비교하면서 작은 값을 temp에 저장
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])       // 왼쪽 값이 더 작거나 같으면
            temp[k++] = arr[i++];   // 왼쪽 값을 복사하고 인덱스 증가
        else
            temp[k++] = arr[j++];   // 오른쪽 값을 복사하고 인덱스 증가
    }

    // 남은 왼쪽 부분 복사
    while (i <= mid)
        temp[k++] = arr[i++];

    // 남은 오른쪽 부분 복사
    while (j <= right)
        temp[k++] = arr[j++];

    // 병합된 배열을 원래 배열로 복사
    for (int l = left; l <= right; l++) {
        arr[l] = temp[l];
    }
}

// 재귀적으로 배열을 나누고 병합하는 함수
void mergeSort(int* arr, int* temp, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;               // 배열을 절반으로 나눔
        mergeSort(arr, temp, left, mid);            // 왼쪽 절반 정렬
        mergeSort(arr, temp, mid + 1, right);       // 오른쪽 절반 정렬
        merge(arr, temp, left, mid, right);         // 정렬된 두 부분을 병합
    }
}

// 메인 함수
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};              // 정렬할 배열
    int n = sizeof(arr) / sizeof(arr[0]);           // 배열 크기 계산
    int temp[100];                                  // 병합용 임시 배열

    cout << "before sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, temp, 0, n - 1);                 // 정렬 실행

    cout << "after sort: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
