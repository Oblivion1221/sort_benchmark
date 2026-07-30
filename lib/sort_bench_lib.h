#pragma once

#include <vector>


void BubbleSort(int arr[], int n);

void SelectionSort(int arr[], int n);

int partition(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr);