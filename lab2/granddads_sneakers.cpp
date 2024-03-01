#include <iostream>

void InsertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; ++i) {
        key = arr[i];
        j = i - 1;
        while (arr[j] > key && j >= 0) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    InsertionSort(arr, n);

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    return 0;
