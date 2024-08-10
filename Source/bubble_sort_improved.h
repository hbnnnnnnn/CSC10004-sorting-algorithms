#ifndef BUBBLE_SORT_IMPROVED_H_INCLUDED
#define BUBBLE_SORT_IMPROVED_H_INCLUDED

void bubbleSortImproved(int a[], int n) {
    int i, j;
    bool flag;
    for (i = 0; i < n - 1; i++) {
        flag = false;
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void combSort(int a[], int n) {
    int step = n, k, i, j;
    while ((step = int(step / 1.3)) > 1) {
        for (j = n - 1; j >= step; j--) {
            k = j - step;
            if (a[j] < a[k]) {
                std::swap(a[j], a[k]);
            }
        }
    }
    bool flag;
    for (i = 0; i < n - 1; i++) {
        flag = false;
        for (j = n - 1; j > i; j--) {
            if (a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void bubbleSortImproved_cpr(int a[], int n, long long& comparisons) {
    int i, j;
    bool flag;
    comparisons = 0;
    for (i = 0; ++comparisons && i < n - 1; i++) {
        flag = false;
        for (j = n - 1; ++comparisons && j > i; j--) {
            if (++comparisons && a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (++comparisons && !flag) {
            break;
        }
    }
}

void combSort_cpr(int a[], int n, long long& comparisons) {
    int step = n, k, i, j;
    comparisons = 0;
    while ((step = int(step / 1.3)) > 1) {
        for (j = n - 1; ++comparisons && j >= step; j--) {
            k = j - step;
            if (++comparisons && a[j] < a[k]) {
                std::swap(a[j], a[k]);
            }
        }
    }
    bool flag;
    for (i = 0; ++comparisons && i < n - 1; i++) {
        flag = false;
        for (j = n - 1; ++comparisons && j > i; j--) {
            if (++comparisons && a[j] < a[j - 1]) {
                std::swap(a[j], a[j - 1]);
                flag = true;
            }
        }
        if (++comparisons && !flag) {
            break;
        }
    }
}

#endif //BUBBLE_SORT_IMPROVED_INCLUDED
