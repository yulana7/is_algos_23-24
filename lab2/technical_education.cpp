#include <iostream>

void QuickSort(long long arr[], long long left, long long right) {
    if (left >= right) {
        return;
    }
    long long i = left;
    long long j = right;
    long long pivot = arr[rand() % (right - left + 1) + left];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
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
    long long arr[n];
    long long arr_deadlines[n];
    for (long long i = 0; i < n; ++i) {
        std::cin >> arr[i] >> arr_deadlines[i];
    }

    long long sum = 0;
    for (long long i = 0; i < n; ++i) {
        sum += arr_deadlines[i];
    }

    QuickSort(arr, 0, n - 1);

    long long days = 0;
    for (long long k = 0; k < n; ++k) {
        days += arr[k];
        sum -= days;
    }
    std::cout << sum;

    return 0;
}
