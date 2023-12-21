#include <stdio.h>
#include <stdlib.h>

void insertionSort(int* array, int size) {
    

    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

int main() {
    int* array = (int*)calloc(10, sizeof(int));

    int valores[] = {7, 9, 3, 4, 5, 6, 8, 2, 1};
    for (int i = 0; i < 10; i++) {
        array[i] = valores[i];
    }

    insertionSort(array, 9);

    for (int i = 0; i < 9; i++) {
        printf("data: %d \n", array[i]);
    }

    free(array); 

    return 0;
}