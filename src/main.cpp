#include "config.h"
#include "sort_bench_lib.h"
#include <iostream>
#include <random>

/*enum class SortAlgorithm
{
    StandardQuickSort = 0,
    MyQuickSort = 1,
    SelectionSort = 2,
    UnknownSort = 3
};*/

int main()
{
    //вывод версии
    std::cout << "Запуск проекта: " << PROJECT_NAME << std::endl;
    std::cout << "Текущая версия: " << PROJECT_VERSION << std::endl;

    size_t size_arr, iterations;

    std::cout << "print size array and size iterations:\n";
    std::cin >> size_arr >> iterations;

    std::vector<double> original_arr (size_arr);
    std::mt19937 rng(42); // Фиксированный сид для честного сравнения
    std::uniform_real_distribution<double> dist(1, 100000);
    
    for (size_t i = 0; i < size_arr; ++i) {
        original_arr[i] = dist(rng);
    }

    std::cout << "Start benchmark => " << "array size = " << size_arr << ", iterations = " << iterations << std::endl;
    
    std::cout << "Benchmark starting Bubble Sort\n";
    sorting_benchmark("Bubble Sort ", bubbleSort, original_arr, iterations);
    
    std::cout << "Benchmark starting Selection Sort\n";
    sorting_benchmark("Selection Sort ", selectionSort, original_arr, iterations);

    std::cout << "Benchmark starting Quick Sort\n";
    sorting_benchmark("Quick Sort ", quickSort, original_arr, iterations);

    return 0;
}