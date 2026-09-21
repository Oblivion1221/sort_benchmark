#include <gtest/gtest.h>
#include "sort_bench_lib.h"
#include <vector>

// Тест для Bubble Sort
TEST(BubbleSortTest, BubbleSorValid) 
{
    std::vector<int> arr = {5, -3, -8, 0, 2};
    std::vector<int> expected = {-8, -3, 0, 2, 5};
    
    bubbleSort(arr);
    
    EXPECT_EQ(arr, expected);
}

// Тест для Selection Sort
TEST(SelectionSortTest, SelectionSortValid) 
{
    std::vector<int> arr = {9, -10, -2, 0, 6};
    std::vector<int> expected = {-10, -2, 0, 6, 9};
    
    selectionSort(arr);
    
    EXPECT_EQ(arr, expected);
}

// Тест для Quick Sort
TEST(QuickSortTest, QuickSortValid) 
{
    std::vector<int> arr = {10, -1, 3, 0, -5};
    std::vector<int> expected = {-5, -1, 0, 3, 10};
    
    // Помним про static_cast, если используем перегруженную версию,
    // либо вызываем функцию напрямую:
    quickSort(arr);
    
    EXPECT_EQ(arr, expected);
}


// Тест на пустой массив
TEST(SortTest, EmptyArray) 
{
    std::vector<int> arr = {};
    
    bubbleSort(arr);
    quickSort(arr);
    selectionSort(arr);
    
    EXPECT_TRUE(arr.empty());
}