#ifndef MERGE_SORT_IMPROVED_H_INCLUDED
#define MERGE_SORT_IMPROVED_H_INCLUDED
#include <algorithm>

namespace merge_sort_improved{
    const int RUN = 32;

    void merge(int a[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; i < n1; i++)
            L[i] = a[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = a[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            }
            else {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }

    void merge_cpr(int a[], int left, int mid, int right, long long& comparisons) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int* L = new int[n1];
        int* R = new int[n2];

        for (int i = 0; ++comparisons && i < n1; i++)
            L[i] = a[left + i];
        for (int j = 0; ++comparisons && j < n2; j++)
            R[j] = a[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while ((++comparisons && i < n1) && (++comparisons && j < n2)) {
            if (++comparisons && L[i] <= R[j]) {
                a[k] = L[i];
                i++;
            }
            else {
                a[k] = R[j];
                j++;
            }
            k++;
        }

        while (++comparisons && i < n1) {
            a[k] = L[i];
            i++;
            k++;
        }

        while (++comparisons && j < n2) {
            a[k] = R[j];
            j++;
            k++;
        }

        delete[] L;
        delete[] R;
    }
}

void insertionSort(int a[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= left && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void mergeSortImproved(int a[], int n) {
    for (int i = 0; i < n; i += merge_sort_improved::RUN)
        insertionSort(a, i, std::min((i + 31), (n - 1)));

    for (int size = merge_sort_improved::RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));

            if (mid < right)
                merge_sort_improved::merge(a, left, mid, right);
        }
    }
}

void insertionSort_cpr(int a[], int left, int right, long long& comparisons) {
    for (int i = left + 1; ++comparisons && i <= right; i++) {
        int temp = a[i];
        int j = i - 1;
        while ((++comparisons && j >= left) && (++comparisons && a[j] > temp)) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void mergeSortImproved_cpr(int a[], int n, long long& comparisons) {
    for (int i = 0; ++comparisons && i < n; i += merge_sort_improved::RUN)
        insertionSort_cpr(a, i, std::min((i + 31), (n - 1)), comparisons);

    for (int size = merge_sort_improved::RUN; ++comparisons && size < n; size = 2 * size) {
        for (int left = 0; ++comparisons && left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            ++comparisons;

            if (++comparisons && mid < right)
                merge_sort_improved::merge_cpr(a, left, mid, right, comparisons);
        }
    }
}
#endif //MERGE_SORT_IMPROVED_INCLUDED
