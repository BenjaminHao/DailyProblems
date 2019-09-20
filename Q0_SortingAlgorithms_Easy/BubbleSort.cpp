#include <algorithm>
#include "SortingAlgorithms.h"

void BubbleSort(int arr[], int N)
{
    bool isSorted = false;
    int lastSorted = N - 1;

    while (!isSorted)
    {
        isSorted = true;
        for (int i = 0; i != lastSorted; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                isSorted = false;
                std::swap(arr[i], arr[i + 1]);
            }
        }
        --lastSorted;
    }
}