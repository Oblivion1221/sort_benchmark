#pragma once

#include <vector>
#include <string>


//bubbleSort
void bubbleSort(std::vector<double> &arr);

//selectionSort
void selectionSort(std::vector<double> &arr);


//quickSort
int partition(std::vector<double> &arr, int low, int high);

void quickSort(std::vector<double> &arr, int low, int high);

void quickSort(std::vector<double> &arr);

//benchmark
template <typename T>

inline void doNotOptimizeAway(const T* ptr)
{
    #if defined(__GNUC__) || defined(__clang__)
    asm volatile("" : : "g"(ptr) : "memory");
    #endif
}

void sorting_benchmark(const std::string &name,
                         void(*sortFunc)(std::vector<double>&),
                         const std::vector<double> &original_arr,
                         int iterations);

