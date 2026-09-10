#include <gtest/gtest.h>
#include "sort_bench_lib.h"
#include <vector>

// Тест для Bubble Sort
TEST(BubbleSortTest, BubbleSorValid) 
{
    std::vector<double> arr = {5.6, -3, -8.8, 0, 2};
    std::vector<double> expected = {-8.8, -3, 0, 2, 5.6};
    
    bubbleSort(arr);
    
    EXPECT_EQ(arr, expected);
}

// Тест для Selection Sort
TEST(SelectionSortTest, SelectionSortValid) 
{
    std::vector<double> arr = {9, -10, -2.7, 0.5, 6.6};
    std::vector<double> expected = {-10, -2.7, 0.5, 6.6, 9};
    
    selectionSort(arr);
    
    EXPECT_EQ(arr, expected);
}

// Тест для Quick Sort
TEST(QuickSortTest, QuickSortValid) 
{
    std::vector<double> arr = {10, -1, 3.8, 0.9, -5.7};
    std::vector<double> expected = {-5.7, -1, 0.9, 3.8, 10};
    
    // Помним про static_cast, если используем перегруженную версию,
    // либо вызываем функцию напрямую:
    quickSort(arr);
    
    EXPECT_EQ(arr, expected);
}


// Тест на пустой массив
TEST(SortTest, EmptyArray) 
{
    std::vector<double> arr = {};
    
    bubbleSort(arr);
    quickSort(arr);
    selectionSort(arr);
    
    EXPECT_TRUE(arr.empty());
}