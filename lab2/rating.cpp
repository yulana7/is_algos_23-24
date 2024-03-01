#include <iostream>
long long count = 0;

void Merge(int arr[], int left, int mid, int right ) {
    int len_left_arr = mid - left + 1;
    int len_right_arr = right - mid;
    int left_sub_arr[len_left_arr];
    int right_sub_arr[len_right_arr];
    for (int x = 0; x < len_left_arr; x++)
        left_sub_arr[x] = arr[left + x];
    for (int l = 0; l < len_right_arr; l++)
        right_sub_arr[l] = arr[mid + 1 + l];

    int i = 0;
    int j = 0;
    int p = left;

    while (i < len_left_arr && j < len_right_arr) {
        if (left_sub_arr[i] <= right_sub_arr[j]) {
            arr[p] = left_sub_arr[i];
            i++;
        } else {
            arr[p] = right_sub_arr[j];
            j++;
            count++;
            count += mid - left - i;
        }
        p++;
    }

    while (i < len_left_arr) {
        arr[p] = left_sub_arr[i];
        i++;
        p++;
    }
    while (j < len_right_arr) {
        arr[p] = right_sub_arr[j];
        j++;
        p++;
    }
}

void RecursiveMergeSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    RecursiveMergeSort(arr, left, mid);
    RecursiveMergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);
}

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    RecursiveMergeSort(array, 0, n - 1);

    std::cout << count;
    return 0;
}