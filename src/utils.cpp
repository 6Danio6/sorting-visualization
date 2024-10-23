#include "../include/utils.h"
#include <iostream>
#include <stdlib.h>

const char* pad[11] = {"", " ", "  ", "   ", "    ", "     ", "      ", "       ", "        ", "         ", "          "};

void swap(int* a, int* b)   
{
    if (a == b) return;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void shuffle(int* arr, int length)
{
    int randomIndex;
    for (int i = 0; i < length-1; i++)
    {
        randomIndex = rand() % (length - i) + i;
        swap(&arr[i], &arr[randomIndex]);
    }
}

char* repeatChar(char character, int count)
{
    char* output = new char[count];
    for (int i=0; i<count; i++) output[i] = character;
    return output;
}

int digitCount(int n)
{
    if (n<100)
    {
        return (n < 10) ? 1 : 2; 
    }
    else
    {
        return (n < 1000) ? 3 : 4; 
    }
}

bool isSorted(int* arr, int length)
{
    for (int i = 0; i < length - 1; i++) if (arr[i] > arr[i+1]) return false;
    return true;
}