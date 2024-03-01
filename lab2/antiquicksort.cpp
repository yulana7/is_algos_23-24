#include <iostream>

void AntiQuickSort(int arr[], int n) {
    for (int i = 2; i < n; ++i) {
        std::swap(arr[i / 2], arr[i]);
    }
}

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        array[i] = i + 1;
    }

    AntiQuickSort(array, n);

    for (int j = 0; j < n; ++j) {
        std::cout << array[j] << ' ';
    }

    return 0;
}