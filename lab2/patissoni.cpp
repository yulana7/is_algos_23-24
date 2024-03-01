#include <iostream>

void QuickSort(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int pivot = arr[rand() % (right - left + 1) + left];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j) {
        QuickSort(arr, left, j);
    }
    if (i < right) {
        QuickSort(arr, i, right);
    }
}

int main() {
    int n;
    std::cin >> n;
    int array[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    int i = 0;
    int j = n - 1;
    QuickSort(array, i, j);

    for (int x = 0; x < n; ++x) {
        std::cout << array[x] << ' ';
    }

    return 0;
}
