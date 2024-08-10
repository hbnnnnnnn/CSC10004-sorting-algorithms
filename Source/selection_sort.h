#ifndef SELECTION_SORT_H_INCLUDED
#define SELECTION_SORT_H_INCLUDED

#include <algorithm>

void selectionSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min_index = i;
        for(int j = i + 1; j < n; j++) 
        {
            if(a[j] < a[min_index]) 
            {
                min_index = j;
            }
        }
        if(i!= min_index) 
        {
            std::swap(a[min_index], a[i]);
        }
    }
}

void selectionSort_cpr(int a[], int n, long long &comparisons)
{
    for (int i = 0;++comparisons && i < n - 1; i++) 
    {
        int min_index = i;
        for(int j = i + 1;++comparisons && j < n; j++) 
        {
            if(++comparisons && a[j] < a[min_index]) 
            {
                min_index = j;
            }
        }
        if(++comparisons && i!= min_index) 
        {
            std::swap(a[min_index], a[i]);
        }
    }
}

#endif // SELECTION_SORT_INCLUDED
