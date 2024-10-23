#include "../include/prints.h"
#include "../include/utils.h"
#include <iostream>

void printValues(int* arr, int length, int width)
{
    bool odd = (width-2) % 2;
    int padLength = (width - 2) / 2;

    for (int i=0; i < length; i++)
    {
        // if (arr[i] < 10) std::cout << pad[odd ? padLength+1 : padLength] << arr[i] << pad[padLength+1];
        // else std::cout << pad[odd ? padLength+1 : padLength] << arr[i] << pad[padLength];
        if (arr[i] < 10) std::cout << repeatChar(' ', odd ? padLength+1 : padLength) << arr[i] << repeatChar(' ', padLength+1);
        else std::cout << repeatChar(' ', padLength) << arr[i] << repeatChar(' ', odd ? padLength + 1 : padLength);
    }

    std::cout << std::endl;
}

void printIterator(int value, int width, char symbol)
{
    bool odd = (width-1) % 2;
    int padLength = (width - 1) / 2;
    for (int i = 0; i < value; i++) std::cout << repeatChar(' ', width);
    std::cout << repeatChar(' ', padLength) << symbol << repeatChar(' ', odd ? padLength + 1 : padLength) << std::endl;
}

void printPillars1(int* arr, int length)
{
    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < length; j++)
        {
            if (i > arr[j])
            {
                std::cout << " ";
            }
            else
            {
                std::cout << "X";
            }
        }
        std::cout << std::endl;
    }
}

void printPillars2(int* arr, int length)
{
    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < length; j++)
        {
            if (i > arr[j])
            {
                std::cout << "  ";
            }
            else
            {
                std::cout << ( (i == arr[j]) ? "__" : "||" );
                // std::cout << "[]";
            }
        }
        std::cout << std::endl;
    }
}

void printPillars(int* arr, int length, int width, pillar* p)
{
    // char* pillarTop = p->corners + repeatChar(p->top, width - 2) + p->corners;
    // char* pillarMiddle = p->sides + repeatChar(p->fill, width - 2) + p->sides;
    
    char* pillarTop = new char[width];
    char* pillarMiddle = new char[width];

    pillarTop[0] = p->corners;
    pillarTop[width-1] = p->corners;

    pillarMiddle[0] = p->sides;
    pillarMiddle[width-1] = p->sides;

    for (int i = 1; i < width-1; i++)
    {
        pillarTop[i] = p->top;
        pillarMiddle[i] = p->fill;
    }

    for (int i = length; i > 0; i--)
    {
        for (int j = 0; j < length; j++)
        {
            if (i > arr[j])
            {
                std::cout << repeatChar(' ', width);
            }
            else
            {
                std::cout << ( (i == arr[j]) ? pillarTop : pillarMiddle );
                // std::cout << "[]";
            }
        }
        std::cout << std::endl;
    }
}

// void printAll(int* arr, int length, int iterator, int width)
// {
//     printPillars(arr, length, width);
//     printValues(arr, length, width);
//     printIterator(iterator, width);
// }