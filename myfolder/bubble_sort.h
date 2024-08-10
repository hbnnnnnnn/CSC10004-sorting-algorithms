#ifndef BUBBLE_SORT_H_INCLUDED
#define BUBBLE_SORT_H_INCLUDED

void bubbleSort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
            }
        }
    }
}

void bubbleSort_cpr(int a[], int n, long long& comparisons) {
    comparisons = 0;
    int i, j;
    for (i = 0; ++comparisons && i < n - 1; i++) {
        for (j = n - 1; ++comparisons && j > i; j--) {
            if (++comparisons && a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
            }
        }
    }
}

#endif // BUBBLE_SORT_H_INCLUDED
