#include <algorithm>
#include "SortingAlgorithms.h"

void SelectionSort(int arr[], int N)
{
    for (int i = 0; i != N - 1; ++i)
    {
        int iMin = i;
        for (int j = i + 1; j != N; ++j)
        {
            if (arr[j] < arr[iMin])
            {
                iMin = j;
            }
        }
        if (iMin != i)
        {
            std::swap(arr[iMin], arr[i]);
        }
    }
}