#include <iostream>
using namespace std;



void mergeAllSubArrays(int arr[], int low, int mid, int high){

}

int mergeSort_divideArrayContinuosely(int arr[], int low, int high){
    if(low > high) return 0;

    int mid = low + (high - low)/2;
    mergeSort_divideArrayContinuosely(arr, low, mid);
    mergeSort_divideArrayContinuosely(arr, mid+1, high);
    mergeAllSubArrays(arr, low, mid, high);

}
void printElements(int array[], int n){

}

int main(){
    int array[] = {2, 10, 6, 3, 8, 14, 6, 4};
    int size = sizeof(array);
    int low = 0; int high = size;
    mergeSort_divideArrayContinuosely(array, low, high);
    printElements(array, size);
    
}