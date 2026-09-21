    #include "sort_bench_lib.h"

    #include <iostream>
    #include <utility>
    #include <algorithm>
    #include <chrono>
    #include <vector>


    //comparison_of_sorting
   void comparison_of_sorting(std::vector<SortAlgorithm>& vec)
{
    size_t n = vec.size();
    if (n == 0) return;

    for (size_t i = 0; i < n; ++i)
    {
        size_t min_index = i;
        for (size_t j = i + 1; j < n; ++j)
        {
            if (vec[j].time < vec[min_index].time)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            std::swap(vec[min_index], vec[i]); 
        }
    }
    
    std::cout << "faster ---> slower\n"; 

    for(int i = 0; i < n; ++i)
    {
        std::cout << i + 1 << " " << vec[i].name << " time = " << vec[i].time << "ms" << std::endl;
    }
}

    //bubbleSort
    void bubbleSort(std::vector<int> &arr)
    {
        if(arr.empty()) return;
        size_t n = arr.size();
        for(size_t i = 0; i < n; ++i)
        {
            bool swapped = false;
            for(size_t j = 0; j < n - i - 1; ++j)
            {
                if(arr[j] > arr[j + 1])
                {
                    std::swap(arr[j], arr[j + 1]);
                    swapped = true;
                }
            }
            if(!swapped)break;
        }
    }

    //selectionSort
    void selectionSort (std::vector<int> &arr)
    {
        if(arr.empty()) return;
        size_t n = arr.size();
        for(size_t i = 0; i < n; ++i)
        {
            size_t min_index = i;
            for(size_t j = i + 1; j < n ; ++j)
            {
                if(arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            if(min_index != i)
            {
                std::swap(arr[min_index], arr[i]); 

            }
        }
    }

    //quickSort
  size_t partition(std::vector<int>& arr, size_t low, size_t high) {
    int pivot = arr[low + (high - low) / 2];
    size_t i = low;
    size_t j = high;

    while (true) {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;

        if (i >= j) return j;

        std::swap(arr[i], arr[j]);
        ++i;
        --j;
    }
}

void quickSort(std::vector<int>& arr, size_t low, size_t high) {
    if (low >= high) return;
    size_t p = partition(arr, low, high);
    if (p > low)
        quickSort(arr, low, p);
    if (p + 1 < high)
        quickSort(arr, p + 1, high);
}

void quickSort(std::vector<int>& arr) {
    if (arr.empty()) return;
    quickSort(arr, 0, arr.size() - 1);
}


    //benchmark
    void sorting_benchmark(SortAlgorithm &data_alg,
        void(*sortFunc)(std::vector<int>&),
        const std::vector<int> &original_arr,
        size_t iterations,
        std::vector<SortAlgorithm> & vec)
    {
        std::vector<int> copy_arr = original_arr;
        sortFunc(copy_arr);
        doNotOptimizeAway(copy_arr.data());

        auto start = std::chrono::high_resolution_clock::now();

        for(size_t i = 0; i < iterations; ++i)
        {
            std::vector<int> test_arr = original_arr;
            sortFunc(test_arr);
            doNotOptimizeAway(test_arr.data());    
        }

        auto end = std::chrono::high_resolution_clock::now();

        auto total_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        double average_time = (static_cast<double>(total_time) / iterations) / 1000.0;

        std::cout << data_alg.name << " average => "<< average_time << "ms " << "( Time for " << iterations << " runs " << total_time / 1000.0 << "ms )" << std::endl;

        data_alg.time = average_time;

        vec.push_back(data_alg);
    }