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
//void QuickSort(long long arr[], long long left, long long right) {
//    if (left >= right) {
//        return;
//    }
//    long long i = left;
//    long long j = right;
//    long long pivot = arr[rand() % (right - left + 1) + left];
//
//    while (i <= j) {
//        while (arr[i] > pivot) {
//            i++;
//        }
//        while (arr[j] < pivot) {
//            j--;
//        }
//        if (i <= j) {
//            long long tmp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = tmp;
//            i++;
//            j--;
//        }
//    }
//    if (left < j) {
//        QuickSort(arr, left, j);
//    }
//    if (i < right) {
//        QuickSort(arr, i, right);
//    }
//}

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
    long long mod = 10e9 + 7;
    long long dop_arr[m];
    long long p = 0;
    for (long long i = 0; i < m; ++i) {
        long long sum = 0;
        for (long long j = 0; j < n; ++j) {
            sum += (arr_judges[j] * arr[i][j]);
        }
//        sum %= mod;
        dop_arr[p] = sum % mod;
        ++p;
    }
    long long dop_arr2[m];
    for (long long i = 0; i < m; ++i) {
        dop_arr2[i] = i + 1;
    }
//    long long dop_arr2[m];
//    for (long long i = 0; i < m; ++i) {
//        dop_arr2[i] = dop_arr[i];
//    }

    BubbleSort(dop_arr, dop_arr2, m - 1);
//    QuickSort(dop_arr2, 0, m - 1);

    for (long long i = 0; i < k; ++i) {
        std::cout << dop_arr2[i] << ' ';
    }
//    long long min_el;
//    for (long long j = 0; j < m; ++j) {
//        if (dop_arr[j] == dop_arr2[m - 1]) {
//            min_el = j + 1;
//        }
//    }
//    for (int i = 0; i < m; ++i) {
//        std::cout << dop_arr[i]<< " ";
//    }
//    std::cout <<'\n';
//
//    for (int i = 0; i < m; ++i) {
//        std::cout << dop_arr2[i]<< " ";
//    }
//    std::cout <<'\n';
//    std::cout << min_el <<'\n';

//    if (k <= m) {
//    for (long long i = 0; i < k; ++i) {
//        for (long long j = 0; j < m; ++j) {
//            if (dop_arr2[i] == dop_arr[j]) {
////                    std::cout << std::endl;
////                    for (int k = 0; k < m; k++) {
////                        std::cout << dop_arr[k] << " ";
////                    }
////                    std::cout << std::endl;
////                    for (int l = 0; l < m; l++) {
////                        std::cout << dop_arr2[l] << " ";
////                    }
////                    std:: cout << std::endl << std::endl;
//////                    std::cout << dop_arr2[j] << ' ';
//                std::cout << j + 1 << ' ';
//                dop_arr[j] = -1;
//                break;
//            }
//        }
//    }
//    } else {
//        for (long long i = 0; i < m; ++i) {
//            for (long long j = 0; j < m; ++j) {
//                if (dop_arr2[i] == dop_arr[j]) {
//                    std::cout << j + 1 << ' ';
////                    std::cout << dop_arr2[j] << ' ';
//                    dop_arr[j] = -1;
//                    break;
//                }
//            }
//        }
//        for (long long i = 0; i < k - m; ++i) {
//            std::cout << min_el << ' ';
//        }

    return 0;
}
//3 6 6
//1 1 1
//3 3 3
//5 5 5
//3 3 3
//89347 1234567890 1937117
//3 3 3
//3 3 3

//6 4 4
//5 1 2 0 2 4
//1 0 9 2 9 5
//5 5 2 0 5 2
//2 7 2 2 5 2
//5 2 4 2 2 5
int Partition(int arr[], int left, int right)
{
    int pivot = arr[right];
    int j = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] >= pivot) {
            std::swap(arr[i], arr[j]);
            ++j;
        }
    }
    std::swap(arr[j], arr[right]);

    return j;
}

int QuickSelect(int arr[], int left, int right, int k) {
    if (k > 0 && k <= right - left + 1) {
        int i = Partition(arr, left, right);
        if (i - left == k - 1) {
            return arr[i];
        }
        if (i - left > k - 1) {
            return QuickSelect(arr, left, i - 1, k);
        }
        return QuickSelect(arr, i + 1, right, k - i + left - 1);
    }
}