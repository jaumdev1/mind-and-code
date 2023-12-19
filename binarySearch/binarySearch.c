#include <stdio.h>

int binarySearch(int numbers[], int size, int numberSearched) {
   int start = 0;
   int end = size - 1;


    while (start <= end) {
        int middle = start + (end-start) / 2;
         printf("Number searched: %d\n", middle);

        if (numbers[middle] == numberSearched) {
            return middle;
        }

        if (numbers[middle] < numberSearched) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    int size = sizeof(numbers) / sizeof(numbers[0]);

    for (size_t i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }

    int result = binarySearch(numbers, size, 100);

    if (result != -1) {
        printf("Número found in position %d\n", result);
    } else {
        printf("Number not found\n");
    }

    return 0;
}
