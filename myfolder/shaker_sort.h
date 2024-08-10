#ifndef SHAKER_SORT_H_INCLUDED
#define SHAKER_SORT_H_INCLUDED

void shakerSort(int a[], int n) {
    bool flag = true;
    int i, left = 0, right = n - 1;
    while (flag) {
        flag = false;
        for (i = left; i < right; i++) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
        flag = false;
        right--;
        for (i = right; i > left; i--) {
            if (a[i] < a[i - 1]) {
                std::swap(a[i], a[i - 1]);
                flag = true;
            }
        }
        left++;
    }
}

void shakerSort_cpr(int a[], int n, long long& comparisons) {
    bool flag = true;
    int i, left = 0, right = n - 1;
    comparisons = 0;
    while (++comparisons && flag) {
        flag = false;
        for (i = left; ++comparisons && i < right; i++) {
            if (++comparisons && a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
                flag = true;
            }
        }
        if (++comparisons && !flag) {
            break;
        }
        flag = false;
        right--;
        for (i = right; ++comparisons && i > left; i--) {
            if (++comparisons && a[i] < a[i - 1]) {
                std::swap(a[i], a[i - 1]);
                flag = true;
            }
        }
        left++;
    }
}


#endif // SHAKER_SORT_H_INCLUDED
