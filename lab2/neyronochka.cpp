#include <iostream>

void BubbleSort(long long arr[],long long arr2[], long long n) {
    for (long long i = 0; i < n; ++i) {
        for (long long j = 0; j < n - i; ++j) {
            if (arr[j] < arr[j + 1]) {
                long long tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                long long tmp2 = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = tmp2;
            }
        }
    }
}

int main() {
    long long n, m, k;
    std::cin >> n;
    if (n < 1) {
        std::cout << 0;
        return 0;
    }
    std::cin >> m >> k;
    long long arr_judges[n];
    for (long long i = 0; i < n; ++i) {
        std::cin >> arr_judges[i];
    }
    long long arr[m][n];
    for (long long i = 0; i < m; ++i) {
        for (long long j = 0; j < n; ++j) {
            std::cin >> arr[i][j];
        }
    }
    long long dop_arr[m];
    long long p = 0;
    for (long long i = 0; i < m; ++i) {
        long long sum = 0;
        for (long long j = 0; j < n; ++j) {
            sum += (arr_judges[j] * arr[i][j]);
        }
        dop_arr[p] = sum % 1000000007;
        ++p;
    }
    long long dop_arr2[m];
    for (long long i = 0; i < m; ++i) {
        dop_arr2[i] = i + 1;
    }

    BubbleSort(dop_arr, dop_arr2, m - 1);

    for (long long i = 0; i < k; ++i) {
        std::cout << dop_arr2[i] << ' ';
    }
    return 0;
}