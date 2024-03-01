#include <iostream>

void QuickSort(int arr[], int left, int right, int k) {
    if (left >= right) {
        return;
    }
    int i = left;
    int j = right;
    int pivot = arr[rand() % (right - left + 1) + left];

    while (i <= j) {
        while (arr[i] > pivot) {
            i++;
        }
        while (arr[j] < pivot) {
            j--;
        }
        if (i <= j) {
            uint32_t tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (left < j && k - 1 < j) {
        QuickSort(arr, left, j, k);
    }
    if (i < right && k > i) {
        QuickSort(arr, i, right, k);
    }
}

int main() {
    int n, k, k_a, k_b, k_c;
    std::cin >> n >> k ;
    int arr[n];
    std::cin >> k_a >> k_b >> k_c >> arr[0] >> arr[1];
    for (int i = 2; i < n; ++i) {
        arr[i] = arr[i - 2] * k_a + arr[i - 1] * k_b + k_c;
    }

    QuickSort(arr, 0, n - 1, k);

    int result = arr[0];
    for (int i = 1; i < k; ++i) {
        result ^= arr[i];
    }
    std::cout << result;

    return 0;
}