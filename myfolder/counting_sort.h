#ifndef COUNTING_SORT_H_INCLUDED
#define COUNTING_SORT_H_INCLUDED

void countingSort(int a[], int n)
{
    int max_element = a[0];
    int min_element = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] > max_element)
            max_element = a[i];
        else
        {
            if (a[i] < min_element)
                min_element = a[i];
        }
    }

    max_element -= min_element;

    for (int i = 0; i < n; i++)
        a[i] -= min_element;

    int* count_array = new int[max_element + 1];

    for (int i = 0; i <= max_element; i++)
    {
        count_array[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        count_array[a[i]]++;
    }

    for (int i = 1; i <= max_element; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    int* tmp = new int[n];

    for (int i = 0; i < n; i++)
    {
        tmp[count_array[a[i]] - 1] = a[i];
        count_array[a[i]]--;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = tmp[i] + min_element;
    }

    delete[] tmp;
    delete[] count_array;
}

void countingSort_cpr(int a[], int n, long long &comparisons)
{
    int max_element = a[0];
    int min_element = a[0];

    for (int i = 1; ++comparisons && i < n; i++)
    {
        if (++comparisons && a[i] > max_element)
            max_element = a[i];
        else
        {
            if (++comparisons && a[i] < min_element)
                min_element = a[i];
        }
    }

    max_element -= min_element;

    for (int i = 0; ++comparisons && i < n; i++)
        a[i] -= min_element;

    int* count_array = new int[max_element + 1];

    for (int i = 0; ++comparisons && i <= max_element; i++)
    {
        count_array[i] = 0;
    }

    for (int i = 0; ++comparisons && i < n; i++)
    {
        count_array[a[i]]++;
    }

    for (int i = 1; ++comparisons && i <= max_element; i++)
    {
        count_array[i] += count_array[i - 1];
    }

    int* tmp = new int[n];

    for (int i = 0; ++comparisons && i < n; i++)
    {
        tmp[count_array[a[i]] - 1] = a[i];
        count_array[a[i]]--;
    }

    for (int i = 0; ++comparisons && i < n; i++)
    {
        a[i] = tmp[i] + min_element;
    }

    delete[] tmp;
    delete[] count_array;
}

#endif //COUNTING_SORT_H_INCLUDED