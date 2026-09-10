    #include "sort_bench_lib.h"

    #include <iostream>
    #include <utility>
    #include <algorithm>
    #include <chrono>

    //bubbleSort
    void bubbleSort(std::vector<double> &arr)
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
    void selectionSort (std::vector<double> &arr)
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
    int partition(std::vector<double> &arr, int low, int high)
    {
        double pivot = arr[low + (high - low) / 2];
        int i = low - 1;
        int j = high + 1;

        while (true)
        {
            do {++i;} while (arr[i] < pivot);

            do {--j;} while (arr[j] > pivot);
            
            if(i >= j) return j;

            std::swap(arr[i], arr[j]);
        }
    }

    void quickSort(std::vector<double> &arr, int low, int high)
    {
        if(low < high)
        {
            int p = partition (arr, low, high);

            quickSort(arr, low, p);
            quickSort(arr, p + 1, high);
        }
    }

    void quickSort(std::vector<double> &arr)
    {
        if(!arr.empty())
        {
            quickSort(arr, 0, arr.size() - 1);
        }
    }

    //benchmark
    void sorting_benchmark(const std::string &name,
        void(*sortFunc)(std::vector<double>&),
        const std::vector<double> &original_arr,
        int iterations)
    {
        std::vector<double> copy_arr = original_arr;
        sortFunc(copy_arr);
        doNotOptimizeAway(copy_arr.data());

        auto start = std::chrono::high_resolution_clock::now();

        for(size_t i = 0; i < iterations; ++i)
        {
            std::vector<double> test_arr = original_arr;
            sortFunc(test_arr);
            doNotOptimizeAway(test_arr.data());    
        }

        auto end = std::chrono::high_resolution_clock::now();

        auto total_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        double average_time = (static_cast<double>(total_time) / iterations) / 1000.0;

        std::cout << name << " average => "<< average_time << "ms " << "( Time for " << iterations << " runs " << total_time / 1000.0 << "ms )" << std::endl;
    }