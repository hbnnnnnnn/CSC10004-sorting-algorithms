#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

void max_heapify(int a[], int n, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest;

    if (left < n && a[index] < a[left])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }

    if (right < n && a[largest] < a[right])
    {
        largest = right;
    }

    if (largest != index)
    {
        std::swap(a[largest], a[index]);
        max_heapify(a, n, largest);
    }
}

void build_max_heap(int a[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        max_heapify(a, n, i);
    }
}

void heapSort(int a[], int n)
{
    build_max_heap(a, n);
    int heap_size = n;

    for (int i = n - 1; i >= 1; i--)
    {
        std::swap(a[0], a[i]);
        heap_size--;
        max_heapify(a, heap_size, 0);
    }
}

void max_heapify_cpr(int a[], int n, int index, long long &comparisons)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest;

    if (++comparisons && left < n && ++comparisons && a[index] < a[left])
    {
        largest = left;
    }
    else
    {
        largest = index;
    }

    if (++comparisons && right < n && ++comparisons && a[largest] < a[right])
    {
        largest = right;
    }

    if (++comparisons && largest != index)
    {
        std::swap(a[largest], a[index]);
        max_heapify_cpr(a, n, largest, comparisons);
    }
}

void build_max_heap_cpr(int a[], int n, long long &comparisons)
{
    for (int i = n / 2 - 1; ++comparisons && i >= 0; i--)
    {
        max_heapify_cpr(a, n, i, comparisons);
    }
}

void heapSort_cpr(int a[], int n, long long &comparisons)
{
    build_max_heap_cpr(a, n, comparisons);
    int heap_size = n;

    for (int i = n - 1; ++comparisons && i >= 1; i--)
    {
        std::swap(a[0], a[i]);
        heap_size--;
        max_heapify_cpr(a, heap_size, 0, comparisons);
    }
}

#endif //HEAP_SORT_INCLUDED
