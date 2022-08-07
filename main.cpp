#include <iostream>

void heap (float array[], int size, int root){
    int largest = root, left = 2 * root + 1, right = 2 * root + 2;
    if (left < size && array[left] > array[largest]) largest = left;
    if (right < size && array[right] > array[largest]) largest = right;
    if (largest != root) {
        std::swap(array[root], array[largest]);
        heap(array, size, largest);
    }
}

void heap_sort(float array[], int size){
    for (int i = size / 2 - 1; i >= 0; --i) heap(array, size, i);
    for (int i = size - 1; i >= 0; --i) {
        std::swap(array[0], array[i]);
        heap(array, i, 0);
    }
}

int main() {
    float unsorted[15];
    std::cout << "Input numbers to sort: ";
    for (int i = 0; i < 15; ++i) std::cin >> unsorted[i];
    heap_sort(unsorted, 15);
    for (int i = 14; i >= 0; --i) {
        std::cout << unsorted[i] << " ";
    }
    return 0;
}