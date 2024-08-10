#ifndef QUICK_SORT_H_INCLUDED
#define QUICK_SORT_H_INCLUDED

#include <algorithm>

int partition(int a[], int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = a[mid];
    std::swap(a[mid], a[high]);

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (a[j] <= pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);

        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void quickSort(int a[], int n) {
    quickSort(a, 0, n - 1);
}

int partition_cpr(int a[], int low, int high, long long& comparisons) {
    int mid = low + (high - low) / 2;
    int pivot = a[mid];
    std::swap(a[mid], a[high]);

    int i = low - 1;

    for (int j = low; ++comparisons && j <= high - 1; j++) {
        if (++comparisons && a[j] <= pivot) {
            i++;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort_cpr(int a[], int low, int high, long long& comparisons) {
    if (++comparisons && low < high) {
        int pi = partition_cpr(a, low, high, comparisons);

        quickSort_cpr(a, low, pi - 1, comparisons);
        quickSort_cpr(a, pi + 1, high, comparisons);
    }
}

void quickSort_cpr(int a[], int n, long long& comparisons) {
    quickSort_cpr(a, 0, n - 1, comparisons);
}

#endif // QUICK_SORT_H_INCLUDED
