#include "config.h"
#include "sort_bench_lib.h"
#include <iostream>

enum class SortAlgorithm
{
    StandardQuickSort = 0,
    MyQuickSort = 1,
    SelectionSort = 2,
    UnknownSort = 3
};



int main()
{
    std::cout << "Запуск проекта: " << PROJECT_NAME << std::endl;
    std::cout << "Текущая версия: " << PROJECT_VERSION << std::endl;
    
    std::cout << "Hello World" << std::endl;

    return 0;
}