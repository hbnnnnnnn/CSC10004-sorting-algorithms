#ifndef SHELL_SORT_H_INCLUDED
#define SHELL_SORT_H_INCLUDED

void shellSort(int a[], int n) {
    int i, j, hCnt, h;
    int increments[20], k;
    for (h = 1, i = 0; h < n; i++){
        increments[i] = h;
        h = 3*h + 1;
    }
    for (i--; i >= 0; i--) {
        h = increments[i];
        for (hCnt = h; hCnt < 2 * h; hCnt++) {
            for (j = hCnt; j < n;) {
                int temp = a[j];
                k = j;
                while (k - h >= 0 && temp < a[k - h]) {
                    a[k] = a[k - h];
                    k -= h;
                }
                a[k] = temp;
                j += h;
            }
        }
    }
}

void shellSort_cpr(int a[], int n, long long& comparisons) {
    int i, j, hCnt, h;
    int increments[20], k;
    comparisons = 0;
    for (h = 1, i = 0; ++comparisons && h < n; i++){
        increments[i] = h;
        h = 3*h + 1;
    }
    for (i--; ++comparisons && i >= 0; i--) {
        h = increments[i];
        for (hCnt = h; ++comparisons && hCnt < 2 * h; hCnt++) {
            for (j = hCnt; ++comparisons && j < n;) {
                int temp = a[j];
                k = j;
                while (++comparisons && k - h >= 0 && ++comparisons && temp < a[k - h]) {
                    a[k] = a[k - h];
                    k -= h;
                }
                a[k] = temp;
                j += h;
            }
        }
    }
}

#endif // SHELL_SORT_H_INCLUDED
