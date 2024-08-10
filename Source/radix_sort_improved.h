#ifndef RADIX_SORT_IMPROVED_H_INCLUDED
#define RADIX_SORT_IMPROVED_H_INCLUDED
namespace radix_sort_improved{
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
int getByte(int number, int byteIndex) {
    return (number >> (8 * byteIndex)) & 0xFF;
}


void countingSortImproved(int a[], int n, int byteIndex) {
    int* output = new int[n];
    int count[256] = {0};

    for (int i = 0; i < n; ++i) {
        int byte = getByte(a[i], byteIndex);
        ++count[byte];
    }

    for (int i = 1; i < 256; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; --i) {
        int byte = getByte(a[i], byteIndex);
        output[count[byte] - 1] = a[i];
        --count[byte];
    }

    for (int i = 0; i < n; ++i) {
        a[i] = output[i];
    }

    delete[] output;
}

void radixSortImproved(int a[], int n) {
    int maxNumber = radix_sort_improved::getMax(a, n);
    int maxBytes = 0;
    while (maxNumber > 0) {
        maxNumber >>= 8;
        ++maxBytes;
    }

    for (int byteIndex = 0; byteIndex < maxBytes; ++byteIndex) {
        countingSortImproved(a, n, byteIndex);
    }
}

void countingSortImproved_cpr(int a[], int n, int byteIndex, long long& comparisons) {
    int* output = new int[n];
    int count[256] = {0};

    for (int i = 0; ++comparisons && i < n; ++i) {
        int byte = getByte(a[i], byteIndex);
        ++count[byte];
    }

    for (int i = 1; ++comparisons && i < 256; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; ++comparisons && i >= 0; --i) {
        int byte = getByte(a[i], byteIndex);
        output[count[byte] - 1] = a[i];
        --count[byte];
    }

    for (int i = 0; ++comparisons && i < n; ++i) {
        a[i] = output[i];
    }

    delete[] output;
}

void radixSortImproved_cpr(int a[], int n, long long& comparisons) {
    int maxNumber = radix_sort_improved::getMax_cpr(a, n, comparisons);
    int maxBytes = 0;
    while (++comparisons && maxNumber > 0) {
        maxNumber >>= 8;
        ++maxBytes;
    }

    for (int byteIndex = 0; ++comparisons && byteIndex < maxBytes; ++byteIndex) {
        countingSortImproved_cpr(a, n, byteIndex, comparisons);
    }
}

#endif //RADIX_SORT_IMPROVED_INCLUDED
