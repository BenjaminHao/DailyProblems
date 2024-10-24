#include <iostream>
#include "SortingAlgorithms.h"

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // Print a newline at the end
}

int main()
{
    int a[]  = {2, 6, 8, 3, 5, 7, 1, 9, 4};
    int b[]  = {2, 6, 8, 3, 5, 7, 1, 9, 4};
    int c[]  = {2, 6, 8, 3, 5, 7, 1, 9, 4};
    int d[]  = {2, 6, 8, 3, 5, 7, 1, 9, 4};
    int e[]  = {2, 6, 8, 3, 5, 7, 1, 9, 4};

    SelectionSort(a, 9);
    InsertionSort(b, 9);
    BubbleSort(c, 9);
    MergeSort(d, 9);
    QuickSort(e, 9);

    std::cout << "After Sorting: " << std::endl;

    std::cout << "Selection Sort: ";
    printArray(a, 9);

    std::cout << "Insertion Sort: ";
    printArray(b, 9);

    std::cout << "Bubble Sort: ";
    printArray(c, 9);

    std::cout << "Merge Sort: ";
    printArray(d, 9);

    std::cout << "Quick Sort: ";
    printArray(e, 9);
}
