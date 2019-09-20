#include <iostream>
#include "SortingAlgorithms.h"

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
    for (int i : a) { std::cout << i << " ";}
    std::cout << std::endl;

    std::cout << "Insertion Sort: ";
    for (int i : b) { std::cout << i << " ";}
    std::cout << std::endl;

    std::cout << "Bubble Sort: ";
    for (int i : c) { std::cout << i << " ";}
    std::cout << std::endl;

    std::cout << "Merge Sort: ";
    for (int i : d) { std::cout << i << " ";}
    std::cout << std::endl;

    std::cout << "Quick Sort: ";
    for (int i : e) { std::cout << i << " ";}
    std::cout << std::endl;

    
}