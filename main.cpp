#include <iostream>

void merge (float *array, int first, int last){
    int middle = (first + last)/2, start = first, final = middle + 1;
    float mass[15];
    for (int i = first; i <= last; ++i) {
        if((start <= middle && final > last) || array[start] < array[final]){
            mass[i] = array[start];
            start++;
        }
        else {
            mass[i] = array[final];
            final++;
        }
    }
    for (int i = first; i <= last; ++i) array[i] = mass[i];
}

void merge_sort (float *array, int first, int last){
    if(first > last){
        merge_sort(array, first, (first+last)/2);
        merge_sort(array, (first+last)/2 + 1, last);
        merge(array, first, last);
    }
}

int main() {
    float unsorted[15];
    std::cout << "Input numbers to sort: ";
    for (int i = 0; i < 15; ++i) std::cin >> unsorted[i];
    merge_sort(unsorted, 0, 14);
    for (int i = 0; i < 15; ++i) {
        std::cout << unsorted[i] << " ";
    }
    return 0;
}
