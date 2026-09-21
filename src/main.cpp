#include "config.h"
#include "sort_bench_lib.h"
#include <iostream>
#include <random>
#include <vector>
#include <string>

int main()
{
    //вывод версии
    std::cout << "Запуск проекта: " << PROJECT_NAME << std::endl;
    std::cout << "Текущая версия: " << PROJECT_VERSION << std::endl;

    size_t size_arr, iterations;

    std::cout << "print size array and size iterations:\n";
    std::cin >> size_arr >> iterations;

    std::vector<int> original_arr (size_arr);
    std::mt19937 rng(42); // Фиксированный сид для честного сравнения
    std::uniform_int_distribution<int> dist(1, 100000);
    
    for (size_t i = 0; i < size_arr; ++i) {
        original_arr[i] = dist(rng);
    }


    SortAlgorithm Bubble_Sort {0.0, "Bubble Sort"};
    SortAlgorithm Selection_Sort {0.0, "Selection Sort"};
    SortAlgorithm Quick_Sort {0.0, "Quick Sort"};

    std::vector<SortAlgorithm> array_of_sorting_time;

    std::cout << "\n=================================================\n\n\n";

    std::cout << "Start benchmark => " << "array size = " << size_arr << ", iterations = " << iterations << std::endl;
    
    std::cout << "\nBenchmark starting Bubble Sort\n";
    sorting_benchmark(Bubble_Sort, bubbleSort, original_arr, iterations, array_of_sorting_time);
    std::cout << std::endl; 

    std::cout << "Benchmark starting Selection Sort\n";
    sorting_benchmark(Selection_Sort, selectionSort, original_arr, iterations, array_of_sorting_time);
    std::cout << std::endl;

    std::cout << "Benchmark starting Quick Sort\n";
    sorting_benchmark(Quick_Sort, quickSort, original_arr, iterations, array_of_sorting_time);
    std::cout << "\n=================================================\n\n\n";

    comparison_of_sorting(array_of_sorting_time);

    return 0;
}