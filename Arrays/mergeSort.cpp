#include <iostream>
using namespace std;



void mergeAllSubArrays(int arr[], int low, int mid, int high){
    int size1 = mid - low + 1;
    int size2 = high - low;

    int temp1[size1];
    int temp2[size2];
    
    //Copying the first half of the numbers of array into temp1.
    for(int i = 0; i < size1; i++){
        temp1[i] = arr[low + i];
    }
    //Copying the second half of the numbers of array into temp2.
    for(int i = 0; i < size2; i++){
        temp2[i] = arr[mid + i + 1];
    }
    
    // Now initialize i, j = 0 and k = low where k will increment to point to the index of modified main array.
    // i, j will iterate over left array and right array respectively.
    int i = 0; int j = 0;
    int k = low;
    
    //Till the time both the array are in the similar indexing
    while(i < size1 && j < size2){
        if(temp1[i] < temp2[j]) {
            arr[k] = temp1[i];
            i++;
        }
        else {
            arr[k] = temp2[j];
            j++;
        }
        k++;
    }
    // If there are still more elements in left array then do as below
    while(i < size1){
        arr[k] = temp1[i];
        i++;
        k++;
    }
    //If there are still more element in right array then do as below
    while(j < size2){
        arr[k] = temp2[j];
        j++;
        k++;
    }
}

void mergeSort_divideArrayContinuosely(int arr[], int low, int high)
{
    if(low > high) {
        int mid = low + (high - low)/2;
        mergeSort_divideArrayContinuosely(arr, low, mid);
        mergeSort_divideArrayContinuosely(arr, mid+1, high);
        mergeAllSubArrays(arr, low, mid, high);
    } 
}
void printElements(int array[], int n){
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout<<endl;

}

int main(){
    int array[] = {2, 10, 6, 3, 8, 14, 6, 4};
    int size = sizeof(array);
    int low = 0; int high = size;
    mergeSort_divideArrayContinuosely(array, low, high);
    printElements(array, size);

    return 0;
    
}