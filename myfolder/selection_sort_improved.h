#ifndef SELECTION_SORT_IMPROVED_H_INCLUDED
#define SELECTION_SORT_IMPROVED_H_INCLUDED

#include <algorithm>

void selectionSortImproved(int a[], int n)
{
    int r = n - 1;
    for (int i = 0; i < r; i++) 
    {
        int max_index = i, min_index = i;
        for(int j = i + 1; j <= r; j++) 
        {
            if(a[j] < a[min_index]) 
            {
                min_index = j;
            } 
            else if(a[j] > a[max_index]) 
            {
                max_index = j;	
            }	
        }
        std::swap(a[min_index], a[i]);
        if(max_index == i) max_index = min_index;
        std::swap(a[max_index], a[r]);
        r--;
    }
}

void selectionSortImproved_cpr(int a[], int n, long long &comparisons)
{
    int r = n - 1;
    for (int i = 0; ++comparisons && i < r; i++) 
    {
        int max_index = i, min_index = i;
        for(int j = i + 1; ++comparisons && j <= r; j++) 
        {
            if(++comparisons && a[j] < a[min_index]) 
            {
                min_index = j;
            } 
            else if(++comparisons && a[j] > a[max_index]) 
            {
                max_index = j;	
            }	
        }
        std::swap(a[min_index], a[i]);
        if(++comparisons && max_index == i) max_index = min_index;
        std::swap(a[max_index], a[r]);
        r--;
    }
}

#endif //SELECTION_SORT_IMPROVED_INCLUDED