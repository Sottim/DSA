#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialization of array with double data type to store +ve and negative numbers
    double array[] = {-1.0, 3.5, -4.5, 6.7, 8.0};
    int size = sizeof(array) / sizeof(array[0]);
    //min and max points to the first element of array initially
    double min = array[0];
    double max = array[0];

    for (int i = 1; i < size; i++) {
        // if min is greater than the arrary[i], min is changed to that element in the array
        if (array[i] < min) {
            min = array[i];
        }
         // if max is less  than the arrary[i], min is changed to that element in the array at the same time
        if (array[i] > max) {
            max = array[i];
        }
    }
    printf("Minimum number in the array is: %f\n", min);
    printf("Maximum number in the array is: %f\n", max);

    return 0;
}