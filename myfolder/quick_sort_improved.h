#ifndef QUICK_SORT_IMPROVED_H_INCLUDED
#define QUICK_SORT_IMPROVED_H_INCLUDED

#include <algorithm>

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) {
        std::swap(arr[low], arr[mid]);
    }
    if (arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }
    if (arr[mid] > arr[high]) {
        std::swap(arr[mid], arr[high]);
    }

    return mid;
}

int partitionImproved(int a[], int low, int high) {
    int pivotIndex = medianOfThree(a, low, high);
    int pivot = a[pivotIndex];
    std::swap(a[pivotIndex], a[high]);
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (a[j] <= pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortImproved(int a[], int low, int high) {
    if (low < high) {
        int pi = partitionImproved(a, low, high);
        quickSortImproved(a, low, pi - 1);
        quickSortImproved(a, pi + 1, high);
    }
}

void quickSortImproved(int a[], int n) {
    quickSortImproved(a, 0, n - 1);
}

int medianOfThree_cpr(int arr[], int low, int high, long long& comparisons) {
    int mid = low + (high - low) / 2;
    if (++comparisons && arr[low] > arr[mid]) {
        std::swap(arr[low], arr[mid]);
    }
    if (++comparisons && arr[low] > arr[high]) {
        std::swap(arr[low], arr[high]);
    }
    if (++comparisons && arr[mid] > arr[high]) {
        std::swap(arr[mid], arr[high]);
    }

    return mid;
}

int partitionImproved_cpr(int a[], int low, int high, long long& comparisons) {
    int pivotIndex = medianOfThree_cpr(a, low, high, comparisons);
    int pivot = a[pivotIndex];
    std::swap(a[pivotIndex], a[high]);
    int i = low - 1;

    for (int j = low; ++comparisons && j < high; ++j) {
        if (++comparisons && a[j] <= pivot) {
            ++i;
            std::swap(a[i], a[j]);
        }
    }
    std::swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSortImproved_cpr(int a[], int low, int high, long long& comparisons) {
    if (++comparisons && low < high) {
        int pi = partitionImproved_cpr(a, low, high, comparisons);
        quickSortImproved_cpr(a, low, pi - 1, comparisons);
        quickSortImproved_cpr(a, pi + 1, high, comparisons);
    }
}

void quickSortImproved_cpr(int a[], int n, long long& comparisons) {
    quickSortImproved_cpr(a, 0, n - 1, comparisons);
}

#endif //QUICK_SORT_IMPROVED_INCLUDED
