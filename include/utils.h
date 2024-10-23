#ifndef UTILS_H
    #define UTILS_H
    
    extern const char* pad[11];
    
    typedef struct pillar pillar;
    struct pillar
    {
        char corners = '+';
        char top = '-';
        char sides = '|';
        char fill = ' ';
    };

    char* repeatChar(char character, int count);
    void swap(int* a, int* b);
    void shuffle(int* arr, int length);
    bool isSorted(int* arr, int length);
#endif