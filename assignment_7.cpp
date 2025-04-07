#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::array;
/* You can add more, e.g., std::@@. */

/* You need to use STL here! */

void get_input(array<int, 20> &arr) { 
    for (int i = 0; i < 20; i++) {
        cin >> arr[i];
    }
    /* blank */
}

void print_array(array<int, 20> arr) {
    for (int i = 0; i < 20; i++) {
        if (i == 19) {
            cout << arr[i] << endl;
        }
        else {
            cout << arr[i] << " ";
        }
    }
    /* blank */
}

void copy_array(array<int, 20> src_arr, array<int, 20> &dst_arr) { 
    std::copy(src_arr.begin(), src_arr.end(), dst_arr.begin());
    /* HINT: Search std::copy */
    /* blank */
}

void reverse_array(array<int, 20> &arr) { 
    std::reverse(arr.begin(), arr.end());
    /* HINT: Search std::reverse */
    /* blank */
}

void sort_array(array<int, 20> &arr) { 
    std::sort(arr.begin(), arr.end());
    /* HINT: Search std::sort */
    /* blank */
}

int find_array(array<int, 20> arr, int target_val) { 
    int target_index;
    target_index = std::find(arr.begin(), arr.end(), target_val) - arr.begin();
    if (target_index == 20) {
        if (arr[target_index] != target_val) {
            target_index = -1;
        }
    }
    return target_index;
    /* HINT 1: Search std::find */
    /* HINT 2: iterator - arr.begin() => value idx */
    /* return index */
    /* blank */
}

void swap_array(array<int, 20> &arr1, array<int, 20> &arr2) { 
    std::swap(arr1, arr2);
    /* HINT: Search std::swap or array.swap */
    /* blank */
}

int main() {
    // Initialization methods
    array<int, 20> arr = {
        0,
    };

    cout << "Get input in arr:" << endl;
    get_input(arr);
    cout << "Initial state of array container: ";
    print_array(arr);

    int find_val = 0;
    cout << "Get target value:" << endl;
    cin >> find_val;
    int find_idx = find_array(arr, find_val);
    cout << "The target value " << find_val << " found index: " << find_idx << endl;

    array<int, 20> new_arr = {
        0,
    };

    copy_array(arr, new_arr);
    cout << "Copied array container to new_arr: ";
    print_array(new_arr);

    reverse_array(new_arr);
    cout << "Reversed new_arr: ";
    print_array(new_arr);

    sort_array(arr);
    cout << "Sorted arr: ";
    print_array(arr);

    cout << "Before swapping arr: ";
    print_array(arr);
    cout << "Before swapping new_arr: ";
    print_array(new_arr);

    swap_array(arr, new_arr);

    cout << "After swapping arr: ";
    print_array(arr);
    cout << "After swapping new_arr: ";
    print_array(new_arr);

    return 0;
}