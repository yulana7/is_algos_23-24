#include <iostream>

void QuickSort(long long arr[], long long left, long long right) {
    if (left >= right) {
        return;
    }
    long long i = left;
    long long j = right;
    long long pivot = arr[rand() % (right - left + 1) + left];

    while (i <= j) {
        while (arr[i] > pivot) {
            i++;
        }
        while (arr[j] < pivot) {
            j--;
        }
        if (i <= j) {
            long long tmp = arr[i];
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
    long long n;
    std::cin >> n;
    long long array[n];
    for (long long i = 0; i < n; ++i) {
        std::cin >> array[i];
    }

    QuickSort(array, 0 , n - 1);

    long long arr[2] = {0, 0};
    long long i = 0;
    long long p = 0;
    long long max_sum = 0;
    while (i < n && p != 2) {
        if (array[i] == array[i + 1]) {
            arr[p] = array[i];
            ++i;
            ++p;
        } else if (array[i] - 1 == array[i + 1]) {
            arr[p] = array[i] - 1;
            ++i;
            ++p;
        } else if (array[i] == array[i + 1] - 1) {
            arr[p] = array[i + 1] - 1;
            ++i;
            ++p;
        }
        ++i;
        if (p == 2) {
            max_sum += arr[0] * arr[1];
            arr[0] = 0;
            arr[1] = 0;
            p = 0;
        }
    }
    std::cout << max_sum;

    return 0;
}