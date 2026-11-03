#pragma once
#include <vector>
#include <memory>
#include <utility>
#include "../Header/Hanghoa.h"

using namespace std;

template <typename Compare>
int partitionTemplate(vector<unique_ptr<Hanghoa>>& arr, int low, int high, Compare comp) {
    auto& pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (comp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <typename Compare>
void quickSortTemplate(vector<unique_ptr<Hanghoa>>& arr, int low, int high, Compare comp) {
    if (low < high) {
        int pi = partitionTemplate(arr, low, high, comp);
        quickSortTemplate(arr, low, pi - 1, comp);
        quickSortTemplate(arr, pi + 1, high, comp);
    }
}