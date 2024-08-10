#ifndef RADIX_SORT_H_INCLUDED
#define RADIX_SORT_H_INCLUDED
namespace radix_sort{
    int getMax(int a[], int n) {
        int mx = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > mx) {
                mx = a[i];
            }
        }
        return mx;
    }

    int getMax_cpr(int a[], int n, long long& comparisons) {
        int mx = a[0];
        for (int i = 1; ++comparisons && i < n; i++) {
            if (++comparisons && a[i] > mx) {
                mx = a[i];
            }
        }
        return mx;
    }
}


int getDigit(int number, int exp) {
    return (number / exp) % 10;
}

void countSort(int a[], int n, int exp) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = getDigit(a[i], exp);
        count[digit]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = getDigit(a[i], exp);
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;
}

void radixSort(int a[], int n) {
    int m = radix_sort::getMax(a, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(a, n, exp);
    }
}


void countSort_cpr(int a[], int n, int exp, long long& comparisons) {
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; ++comparisons && i < n; i++) {
        int digit = getDigit(a[i], exp);
        count[digit]++;
    }

    for (int i = 1; ++comparisons && i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comparisons && i >= 0; i--) {
        int digit = getDigit(a[i], exp);
        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for (int i = 0; ++comparisons && i < n; i++) {
        a[i] = output[i];
    }

    delete[] output;
}

void radixSort_cpr(int a[], int n, long long& comparisons) {
    int m = radix_sort::getMax_cpr(a, n, comparisons);

    for (int exp = 1; ++comparisons && m / exp > 0; exp *= 10) {
        countSort_cpr(a, n, exp, comparisons);
    }
}


#endif // RADIX_SORT_H_INCLUDED
