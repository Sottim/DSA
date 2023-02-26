#include <stdio.h>
#include <stdlib.h>

int findMaxMin(double array[], int low, int high, double *max, double *min) {
    
    // Case 1: If array has only one element 
    if (low == high) {
        *min = array[low];
        *max = array[low];
        return 0;
    }
    
    // Case 2: If array has two elements
    if (high == low + 1) {
        if (array[low] > array[high]) {
            *max = array[low];
            *min = array[high];
        } else {
            *max = array[high];
            *min = array[low];
        }
        return 0;
    }
    
    // Divide the array into two halves
    double left_min, left_max, right_min, right_max;
    
    int mid = (low + high) / 2;
    // Recursive call to the function and divide the function in the half continuosly
    findMaxMin(array, low, mid, &left_max, &left_min);
    findMaxMin(array, mid + 1, high, &right_max, &right_min);
    
    // Find the maximum and minimum in the two halfs of the array
    // Find the maximum
    if (left_max > right_max)
        *max = left_max;
     else
        *max = right_max;
    // Find the minimum
    if (left_min < right_min)
        *min = left_min;
     else 
        *min = right_min;
}

int main() {
    double arr[] = {2.0, 10.2, 6.78, -3.87, 18.2, 14.0, -1.0};
    int size = sizeof(arr) / sizeof(arr[0]);
    double max, min;
    int low;
    findMaxMin(arr, low, size, &max, &min);
    
    printf("Maximum value: %f\n", max);
    printf("Minimum value: %f\n", min);
    
    return 0;
}