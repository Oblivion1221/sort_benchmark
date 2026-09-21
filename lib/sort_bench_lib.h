#pragma once

#include <vector>
#include <string>

struct SortAlgorithm
{
    double time;
    std::string name;
};

//comparison
void comparison_of_sorting(std::vector<SortAlgorithm> &vec);

//bubbleSort
void bubbleSort(std::vector<int> &arr);

//selectionSort
void selectionSort(std::vector<int> &arr);


//quickSort
size_t partition(std::vector<int> &arr, size_t low, size_t high);

void quickSort(std::vector<int> &arr, size_t low, size_t high);

void quickSort(std::vector<int> &arr);

//benchmark
template <typename T>

inline void doNotOptimizeAway(const T* ptr)
{
    #if defined(__GNUC__) || defined(__clang__)
    asm volatile("" : : "g"(ptr) : "memory");
    #endif
}

void sorting_benchmark(SortAlgorithm &data_alg,
                         void(*sortFunc)(std::vector<int>&),
                         const std::vector<int> &original_arr,
                         size_t iterations,
                        std::vector<SortAlgorithm> &vec);

