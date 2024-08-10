#ifndef MERGE_SORT_H_INCLUDED
#define MERGE_SORT_H_INCLUDED

#include <algorithm>
namespace merge_sort {
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

void mergeSort(int a[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge_sort::merge(a, left, mid, right);
}

void mergeSort(int a[], int n) {
    mergeSort(a, 0, n - 1);
}



void mergeSort_cpr(int a[], int left, int right, long long& comparisons) {
    if (++comparisons && left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort_cpr(a, left, mid, comparisons);
    mergeSort_cpr(a, mid + 1, right, comparisons);
    merge_sort::merge_cpr(a, left, mid, right, comparisons);
}

void mergeSort_cpr(int a[], int n, long long& comparisons) {
    mergeSort_cpr(a, 0, n - 1, comparisons);
}


#endif // MERGE_SORT_H_INCLUDED
