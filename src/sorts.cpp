#include "../include/sorts.h"
#include "../include/utils.h"
#include "../include/prints.h"
#include <iostream>
#include <unistd.h>

// sorting algorithms
void bubbleSort(int* arr, int length)
{
    bool swapped;
    for (int i = length - 1; i > 0; i--)
    {
        swapped = false;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) return;   
    }
}

// visual sorting algorithms
void visualizeBubbleSort(int* arr, int length, pillar* p, int delay = 100, int width = 4)
{
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }

            std::cout << "\033c";
            printPillars(arr, length, width, p);
            printValues(arr, length, width);
            printIterator(i, width, 'i');
            printIterator(j, width, 'j');
            usleep(delay * 1000);

            if ( isSorted(arr, length) ) return;
        }
    }
}

void visualizeInsertSort(int* arr, int length, pillar* p, int delay = 100, int width = 4)
{
    for (int i = length - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }

            std::cout<<"\033[2J";
            printPillars(arr, length, width, p);
            printValues(arr, length, width);
            printIterator(i, width, 'i');
            printIterator(j, width, 'j');
            usleep(delay * 1000);

            if ( isSorted(arr, length) ) return;
        }
    }
}