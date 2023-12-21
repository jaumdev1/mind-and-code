#include <stdio.h>
#include <stdlib.h>
void selectionSort(int *array, int size){
    for (int i = 0; i < size; i++){
        int mIndex  = i;
      
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[mIndex])
            {
                mIndex = j;
            }
        }
        int temp = array[mIndex];
        array[mIndex] = array[i];
        array[i] = temp;
        
    }
}

int main(){
   int* array = (int*)calloc(10, sizeof(int));
   int values[] = {7, 9, 3, 4, 5, 6, 8, 2, 1};
   for (int i = 0; i <9; i++){
     array[i] = values[i];
   }
    selectionSort(array, 9);
    for (int i = 0; i < 9; i++) {
        printf("data: %d \n", array[i]);
    }

    free(array); 
    return 0;
}