    #include "sort_bench_lib.h"
    #include <utility>
    #include <algorithm>

    void BubbleSort(int arr[], int n)
    {
        for(int i = 0; i < n - 1; ++i)
        {
            bool swapped = false;
            for(int j = 0; j < n - i - 1; ++j)
            {
                if(arr[j] > arr[j + 1])
                {
                    int buf = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = buf;
                    swapped = true;
                }
            }
            if(!swapped)break;
        }
    }

    void SelectionSort (int arr[], int n)
    {
        for(int i = 0; i < n - 1; ++i)
        {
            int min_index = i;
            for(int j = i + 1; j < n ; ++j)
            {
                if(arr[j] < arr[min_index])
                {
                    min_index = j;
                }
            }
            if(min_index != i)
            {
                int buf = arr[i];
                arr[i] = arr[min_index];
                arr[min_index] = buf; 
            }
        }
    }

    int partition(std::vector<int> &arr, int low, int high)
    {
        int pivot = arr[low + (high - low) / 2];
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

    void quickSort(std::vector<int> &arr, int low, int high)
    {
        if(low < high)
        {
            int p = partition (arr, low, high);

            quickSort(arr, low, p);
            quickSort(arr, p + 1, high);
        }
    }

    void quickSort(std::vector<int> &arr)
    {
        if(!arr.empty())
        {
            quickSort(arr, 0, arr.size() - 1);
        }
    }