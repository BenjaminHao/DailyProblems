#include "SortingAlgorithms.h"

void MergeSort(int arr[], int N)
{
    int* tmp = new int[N];
    MergeSort(arr, tmp, 0, N - 1);
    delete[] tmp;
}

void MergeSort(int arr[], int tmp[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(arr, tmp, left, mid);
        MergeSort(arr, tmp, mid + 1, right);
        Merge(arr, tmp, left, right, mid);
    }
}

void Merge(int arr[], int tmp[], int left, int right, int mid)
{
    int i = left, k = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j]) { tmp[k] = arr[i]; ++i; ++k; }
        else { tmp[k] = arr[j]; ++j; ++k; }
    }
    while (i <= mid) { tmp[k] = arr[i]; ++i; ++k; }
    while (j <= right) { tmp[k] = arr[j]; ++j; ++k; }

    for (i = left; i != k; ++i)
    {
        arr[i] = tmp[i];
    }
}