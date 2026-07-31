#pragma once

#include <vector>
#include <string>


//bubbleSort
void bubbleSort(std::vector<int> &arr);

//selectionSort
void selectionSort(std::vector<int> &arr);


//quickSort
int partition(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr);

//benchmark
template <typename T>

inline void doNotOptimizeAway(const T* ptr)
{
    #if defined(__GNUC__) || defined(__clang__)
    asm volatile("" : : "g"(ptr) : "memory");
    #endif
}

void sorting_benchmark(const std::string &name, void(*sortFunc)(std::vector<int>&), const std::vector<int> &original_arr, int iterations);