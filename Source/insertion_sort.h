#ifndef INSERTION_SORT_H_INCLUDED
#define INSERTION_SORT_H_INCLUDED

void insertionSort(int a[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        j = i - 1; temp = a[i];
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void insertionSort_cpr(int a[], int n, long long& comparisons) {
    int i, j, temp;
    comparisons = 0;
    for (i = 1; ++comparisons && i < n; i++) {
        j = i - 1; temp = a[i];
        while (++comparisons && j >= 0 && ++comparisons && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

#endif // INSERTION_SORT_H_INCLUDED
