#ifndef FLASH_SORT_H_INCLUDED
#define FLASH_SORT_H_INCLUDED

void flashSort(int a[], int n) {
    if (n <= 1) return;

    int m = n * 0.45;
    if (m <= 2) {
        m = 2;
    }

    const int maxN = 500000;
    int group[maxN];

    for(int i = 0; i <= m; ++i) group[i] = 0;

    int max = a[0], min = a[0];
    for(int i = 0; i < n; ++i) {
        if (max < a[i]) max = a[i];
        if (min > a[i]) min = a[i];
    }
    if (max == min) return;

    #define getGroup(x) 1ll * (m - 1) * (x - min) / (max - min)

    for(int i = 0; i < n; ++i) {
        ++group[getGroup(a[i])];
    }
    for(int i = 1; i < m; ++i) {
        group[i] += group[i - 1];
    }

    int count = 0, i = 0;
    while (count < n) {
        int k = getGroup(a[i]);
        while (i >= group[k]) k = getGroup(a[++i]);
        int z = a[i];
        while (i != group[k]) {
            k = getGroup(z);
            int y = a[group[k] - 1];
            a[--group[k]] = z;
            z = y;
            ++count;
        }
    }

    for(int k = 1; k < m; ++k) {
        for(int i = group[k] - 2; i >= group[k - 1]; --i) {
            if (a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }
}

void flashSort_cpr(int a[], int n, long long &comparison) {
    if (++comparison && n <= 1) return;

    int m = n * 0.45;
    if (++comparison && m <= 2) {
        m = 2;
    }

    const int maxN = 500000;
    int group[maxN];

    for(int i = 0; ++comparison && i <= m; ++i) group[i] = 0;

    int max = a[0], min = a[0];
    for(int i = 0; ++comparison && i < n; ++i) {
        if (++comparison && max < a[i]) max = a[i];
        if (++comparison && min > a[i]) min = a[i];
    }
    if (++comparison && max == min) return;

    #define getGroup(x) 1ll * (m - 1) * (x - min) / (max - min)

    for(int i = 0; ++comparison && i < n; ++i) {
        ++group[getGroup(a[i])];
    }
    for(int i = 1; ++comparison && i < m; ++i) {
        group[i] += group[i - 1];
    }

    int count = 0, i = 0;
    while (++comparison && count < n) {
        int k = getGroup(a[i]);
        while (++comparison && i >= group[k]) k = getGroup(a[++i]);
        int z = a[i];
        while (++comparison && i != group[k]) {
            k = getGroup(z);
            int y = a[group[k] - 1];
            a[--group[k]] = z;
            z = y;
            ++count;
        }
    }

    for(int k = 1; ++comparison && k < m; ++k) {
        for(int i = group[k] - 2; ++comparison && i >= group[k - 1]; --i) {
            if (++comparison && a[i] > a[i + 1]) {
                int t = a[i], j = i;
                while (++comparison && t > a[j + 1]) {
                    a[j] = a[j + 1];
                    ++j;
                }
                a[j] = t;
            }
        }
    }
}

#endif // FLASH_SORT_H_INCLUDED
