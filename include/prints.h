#ifndef PRINTS_H
    #define PRINTS_H

    #include "utils.h"
    // void printAll(int* arr, int length, int iterator, int width);

    void printValues(int* arr, int length, int width);
    void printIterator(int value, int width, char symbol);
    void printPillars(int* arr, int length, int width, pillar* p);

    // legacy
    void printPillars1(int* arr, int length);
    void printPillars2(int* arr, int length);
#endif