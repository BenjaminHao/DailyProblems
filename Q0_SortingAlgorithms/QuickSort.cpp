#include <ctime>
#include <cstdlib>
#include <algorithm>
#include "SortingAlgorithms.h"

void QuickSort(int arr[], int N)
{
    std::srand(std::time(NULL));
    QuickSort(arr, 0, N - 1);
}

void QuickSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int partationIndex = Partation(arr, left, right);
        QuickSort(arr, left, partationIndex - 1);
        QuickSort(arr, partationIndex + 1, right);
    }
}

int Partation(int arr[], int left, int right)
{
    // get random pivot to pervent worst case
    int randomIndex = std::rand() % (right - left) + left;
    std::swap(arr[randomIndex], arr[right]);

    int partationIndex = left, pivot = arr[right];
    
    for (int i = left; i != right; ++i)
    {
        if (arr[i] < pivot)
        {
            std::swap(arr[i], arr[partationIndex]);
            ++partationIndex;
        }
    }
    std::swap(arr[partationIndex], arr[right]);
    return partationIndex;
}