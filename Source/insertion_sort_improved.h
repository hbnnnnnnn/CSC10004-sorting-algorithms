#ifndef INSERTION_SORT_IMPROVED_H_INCLUDED
#define INSERTION_SORT_IMPROVED_H_INCLUDED

void binaryInsertionSort(int a[], int n) {
    int i, j, temp, low, high, mid;
    for (i = 1; i < n; i++) {
        temp = a[i]; low = 0; high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] > temp) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        j = i - 1;
        while (j >= low) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void binaryInsertionSort_cpr(int a[], int n, long long& comparisons) {
    int i, j, temp, low, high, mid;
    comparisons = 0;
    for (i = 1; ++comparisons && i < n; i++) {
        temp = a[i]; low = 0; high = i - 1;
        while (++comparisons && low <= high) {
            mid = (low + high) / 2;
            if (++comparisons && a[mid] > temp) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        j = i - 1;
        while (++comparisons && j >= low) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}
#endif //INSERTION_SORT_IMPROVED_INCLUDED