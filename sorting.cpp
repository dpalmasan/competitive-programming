#include <algorithm>

void bubble_sort(int* arr, const std::size_t& n) {
    for (std::size_t i = 0; i < n; ++i) {
        for (std::size_t j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void __merge(int* arr, const std::size_t& a, const std::size_t& b, const std::size_t& mid) {
    auto *tmp1 = new int[mid - a + 1], *tmp2 = new int[b - mid];
    for (auto i = 0; i < mid - a + 1; ++i) {
        tmp1[i] = arr[a + i];
    }
    for (auto i = 0; i < b - mid; ++i) {
        tmp2[i] = arr[mid + 1 + i];
    }

    std::size_t i = 0, j = 0, k = a;

    while (i < mid - a + 1 && j < b - mid) {
        if (tmp1[i] < tmp2[j]) {
            arr[k++] = tmp1[i++];
        } else {
            arr[k++] = tmp2[j++];
        }
    }
    while (i < mid - a + 1) {
        arr[k++] = tmp1[i++];
    }
    while (j < b - mid) {
        arr[k++] = tmp2[j++];
    }
}

void __sort(int* arr, const std::size_t& a, const std::size_t& b) {
    if (a >= b) {
        return;
    }

    std::size_t mid = a + (b - a) / 2;
    __sort(arr, a, mid);
    __sort(arr, mid + 1, b);
    __merge(arr, a, b, mid);
}

void merge_sort(int* arr, const std::size_t& n) {
    __sort(arr, 0, n - 1);
}

void count_sort(int* arr, const std::size_t& n, int c) {
    auto table = new int[c + 1];

    for (auto i = 0; i < n; ++i) {
        table[arr[i]] += 1;
    }

    for (auto i = 0, j = 0; i < c; ++i) {
        while (table[i] > 0) {
            arr[j++] = i;
            table[i]--;
        }
    }
}