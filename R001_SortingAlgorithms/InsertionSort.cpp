#include <algorithm>
#include "SortingAlgorithms.h"

void InsertionSort(int arr[], int N)
{
    for (int i = 1; i != N; ++i)
    {
        for (int j = i; j != 0 && arr[j - 1] > arr[j]; --j)
        {
            std::swap(arr[j], arr[j - 1]);
        }
    }
}
