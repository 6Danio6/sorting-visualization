#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "../include/utils.h"
#include "../include/prints.h"
#include "../include/sorts.h"

int main()
{
    srand(time(NULL));

    int samples;
    int delay;
    int width;

    std::cout << "Sample count: ";
    std::cin >> samples;

    std::cout << "Millisecond delay: ";
    std::cin >> delay;

    std::cout << "Pillar width: ";
    std::cin >> width;

    int* a = new int[samples];
    for (int i = 0; i < samples; i++)
    {
        a[i] = i+1;
    }
    shuffle(a, samples);

    pillar pillar = {'+', '-', '|', ' '};

    std::cout << std::endl << "Sorting..." << std::endl;
    visualizeBubbleSort(a, samples, &pillar, delay, width);
    std::cout << std::endl;
    return 0;
}
